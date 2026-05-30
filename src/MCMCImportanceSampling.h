#ifndef MCMCImportanceSamplingF
#define MCMCImportanceSamplingF

#include <stdlib.h>
#include <stdio.h>

#include "Tree.h"
#include "Fossil.h"
#include "FossilInt.h"
#include "Model.h"

#ifdef __cplusplus
extern "C" {
#endif

/*Sample model parameters and return the speciation-time distribution for one node.*/
TypeDistribution MCMCSamplingSpeciationDist(FILE *fout, FILE *find, int *node, TypeTree **tree, TypeFossilIntFeature *fi, double step, double al, int burn, int gap, int iter, double prop, TypeModelParam *windSize, TypeModelParam *init, double probSpe, double probExt);
/*Sample model parameters and return extinction-time distributions for clades/taxa.*/
TypeDistribution *MCMCSamplingExtinctionDist(FILE *fout, FILE *find, int **taxa, TypeTree **tree, TypeFossilIntFeature *fi, double maxDisplayTime, double step, double al, int burn, int gap, int iter, double prop, TypeModelParam *windSize, TypeModelParam *init, double probSpe, double probExt);
#ifdef __cplusplus
}
#endif

#endif
