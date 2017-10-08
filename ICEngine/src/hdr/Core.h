#ifndef DEF_ICE_CORE
#define DEF_ICE_CORE
#include "Game.h"

int ICE_InitGameEngine();
int ICE_CloseGameEngine();
int ICE_GameLoop(ICE_Game(*call_create)(void), void(*call_update)(ICE_Game*), void(*call_destroy)(ICE_Game*));

#endif
