#include "hdr/Debug.h"
#include "hdr/TypesCore.h"

extern ICE_Game game;

void ICE_Debug(const ICE_Bool yn)
{
	game.debug = yn;
}
