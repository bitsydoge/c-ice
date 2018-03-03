#include "hdr/Render_private.h"

#include <SDL2/SDL.h>
#include "hdr/TypesCore.h"

extern ICE_Game game;

int ICE_RenderClear() {
	return SDL_RenderClear(game.window.render);
}
void ICE_RenderNow() {
	SDL_RenderPresent(game.window.render);
}