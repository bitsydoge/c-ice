#include "Game.h"

#include "TypesCore.h"

extern ICE_Core CORE;

ICE_Float ICE_Game_GetDelta()
{
	return CORE.time.delta;
}

ICE_Float ICE_Game_GetFps()
{
	return CORE.time.fps;
}