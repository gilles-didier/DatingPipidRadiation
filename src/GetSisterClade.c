#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <fenv.h>

// #include "Utils.h"
#include "Tree.h"

#ifdef DO_PS
#endif
#define PREFIX "Trees"
#define STRING_SIZE 300

#define HELPMESSAGE "--------------------------\n\nNAME\n	dist - Computation of the divergence time distibution associated to a given clade from a set of possible trees, the fossil ages, and the diversification rates\n	\nSYNOPSIS\n	dist [OPTIONS] <input Tree File> <input Fossil File> <input List Clade> [output File]\n\nDESCRIPTION\n	Compute the distribution of the divergence time associated to the clade corresponding to the list of tips given in <input List Clade> by sampling into the trees contianed in <input Tree File> (in Newick format) into the fossil ranges provided in <input Fossil File> (in csv format) and output the distribution as a .csv table <output File>.csv\n\n	Options are\n	-z <input Tree File>\n		output the tree in text debug format in the console and exit \n	-o <origin bound inf> [origin bound sup]\n		set the origin range; if origin bound sup is not given it is set to the most ancient fossil age\n	-e <end bound inf> <end bound sup>\n		set the end time range\n	-p <speciation rate> <extinction rate> <fossilization rate>\n		set the speciation, extinction and fossilization rates\n	-s <number>\n		set the number of samples\n	-d\n		return the distribution (otherwise the density is returned by default)\n	-u <value>\n		set the step discretizing the time distribution to <value>\n	-s <number>\n		set the number of thread running in parallell\n	-h\n		display help\n\n--------------------------\n\n"

static char **readList(FILE *f);

int main(int argc, char **argv) {
	char *inputFileNameTree, *inputFileNameList, *outputPrefix = PREFIX, option[256];
	FILE *fi, *fl;
	int i, j;

	// feenableexcept(FE_DIVBYZERO | FE_INVALID | FE_OVERFLOW);
	for(i = 0; i < 256; i++)
		option[i] = 0;

	for(i = 1; i < argc && *(argv[i]) == '-'; i++) {
		for(j = 1; argv[i][j] != '\0'; j++)
			option[argv[i][j]] = 1;
		if(option['z']) {
			option['z'] = 0;
			if((i + 1) < argc && (fi = fopen(argv[++i], "r"))) {
				TypeTree *tree;
				tree = readTree(fi);
				toBinary(tree);
				printTreeDebug(stdout, tree->root, tree, tree->name);
				//				bltoabsTime(tree);
				reorderTree(tree->name, tree);
				if(tree->minTime == NO_TIME || tree->minTime == 0.)
					tree->minTime = tree->time[tree->root] * 0.9;
				if(tree->maxTime == NO_TIME) {
					int n;
					tree->maxTime = 0.;
					for(n = 0; n < tree->size; n++)
						if(tree->time[n] > tree->maxTime)
							tree->maxTime = tree->time[n];
				}
			} else {
				fprintf(stderr, "Error while reading %s.\n", argv[i]);
				exit(1);
			}
			exit(0);
		}
		if(option['h']) {
			option['h'] = 0;
			error("%s\n", HELPMESSAGE);
		}
	}
	if(i < argc) {
		inputFileNameList = argv[i++];
	} else {
		fprintf(stderr, "Please provide the name of a file containing a list of leaf names\n");
		exit(1);
	}
	if(i < argc) {
		inputFileNameTree = argv[i++];
	} else {
		fprintf(stderr, "Please provide the name of a file containing a phylogenetic tree in Newick format\n");
		exit(1);
	}
	if(i < argc)
		outputPrefix = argv[i++];
	if((fi = fopen(inputFileNameTree, "r")) && (fl = fopen(inputFileNameList, "r"))) {
		TypeTree **tree;
		int i, sizeTree, countCladeOK;
		char **list;
		FILE *fout;
		char nameOutput[STRING_SIZE];

		list = readList(fl);
		fclose(fl);
		tree = readTrees(fi);
		fclose(fi);
		if(tree[0] == NULL) {
			fprintf(stderr, "Error: no tree\n");
			return 1;
		}
		//		fixTreeSet(tree);
		sizeTree = 0;
		countCladeOK = 0;
		sprintf(nameOutput, "%s_sister.txt", outputPrefix);
		if((fout = fopen(nameOutput, "w"))) {
			for(i = 0; tree[i] != NULL; i++) {
				int n;
				sizeTree++;
				n = getClade(list, tree[i]);
				if(n != NOSUCH) {
					int *parent, a, c;
					countCladeOK++;
					parent = getParent(tree[i]);
					a = parent[n];
					free((void *)parent);
					printf("node %d ancestor %d -> %d %d\n", n, a, tree[i]->node[a].child, tree[i]->node[tree[i]->node[a].child].sibling);
					for(c = tree[i]->node[a].child; c != NOSUCH && c == n; c = tree[i]->node[c].sibling)
						;
					printf("c %d\n", c);
					if(c != NOSUCH) {
						fprintTips(fout, c, tree[i]);
						fprintf(fout, "\n");
					} else
						printf("problem tree %d\n", i + 1);
				}
			}
			fclose(fout);
		}
		printf("clade OK %d/%d\n", countCladeOK, sizeTree);
		for(i = 0; i < sizeTree; i++)
			freeTree(tree[i]);
		free((void *)tree);
		for(i = 0; list[i] != NULL; i++)
			free((void *)list[i]);
		free((void *)list);
	} else {
		fprintf(stderr, "Cannot read %s or %s\n", inputFileNameTree, inputFileNameList);
		exit(1);
	}
	return 0;
}

#define MAX_SIZE_TMP 50
#define INC_BUFFER 50
#define IS_SEP(c) (c == ' ' || c == '\t' || c == '\r' || c == '\n' || c == ';')

char **readList(FILE *f) {
	char c, tmp[MAX_SIZE_TMP + 1], **list;
	int size, sizeBuffer;

	sizeBuffer = INC_BUFFER;
	list = (char **)malloc(sizeBuffer * sizeof(char *));
	size = 0;
	do {
		c = getc(f);
	} while(c != EOF && IS_SEP(c));
	while(c != EOF) {
		int i;
		i = 0;
		while(i < MAX_SIZE_TMP && c != EOF && !IS_SEP(c)) {
			tmp[i] = c;
			c = getc(f);
			i++;
		}
		tmp[i++] = '\0';
		if(i == MAX_SIZE_TMP) {
			fprintf(stderr, "Ident too long (%s) ...", tmp);
			exit(1);
		}
		if(i > 1) {
			if(size >= sizeBuffer) {
				sizeBuffer += INC_BUFFER;
				list = (char **)realloc((void *)list, sizeBuffer * sizeof(char *));
			}
			list[size] = (char *)malloc((strlen(tmp) + 1) * sizeof(char));
			strcpy(list[size], tmp);
			size++;
		}
		while(c != EOF && IS_SEP(c))
			c = getc(f);
	}
	if(size >= sizeBuffer) {
		sizeBuffer += INC_BUFFER;
		list = (char **)realloc((void *)list, sizeBuffer * sizeof(char *));
	}
	list[size++] = NULL;
	return list;
}
