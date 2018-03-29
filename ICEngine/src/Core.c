#include "hdr/Core.h"
#include "hdr/Core_private.h"
#include "hdr/Game_private.h"
#include "hdr/Input_private.h"
#include "hdr/Render_private.h"
#include "hdr/Time_private.h"
#include <stdio.h>

extern ICE_Game game;

int ICE_Core_Main(const ICE_String title, const int window_width, const int window_height, void(*call_preload)(void), void(*call_create)(void), void(*call_update)(void), void(*call_destroy)(void)) 
{
	ICE_Core_Init();
	call_preload();

	ICE_Game_Create(title, window_width, window_height);
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
		ICE_Time_Start();
		ICE_Input_Return();
		ICE_Render_SetColor(game.window.background);
		if(game.window.auto_clear)
			ICE_Render_Clear();
		call_update();

		// RENDER HERE

		if(game.window.auto_render)
			ICE_Render_Now();

		ICE_Time_End();
	}
	printf("------------------------\n");
	ICE_Log(ICE_LOG_SUCCES, "Game]::[Update]::[Finish");
	printf("------------------------\n");
	printf("\n");
	printf("------------------------\n");
	ICE_Log(ICE_LOG_RUNNING, "Game]::[Destroy]::[Start");
	printf("------------------------\n");
	call_destroy();
	ICE_Game_Destroy();
	printf("------------------------\n");
	ICE_Log(ICE_LOG_SUCCES, "Game]::[Destroy]::[Finish");
	printf("------------------------\n\n");
	
	ICE_Core_Close();
	return 0;
}