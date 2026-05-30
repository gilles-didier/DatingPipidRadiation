#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include "MyR.h"

void error(const char *message, ...) {
	va_list args;

	va_start(args, message);
	vprintf(message, args);
	va_end(args);
	exit(1);
}

void warning(const char *message, ...) {
	va_list args;

	va_start(args, message);
	vprintf(message, args);
	va_end(args);
}

void Rprintf(const char *message, ...) {
	va_list args;

	va_start(args, message);
	vprintf(message, args);
	va_end(args);
}

double lgammafn(double x) {
	return lgamma(x);
}

double unif_rand() {
	return (((double)rand()) / ((double)RAND_MAX));
}
