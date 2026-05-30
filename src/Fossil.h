#ifndef FossilF
#define FossilF

#include <stdlib.h>
#include <stdio.h>
#include "Utils.h"
#include "Tree.h"

#define TAG_FOSSIL "FOS"
#define TAG_ORIGIN "ORI"
#define TAG_END "END"
#define TAG_STATUS "STAT"
#define TAG_TIME "TIME"

#define INC_BUF_TIME_TABLE 3

typedef enum {
	noneNodeStatus = 0,
	contempNodeStatus,
	extinctNodeStatus,
	unknownNodeStatus,
	divergenceNodeStatus
} TypeNodeStatus;

typedef struct INTERVAL {
	double inf, sup;
} TypeInterval;

typedef struct FOSSIL_LIST {
	double time;
	int prec;
} TypeFossilList;

typedef struct FOSSIL_TAB {
	double *time;
	int size;
} TypeFossilTab;

/*Entries of fossilList are assumed sorted in increasing order with regard to the times while the chain prec have to go in decreasing order again with time*/
typedef struct FOSSIL_FEATURE {
	TypeFossilList *fossilList;
	TypeTimeInterval *endTimeTable;
	TypeNodeStatus *status;
	int *fossil, size, sizeBuf;
} TypeFossilFeature;

typedef struct STANDARD_AND_FOSSIL_FEATURE {
	//	TypeStandardFeature *std;
	TypeFossilFeature *fos;
} TypeStandardAndFossilFeature;

typedef struct BASIC_FOSSIL_FEATURE {
	char **name, **comment;
	double *time, maxTime, minTime;
	TypeFossilList *fossilList;
	int *fossil, size, sizeBuf;
} TypeBasicFossilFeature;

typedef struct FOSSIL_FEATURE_MAX {
	TypeFossilFeature *fos;
	double *maxTime;
} TypeFossilFeatureMaxTime;

#ifdef __cplusplus
extern "C" {
#endif

/*Copy precise fossil data for n nodes.*/
TypeFossilFeature *cpyFossilFeature(TypeFossilFeature *feat, int n);
/*Return the minimum fossil time.*/
double getMinFossilTime(TypeFossilFeature *feat);
/*Return the maximum fossil time.*/
double getMaxFossilTime(TypeFossilFeature *feat);
/*Adjust tree times using precise fossil data.*/
void fixTreeBis(TypeTree *tree, TypeFossilFeature *fos);
/*Adjust tree times using an alternate fossil fixing strategy.*/
void fixTreeTer(TypeTree *tree, TypeFossilFeature *fos);
/*Fill unknown tree times using fossil constraints.*/
void fillUnknownTimesFossil(double tmin, double tmax, TypeTree *tree, TypeFossilFeature *fos);
/*Check consistency between fossil records and node count.*/
int checkConsistency(TypeFossilFeature *fp, int size);

/*compare two fossils a and b with regard to their times*/
int compareFossilList(const void *a, const void *b);
/*desallocate memory space of fos*/
void freeFossilFeature(TypeFossilFeature *fos);
/*returns the number of internal fossil finds of "tree", i.e. the ones which are not just before an extinction*/
int countInternalFossils(double *time, TypeFossilFeature *fos, int size);
/*Compare two intervals for sorting.*/
int compareInterval(const void *a, const void *b);
/*print fossil*/
void fprintInterval(FILE *f, TypeInterval fos);
/*print fossil*/
int sprintInterval(char *s, TypeTimeInterval fos);
/*print tree in newick format*/
void fprintFossilTreeNewick(FILE *f, TypeTree *tree, TypeFossilFeature *fos);
/*prune "tree" to that can be observed from contemporary lineages and fossil finds*/
TypeTree *pruneFossil(TypeTree *tree, TypeFossilFeature *fos);
/*Copy a subtree while transforming it to binary form and carrying fossil data.*/
int iterateBinaryFossil(int n, TypeTree *resT, TypeFossilFeature *resF, TypeTree *tree, TypeFossilFeature *fos);
/*Return a binary version of a tree and its fossil data.*/
TypeTree *fixBinaryFossil(TypeTree *tree, TypeFossilFeature *fos);
/*print fossil table*/
void sprintFossilNHX(char *s, char *prefix, int e, TypeFossilList *list);
/*Merge fossil annotations into existing comment strings.*/
char **getFossilComment(char **comment, TypeFossilFeature *fos, int size);
/*Convert linked fossil lists to per-node fossil time tables.*/
TypeFossilTab *listToFossilTab(TypeFossilFeature *fos, int size);
/*free a fossil tab*/
void freeFossilTab(TypeFossilTab *fosTab, int size);
/*Print fossil feature data for all nodes.*/
void fprintFossilFeature(FILE *f, TypeFossilFeature *feat, char **name, int size);
/*Print one linked fossil list.*/
void fprintFossilList(FILE *fo, int e, TypeFossilList *list);
/*Append one linked fossil list as an NHX string.*/
int sprintFossilListNHX(char *s, int e, TypeFossilList *list);
/*Fill tree comments with fossil annotations.*/
void fillCommentFossil(TypeTree *tree, TypeFossilFeature *fos);
/*Save tree with fossil as comments*/
void fprintTreeFossil(FILE *f, TypeTree *tree, TypeFossilFeature *fos);
/*Adjust a tree so fossil-bearing nodes have compatible times.*/
void fixTreeFossil(TypeTree *tree, TypeFossilFeature *fos);
/*Prune a tree using the second fossil-aware pruning strategy.*/
TypeTree *pruneFossilBis(TypeTree *tree, TypeFossilFeature *fos);
/*Sort fossil chains attached to each node by time.*/
void fixFossilOrder(TypeFossilFeature *sample, int size);
/*Print fossil data in a debug-oriented format.*/
void printFossilDebug(FILE *f, TypeFossilFeature *sample, int size);
/*fill the table maxTime where entry n the most recent time of the clade n*/
void fillMaxTime(int n, TypeTree *tree, double *maxTime);
/*Return a binary tree while preserving fossil data and clade max times.*/
TypeTree *fixBinaryFossilBis(TypeTree *tree, TypeFossilFeature *fos, double *maxTime);
/*prune "tree" to that can be observed from contemporary lineages and fossil finds*/
TypeTree *pruneFossilTer(TypeTree *tree, TypeFossilFeature *fos);
/*Return the maximum fossil time below node n.*/
double getMaxFossilTimeToNode(int n, TypeTree *tree, TypeFossilFeature *feat);

#ifdef __cplusplus
}
#endif

#endif
