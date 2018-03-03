#include "hdr/Render.h"

#include "hdr/TypesCore.h"

extern ICE_Game game;

int ICE_RenderSetColor(const ICE_Color rgba_hex) {
	const int r = rgba_hex >> 24 & 255;
	const int g = rgba_hex >> 16 & 255;
	const int b = rgba_hex >> 8 & 255;
	const int a = rgba_hex & 255;
	return SDL_SetRenderDrawColor(game.window.render, r, g, b, a);
}