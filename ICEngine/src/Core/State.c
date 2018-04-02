#include "State.h"

#include "TypesCore.h"
#include "Time_private.h"
#include "Input_private.h"
#include "Input.h"

#include "../Graphics/Render.h"
#include "../Graphics/Render_private.h"
#include "../Framework/Log.h"
#include "../Core/Label.h"
#include "../Graphics/Draw.h"

#include <stdio.h>
#include "../ICE.h"

extern ICE_Game game;

ICE_State ICE_State_Create(void (*func_create)(void), void (* func_update)(void), void (* func_destroy)(void))
{
	ICE_State state = {0};

	state.func_create = func_create;
	state.func_update = func_update;
	state.func_destroy = func_destroy;


	return state;
}

void ICE_State_Change(ICE_State state)
{
	game.state_mngr.current = &state;
}

void ICE_State_Quit()
{
	game.state_mngr.current->quit = ICE_True;
}

void ICE_Substate_Start(ICE_State *state)
{
	state->parent = game.state_mngr.current;

	game.state_mngr.current = state;

	ICE_Substate_Loop();

	game.state_mngr.current = state->parent;
	

}

void ICE_Substate_Loop()
{
	ICE_Input_Reset();
	ICE_State * current = game.state_mngr.current;

	printf("------------------------\n");
	ICE_Log(ICE_LOG_RUNNING, "Substate]::[Create]::[Start");
	printf("------------------------\n");
	
	current->func_create();

	printf("------------------------\n");
	ICE_Log(ICE_LOG_SUCCES, "Substate]::[Create]::[Finish");
	printf("------------------------\n");
	printf("\n");
	printf("------------------------\n");
	ICE_Log(ICE_LOG_RUNNING, "Substate]::[Update]::[Start");
	printf("------------------------\n");
	while (!game.window.input.quit && !game.state_mngr.current->quit)
	{
		ICE_Time_Start();
		ICE_Input_Return();
		ICE_Render_SetColor(game.window.background);
		if (game.window.auto_clear)
			ICE_Render_Clear();
		current->func_update();

		// RENDER HERE
		ICE_Draw_LabelWorld();
		ICE_Draw_Gui();
		ICE_Draw_LabelScreen();

		if (game.window.auto_render)
			ICE_Render_Now();

		ICE_Time_End();
	}
	printf("------------------------\n");
	ICE_Log(ICE_LOG_SUCCES, "Substate]::[Update]::[Finish");
	printf("------------------------\n");
	printf("\n");
	printf("------------------------\n");
	ICE_Log(ICE_LOG_RUNNING, "Substate]::[Destroy]::[Start");
	printf("------------------------\n");
	current->func_destroy();
	ICE_LabelManager_DestroyAll();
	ICE_GuiManager_DestroyAll();
	ICE_ObjectManager obj = { 0 };
	current->object = obj;
	ICE_Input_Reset();
}

ICE_State * ICE_State_GetParent(ICE_State * state)
{
	if (!state)
		state = game.state_mngr.current;


	if(state->parent)
		return state->parent;
	ICE_Log(ICE_LOG_CRITICAL, "No Parent State");
	return state;
}