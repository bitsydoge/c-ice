#include "hdr/Render.h"

#include "hdr/TypesCore.h"

extern ICE_Game game;

void ICE_RenderBgColor(const ICE_Color rgba_hex) {
	game.window.background = rgba_hex;
}