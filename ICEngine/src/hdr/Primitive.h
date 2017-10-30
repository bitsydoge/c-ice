#ifndef DEF_ICE_PRIMITIVE
#define DEF_ICE_PRIMITIVE
#include "Struct.h"
#include "Render.h"

ICE_Rect NewRect(int x, int y, int w, int h);
int ICE_DrawPoint(ICE_Game *game, int x, int y, const ICE_Color color);
int ICE_DrawLine(ICE_Game *game, int x1, int y1, int x2, int y2, const ICE_Color color);
int ICE_DrawRectangle(ICE_Game *game, ICE_Rect rect, const ICE_Color color);
int ICE_DrawRectangleFill(ICE_Game *game, const ICE_Rect rect, const ICE_Color color);

#endif
