#ifndef DistributionF
#define DistributionF

#include <stdlib.h>
#include <stdio.h>

typedef struct DENSITY_ITEM {
	double val, dens;
} TypeDistributionItem;

typedef struct DENSITY {
	int size;
	TypeDistributionItem *item;
} TypeDistribution;

#ifdef __cplusplus
extern "C" {
#endif

/*Return the index of the distribution item whose value brackets v.*/
int binarySearchValDistribution(double v, TypeDistribution d);
/*Read a value/density table from a stream.*/
TypeDistribution readDistribution(FILE *f);
/*Compare distribution items by their value for sorting.*/
int compareDistributionItem(const void *a, const void *b);
// TypeDistribution meanDistribution(TypeDistribution d1, double w1, TypeDistribution d2, double w2);
/*Write a distribution as value/density rows.*/
void fprintDistribution(FILE *f, TypeDistribution d);
/*Integrate densities by direct summation.*/
double sumDistribution(TypeDistribution d);
/*Integrate densities with the trapezoidal rule.*/
double sumTrapezeDistribution(TypeDistribution d);
/*Integrate log-densities with the trapezoidal rule.*/
double sumExpTrapezeDistribution(TypeDistribution d);
/*Integrate densities with Simpson's rule.*/
double sumSimpsonDistribution(TypeDistribution d);
/*Integrate log-densities with Simpson's rule.*/
double sumExpSimpsonDistribution(TypeDistribution d);
/*Write the numerical derivative of a distribution.*/
void fprintDerive(FILE *f, TypeDistribution d);
/*Return the mean value using densities as weights.*/
double getMean(TypeDistribution d);
/*Return the value with the largest density.*/
double getMode(TypeDistribution d);
/*Return the median value from cumulative densities.*/
double getMedian(TypeDistribution d);
/*Return the mean of density values.*/
double getMeanDens(TypeDistribution d);
/*Return the median of density values.*/
double getMedianDens(TypeDistribution d);
/*Return the lower value at cumulative probability q.*/
double getQuantileInf(TypeDistribution d, double q);
/*Return the upper value at cumulative probability q.*/
double getQuantileSup(TypeDistribution d, double q);
/*Replace densities by finite differences between adjacent items.*/
void deriveDistribution(TypeDistribution *d);
/*Replace densities by cumulative integrated values.*/
void integrateDistribution(TypeDistribution *d);
/*Aggregate several distributions on a common grid.*/
TypeDistribution agregDistribution(TypeDistribution *d, int size, int def);
/*Resample a distribution on a regular grid.*/
TypeDistribution resampleDistribution(TypeDistribution d, double min, double max, int def);
/*Return an empirical quantile from weighted items.*/
double getEmpiricalQuantile(TypeDistribution d, double q);
/*Return the density threshold corresponding to quantile q.*/
double getQuantileDensity(TypeDistribution d, double q);
/*Return the modal density value.*/
double getModeDensity(TypeDistribution d);

#ifdef __cplusplus
}
#endif

#endif
