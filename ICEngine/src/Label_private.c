#include <SDL2/SDL.h>
#include "hdr/TypesCore.h"
#include "hdr/Color_private.h"

extern iceGame game;

void iceLabelUpdateTexture(int man, int text)
{
	SDL_Surface *surf = TTF_RenderText_Blended(
		game.fontmanager.size[game.labelmanager[man].text[text].size],
		game.labelmanager[man].text[text].text,
		iceColorToSdl(game.labelmanager[man].text[text].color)
	);
	iceTexture texture = { 0 };
	texture.handle = SDL_CreateTextureFromSurface(game.drawer.render, surf);
	texture.w = surf->w; texture.h = surf->h;
	if (game.labelmanager[man].text[text].texture.exist)
	{
		SDL_DestroyTexture(game.labelmanager[man].text[text].texture.handle);
	}
	game.labelmanager[man].text[text].texture = texture;
	game.labelmanager[man].text[text].texture.exist = iceTrue;
	SDL_FreeSurface(surf);
}
