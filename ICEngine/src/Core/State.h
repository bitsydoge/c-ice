#ifndef DEF_ICE_STATE
#define DEF_ICE_STATE

#define ICE_DEFAULT_STATE_MNGR_SIZE 4

#include "TypesCore.h"


ICE_State ICE_State_Create(void(*func_create)(void), void(*func_update)(void), void(*func_destroy)(void));

void ICE_State_Change(ICE_State * state);

void ICE_State_Quit();

void ICE_State_Pause();

void ICE_State_ResumeCallback(ICE_State * state, void(*func_resume)(void));

void ICE_State_PauseCallback(ICE_State * state, void(*func_pause)(void));

ICE_Bool ICE_State_WasPaused();

void ICE_Substate_Start(ICE_State * state);

void ICE_State_Destroy(ICE_State * state);

void ICE_Substate_Loop();

ICE_State * ICE_State_GetParent(ICE_State * state);

#endif