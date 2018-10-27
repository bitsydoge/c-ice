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

#include <stdio.h>

extern ICE_Game game;
extern ICE_Core core;

int ICE_Core_Main(char * title, const int window_width, const int window_height, void(*call_create)(void), void(*call_update)(void), void(*call_destroy)(void), int argc, char **argv)
{
#if defined(_DEBUG) && defined (_MSC_VER)
	puts("");
#endif
	ICE_Core_Init();
	ICE_GameObject_Create(title, window_width, window_height, argc, argv);
	ICE_Asset_Init();
	ICE_Log_Line();
	ICE_Log(ICE_LOG_RUNNING, "Game :: Create ...");
	call_create();
	ICE_Log(ICE_LOG_FINISH, "Game :: Create :: Ok");
	printf("\n");
	ICE_Log_Line();
	ICE_Log(ICE_LOG_RUNNING, "Game :: Update ...");
	while (!core.window.input.quit)
	{	
		ICE_Time_Start();
		ICE_Input_Return();
		ICE_Render_SetColor(game.current->background);
		if(core.window.auto_clear)
			ICE_Render_Clear();
		call_update();

		// RENDER HERE
		ICE_Draw_Entity();
		ICE_Draw_LabelWorld();
		ICE_Draw_Gui();
		ICE_Draw_LabelScreen();

#if defined(_DEBUG)
		if (core.lateDrawDebug)
			core.lateDrawDebug();
#endif
		if(core.window.auto_render)
			ICE_Render_Now();

		ICE_Time_End();
	}
	ICE_Log(ICE_LOG_FINISH, "Game :: Update :: Ok");
	printf("\n");
	ICE_Log_Line();
	ICE_Log(ICE_LOG_RUNNING, "Game :: Destroy ...");
	call_destroy();
	ICE_GameObject_Destroy();
	ICE_Log(ICE_LOG_FINISH, "Game :: Destroy :: Ok");
	
	ICE_Core_Close();

	return 0;
}

ICE_StringStd ICE_Core_GetLinkedVersion()
{
	return ICE_VERSION;
}

