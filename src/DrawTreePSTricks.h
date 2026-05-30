#ifndef DrawTreePstricksF
#define DrawTreePstricksF
#include "Tree.h"
#include "DrawTreeGeneric.h"

#ifdef __cplusplus
extern "C" {
#endif

/*Draw text in PSTricks output.*/
void drawTextPSTricks(double x0, double y0, char *text, char *mod, TypeParamDrawTreeGeneric *param);
/*Draw rotated text in PSTricks output.*/
void drawTextAnglePSTricks(double x0, double y0, double a, char *text, char *mod, TypeParamDrawTreeGeneric *param);
/*Draw a dotted line through the generic drawing interface.*/
void drawDottedLineCairo(double x1, double y1, double x2, double y2, TypeParamDrawTreeGeneric *param);
/*Draw a solid line in PSTricks output.*/
void drawLinePSTricks(double x0, double y0, double x1, double y1, TypeParamDrawTreeGeneric *param);
/*Install PSTricks drawing callbacks.*/
void setFunctPSTricks(TypeFunctDrawTreeGeneric *funct);
/*Open a PSTricks output file sized from a tree.*/
void startPSTricks(char *filename, TypeTree *tree, TypeParamDrawTreeGeneric *param);
/*Close a PSTricks output file.*/
void endPSTricks(TypeParamDrawTreeGeneric *param);
/*Format an RGB color for PSTricks output.*/
char *sprintRGBPSTricks(char *buffer, TypeRGB rgb);
/*Estimate the maximum leaf label width for PSTricks output.*/
double getMaxLeafLabelWidthPSTricks(TypeTree *tree);
/*Draw a line with a terminal dot in PSTricks output.*/
void drawLineDotPSTricks(TypeRGB rgb, double alpha, double radius, double x0, double y0, double x1, double y1, TypeParamDrawTreeGeneric *param);
/*Draw a dot in PSTricks output.*/
void drawDotPSTricks(TypeRGB rgb, double alpha, double radius, double x, double y, TypeParamDrawTreeGeneric *param);

/*Open a fixed-size PSTricks output file.*/
void startPSTricksStd(char *filename, double width, double height, TypeParamDrawTreeGeneric *param);
void startPSTricks(char *filename, TypeTree *tree, TypeParamDrawTreeGeneric *param);
void endPSTricks(TypeParamDrawTreeGeneric *param);
void drawTextPSTricks(double x0, double y0, char *text, char *mod, TypeParamDrawTreeGeneric *param);
void drawLinePSTricks(double x0, double y0, double x1, double y1, TypeParamDrawTreeGeneric *param);
/*Fill an angular wedge in PSTricks output.*/
void fillWedgePSTricks(TypeRGB rgb, double x, double y, double a, double b, TypeParamDrawTreeGeneric *param);
/*Draw an angular wedge outline in PSTricks output.*/
void drawWedgePSTricks(double x, double y, double a, double b, TypeParamDrawTreeGeneric *param);
/*Fill a gradient rectangle in PSTricks output.*/
void fillGradientPSTricks(TypeRGB rgb0, TypeRGB rgb1, double x0, double y0, double x1, double y1, TypeParamDrawTreeGeneric *param);
/*Fill a polygon in PSTricks output.*/
void fillPolygonPSTricks(TypeRGB rgb, double alpha, double *x, double *y, int size, TypeParamDrawTreeGeneric *param);

#ifdef __cplusplus
}
#endif

#endif
