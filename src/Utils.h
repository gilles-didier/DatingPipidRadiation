#ifndef UtilsF
#define UtilsF

#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include "MyR.h"

typedef /*unsigned*/ long TypePosition;

typedef unsigned int TypeNumber;

typedef enum TS {
	ErrorArgument = 0,
	ErrorInit,
	ErrorReading,
	ErrorWriting,
	ErrorMemory,
	ErrorExec,
	ErrorArgs,
	ExitOk
} TypeExit;

#define END_LIST_INT INT_MIN
#define INC_SIZE_BUFFER_TABLE_DOUBLE 100
#define INC_SIZE_DICT 100
#define MAX_DICT_LENGTH 1000

typedef struct LIST_DOUBLE {
	int size;
	double *val;
} TypeListDouble;

typedef struct TABLE_DOUBLE {
	int size, sizeBuffer;
	double *table;
} TypeTableDouble;

/*if symbol ==-1 then child contains an index*/
typedef struct LEXI_NODE {
	char symbol;
	int child, sibling;
} TypeLexiNode;

typedef struct LEXI_TREE {
	TypeLexiNode *node;
	int root, size, sizeBuf;
} TypeLexiTree;

typedef struct DICT_NODE {
	char symbol;
	struct DICT_NODE *child;
	struct DICT_NODE *sibling;
	long index;
} TypeDictNode;

typedef struct DICT_TREE {
	TypeDictNode *root;
	long index;
} TypeDictTree;

typedef struct INDEX {
	int size, buffer;
	char **name;
	TypeDictNode *dict;
} TypeIndex;

#ifdef __cplusplus
extern "C" {
#endif
/*Parse a textual numeric interval into lower and upper bounds.*/
void toInterval(char *s, double *inf, double *sup);
/*Duplicate a string with project memory allocation conventions.*/
char *strdpl(char *src);
/*Return whether a character is an equality separator.*/
int isequal(char c);
/*Parse the next tag=value pair from a string.*/
char *nextTag(char *s, char **tag, char **value);
/*Replace all occurrences of one character in a string.*/
void replaceChar(char *s, char a, char n);
/*Remove spaces from a string in place.*/
void removeSpaces(char *s);
/*Free a dynamic list of doubles.*/
void freeListDouble(TypeListDouble *list);

/*Find a word in a lexical tree.*/
int findWordLexi(char *w, TypeLexiTree *dict);
/*Insert a word/index pair in a lexical tree.*/
int addWordLexi(char *w, int index, TypeLexiTree *dict);
/*Initialize one lexical tree node.*/
void initLexiNode(char symbol, TypeLexiNode *n);
/*Allocate an empty lexical tree.*/
TypeLexiTree *newLexiTree();
/*Free a lexical tree.*/
void freeLexiTree(TypeLexiTree *dict);
/*Print a lexical tree for debugging.*/
void fprintLexiTree(FILE *f, TypeLexiTree *dict);
/*return a lexitree from tab name*/
TypeLexiTree *getDictNameTab(char **name, int size);

/*Initialize a name index.*/
void initIndex(TypeIndex *species);
/*Print a name index for debugging.*/
void printIndex(FILE *f, TypeIndex *index);
/*Add a name to an index and return its index.*/
int addIndex(char *name, TypeIndex *species);

/*Free a dictionary node and its descendants.*/
void freeDictNode(TypeDictNode *n);
/*Allocate one dictionary node.*/
TypeDictNode *newDictNode(char c);
/*Return the index and consumed size for a dictionary lookup.*/
int getIndexString(char *s, TypeDictNode *cur, int *size);
/*Return the index associated with a string in a dictionary.*/
int getIndex(char *s, TypeDictNode *cur);
/*Return whether a character is a generic separator.*/
int IsSeparator(char c);
/*Return whether a character separates items.*/
int IsItemSeparator(char c);
/*Return whether a character separates lines.*/
int IsLineSeparator(char c);
/*Read one logical line from a stream.*/
int readLine(FILE *f, char *buffer);
/*Read one item from a stream.*/
int readItem(FILE *f, char *buffer);
/*Split a string into tokens.*/
int tokenize(char *src, char **dest);
/*Advance to the next non-empty line start.*/
char nextStartLine(FILE *f, char c);
/*Advance to the next item start.*/
char nextStartItem(FILE *f, char c);
/*Skip separators in a stream.*/
void skipSeparator(FILE *f);
/*Skip complete lines in a stream.*/
char passLines(FILE *f, char c);
/*Skip spaces in a stream.*/
char passSpaces(FILE *f, char c);
/*Find a string in a string table.*/
int find(char *src, char **dest, int size);
/*Normalize whitespace in a string.*/
void fixSpace(char *src);
/*Return a filename without its extension.*/
char *truncFileName(char *name);
/*Return the extension part of a filename.*/
char *getExtension(char *name);

/*Skip blank space and comments until the next line/item character.*/
char skipLineSpaceComment(FILE *f, char c);
/*Skip separators from a given current character.*/
char skipSep(FILE *f, char c);
/*Return whether a character is a line separator.*/
int isline(char c);
/*Return whether a character is an item separator.*/
int issep(char c);
/*Return whether a character is either an item or line separator.*/
int issepline(char c);

/*Compare two integers for qsort.*/
int compareInt(const void *a, const void *b);
/*Compare two doubles for qsort.*/
int compareDouble(const void *a, const void *b);
/*Compare two strings for qsort.*/
int compareString(const void *a, const void *b);

/*sort the table base and return the map from old index to new one (index[i] is the index of entry i in the sorted table*/
size_t *qsortindex(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *));
/*return the ordered table of index of base*/
size_t *qsortTable(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *));
/*Format a number into a compact printable representation.*/
void numprint(char *buffer, double val);
#ifdef __cplusplus
}
#endif

extern int DEBUGX;

#define SEP '|'
#define utils_MAX(x, y) ((x) > (y) ? (x) : (y))
#define utils_MIN(x, y) ((x) < (y) ? (x) : (y))
#define utils_ABS(x) ((x) < (0) ? (-x) : (x))
#define POS(x) ((x) < (0) ? (0) : (x))
// #define NEG_INFTY -DBL_MAX
// #define POS_INFTY DBL_MAX
// #define NEG_INFTY -1./0.
// #define POS_INFTY 1./0.
#define NEG_INFTY -INFINITY
#define POS_INFTY INFINITY
#define MY_NAN sqrt(-1.)
#define EPSILON 0.0000001
// #define DEBUGX 0
#define DEBUG(x)      \
	if(DEBUGX == 1) { \
		x             \
	}
/*return a random double in [0, 1]*/
#define UNIF_RAND unif_rand()
/*return a random int in [0, k-1]*/
#define RANGE_RAND(k) (int)floor((((double)k) * unif_rand()))
#endif
