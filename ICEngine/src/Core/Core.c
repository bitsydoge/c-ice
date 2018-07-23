#include "Core.h"

#include "TypesCore.h"
#include "Core_private.h"
#include "Game_private.h"
#include "Input_private.h"
#include "Time_private.h"
#include "Asset_private.h"

#include "../Graphics/Draw.h"
#include "../Graphics/Render.h"
#include "../Graphics/Render_private.h"
#include "../Framework/Log.h"
#include "../Core/Debug.h"

#include <stdio.h>


extern ICE_Game game;

int ICE_Core_Main(char * title, const int window_width, const int window_height, void(*call_create)(void), void(*call_update)(void), void(*call_destroy)(void), int argc, char **argv)
{
#if defined(_DEBUG) && defined (_MSC_VER)
	puts("");
#endif

	ICE_Core_Init();
	ICE_GameObject_Create(title, window_width, window_height, argc, argv);
	ICE_Asset_Init();
	ICE_Log(ICE_LOG_RUNNING, "Game]::[Create]::[Start");
	call_create();
	ICE_Log(ICE_LOG_SUCCES, "Game]::[Create]::[Finish");
	printf("\n");
	ICE_Log(ICE_LOG_RUNNING, "Game]::[Update]::[Start");
	while (!game.window.input.quit)
	{	
		ICE_Time_Start();
		ICE_Input_Return();
		ICE_Render_SetColor(game.current->background);
		if(game.window.auto_clear)
			ICE_Render_Clear();
		call_update();

		// RENDER HERE
		ICE_Draw_Entity();
		ICE_Draw_LabelWorld();
		ICE_Draw_Gui();
		ICE_Draw_LabelScreen();

		if (game.lateDrawDebug && ICE_Debug())
			game.lateDrawDebug();
	
		if(game.window.auto_render)
			ICE_Render_Now();

		ICE_Time_End();
	}
	ICE_Log(ICE_LOG_SUCCES, "Game]::[Update]::[Finish");
	printf("\n");
	ICE_Log(ICE_LOG_RUNNING, "Game]::[Destroy]::[Start");
	call_destroy();
	ICE_GameObject_Destroy();
	ICE_Log(ICE_LOG_SUCCES, "Game]::[Destroy]::[Finish");
	
	ICE_Core_Close();

	return 0;
}