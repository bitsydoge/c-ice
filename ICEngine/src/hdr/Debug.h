#ifndef DEF_ICE_DEBUG
#define DEF_ICE_DEBUG
#include "TypesCore.h"

ICE_Bool ICE_Debug(const ICE_Bool yn);
void ICE_DebugMouseCoordinate();
void ICE_DebugShowFps();
void ICE_DebugShowFpsTitle();
void ICE_DebugFontDrawBgColor(int r, int g, int b);
void ICE_DebugFontDrawFgColor(int r, int g, int b);
void ICE_DebugFontDraw(int y, const char* format, ...);
void ICE_DebugMoveCamera();

#endif
