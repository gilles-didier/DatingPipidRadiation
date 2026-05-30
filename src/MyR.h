#ifndef MyRF
#define MyRF

#ifdef __cplusplus
extern "C" {
#endif

/*Print an error message and stop execution.*/
void error(const char *format, ...);
/*Print a warning message without stopping execution.*/
void warning(const char *format, ...);
/*Compatibility wrapper for R-style formatted output.*/
void Rprintf(const char *format, ...);
/*Compatibility wrapper for the log-gamma function.*/
double lgammafn(double x);
/*Compatibility wrapper returning a pseudo-random number in [0, 1].*/
double unif_rand();

#ifdef __cplusplus
}
#endif

#endif
