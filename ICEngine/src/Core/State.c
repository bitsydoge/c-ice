#include "State.h"

#include "TypesCore.h"
#include "Time_private.h"
#include "Input_private.h"
#include "Input.h"

#include "../Graphics/Render_private.h"
#include "../Framework/Log.h"
#include "../Core/Label.h"
#include "../Graphics/Draw.h"
#include "../Graphics/Gui.h"

#include "Data.h"
#include "../Graphics/Gui_private.h"
#include "../ICE.h"

extern ICE_Game GAME;
extern ICE_Core CORE;

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
	GAME.current = state;
}

void ICE_State_Quit()
{
	GAME.current->quit = ICE_True;
}

void ICE_State_Pause()
{
	GAME.current->quit = ICE_True;
	GAME.current->isPaused = ICE_True;
}

void ICE_State_ResumeCallback(ICE_State * state, void(*func_resume)(void))
{
	if (!state)
		state = GAME.current;

	state->func_OnResume = func_resume;
}

void ICE_State_PauseCallback(ICE_State * state, void(*func_pause)(void))
{
	if (!state)
		state = GAME.current;

	state->func_OnPause = func_pause;
}

ICE_Bool ICE_State_WasPaused()
{
	return GAME.current->isPaused;
}

void ICE_Substate_Start(ICE_State *state)
{
	state->parent = GAME.current;
	GAME.current = state;

	if(GAME.current->isPaused)
	{
		GAME.current->quit = ICE_False;
	}

	ICE_Substate_Loop();

	GAME.current = state->parent;
	

}

ICE_State * ICE_State_Main()
{
	return &GAME.state_main;
}

void ICE_State_Destroy(ICE_State * state)
{
	if(!state->isFree)
	{
		ICE_LabelManager_Destroy(state);
		ICE_GuiManager_Destroy(state);
		ICE_Data_DestroyAll(state);
	}
}

void ICE_Substate_Loop()
{
	ICE_Input_Reset();
	ICE_State * current = GAME.current;



	ICE_Log(ICE_LOG_RUNNING, "Entering substate");
	
	if (!current->isPaused)
	{
		ICE_LabelManager_Init(NULL);
		ICE_GuiManager_Init(NULL);
		ICE_EntityManager_Init(NULL);
		current->func_create();
	}
	else
		if (current->func_OnResume != NULL)
			current->func_OnResume();

	while (!CORE.window.input.quit && !GAME.current->quit)
	{
		ICE_Time_Start();
		ICE_Input_Return();
		ICE_Render_SetColor(current->background);
		ICE_Render_Clear();

		current->func_update();

		// RENDER HERE
		ICE_Draw_Entity();
		ICE_Draw_LabelWorld();
		ICE_Draw_Gui();
		ICE_Draw_LabelScreen();
		ICE_Render_Now();
		ICE_Time_End();
	}

	if (!current->isPaused)
	{
		current->func_destroy();
		current->isFree = ICE_True;
		ICE_LabelManager_Destroy(NULL);
		ICE_GuiManager_Destroy(NULL);
		ICE_EntityManager_Destroy(NULL);
		ICE_Data_DestroyAll(NULL);
		ICE_ObjectManager obj = { 0 };
		current->object = obj;
	}
	else
		if(current->func_OnPause != NULL)
			current->func_OnPause();

	ICE_Log(ICE_LOG_RUNNING, "Leaving substate");

	ICE_Input_Reset();
}

ICE_State * ICE_State_GetParent(ICE_State * state)
{
	if (!state)
		state = GAME.current;


	if(state->parent)
		return state->parent;
	ICE_Log(ICE_LOG_CRITICAL, "No Parent State");
	return state;
}

ICE_String ICE_State_CurrentName()
{
	return GAME.current->name;
}
