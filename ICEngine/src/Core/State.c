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
#include "../Graphics/Gui.h"

#include <stdio.h>
#include "Data.h"

extern ICE_Game game;

ICE_State ICE_State_Create(void (*func_create)(void), void (* func_update)(void), void (* func_destroy)(void))
{
	ICE_State state = {0};

	state.func_create = func_create;
	state.func_update = func_update;
	state.func_destroy = func_destroy;


	return state;
}

void ICE_State_Change(ICE_State * state)
{
	game.state_mngr.current = state;
}

void ICE_State_Quit()
{
	game.state_mngr.current->quit = ICE_True;
}

void ICE_State_Pause()
{
	game.state_mngr.current->quit = ICE_True;
	game.state_mngr.current->isPaused = ICE_True;
}

void ICE_State_ResumeCallback(ICE_State * state, void(*func_resume)(void))
{
	if (!state)
		state = game.state_mngr.current;

	state->func_resume = func_resume;
}

void ICE_State_PauseCallback(ICE_State * state, void(*func_pause)(void))
{
	if (!state)
		state = game.state_mngr.current;

	state->func_pause = func_pause;
}

ICE_Bool ICE_State_WasPaused()
{
	return game.state_mngr.current->isPaused;
}

void ICE_Substate_Start(ICE_State *state)
{
	state->parent = game.state_mngr.current;
	game.state_mngr.current = state;

	if(game.state_mngr.current->isPaused)
	{
		game.state_mngr.current->quit = ICE_False;
	}

	ICE_Substate_Loop();

	game.state_mngr.current = state->parent;
	

}

ICE_State * ICE_State_Main()
{
	return &game.state_main;
}

void ICE_State_Destroy(ICE_State * state)
{
	if(!state->isFree)
	{
		ICE_LabelManager_DestroyAll(state);
		ICE_GuiManager_DestroyAll(state);
		ICE_Data_DestroyAll(state);
	}
}

void ICE_Substate_Loop()
{
	ICE_Input_Reset();
	ICE_State * current = game.state_mngr.current;

	ICE_Log(ICE_LOG_RUNNING, "Substate]::[Create]::[Start");
	
	if (!current->isPaused)
		current->func_create();
	else
		if (current->func_resume != NULL)
			current->func_resume();

	ICE_Log(ICE_LOG_SUCCES, "Substate]::[Create]::[Finish");
	printf("\n");
	ICE_Log(ICE_LOG_RUNNING, "Substate]::[Update]::[Start");
	while (!game.window.input.quit && !game.state_mngr.current->quit)
	{
		ICE_Time_Start();
		ICE_Input_Return();
		ICE_Render_SetColor(current->background);
		if (game.window.auto_clear)
			ICE_Render_Clear();
		current->func_update();

		// RENDER HERE
		ICE_Draw_Entity();
		ICE_Draw_LabelWorld();
		ICE_Draw_Gui();
		ICE_Draw_LabelScreen();

		if (game.window.auto_render)
			ICE_Render_Now();

		ICE_Time_End();
	}
	ICE_Log(ICE_LOG_SUCCES, "Substate]::[Update]::[Finish");
	printf("\n");
	ICE_Log(ICE_LOG_RUNNING, "Substate]::[Destroy]::[Start");
	if (!current->isPaused)
	{
		current->func_destroy();
		current->isFree = ICE_True;
		ICE_LabelManager_DestroyAll(NULL);
		ICE_GuiManager_DestroyAll(NULL);
		ICE_Data_DestroyAll(NULL);
		ICE_ObjectManager obj = { 0 };
		current->object = obj;
	}
	else
		if(current->func_pause != NULL)
			current->func_pause();

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