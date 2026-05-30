#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <fenv.h>

#include <gsl/gsl_rng.h>

#include "Utils.h"
#include "Tree.h"

#ifdef DO_PS
#endif

#define STRING_SIZE 300
#define INC_CUT 5
#define SEQ_SIZE 30
#define EXT_OUTPUT "_added.phy"
#define MAX_PRED 7.5E+07

#define SIZE_BUFFER_CHAR 300
#define INFTY 1E99
#define RINFTY 1E99
#define DEF 10
#define MIN_VAL 0.000001
#define DELTA 0.000001

#define MINVAL 0.01
#define TRIAL 10
#define FIX_VAL(x) (((x) <= 0) ? MINVAL : (x))

#define MAX_ITER 1000

#define M_MAX 6
#define M_MAX_F 4
#define MIN_TREE 20
#define PREFIX "table"
#define MAX_TRIALS 1000

#define HELPMESSAGE "--------------------------\n\nNAME\n	dist - Computation of the divergence time distibution associated to a given clade from a set of possible trees, the fossil ages, and the diversification rates\n	\nSYNOPSIS\n	dist [OPTIONS] <input Tree File> <input Fossil File> <input List Clade> [output File]\n\nDESCRIPTION\n	Compute the distribution of the divergence time associated to the clade corresponding to the list of tips given in <input List Clade> by sampling into the trees contianed in <input Tree File> (in Newick format) into the fossil ranges provided in <input Fossil File> (in csv format) and output the distribution as a .csv table <output File>.csv\n\n	Options are\n	-z <input Tree File>\n		output the tree in text debug format in the console and exit \n	-o <origin bound inf> [origin bound sup]\n		set the origin range; if origin bound sup is not given it is set to the most ancient fossil age\n	-e <end bound inf> <end bound sup>\n		set the end time range\n	-p <speciation rate> <extinction rate> <fossilization rate>\n		set the speciation, extinction and fossilization rates\n	-s <number>\n		set the number of samples\n	-d\n		return the distribution (otherwise the density is returned by default)\n	-u <value>\n		set the step discretizing the time distribution to <value>\n	-s <number>\n		set the number of thread running in parallell\n	-h\n		display help\n\n--------------------------\n\n"

int main(int argc, char **argv) {
	char *inputFileNameTree1, *inputFileNameTree2, option[256];
	FILE *fi1, *fi2;
	int i, j;

	for(i = 0; i < 256; i++)
		option[i] = 0;

	for(i = 1; i < argc && *(argv[i]) == '-'; i++) {
		for(j = 1; argv[i][j] != '\0'; j++)
			option[argv[i][j]] = 1;
		if(option['h']) {
			option['h'] = 0;
			error("%s\n", HELPMESSAGE);
		}
	}
	if(i < argc) {
		inputFileNameTree1 = argv[i++];
	} else {
		fprintf(stderr, "Please provide the name of a file containing a phylogenetic tree in Newick format\n");
		exit(1);
	}
	if(i < argc) {
		inputFileNameTree2 = argv[i++];
	} else {
		fprintf(stderr, "Please provide the name of a file containing a phylogenetic tree in Newick format\n");
		exit(1);
	}
	if((fi1 = fopen(inputFileNameTree1, "r")) && (fi2 = fopen(inputFileNameTree2, "r"))) {
		TypeTree *tree, **trees;
		int i, sizeTree, n;

		tree = readTree(fi1);
		fclose(fi1);
		trees = readTrees(fi2);
		fclose(fi2);
		if(trees[0] == NULL) {
			fprintf(stderr, "Error: no tree\n");
			return 1;
		}
		fixTreeSet(trees);
		for(sizeTree = 0; trees[sizeTree] != NULL; sizeTree++)
			;
		if(sizeTree == 0)
			error("Error: no tree (size)\n");
		char **tab = (char **)malloc((tree->size + 1) * sizeof(char *));
		for(n = 0; n < tree->size; n++) {
			char outputFileName[1000];
			FILE *fo;
			if(tree->node[n].child != NOSUCH) {
				int size = 0;
				fillTips(n, tree, tab, &size);
				tab[size] = NULL;
				for(i = 0; i < sizeTree && getClade(tab, trees[i]) != NOSUCH; i++)
					;
				printf("\nnode %d (%d) i %d/%d\n", n, tree->root, i, sizeTree);
				if(i == sizeTree) {
					int j;
					// printf("\nnode %d (%d)\n", n, tree->root);
					// for(j=0; tab[j] != NULL; j++)
					// fprintf(stdout, "%s\n", tab[j]);

					sprintf(outputFileName, "%s_%d.txt", inputFileNameTree2, n);
					// if(tree->name[n] == NULL) {
					// sprintf(outputFileName, "%s_%d.txt", inputFileNameTree2, n);
					//} else {
					// sprintf(outputFileName, "%s_%s.txt", inputFileNameTree2, tree->name[n]);
					//}
					if((fo = fopen(outputFileName, "w"))) {
						for(j = 0; tab[j] != NULL; j++)
							fprintf(fo, "%s\n", tab[j]);
						fclose(fo);
					}
				}
				if(n == tree->root) {
					for(i = 0; i < sizeTree; i++)
						if(getClade(tab, trees[i]) == NOSUCH) {
							fprintf(stderr, "Problem tree %d\n", i + 1);
							fprintTreeNewick(stderr, trees[i]);
							exit(0);
						}
				}
			}
			// else {
			// sprintf(outputFileName, "%s_%d.txt", inputFileNameTree2, n);
			// if((tree->name[n] != NULL) && (fo = fopen(outputFileName, "w"))) {
			// fprintf(fo, "%s\n", tree->name[n]);
			// fclose(fo);
			//}
			//}
		}
		freeTree(tree);
		for(i = 0; i < sizeTree; i++)
			freeTree(trees[i]);
		free((void *)trees);
		free((void *)tab);
	} else {
		fprintf(stderr, "Cannot read %s or %s\n", inputFileNameTree1, inputFileNameTree2);
		exit(1);
	}
	return 0;
}
