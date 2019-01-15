#include "Game.h"

#include "TypesCore.h"

extern ICE_Core CORE;
extern ICE_Config CONFIG;

ICE_Float ICE_Game_GetDelta()
{
	return CORE.time.delta;
}

ICE_Float ICE_Game_GetFps()
{
	return CORE.time.fps;
}

ICE_StringStd ICE_Game_GetVersion()
{
	return CONFIG.game_version;
}