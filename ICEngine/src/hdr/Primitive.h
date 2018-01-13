#ifndef DEF_ICE_PRIMITIVE
#define DEF_ICE_PRIMITIVE
#include "TypesCore.h"
#include "TypesMaths.h"
#include "Draw.h"
#include "Converter.h"
/// Draw Point
int iceDrawPoint(iceVect vect, const iceColor color);
/// Draw Line
int iceDrawLine(iceVect vect1, iceVect vect2, const iceColor color);
/// Draw One Pixel Line Rectangle
int iceDrawRectangle(iceBox rect, const iceColor color);
/// Draw Filled Rectangle
int iceDrawRectangleFill(iceBox rect, const iceColor color);

#endif
