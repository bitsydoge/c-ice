#ifndef DEF_ICE_PRIMITIVE
#define DEF_ICE_PRIMITIVE

#include "TypesGraphics.h"
#include "TypesMaths.h"

/// Draw Point
int ICE_Draw_Point(ICE_Vect vect, const ICE_Color color);
/// Draw Line
int ICE_Draw_Line(ICE_Vect vect1, ICE_Vect vect2, const ICE_Color color);
/// Draw One Pixel Line Rectangle
int ICE_Draw_Rectangle(ICE_Box rect, const ICE_Color color);
/// Draw Filled Rectangle
int ICE_Draw_RectangleFill(ICE_Box rect, const ICE_Color color);

// AA

int ICE_Draw_LineAA(const ICE_Vect vect1, const ICE_Vect vect2, const ICE_Color color);
int ICE_Draw_CircleAA(ICE_Vect vect, ICE_Float r, ICE_Color color);

#endif
