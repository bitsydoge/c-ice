#ifndef DEF_ICE_PRIMITIVE
#define DEF_ICE_PRIMITIVE
#include "Struct.h"
#include "Render.h"


// raw

/// Return a new Rectangle X Y W H
ICE_Rect NewRect(int x, int y, int w, int h);
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