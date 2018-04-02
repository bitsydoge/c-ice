#include "Render.h"

#include "../Core/TypesCore.h"

extern ICE_Game game;

int ICE_Render_Clear() {
	return SDL_RenderClear(game.window.render);
}
void ICE_Render_Now() {
	SDL_RenderPresent(game.window.render);
}

void ICE_Render_AutoDraw(ICE_Bool yn)
{
	game.window.auto_render = yn;
}

void ICE_Render_AutoClear(ICE_Bool yn)
{
	game.window.auto_clear = yn;
}

void ICE_Render_Color(const ICE_Color rgba_hex) {
	game.window.background = rgba_hex;
}