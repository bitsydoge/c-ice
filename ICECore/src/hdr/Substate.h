#ifndef DEF_ICE_SUBSTATE
#define DEF_ICE_SUBSTATE

#include "Input.h"
#include "Game.h"

int iceSubstateLoop(iceGame* game, void(*call_create)(iceGame*), void(*call_update)(iceGame*), void(*call_destroy)(iceGame*));

#endif
