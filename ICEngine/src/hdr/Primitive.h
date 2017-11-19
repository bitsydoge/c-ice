#ifndef DEF_ICE_PRIMITIVE
#define DEF_ICE_PRIMITIVE
#include "Struct.h"
#include "Render.h"

ICE_Rect RectNew(int x, int y, int w, int h);
void RectEdit(ICE_Rect * rect, int x, int y, int w, int h);
void RectMove(ICE_Rect * rect, int x, int y);
void RectResize(ICE_Rect * rect, int w, int h);
void RectShift(ICE_Rect * rect, int x, int y);

// POINT

ICE_Point PointNew(int x, int y);
void PointMove(ICE_Point * point, int x, int y);
void PointShift(ICE_Point *point, int x, int y);

/// Draw Point
int ICE_DrawPoint(ICE_Game *game, int x, int y, const ICE_Color color);
/// Draw Line
int ICE_DrawLine(ICE_Game *game, int x1, int y1, int x2, int y2, const ICE_Color color);
/// Draw One Pixel Line Rectangle
int ICE_DrawRectangle(ICE_Game *game, ICE_Rect rect, const ICE_Color color);
/// Draw Filled Rectangle 
int ICE_DrawRectangleFill(ICE_Game *game, const ICE_Rect rect, const ICE_Color color);

// gl like

int ICE_DrawPointGL(ICE_Game *game, int x, int y, const ICE_Color color);
int ICE_DrawLineGL(ICE_Game *game, int x1, int y1, int x2, int y2, const ICE_Color color);
int ICE_DrawRectangleGL(ICE_Game *game, ICE_Rect rect, const ICE_Color color);
int ICE_DrawRectangleFillGL(ICE_Game *game, const ICE_Rect rect, const ICE_Color color);

#endif