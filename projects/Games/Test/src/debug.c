#include "debug.h"
#include "ICE.h"
#include "game.h"

void GAME_Debug_LateDraw()
{
	GAME_DATA * D = ICE_Data_Get(ICE_State_Current, 0);
	
	ICE_Debug_FontDraw(4, "%s Test", ICE_VERSION);
	ICE_Debug_DrawFps(5);

	if(D->screenShotDraw)
#
		ICE_Debug_FontDraw(3, "Screenshot %s saved", D->screenshot_name);
}
