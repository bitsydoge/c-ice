#ifndef DEF_ICE_PRIMITIVE
#define DEF_ICE_PRIMITIVE
#include "Struct.h"
#include "Render.h"

iceRect RectNew(iceFloat x, iceFloat y, iceFloat w, iceFloat h);
void RectEdit(iceRect * rect, iceFloat x, iceFloat y, iceFloat w, iceFloat h);
void RectMove(iceRect * rect, iceFloat x, iceFloat y);
void RectResize(iceRect * rect, iceFloat w, iceFloat h);
void RectShift(iceRect * rect, iceFloat x, iceFloat y);

/// Draw Point
int ICE_DrawPoint(ICE_Game *game, int x, int y, const iceColor color);
/// Draw Line
int ICE_DrawLine(ICE_Game *game, int x1, int y1, int x2, int y2, const iceColor color);
/// Draw One Pixel Line Rectangle
int ICE_DrawRectangle(ICE_Game *game, iceRect rect, const iceColor color);
/// Draw Filled Rectangle 
int ICE_DrawRectangleFill(ICE_Game *game, const iceRect rect, const iceColor color);

// gl like

int ICE_DrawPointGL(ICE_Game *game, int x, int y, const iceColor color);
int ICE_DrawLineGL(ICE_Game *game, int x1, int y1, int x2, int y2, const iceColor color);
int ICE_DrawRectangleGL(ICE_Game *game, iceRect rect, const iceColor color);
int ICE_DrawRectangleFillGL(ICE_Game *game, const iceRect rect, const iceColor color);

#endif