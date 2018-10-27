#include "Game.h"

#include "TypesCore.h"

extern ICE_Core core;

ICE_Float ICE_Game_GetDelta()
{
	return core.time.delta;
}

ICE_Float ICE_Game_GetFps()
{
	return core.time.fps;
}