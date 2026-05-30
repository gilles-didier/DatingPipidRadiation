#ifndef UncertaintyF
#define UncertaintyF

#include <stdlib.h>
#include <stdio.h>
#include "Utils.h"
#include "Tree.h"
#include "Fossil.h"
#include "Model.h"
#include "Distribution.h"

typedef struct PARAM_UNCERTAINTY {
	TypeTree *tree;
	TypeFossilFeature *fos;
	double fossil;
} TypeParamUncertainty;

#ifdef __cplusplus
extern "C" {
#endif
/*Run a diagnostic computation for one uncertainty configuration.*/
void testUncertainty(int k, int l, double tstartA, double tstartB, double tend, TypeModelParam *model);

/*Return the special log density for a node time and update total density.*/
double getLogDensitySpecialX(double *tot, double time, int n, TypeTree *tree, TypeFossilFeature *fos, TypeModelParam *param);
/*Return the special log density for a node time.*/
double getLogDensitySpecial(double time, int n, TypeTree *tree, TypeFossilFeature *fos, TypeModelParam *param);
/*Fill a log-density distribution for one node.*/
void fillLogDistributionSpecial(TypeDistribution *logD, int n, TypeTree *tree, TypeFossilFeature *fos, TypeModelParam *param);
/*Return and print diagnostic likelihood details for a tree with fossils.*/
double getLogLikelihoodTreeFossilDebug(TypeTree *tree, TypeFossilFeature *fos, TypeModelParam *param);
/*Split a fossil-bearing tree into uncertainty subtrees.*/
void splitTreeFossil(TypeTree *tree, TypeFossilFeature *fos, TypeTree ***treeList, int *size);
/*Return the likelihood contribution for a lineage interval.*/
double likelihood(double timeStart, double timeEnd, int nLeaves);
/*Return the event-based log likelihood for a tree with fossils.*/
double getLogLikelihoodEvent(TypeTree *tree, TypeFossilFeature *fos, TypeModelParam *param);
/*Return the log likelihood of a tree with fossil uncertainty.*/
double getLogLikelihoodTreeFossil(TypeTree *tree, TypeFossilFeature *fos, TypeModelParam *param);
/*Return the number of possible fossil/tree uncertainty items.*/
double getItemNumber(TypeTree *tree, TypeFossilFeature *fos);
/*Return the number of uncertainty items after splitting the tree.*/
double getItemNumberSplitted(TypeTree *tree);
/*Build a density distribution for one node.*/
TypeDistribution getDistribution(int n, double step, TypeTree *tree, TypeFossilFeature *fos, TypeModelParam *param);
/*Build a one-point density distribution for one node value.*/
TypeDistribution getDistributionUn(int n, double val, TypeTree *tree, TypeFossilFeature *fos, TypeModelParam *param);
/*Fill a density distribution for one node.*/
void fillDistribution(TypeDistribution *d, int n, TypeTree *tree, TypeFossilFeature *fos, TypeModelParam *param);
/*Fill a log-density distribution and its conditioning value for one node.*/
void fillLogDistribution(TypeDistribution *logD, double *logCond, int n, TypeTree *tree, TypeFossilFeature *fos, TypeModelParam *param);

#ifdef __cplusplus
}
#endif

#endif
