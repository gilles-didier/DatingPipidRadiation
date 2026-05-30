#ifndef ModelF
#define ModelF

#include <stdlib.h>
#include <stdio.h>
#include <gsl/gsl_vector.h>
#include "Tree.h"
#include "Fossil.h"

#define RINFTY 1E99

typedef struct MODEL_PARAM {
	double birth, death, fossil, sampling;
} TypeModelParam;

typedef struct EXTENDED_MODEL_PARAM {
	double birth, death, fossil, sampling;
	double alpha, beta, omega, delta;
	double ab, bma, bmab, amab;
	double bs, as;
} TypeExtendedModelParam;

typedef struct PIECEWISE_MODEL_PARAM {
	int size;
	double *startTime;
	TypeModelParam *param;
} TypePiecewiseModelParam;

typedef struct EVENT {
	char type;
	int n;
	double time;
} TypeEvent;

typedef struct LISTEEVENT {
	TypeEvent *list;
	int size;
	double minTime, maxTime;
} TypeListEvent;

typedef double TypeLikelihoodTreeFosFunction(TypeTree *, TypeFossilFeature *, TypeModelParam *);
typedef double TypeLikelihoodEventListFunction(TypeListEvent *, TypeModelParam *);

#ifdef __cplusplus
extern "C" {
#endif

/*Return the log probability that all members of a clade go extinct before maxTime.*/
double getLogProbExtinctClade(int *clade, double *time, double maxTime, TypeExtendedModelParam *pext);
/*Return the log density of a clade divergence/extinction event at val.*/
double getLogDensClade(double val, int *clade, double *time, double maxTime, TypeExtendedModelParam *pext);
/*Return the log probability that a clade event occurs before val.*/
double getLogProbClade(double val, int *clade, double *time, double maxTime, TypeExtendedModelParam *pext);
/*Return the time quantile for a clade event probability.*/
double getQuantileClade(double q, double tol, int *clade, double *time, double maxTime, TypeExtendedModelParam *pext);
/*Return the time quantile for extinction conditioned on an interval.*/
double getQuantile(double q, double tol, double startTime, double maxTime, TypeExtendedModelParam *param);
/*Derive cached algebraic coefficients from basic model parameters.*/
TypeExtendedModelParam getExtendedModelParam(TypeModelParam *param);
/*Return the log probability that a lineage is not observable at time t.*/
double getLogProbNotObservable(double t, double maxTime, TypeExtendedModelParam *param);
/*return the probability that a lineage alive at last startTime (e.g. last fossil age) goes extinct a time t without  leaving any fossil between startTime and  t*/
double getLogProbExtinct(double t, double startTime, TypeExtendedModelParam *param);
/*return the probability that a lineage alive at last startTime (e.g. last fossil age) goes extinct a time t without  leaving any fossil between startTime and  t, conditionned on the that lineage goes extinct before maxTime*/
double getLogProbExtinctCond(double t, double startTime, double maxTime, TypeExtendedModelParam *param);
/*Return the conditioned extinction log density at time t.*/
double getLogDensExtinctCond(double t, double startTime, double maxTime, TypeExtendedModelParam *param);
/*Wrap a constant model parameter set as a single-piece model.*/
TypePiecewiseModelParam simple2piecewise(TypeModelParam *param, double startTime, double endTime);
/*Return the piecewise interval containing value v.*/
int getPieceIndex(double v, TypePiecewiseModelParam *param);
/*Print a piecewise model parameterization.*/
void printPiecewiseModel(FILE *f, TypePiecewiseModelParam *param);
/*Count birth, death, and fossil events in an event list.*/
void getStatEvent(TypeListEvent *event, int *b, int *d, int *f);
/*Free an event list.*/
void freeListEvent(TypeListEvent *event);
/*Print one event.*/
void fprintEvent(FILE *f, TypeEvent *event);
/*Print all events in an event list.*/
void fprintListEvent(FILE *f, TypeListEvent *event);
/*get the total time*/
double getTotalTimeEvent(TypeListEvent *event);
/*Build the fossilized birth-death event sequence for a tree and fossils.*/
TypeListEvent *getEventSequenceFBD(TypeTree *tree, TypeFossilFeature *fos);
/*Build the birth-death event sequence for a tree.*/
TypeListEvent *getEventSequenceBD(TypeTree *tree);

/*Return the log probability of a birth-death event sequence.*/
double logProbEventBD(TypeListEvent *event, TypeModelParam *param);
/*Return the log probability of a fossilized birth-death event sequence.*/
double logProbEventFBD(TypeListEvent *event, TypeModelParam *param);

/*Return the Stadler likelihood for a tree with fossils.*/
double getLogLikelihoodStadler(TypeTree *tree, TypeFossilFeature *fos, TypeModelParam *param);
/*Return the Didier likelihood for a tree with fossils.*/
double getLogLikelihoodDidier(TypeTree *tree, TypeFossilFeature *fos, TypeModelParam *param);

#ifdef __cplusplus
}
#endif

#endif
