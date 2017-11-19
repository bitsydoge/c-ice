#ifndef DEF_ICE_SUBSTATE
#define DEF_ICE_SUBSTATE

#include "Input.h"
#include "Game.h"

int ICE_SubstateLoop(ICE_Game* game, void(*call_create)(ICE_Game*), void(*call_update)(ICE_Game*), void(*call_destroy)(ICE_Game*));

#endif
