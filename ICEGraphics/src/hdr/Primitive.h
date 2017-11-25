#ifndef DEF_ICE_PRIMITIVE
#define DEF_ICE_PRIMITIVE
#include "StructCore.h"
#include "StructMaths.h"
#include "Render.h"
#include "Converter.h"
/// Draw Point
int iceDrawPoint(iceGame *game, iceVect vect, const iceColor color);
/// Draw Line
int iceDrawLine(iceGame *game, iceVect vect1, iceVect vect2, const iceColor color);
/// Draw One Pixel Line Rectangle
int iceDrawRectangle(iceGame *game, iceBox rect, const iceColor color);
/// Draw Filled Rectangle
int iceDrawRectangleFill(iceGame *game, iceBox rect, const iceColor color);

// gl like

int iceDrawPointGL(iceGame *game, int x, int y, const iceColor color);
int iceDrawLineGL(iceGame *game, int x1, int y1, int x2, int y2, const iceColor color);
int iceDrawRectangleGL(iceGame *game, iceBox rect, const iceColor color);
int iceDrawRectangleFillGL(iceGame *game, iceBox rect, const iceColor color);

#endif
