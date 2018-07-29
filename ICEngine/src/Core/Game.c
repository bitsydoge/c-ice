#include "Game.h"

#include "TypesCore.h"

extern ICE_Game game;

ICE_Float ICE_Game_GetDelta()
{
	return game.time.delta;
}

ICE_Float ICE_Game_GetFps()
{
	return game.time.fps;
}