#include "Core.h"
#include "TypesCore.h"
#include "Core_private.h"
#include "Game_private.h"
#include "../Graphics/Draw.h"
#include "../Graphics/Render_private.h"
#include "Time_private.h"
#include "Input_private.h"
#include "../Framework/Log.h"
#include "Entity.h"

extern ICE_Game GAME;
extern ICE_Core CORE;

void ICE_Core_Main(void(*call_create)(void), void(*call_update)(void), void(*call_destroy)(void))
{
	ICE_Core_Init();
	ICE_Render_Init();
	ICE_Game_Init();

	ICE_Log_Line();
	ICE_Log(ICE_LOGTYPE_RUNNING, "Main Create ...");
	call_create();
	ICE_Log(ICE_LOGTYPE_FINISH, "Main Create");
	ICE_Log_Line(); 

	ICE_Log_Line();
	ICE_Log(ICE_LOGTYPE_RUNNING, "Main Update ...");
	while (!CORE.window.input.quit)
	{
		// LOGIC HERE
		ICE_Time_Start();
		ICE_Input_Return();

		ICE_Entity_FunctionUpdate(NULL);
		call_update();

		// RENDER HERE
		ICE_Render_SetColor(GAME.current->background);
		ICE_Render_Clear();

		ICE_Draw_AllEntity();
		ICE_Draw_LabelWorld();
		ICE_Draw_AllGui();
		ICE_Draw_LabelScreen();

#if defined(_DEBUG)
		if (CORE.lateDrawDebug)
			CORE.lateDrawDebug();
#endif

		ICE_Render_Now();
		ICE_Time_End();
	}
	ICE_Log(ICE_LOGTYPE_FINISH, "Main Update");
	ICE_Log_Line();

	ICE_Log_Line();
	ICE_Log(ICE_LOGTYPE_RUNNING, "Main Destroy ...");
	call_destroy();
	ICE_Log(ICE_LOGTYPE_FINISH, "Main Destroy");
	ICE_Log_Line();

	ICE_Game_Quit();
	ICE_Render_Quit();
	ICE_Core_Quit();
}