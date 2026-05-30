#ifndef DrawTreeCairoF
#define DrawTreeCairoF
#include "Tree.h"
#include "DrawTreeGeneric.h"

/*Draw text with Cairo at a tree-canvas position.*/
void drawTextCairo(double x, double y, char *text, char *al, TypeParamDrawTreeGeneric *param);
/*Draw rotated text with Cairo.*/
void drawTextAngleCairo(double x, double y, double a, char *text, char *al, TypeParamDrawTreeGeneric *param);
/*Draw a dotted Cairo line.*/
void drawDottedLineCairo(double x1, double y1, double x2, double y2, TypeParamDrawTreeGeneric *param);
/*Draw a solid Cairo line.*/
void drawLineCairo(double x1, double y1, double x2, double y2, TypeParamDrawTreeGeneric *param);
void drawLineDotCairo(TypeRGB rgb, double alpha, double radius, double x1, double y1, double x2, double y2, TypeParamDrawTreeGeneric *param);
void drawDotCairo(TypeRGB rgb, double alpha, double radius, double x, double y, TypeParamDrawTreeGeneric *param);
void fillPolygonCairo(TypeRGB rgb, double alpha, double *x, double *y, int size, TypeParamDrawTreeGeneric *param);
void fillWedgeCairo(TypeRGB rgb, double x, double y, double a, double b, TypeParamDrawTreeGeneric *param);
void drawWedgeCairo(double x, double y, double a, double b, TypeParamDrawTreeGeneric *param);
void fillGradientCairo(TypeRGB rgb0, TypeRGB rgb1, double x0, double y0, double x1, double y1, TypeParamDrawTreeGeneric *param);
/*Install Cairo SVG drawing callbacks.*/
void setFunctSVG(TypeFunctDrawTreeGeneric *funct);
/*Open a fixed-size SVG surface.*/
void startSVGStd(char *filename, double width, double height, TypeParamDrawTreeGeneric *param);
/*Open an SVG surface sized from a tree.*/
void startSVG(char *filename, TypeTree *tree, TypeParamDrawTreeGeneric *param);
/*Install Cairo PDF drawing callbacks.*/
void setFunctPDF(TypeFunctDrawTreeGeneric *funct);
/*Open a fixed-size PDF surface.*/
void startPDFStd(char *filename, double width, double height, TypeParamDrawTreeGeneric *param);
/*Open a PDF surface sized from a tree.*/
void startPDF(char *filename, TypeTree *tree, TypeParamDrawTreeGeneric *param);
/*Install Cairo PostScript drawing callbacks.*/
void setFunctPS(TypeFunctDrawTreeGeneric *funct);
/*Open a fixed-size PostScript surface.*/
void startPSStd(char *filename, double width, double height, TypeParamDrawTreeGeneric *param);
/*Open a PostScript surface sized from a tree.*/
void startPS(char *filename, TypeTree *tree, TypeParamDrawTreeGeneric *param);
/*Install Cairo PNG drawing callbacks.*/
void setFunctPNG(TypeFunctDrawTreeGeneric *funct);
/*Open a fixed-size PNG surface.*/
void startPNGStd(char *filename, double width, double height, TypeParamDrawTreeGeneric *param);
/*Open a PNG surface sized from a tree.*/
void startPNG(char *filename, TypeTree *tree, TypeParamDrawTreeGeneric *param);
/*Finish and write a PNG surface.*/
void endPNG(TypeParamDrawTreeGeneric *param);
/*Finish and free a Cairo drawing surface.*/
void endCairo(TypeParamDrawTreeGeneric *param);

#endif
