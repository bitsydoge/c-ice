#include "Render.h"

#include "../Core/TypesCore.h"

extern ICE_Game game;
extern ICE_Core core;

int ICE_Render_Clear() {
	return SDL_RenderClear(core.window.render);
}
void ICE_Render_Now() {
	SDL_RenderPresent(core.window.render);
}

void ICE_Render_AutoDraw(ICE_Bool yn)
{
	core.window.auto_render = yn;
}

void ICE_Render_AutoClear(ICE_Bool yn)
{
	core.window.auto_clear = yn;
}

void ICE_Render_Color(const ICE_Color rgba_hex) {
	game.current->background = rgba_hex;
}