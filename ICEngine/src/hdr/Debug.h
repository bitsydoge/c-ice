#ifndef DEF_ICE_DEBUG
#define DEF_ICE_DEBUG
#include "TypesCore.h"

ICE_Bool ICE_Debug(const ICE_Bool yn);
void ICE_Debug_DrawCoordinate();
void ICE_Debug_DrawFps();
void ICE_Debug_TitleFps();
void ICE_Debug_FontSetColorBg(int r, int g, int b);
void ICE_Debug_FontSetColorFg(int r, int g, int b);
void ICE_Debug_FontDraw(int y, const char* format, ...);
void ICE_Debug_CameraControl();

#endif
