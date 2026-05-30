#ifndef FossilIntF
#define FossilIntF

#include <stdlib.h>
#include <stdio.h>
#include "Utils.h"
#include "Tree.h"
#include "Fossil.h"

typedef struct FOSSIL_INT_LIST {
	TypeTimeInterval fossilInt;
	int prec;
} TypeFossilIntList;

typedef struct FOSSIL_INT_TAB {
	TypeTimeInterval *fossilInt;
	int size;
} TypeFossilIntTab;

typedef struct INDEX_FOSSIL_INT_TAB {
	int size, *index;
	TypeFossilIntTab *fossilIntTab;
} TypeIndexFossilIntTab;

typedef struct NAME_FOSSIL_INT_TAB {
	char **name;
	TypeFossilIntTab *fossilIntTab;
	double *stopTime;
	int size;
} TypeNameFossilIntTab;

typedef struct FOSSIL_INT_FEATURE {
	TypeFossilIntList *fossilIntList;
	TypeTimeInterval *endTimeTable;
	int *fossilInt, sizeFossil, sizeBufFossil, sizeTime, sizeBufTime, sizeNode, sizeBufNode, *endTime;
	TypeNodeStatus *status;
} TypeFossilIntFeature;

typedef struct TMP_FOSSIL_INT_ITEM {
	char *name;
	TypeFossilIntTab fossilIntTab;
} TypeFossilIntItem;

#ifdef __cplusplus
extern "C" {
#endif
/*Return the latest lower bound among all fossil intervals.*/
double getFossilIntMaxInfTime(TypeFossilIntFeature *feat);
/*Return the first fossil interval time reachable from a node.*/
double getFirstFossilIntTimeFromNode(int n, TypeTree *tree, TypeFossilIntFeature *feat);
/*Return the midpoint fossil interval time reachable from a node.*/
double getMidFossilIntTimeFromNode(int n, TypeTree *tree, TypeFossilIntFeature *feat);
/*index[i] is the new index of former index i (NOSUCH if removed)*/
/*assume that no risk of ecrase a data*/
void reindexFossilInt(TypeFossilIntFeature *fos, int *index);
/*fix status of leaves*/
void fixStatus(TypeTree *tree, TypeFossilIntFeature *feat);
/*Fill tree comments with fossil interval annotations.*/
void fillComment(TypeTree *tree, TypeFossilIntFeature *fos);
/*print fossilInt table*/
int sprintFossilIntListNHX(char *s, int e, TypeFossilIntList *list);
/*from fos to FossilInt fos*/
TypeFossilIntFeature *fosToFossilInt(TypeTree *tree);
/*Remove fossil interval data attached to one node.*/
void removeFossilIntNode(TypeFossilIntFeature *fos, int n);
/*Remove fossil interval records listed by index.*/
void removeFossilIntFossil(TypeFossilIntFeature *fos, int *list);
/*Resize node-related fossil interval storage.*/
void reallocFossilIntNode(TypeFossilIntFeature *fos, int size);
/*allocate a new fossil int feature with n entries/nodes*/
TypeFossilIntFeature *newFossilIntFeature(int n);
/*add a new fossil to n*/
void addFossilInt(TypeFossilIntFeature *fos, int n, double inf, double sup);
/*Copy fossil interval data for n nodes.*/
TypeFossilIntFeature *cpyFossilIntFeature(TypeFossilIntFeature *feat, int n);
/*Synchronize tree tip times/statuses with fossil interval data.*/
void fixTree(TypeTree *tree, TypeFossilIntFeature *fos);
/*Parse a textual interval into a fossil interval.*/
TypeTimeInterval toFossilInt(char *s);
/*Parse a list of fossil intervals from text.*/
TypeFossilIntTab getFossilInt(char *str);
/*Build fossil interval data from tree annotations.*/
TypeFossilIntFeature *treeToFossilInt(TypeTree *tree);
/*Read named fossil interval tables from a stream.*/
TypeNameFossilIntTab *readFossilIntTab(FILE *f);
/*Free a named fossil interval table.*/
void freeNameFossilIntTab(TypeNameFossilIntTab *list);
/*Free an indexed fossil interval table.*/
void freeIndexFossilIntTab(TypeIndexFossilIntTab *list);
/*Map named fossil interval tables to tree node indices.*/
TypeIndexFossilIntTab *name2indexFossilIntTab(TypeNameFossilIntTab *tab, char **name, int size);
/*Read fossil intervals and attach them to tree node names.*/
TypeFossilIntFeature *getFossilIntFeature(FILE *f, char **name, int size);
/*Print one fossil interval.*/
void fprintFossilInt(FILE *f, TypeTimeInterval fos);
/*Print fossil interval data for all nodes.*/
void fprintFossilIntFeature(FILE *f, TypeFossilIntFeature *feat, char **name, int size);
/*Print the fossil interval chain for one node.*/
void fprintFossilIntList(FILE *fo, int e, TypeFossilIntList *list);
/*Sample precise fossil times from fossil intervals.*/
TypeFossilFeature *sampleFossilInt(TypeFossilIntFeature *feat, int size);
/*Return the earliest sampled interval time.*/
double getFirstFossilIntTime(TypeFossilIntFeature *feat);
/*Return the midpoint time over all fossil intervals.*/
double getMidFossilIntTime(TypeFossilIntFeature *feat);
/*Return the minimum fossil interval bound.*/
double getMinFossilIntTime(TypeFossilIntFeature *feat);
/*Return the maximum fossil interval bound.*/
double getMaxFossilIntTime(TypeFossilIntFeature *feat);
/*Return the minimum fossil interval time below a node.*/
double getMinFossilIntTimeFromNode(int n, TypeTree *tree, TypeFossilIntFeature *feat);
/*Return the maximum fossil interval time below a node.*/
double getMaxFossilIntTimeToNode(int n, TypeTree *tree, TypeFossilIntFeature *feat);
/*Convert fossil interval signs/orientation in place.*/
void negateFossilInt(TypeFossilIntFeature *feat);
/*Compare two fossil intervals for sorting.*/
int compareFossilInt(const void *a, const void *b);
/*Compare two fossil interval list entries for sorting.*/
int compareFossilIntList(const void *a, const void *b);
/*Free fossil interval feature storage.*/
void freeFossilIntFeature(TypeFossilIntFeature *fos);
/*Print a tree with fossil interval annotations.*/
void fprintTreeFossilInt(FILE *f, TypeTree *tree, TypeFossilIntFeature *fos);
/*Save subtree at node with fossil intervals as comments*/
void fprintSubTreeFossilInt(FILE *f, int node, TypeTree *tree, TypeFossilIntFeature *fos);
/*Fill unknown tree times using fossil interval bounds.*/
void fillUnknownTimesFossilInt(double tmin, double tmax, TypeTree *tree, TypeFossilIntFeature *fos);
/*Create precise fossil data from interval data and chosen node times.*/
TypeFossilFeature *setTimeFossilInt(TypeFossilIntFeature *feat, double *time, int size);
#ifdef __cplusplus
}
#endif

#endif
