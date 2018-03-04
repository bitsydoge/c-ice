#include "hdr/Core.h"
#include "hdr/Core_private.h"
#include "hdr/Game_private.h"
#include "hdr/Input_private.h"
#include "hdr/Render_private.h"
#include "hdr/Time_private.h"

extern ICE_Game game;

int ICE_CoreLoop(const ICE_String title, const int window_width, const int window_height, void(*call_preload)(void), void(*call_create)(void), void(*call_update)(void), void(*call_destroy)(void)) 
{
	ICE_CoreInit();
	call_preload();
	ICE_GameCreate(title, window_width, window_height);
	call_create();
	while (!game.window.input.quit)
	{	
		ICE_TimeStart();
		ICE_InputReturn();
		ICE_RenderSetColor(game.window.background);
		ICE_RenderClear();
		call_update();

		// RENDER HERE

		ICE_RenderNow();

		ICE_TimeEnd();
	}
	call_destroy();
	ICE_GameDestroy();
	ICE_CoreClose();
	return 0;
}
