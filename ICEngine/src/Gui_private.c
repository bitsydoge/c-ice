#include <SDL2/SDL.h>
#include "hdr/TypesCore.h"
#include "hdr/Vector.h"
#include "hdr/Gui.h"

extern iceGame game;

void iceGuiCreateTextureCache(int man, int gui)
{
	iceTexture texture = { 0 };
	texture.handle = SDL_CreateTexture(game.drawer.render, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, game.guimanager[man].gui[gui].box.w, game.guimanager[man].gui[gui].box.h);
	SDL_SetRenderTarget(game.drawer.render, texture.handle);
	SDL_SetTextureBlendMode(texture.handle, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(game.drawer.render, 0, 0, 0, 0);
	SDL_RenderClear(game.drawer.render);
	iceBox box2 = game.guimanager[man].gui[gui].box;
	box2.p = iceVectNew(0, 0);
	iceGuiRect(game.guimanager[man].gui[gui].texturemanager, game.guimanager[man].gui[gui].texture_nb, box2);
	SDL_SetRenderTarget(game.drawer.render, NULL);
	if (game.guimanager[man].gui[gui].texture_cache.handle)
		SDL_DestroyTexture(game.guimanager[man].gui[gui].texture_cache.handle);
	game.guimanager[man].gui[gui].texture_cache = texture;
}
