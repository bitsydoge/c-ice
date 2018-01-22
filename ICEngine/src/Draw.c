#include "hdr/Draw.h"

extern iceGame game;

void iceDrawSetColor(iceColor color)
{
	game.background = color;
}