#ifndef DEF_ICE_PRIMITIVE
#define DEF_ICE_PRIMITIVE
#include "Struct.h"
#include "Render.h"

/// Draw Point
int iceDrawPoint(iceGame *game, int x, int y, const iceColor color);
/// Draw Line
int iceDrawLine(iceGame *game, int x1, int y1, int x2, int y2, const iceColor color);
/// Draw One Pixel Line Rectangle
int iceDrawRectangle(iceGame *game, iceRect rect, const iceColor color);
/// Draw Filled Rectangle 
int iceDrawRectangleFill(iceGame *game, iceRect rect, const iceColor color);

// gl like

int iceDrawPointGL(iceGame *game, int x, int y, const iceColor color);
int iceDrawLineGL(iceGame *game, int x1, int y1, int x2, int y2, const iceColor color);
int iceDrawRectangleGL(iceGame *game, iceRect rect, const iceColor color);
int iceDrawRectangleFillGL(iceGame *game, iceRect rect, const iceColor color);

#endif