#ifndef DrawTreeTikzF
#define DrawTreeTikzF
#include "Tree.h"
#include "DrawTreeGeneric.h"

#ifdef __cplusplus
extern "C" {
#endif

/*Draw text in TikZ output.*/
void drawTextTikz(double x0, double y0, char *text, char *mod, TypeParamDrawTreeGeneric *param);
/*Draw rotated text in TikZ output.*/
void drawTextAngleTikz(double x0, double y0, double a, char *text, char *mod, TypeParamDrawTreeGeneric *param);
/*Draw a dotted line in TikZ output.*/
void drawDottedLineTikz(double x1, double y1, double x2, double y2, TypeParamDrawTreeGeneric *param);
/*Draw a solid line in TikZ output.*/
void drawLineTikz(double x0, double y0, double x1, double y1, TypeParamDrawTreeGeneric *param);
/*Draw a line with a terminal dot in TikZ output.*/
void drawLineDotTikz(TypeRGB rgb, double alpha, double radius, double x0, double y0, double x1, double y1, TypeParamDrawTreeGeneric *param);
/*Install TikZ drawing callbacks.*/
void setFunctTikz(TypeFunctDrawTreeGeneric *funct);
/*Open a TikZ output file sized from a tree.*/
void startTikz(char *filename, TypeTree *tree, TypeParamDrawTreeGeneric *param);
/*Close a TikZ output file.*/
void endTikz(TypeParamDrawTreeGeneric *param);
/*Format an RGB color for TikZ output.*/
char *sprintRGBTikz(char *buffer, TypeRGB rgb);
/*Estimate the maximum leaf label width for TikZ output.*/
double getMaxLeafLabelWidthTikz(TypeTree *tree);
/*Open a fixed-size TikZ output file.*/
void startTikzStd(char *filename, double width, double height, TypeParamDrawTreeGeneric *param);
void startTikz(char *filename, TypeTree *tree, TypeParamDrawTreeGeneric *param);
void endTikz(TypeParamDrawTreeGeneric *param);
void drawTextTikz(double x0, double y0, char *text, char *mod, TypeParamDrawTreeGeneric *param);
void drawLineTikz(double x0, double y0, double x1, double y1, TypeParamDrawTreeGeneric *param);
/*Fill an angular wedge in TikZ output.*/
void fillWedgeTikz(TypeRGB rgb, double x, double y, double a, double b, TypeParamDrawTreeGeneric *param);
/*Draw an angular wedge outline in TikZ output.*/
void drawWedgeTikz(double x, double y, double a, double b, TypeParamDrawTreeGeneric *param);
/*Fill a gradient rectangle in TikZ output.*/
void fillGradientTikz(TypeRGB rgb0, TypeRGB rgb1, double x0, double y0, double x1, double y1, TypeParamDrawTreeGeneric *param);
/*Fill a polygon in TikZ output.*/
void fillPolygonTikz(TypeRGB rgb, double alpha, double *x, double *y, int size, TypeParamDrawTreeGeneric *param);
/*Draw a dot in TikZ output.*/
void drawDotTikz(TypeRGB rgb, double alpha, double radius, double x, double y, TypeParamDrawTreeGeneric *param);

#ifdef __cplusplus
}
#endif

#endif
