#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <pthread.h>
#include <signal.h>
#include <gsl/gsl_integration.h>
#include <gsl/gsl_sf_gamma.h>

#include "Utils.h"
#include "Uncertainty.h"
#include "MCMCImportanceSampling.h"

typedef struct MINIMIZATION_PARAM_DATA {
	TypeTree **tree;
	TypeFossilFeature **fos;
	int nTree;
} TypeMinimizationParamData;

typedef struct INTEGRATION_PARAM {
	int *cladeA, *cladeB;
	double *time, maxTime, a, b;
	TypeExtendedModelParam *param;
} TypeIntegrationParameter;

typedef struct THREAD_PARAMETER_DENS {
	int *number;
	pthread_mutex_t *mutex_number, *mutex_sum;
	pthread_cond_t *cond_number;
	TypeTree *tree;
	TypeFossilFeature *ffe;
	int node;
	double *sum;
	TypeModelParam *param;
} TypeThreadParameterDens;

typedef struct THREAD_PARAMETER_DIST {
	int *number;
	pthread_mutex_t *mutex_number;
	pthread_cond_t *cond_number;
	TypeTree *tree;
	TypeFossilFeature *ffe;
	int node;
	TypeDistribution *logD;
	double *logCond;
	TypeModelParam *param;
} TypeThreadParameterDist;

typedef struct THREAD_PARAMETER_SINGLE {
	int *number;
	pthread_mutex_t *mutex_number;
	pthread_cond_t *cond_number;
	TypeTree *tree;
	TypeFossilFeature *ffe;
	int taxa;
	TypeDistribution *logD;
	TypeExtendedModelParam *pext;
} TypeThreadParameterExtSingleTree;

typedef struct THREAD_PARAMETER_EXT_MULTIPLE {
	int *number;
	pthread_mutex_t *mutex_number;
	pthread_cond_t *cond_number;
	int *clade;
	TypeTree *tree;
	TypeFossilFeature *ffe;
	TypeDistribution *logD;
	TypeModelParam *param;
	TypeExtendedModelParam *pext;
} TypeThreadParameterExtMultipleTree;

typedef struct THREAD_PARAMETER_SINGLE_QUANT {
	int *number;
	pthread_mutex_t *mutex_number;
	pthread_cond_t *cond_number;
	TypeTree *tree;
	TypeFossilFeature *ffe;
	int taxa;
	double order, *quant;
	TypeExtendedModelParam *pext;
} TypeThreadParameterExtQuantSingleTree;

static pthread_mutex_t mutexN = PTHREAD_MUTEX_INITIALIZER, mutexS = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t condN = PTHREAD_COND_INITIALIZER;
static int maxT = 40;
// static int maxT = 1;

static void *threadComputeDens(void *data);
static void *threadComputeDistribution(void *data);
static void *threadComputeExtMultipleTree(void *data);

static void fillFolNode(TypeFossilFeature *f, int size, int *fol);
static void fillBranchNode(TypeFossilFeature *f, int size, int *branch);
static void getProposalFossil(TypeFossilFeature *fp, TypeFossilIntFeature *fi, int *fol, double al, int *move, double *newTime);
static void changeFossil(TypeTree **tree, int nTree, TypeFossilFeature *fp, int *fol, int *branch, int move, double newTime);
static double update(TypeTree **tree, int nTree, TypeFossilFeature *fp, TypeFossilIntFeature *fi, int *fol, int *branch, double prob, double al, double propParam, TypeModelParam *param, TypeModelParam *windSize, double probSpe, double probExt);
static TypeFossilFeature *sampleFossil(TypeFossilIntFeature *feat, int size);
static int compareLocal(const void *a, const void *b);
static double getLogDensitySum(TypeTree **tree, int nTree, TypeFossilFeature *fp, TypeModelParam *param);
static double getLogDensitySumNoThread(TypeTree **tree, int nTree, TypeFossilFeature *fp, TypeModelParam *param);
static TypeFossilList *fossilList;

/*return log(a+b) in an accurate way*/
double logSum(double a, double b) {
	double max, min;
	if(a > b) {
		max = a;
		min = b;
	} else {
		min = a;
		max = b;
	}
	return log(max) + log1p(min / max);
}

/*return log(exp(a)+exp(b)) in an accurate way*/
double logSumLog(double a, double b) {
	double max, min;
	if(a == NEG_INFTY)
		return b;
	if(b == NEG_INFTY)
		return a;
	if(a > b) {
		max = a;
		min = b;
	} else {
		min = a;
		max = b;
	}
	return max + log1p(exp(min - max));
}

int compareLocal(const void *a, const void *b) {
	if(fossilList[*((int *)a)].time > fossilList[*((int *)b)].time)
		return 1;
	if(fossilList[*((int *)a)].time < fossilList[*((int *)b)].time)
		return -1;
	return 0;
}

TypeFossilFeature *sampleFossil(TypeFossilIntFeature *feat, int size) {
	TypeFossilFeature *sample;
	int i, n, f, *tmp;

	if(feat == NULL)
		return NULL;
	sample = (TypeFossilFeature *)malloc(sizeof(TypeFossilFeature));
	sample->size = feat->sizeFossil;
	sample->sizeBuf = feat->sizeFossil;
	sample->fossilList = (TypeFossilList *)malloc(sample->size * sizeof(TypeFossilList));
	sample->fossil = (int *)malloc(size * sizeof(int));
	sample->status = (TypeNodeStatus *)malloc(size * sizeof(int));
	for(i = 0; i < size; i++)
		sample->fossil[i] = feat->fossilInt[i];
	for(i = 0; i < sample->size; i++) {
		sample->fossilList[i].prec = feat->fossilIntList[i].prec;
		sample->fossilList[i].time = feat->fossilIntList[i].fossilInt.inf + UNIF_RAND * (feat->fossilIntList[i].fossilInt.sup - feat->fossilIntList[i].fossilInt.inf);
	}
	fossilList = sample->fossilList;
	tmp = (int *)malloc((sample->size + 1) * sizeof(int));
	for(n = 0; n < size; n++) {
		int ind = 0;
		for(f = sample->fossil[n]; f != NOSUCH; f = sample->fossilList[f].prec)
			tmp[ind++] = f;
		if(ind > 0) {
			qsort(tmp, ind, sizeof(int), compareLocal);
			sample->fossilList[tmp[0]].prec = NOSUCH;
			for(f = 1; f < ind; f++)
				sample->fossilList[tmp[f]].prec = tmp[f - 1];
			sample->fossil[n] = tmp[ind - 1];
		}
	}
	free((void *)tmp);
	return sample;
}

void fillFolNode(TypeFossilFeature *f, int size, int *fol) {
	int n;
	for(n = 0; n < size; n++) {
		int k, tmp;
		tmp = NOSUCH;
		for(k = f->fossil[n]; k != NOSUCH; k = f->fossilList[k].prec) {
			fol[k] = tmp;
			tmp = k;
		}
	}
}

void fillBranchNode(TypeFossilFeature *f, int size, int *branch) {
	int n;
	for(n = 0; n < size; n++) {
		int k;
		for(k = f->fossil[n]; k != NOSUCH; k = f->fossilList[k].prec)
			branch[k] = n;
	}
}

TypeModelParam getProposalParam(TypeModelParam *param, TypeModelParam *windSize, double probSpe, double probExt) {
	TypeModelParam res;
	double p = UNIF_RAND;
	res = *param;
	if(p < probSpe) {
		res.birth = UNIF_RAND * windSize->birth + param->birth - 0.5 * windSize->birth;
		if(res.birth < 0.)
			res.birth = -res.birth;
	} else {
		if(p < probSpe + probExt) {
			res.death = UNIF_RAND * windSize->death + param->death - 0.5 * windSize->death;
			if(res.death < 0.)
				res.death = -res.death;
		} else {
			res.fossil = UNIF_RAND * windSize->fossil + param->fossil - 0.5 * windSize->fossil;
			if(res.fossil < 0.)
				res.fossil = -res.fossil;
		}
	}
	return res;
}

void getProposalFossil(TypeFossilFeature *fp, TypeFossilIntFeature *fi, int *fol, double al, int *move, double *newTime) {
	double length;
	*move = RANGE_RAND(fp->size);
	length = (fi->fossilIntList[*move].fossilInt.sup - fi->fossilIntList[*move].fossilInt.inf) * al / 2.;
	*newTime = UNIF_RAND * (2. * length) + fp->fossilList[*move].time - length;
	if(*newTime < fi->fossilIntList[*move].fossilInt.inf)
		*newTime = 2. * fi->fossilIntList[*move].fossilInt.inf - *newTime;
	if(*newTime > fi->fossilIntList[*move].fossilInt.sup)
		*newTime = 2. * fi->fossilIntList[*move].fossilInt.sup - *newTime;
}

void changeFossil(TypeTree **tree, int nTree, TypeFossilFeature *fp, int *fol, int *branch, int move, double newTime) {
	int xA, xB, change, i;
	change = (tree[0]->time[branch[move]] == fp->fossilList[fp->fossil[branch[move]]].time);
	fp->fossilList[move].time = newTime;
	xA = NOSUCH;
	for(xB = fol[move]; xB != NOSUCH && fp->fossilList[move].time > fp->fossilList[xB].time; xB = fol[xB])
		xA = xB;
	if(xB != fol[move]) {
		;
		if(fol[move] != NOSUCH)
			fp->fossilList[fol[move]].prec = fp->fossilList[move].prec;
		else
			fp->fossil[branch[move]] = fp->fossilList[move].prec;
		if(fp->fossilList[move].prec != NOSUCH)
			fol[fp->fossilList[move].prec] = fol[move];
		if(xB != NOSUCH)
			fp->fossilList[xB].prec = move;
		else
			fp->fossil[branch[move]] = move;
		if(xA != NOSUCH)
			fol[xA] = move;
		fol[move] = xB;
		fp->fossilList[move].prec = xA;
	}
	xA = NOSUCH;
	for(xB = fp->fossilList[move].prec; xB != NOSUCH && fp->fossilList[move].time < fp->fossilList[xB].time; xB = fp->fossilList[xB].prec)
		xA = xB;
	if(xB != fp->fossilList[move].prec) {
		if(fol[move] != NOSUCH)
			fp->fossilList[fol[move]].prec = fp->fossilList[move].prec;
		else
			fp->fossil[branch[move]] = fp->fossilList[move].prec;
		if(fp->fossilList[move].prec != NOSUCH)
			fol[fp->fossilList[move].prec] = fol[move];
		if(xB != NOSUCH)
			fol[xB] = move;
		if(xA != NOSUCH)
			fp->fossilList[xA].prec = move;
		fol[move] = xA;
		fp->fossilList[move].prec = xB;
	}
	double min = getMinFossilTime(fp);
	if(tree[0]->minTimeInt.sup > min)
		for(i = 0; i < nTree; i++)
			tree[i]->minTimeInt.sup = min;
	if(change)
		for(i = 0; i < nTree; i++)
			tree[i]->time[branch[move]] = fp->fossilList[fp->fossil[branch[move]]].time;
}

double update(TypeTree **tree, int nTree, TypeFossilFeature *fp, TypeFossilIntFeature *fi, int *fol, int *branch, double prob, double al, double propParam, TypeModelParam *param, TypeModelParam *windSize, double probSpe, double probExt) {
	int move;
	double newTime, oldTime, newProb;
	if(UNIF_RAND < propParam) {
		TypeModelParam newParam = getProposalParam(param, windSize, probSpe, probExt);
		//		newProb = getLogDensitySum(tree, nTree, fp, &newParam);
		newProb = getLogDensitySumNoThread(tree, nTree, fp, &newParam);
		if(isnan(newProb))
			error("Param %.2le %.2le %.2le\n", newParam.birth, newParam.death, newParam.fossil);
		if(UNIF_RAND < exp(newProb - prob)) {
			*param = newParam;
			return newProb;
		} else {
			return prob;
		}
	} else {
		getProposalFossil(fp, fi, fol, al, &move, &newTime);
		oldTime = fp->fossilList[move].time;
		changeFossil(tree, nTree, fp, fol, branch, move, newTime);
		//		newProb = getLogDensitySum(tree, nTree, fp, param);
		newProb = getLogDensitySumNoThread(tree, nTree, fp, param);
		if(isnan(newProb))
			error("fossil %d %.5lf -> %.5lf (%d %s) time %.5lf\n", move, oldTime, newTime, branch[move], tree[0]->name[branch[move]], tree[0]->time[branch[move]]);
		if(UNIF_RAND < exp(newProb - prob)) {
			return newProb;
		} else {
			changeFossil(tree, nTree, fp, fol, branch, move, oldTime);
			return prob;
		}
	}
	return prob;
}

double getLogDensitySumNoThread(TypeTree **tree, int nTree, TypeFossilFeature *fp, TypeModelParam *param) {
	double sum;
	int i;
	sum = NEG_INFTY;
	for(i = 0; i < nTree; i++) {
		//		printf("tree %d\n", i);
		sum = logSumLog(sum, getLogLikelihoodTreeFossil(tree[i], fp, param));
	}
	return sum;
}

double getLogDensitySum(TypeTree **tree, int nTree, TypeFossilFeature *fp, TypeModelParam *param) {
	double sum;
	int cont = 1, nT = 0, i = 0;
	cont = 1;
	sum = NEG_INFTY;
	i = 0;
	while(cont) {
		pthread_mutex_lock(&mutexN);
		while(i < nTree && nT < maxT) {
			pthread_t thread;
			int ret = 0;
			TypeThreadParameterDens *tp;
			tp = (TypeThreadParameterDens *)malloc(sizeof(TypeThreadParameterDens));
			tp->tree = tree[i];
			tp->ffe = fp;
			tp->param = param;
			tp->sum = &sum;
			tp->mutex_sum = &mutexS;
			tp->mutex_number = &mutexN;
			tp->cond_number = &condN;
			tp->number = &nT;
			if((ret = pthread_create(&thread, NULL, threadComputeDens, (void *)tp)) == 0) {
				int err;
				if((err = pthread_detach(thread)) == 0) {
					nT++;
					i++;
				} else {
					warning("Error %d while detaching thread: %s\n", err, (char *)strerror(err));
				}
			} else
				warning("Error %d while creating thread: %s\n", ret, (char *)strerror(ret));
		}
		cont = (nT > 0);
		if(cont)
			pthread_cond_wait(&condN, &mutexN);
		pthread_mutex_unlock(&mutexN);
	}
	return sum;
}

void *threadComputeDens(void *data) {
	double tmp;
	tmp = getLogLikelihoodTreeFossil(((TypeThreadParameterDens *)data)->tree, ((TypeThreadParameterDens *)data)->ffe, ((TypeThreadParameterDens *)data)->param);
	pthread_mutex_lock(((TypeThreadParameterDens *)data)->mutex_sum);
	*(((TypeThreadParameterDens *)data)->sum) = logSumLog(*(((TypeThreadParameterDens *)data)->sum), tmp);
	pthread_mutex_unlock(((TypeThreadParameterDens *)data)->mutex_sum);
	pthread_mutex_lock(((TypeThreadParameterDens *)data)->mutex_number);
	(*((TypeThreadParameterDens *)data)->number)--;
	pthread_cond_signal(((TypeThreadParameterDens *)data)->cond_number);
	pthread_mutex_unlock(((TypeThreadParameterDens *)data)->mutex_number);
	free(data);
	return NULL;
}

TypeDistribution MCMCSamplingSpeciationDist(FILE *fout, FILE *find, int *node, TypeTree **tree, TypeFossilIntFeature *fi, double step, double al, int burn, int gap, int iter, double prop, TypeModelParam *windSize, TypeModelParam *init, double probSpe, double probExt) {
	int *fol, *branch, i, j, s, n, nTree;
	double prob, min, max, *logCond, logSumCond;
	TypeFossilFeature *fp;
	TypeDistribution *logDTmp, logSTmp, dist;
	TypeModelParam param, *saveParam;
	param.birth = UNIF_RAND * init->birth;
	param.death = UNIF_RAND * init->death;
	param.fossil = UNIF_RAND * init->fossil;
	param.sampling = 1.;

	fp = sampleFossil(fi, tree[0]->size);
	for(nTree = 0; tree[nTree] != NULL; nTree++) {
		for(n = 0; n < tree[nTree]->size; n++) {
			if(tree[nTree]->node[n].child == NOSUCH) {
				switch(fi->status[n]) {
					case contempNodeStatus:
						tree[nTree]->time[n] = tree[nTree]->maxTime;
						break;
					case unknownNodeStatus:

						break;
					case extinctNodeStatus:
						tree[nTree]->time[n] = fp->fossilList[fp->fossil[n]].time;
						break;
					default:;
				}
			} else
				tree[nTree]->time[n] = NO_TIME;
		}
	}
	fol = (int *)malloc(fp->size * sizeof(int));
	fillFolNode(fp, tree[0]->size, fol);
	branch = (int *)malloc(fp->size * sizeof(int));
	fillBranchNode(fp, tree[0]->size, branch);
	min = getMaxFossilIntTimeToNode(node[0], tree[0], fi);
	max = getMinFossilIntTimeFromNode(node[0], tree[0], fi);
	min = floor(min / step) * step;
	max = (ceil(max / step)) * step;
	double **save;
	int f;
	saveParam = (TypeModelParam *)malloc(iter * sizeof(TypeModelParam));
	save = (double **)malloc(fp->size * sizeof(double *));
	for(f = 0; f < fp->size; f++)
		save[f] = (double *)malloc(iter * sizeof(double));
	prob = getLogDensitySum(tree, nTree, fp, &param);
	for(i = 0; i < burn; i++) {
		prob = update(tree, nTree, fp, fi, fol, branch, prob, al, prop, &param, windSize, probSpe, probExt);
		if(i % 10 == 0) {
			fprintf(stderr, "it %-7d\r", i);
			fflush(stderr);
		}
	}
	logSumCond = NEG_INFTY;
	logCond = (double *)malloc(nTree * sizeof(double));
	logSTmp.size = (int)ceil((max - min) / step) + 1;
	logSTmp.item = (TypeDistributionItem *)malloc(logSTmp.size * sizeof(TypeDistributionItem));
	logDTmp = (TypeDistribution *)malloc(nTree * sizeof(TypeDistribution));
	for(i = 0; i < nTree; i++) {
		logDTmp[i].size = logSTmp.size;
		logDTmp[i].item = (TypeDistributionItem *)malloc(logSTmp.size * sizeof(TypeDistributionItem));
	}
	dist.size = logSTmp.size;
	dist.item = (TypeDistributionItem *)malloc(dist.size * sizeof(TypeDistributionItem));
	for(j = 0; j < logSTmp.size; j++) {
		for(i = 0; i < nTree; i++)
			logDTmp[i].item[j].val = min + ((double)j) * step;
		logSTmp.item[j].val = min + ((double)j) * step;
		dist.item[j].val = min + ((double)j) * step;
		dist.item[j].dens = NEG_INFTY;
	}
	printf("end burning\n");
	for(s = 0; s < iter; s++) {
		int j;
		int cont = 1, nT = 0, i = 0;
		while(cont) {
			pthread_mutex_lock(&mutexN);
			while(i < nTree && nT < maxT) {
				pthread_t thread;
				int ret = 0;
				TypeThreadParameterDist *tp;
				tp = (TypeThreadParameterDist *)malloc(sizeof(TypeThreadParameterDist));
				tp->tree = tree[i];
				tp->ffe = fp;
				tp->param = &param;
				tp->node = node[i];
				tp->logD = &(logDTmp[i]);
				tp->logCond = &(logCond[i]);
				tp->mutex_number = &mutexN;
				tp->cond_number = &condN;
				tp->number = &nT;
				if((ret = pthread_create(&thread, NULL, threadComputeDistribution, (void *)tp)) == 0) {
					int err;
					if((err = pthread_detach(thread)) == 0) {
						nT++;
						i++;
					} else {
						warning("Error %d while detaching thread: %s\n", err, (char *)strerror(err));
					}
				} else
					warning("Error %d while creating thread: %s\n", ret, (char *)strerror(ret));
			}
			cont = (nT > 0);
			if(cont)
				pthread_cond_wait(&condN, &mutexN);
			pthread_mutex_unlock(&mutexN);
		}
		logSumCond = NEG_INFTY;
		for(j = 0; j < logSTmp.size; j++)
			logSTmp.item[j].dens = NEG_INFTY;
		for(i = 0; i < nTree; i++) {
			logSumCond = logSumLog(logSumCond, logCond[i]);
			for(j = 0; j < dist.size; j++)
				logSTmp.item[j].dens = logSumLog(logSTmp.item[j].dens, logDTmp[i].item[j].dens);
		}
		for(j = 0; j < dist.size; j++)
			dist.item[j].dens = logSumLog(dist.item[j].dens, logSTmp.item[j].dens - logSumCond);
		saveParam[s] = param;
		for(f = 0; f < fp->size; f++)
			save[f][s] = fp->fossilList[f].time;
		for(j = 0; j < gap; j++) {
			prob = update(tree, nTree, fp, fi, fol, branch, prob, al, prop, &param, windSize, probSpe, probExt);
		}
		if(s % 10 == 0) {
			fprintf(stderr, "it %-7d\r", s);
			fflush(stderr);
		}
	}
	for(j = 0; j < dist.size; j++)
		dist.item[j].dens = exp(dist.item[j].dens - log((double)iter));
	for(s = 0; s < iter; s++)
		fprintf(fout, "%d\t%lf\n", s + burn + 1, saveParam[s].birth);
	for(s = 0; s < iter; s++)
		fprintf(fout, "%d\t%lf\n", s + burn + 1, saveParam[s].death);
	for(s = 0; s < iter; s++)
		fprintf(fout, "%d\t%lf\n", s + burn + 1, saveParam[s].fossil);
	free((void *)saveParam);
	for(f = 0; f < fp->size; f++)
		for(s = 0; s < iter; s++)
			fprintf(fout, "%d\t%lf\n", s + burn + 1, save[f][s]);
	for(f = 0; f < fp->size; f++)
		free((void *)save[f]);
	free((void *)save);
	int off = 0;
	fprintf(find, "birth\t%d\t%d\n", off * iter + 1, (off + 1) * iter);
	off++;
	fprintf(find, "death\t%d\t%d\n", off * iter + 1, (off + 1) * iter);
	off++;
	fprintf(find, "fossil\t%d\t%d\n", off * iter + 1, (off + 1) * iter);
	off++;
	for(f = 0; f < fp->size; f++) {
		fprintf(find, "%d", f + 1);
		if(branch[f] != NOSUCH && tree[0]->name[branch[f]] != NULL)
			fprintf(find, "_%s_%d_%d", tree[0]->name[branch[f]], (int)round(fi->fossilIntList[f].fossilInt.inf), (int)round(fi->fossilIntList[f].fossilInt.sup));
		fprintf(find, "\t%d\t%d\n", off * iter + 1, (off + 1) * iter);
		off++;
	}
	freeFossilFeature(fp);
	free((void *)branch);
	free((void *)fol);
	free((void *)logSTmp.item);
	for(i = 0; i < nTree; i++)
		free((void *)logDTmp[i].item);
	free((void *)logDTmp);
	free((void *)logCond);
	return dist;
}

void *threadComputeDistribution(void *data) {
	fillLogDistribution(((TypeThreadParameterDist *)data)->logD, ((TypeThreadParameterDist *)data)->logCond, ((TypeThreadParameterDist *)data)->node, ((TypeThreadParameterDist *)data)->tree, ((TypeThreadParameterDist *)data)->ffe, ((TypeThreadParameterDist *)data)->param);
	pthread_mutex_lock(((TypeThreadParameterDist *)data)->mutex_number);
	(*((TypeThreadParameterDist *)data)->number)--;
	pthread_cond_signal(((TypeThreadParameterDist *)data)->cond_number);
	pthread_mutex_unlock(((TypeThreadParameterDist *)data)->mutex_number);
	free(data);
	return NULL;
}

TypeDistribution *MCMCSamplingExtinctionDist(FILE *fout, FILE *find, int **clade, TypeTree **tree, TypeFossilIntFeature *fi, double maxDisplayTime, double step, double al, int burn, int gap, int iter, double prop, TypeModelParam *windSize, TypeModelParam *init, double probSpe, double probExt) {
	int *fol, *branch, i, j, f, s, n, nTree = 0, nClade = 0, nExt = 0, *ext;
	double prob, **save, **saveText, min;
	TypeFossilFeature *fp;
	TypeDistribution *d, *logSTmp;
	TypeModelParam param, *saveParam;
	TypeExtendedModelParam pext;

	param.birth = UNIF_RAND * init->birth;
	param.death = UNIF_RAND * init->death;
	param.fossil = UNIF_RAND * init->fossil;
	param.sampling = 1.;
	fp = sampleFossil(fi, tree[0]->size);
	for(nTree = 0; tree[nTree] != NULL; nTree++) {
		for(n = 0; n < tree[nTree]->size; n++) {
			if(tree[nTree]->node[n].child == NOSUCH) {
				switch(fi->status[n]) {
					case contempNodeStatus:
						tree[nTree]->time[n] = tree[nTree]->maxTime;
						break;
					case unknownNodeStatus:

						break;
					case extinctNodeStatus:
						tree[nTree]->time[n] = fp->fossilList[fp->fossil[n]].time;
						break;
					default:;
				}
			} else
				tree[nTree]->time[n] = NO_TIME;
		}
	}
	ext = (int *)malloc(tree[0]->size * sizeof(int));
	for(n = 0; n < tree[0]->size; n++)
		if(tree[0]->node[n].child == NOSUCH && fi->status[n] == extinctNodeStatus)
			ext[nExt++] = n;
	fol = (int *)malloc(fp->size * sizeof(int));
	fillFolNode(fp, tree[0]->size, fol);
	branch = (int *)malloc(fp->size * sizeof(int));
	fillBranchNode(fp, tree[0]->size, branch);
	saveParam = (TypeModelParam *)malloc(iter * sizeof(TypeModelParam));
	save = (double **)malloc(fp->size * sizeof(double *));
	for(f = 0; f < fp->size; f++)
		save[f] = (double *)malloc(iter * sizeof(double));
	saveText = (double **)malloc(nExt * sizeof(double *));
	for(n = 0; n < nExt; n++)
		saveText[n] = (double *)malloc(iter * sizeof(double));
	prob = getLogDensitySum(tree, nTree, fp, &param);
	for(i = 0; i < burn; i++) {
		prob = update(tree, nTree, fp, fi, fol, branch, prob, al, prop, &param, windSize, probSpe, probExt);
		if(i % 10 == 0) {
			fprintf(stderr, "it %-7d\r", i);
			fflush(stderr);
		}
	}
	for(nClade = 0; clade[nClade] != NULL; nClade++)
		;
	min = getMaxFossilIntTimeToNode(ext[0], tree[0], fi);
	for(n = 1; n < nExt; n++) {
		if(getMaxFossilIntTimeToNode(ext[n], tree[0], fi) < min)
			min = getMaxFossilIntTimeToNode(ext[n], tree[0], fi);
	}
	min = floor(min / step) * step;
	logSTmp = (TypeDistribution *)malloc(nClade * sizeof(TypeDistribution));
	logSTmp[0].size = (int)ceil((ceil(maxDisplayTime / step) * step - min) / step) + 1;
	// printf("size %d (%lf %lf %lf)\n", logSTmp[0].size, maxDisplayTime, step, min);
	for(n = 0; n < nClade; n++) {
		logSTmp[n].size = logSTmp[0].size;
		logSTmp[n].item = (TypeDistributionItem *)malloc(logSTmp[n].size * sizeof(TypeDistributionItem));
		for(j = 0; j < logSTmp[n].size; j++) {
			logSTmp[n].item[j].val = min + ((double)j) * step;
			logSTmp[n].item[j].dens = NEG_INFTY;
		}
	}
	for(s = 0; s < iter; s++) {
		int j;
		pext = getExtendedModelParam(&param);
		int cont = 1, nT = 0, i = 0;
		while(cont) {
			pthread_mutex_lock(&mutexN);
			while(i < nClade && nT < maxT) {
				pthread_t thread;
				int ret = 0;
				TypeThreadParameterExtMultipleTree *tp;
				tp = (TypeThreadParameterExtMultipleTree *)malloc(sizeof(TypeThreadParameterExtMultipleTree));
				tp->tree = tree[0];
				tp->ffe = fp;
				tp->pext = &pext;
				tp->param = &param;
				tp->clade = clade[i];
				tp->logD = &(logSTmp[i]);
				tp->mutex_number = &mutexN;
				tp->cond_number = &condN;
				tp->number = &nT;
				if((ret = pthread_create(&thread, NULL, threadComputeExtMultipleTree, (void *)tp)) == 0) {
					int err;
					if((err = pthread_detach(thread)) == 0) {
						nT++;
						i++;
					} else {
						warning("Error %d while detaching thread: %s\n", err, (char *)strerror(err));
					}
				} else
					warning("Error %d while creating thread: %s\n", ret, (char *)strerror(ret));
			}
			cont = (nT > 0);
			if(cont)
				pthread_cond_wait(&condN, &mutexN);
			pthread_mutex_unlock(&mutexN);
		}
		saveParam[s] = param;
		for(f = 0; f < fp->size; f++)
			save[f][s] = fp->fossilList[f].time;
		for(n = 0; n < nExt; n++)
			saveText[n][s] = tree[0]->time[ext[n]];
		for(j = 0; j < gap; j++) {
			prob = update(tree, nTree, fp, fi, fol, branch, prob, al, prop, &param, windSize, probSpe, probExt);
		}
		if(s % 10 == 0) {
			fprintf(stderr, "it %-7d\r", s);
			fflush(stderr);
		}
	}
	d = (TypeDistribution *)malloc(nClade * sizeof(TypeDistribution));
	// printf("%d clades\n", nClade);
	for(n = 0; n < nClade; n++) {
		// printf("clade %d -> %d\n", n, logSTmp[n].size);
		d[n].size = logSTmp[n].size;
		d[n].item = (TypeDistributionItem *)malloc(logSTmp[n].size * sizeof(TypeDistributionItem));
		for(j = 0; j < logSTmp[n].size; j++) {
			d[n].item[j].val = logSTmp[n].item[j].val;
			if(logSTmp[n].item[j].dens > NEG_INFTY)
				d[n].item[j].dens = exp(logSTmp[n].item[j].dens - log((double)iter));
			else
				d[n].item[j].dens = 0.;
		}
		free((void *)logSTmp[n].item);
	}
	free((void *)logSTmp);
	for(s = 0; s < iter; s++)
		fprintf(fout, "%d\t%lf\n", s + burn + 1, saveParam[s].birth);
	for(s = 0; s < iter; s++)
		fprintf(fout, "%d\t%lf\n", s + burn + 1, saveParam[s].death);
	for(s = 0; s < iter; s++)
		fprintf(fout, "%d\t%lf\n", s + burn + 1, saveParam[s].fossil);
	free((void *)saveParam);
	for(f = 0; f < fp->size; f++)
		for(s = 0; s < iter; s++)
			fprintf(fout, "%d\t%lf\n", s + burn + 1, save[f][s]);
	for(f = 0; f < fp->size; f++)
		free((void *)save[f]);
	free((void *)save);
	for(n = 0; n < nExt; n++)
		for(s = 0; s < iter; s++)
			fprintf(fout, "%d\t%lf\n", s + burn + 1, saveText[n][s]);
	for(n = 0; n < nExt; n++)
		free((void *)saveText[n]);
	free((void *)saveText);
	int off = 0;
	fprintf(find, "birth\t%d\t%d\n", off * iter + 1, (off + 1) * iter);
	off++;
	fprintf(find, "death\t%d\t%d\n", off * iter + 1, (off + 1) * iter);
	off++;
	fprintf(find, "fossil\t%d\t%d\n", off * iter + 1, (off + 1) * iter);
	off++;
	for(f = 0; f < fp->size; f++) {
		fprintf(find, "%d", f + 1);
		if(branch[f] != NOSUCH && tree[0]->name[branch[f]] != NULL)
			fprintf(find, "_%s_%d_%d", tree[0]->name[branch[f]], (int)round(fi->fossilIntList[f].fossilInt.inf), (int)round(fi->fossilIntList[f].fossilInt.sup));
		fprintf(find, "\t%d\t%d\n", off * iter + 1, (off + 1) * iter);
		off++;
	}
	for(n = 0; n < nExt; n++) {
		if(tree[0]->name[ext[n]] != NULL)
			fprintf(find, "%s", tree[0]->name[ext[n]]);
		else
			fprintf(find, "node_%d", ext[n]);
		fprintf(find, "\t%d\t%d\n", off * iter + 1, (off + 1) * iter);
		off++;
	}
	freeFossilFeature(fp);
	free((void *)branch);
	free((void *)fol);
	free((void *)ext);
	return d;
}

void *threadComputeExtMultipleTree(void *data) {
	int j;
	for(j = 0; j < ((TypeThreadParameterExtMultipleTree *)data)->logD->size; j++) {
		int i;
		double tmp = 0.;
		for(i = 0; ((TypeThreadParameterExtMultipleTree *)data)->clade[i] != END_LIST_INT && ((TypeThreadParameterExtMultipleTree *)data)->logD->item[j].val >= ((TypeThreadParameterExtMultipleTree *)data)->tree->time[((TypeThreadParameterExtMultipleTree *)data)->clade[i]]; i++)
			tmp += getLogProbExtinctCond(((TypeThreadParameterExtMultipleTree *)data)->logD->item[j].val, ((TypeThreadParameterExtMultipleTree *)data)->tree->time[((TypeThreadParameterExtMultipleTree *)data)->clade[i]], ((TypeThreadParameterExtMultipleTree *)data)->tree->maxTime, ((TypeThreadParameterExtMultipleTree *)data)->pext);
		if(((TypeThreadParameterExtMultipleTree *)data)->clade[i] != END_LIST_INT)
			tmp = NEG_INFTY;
		if(tmp != NEG_INFTY)
			((TypeThreadParameterExtMultipleTree *)data)->logD->item[j].dens = logSumLog(((TypeThreadParameterExtMultipleTree *)data)->logD->item[j].dens, tmp);
	}
	pthread_mutex_lock(((TypeThreadParameterExtMultipleTree *)data)->mutex_number);
	(*((TypeThreadParameterExtMultipleTree *)data)->number)--;
	pthread_cond_signal(((TypeThreadParameterExtMultipleTree *)data)->cond_number);
	pthread_mutex_unlock(((TypeThreadParameterExtMultipleTree *)data)->mutex_number);
	free(data);
	return NULL;
}
