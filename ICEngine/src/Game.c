#include "hdr/Game.h"

#include "hdr/TypesMaths.h"
#include "hdr/TypesCore.h"

extern ICE_Game game;

ICE_Float ICE_GameDelta()
{
	return game.time.delta;
}

ICE_Float ICE_GameFps()
{
	return game.time.fps;
}