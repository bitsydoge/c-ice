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
enum ICE_LogTypes
{
	ICE_LOG_CRITICAL = -3,
	ICE_LOG_ERROR = -2,
	ICE_LOG_WARNING = -1,

	ICE_LOG_NONE = 0,

	ICE_LOG_SUCCES = 1
}; typedef enum ICE_LogTypes ICE_LogTypes;

void ICE_Log(ICE_LogTypes type, const char * format, ...);
void ICE_Log_no_n(ICE_LogTypes type, const char * format, ...);

#endif
