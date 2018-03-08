#include "hdr/Core.h"
#include "hdr/Core_private.h"
#include "hdr/Game_private.h"
#include "hdr/Input_private.h"
#include "hdr/Render_private.h"
#include "hdr/Time_private.h"
#include <stdio.h>

extern ICE_Game game;

int ICE_CoreLoop(const ICE_String title, const int window_width, const int window_height, void(*call_preload)(void), void(*call_create)(void), void(*call_update)(void), void(*call_destroy)(void)) 
{
	ICE_CoreInit();
	call_preload();

	ICE_GameCreate(title, window_width, window_height);
	printf("------------------------\n");
	ICE_Log(ICE_LOG_RUNNING, "Game]::[Create]::[Start");
	printf("------------------------\n");
	call_create();
	printf("------------------------\n");
	ICE_Log(ICE_LOG_SUCCES, "Game]::[Create]::[Finish");
	printf("------------------------\n");
	printf("\n");
	printf("------------------------\n");
	ICE_Log(ICE_LOG_RUNNING, "Game]::[Update]::[Start");
	printf("------------------------\n");
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
	printf("------------------------\n");
	ICE_Log(ICE_LOG_SUCCES, "Game]::[Update]::[Finish");
	printf("------------------------\n");
	printf("\n");
	printf("------------------------\n");
	ICE_Log(ICE_LOG_RUNNING, "Game]::[Destroy]::[Start");
	printf("------------------------\n");
	call_destroy();
	ICE_GameDestroy();
	printf("------------------------\n");
	ICE_Log(ICE_LOG_SUCCES, "Game]::[Destroy]::[Finish");
	printf("------------------------\n\n");
	
	ICE_CoreClose();
	return 0;
}
