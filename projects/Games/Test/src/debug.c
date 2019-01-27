#include "debug.h"
#include "ICE.h"

void GAME_Debug_LateDraw()
{
	ICE_Debug_FontDraw(4, "%s Test", ICE_VERSION);
	ICE_Debug_DrawFps(5);
}
