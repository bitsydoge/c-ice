#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "TypesCore.h"
#include "../Graphics/Color_private.h"

extern ICE_Asset asset;
extern ICE_Game game;

void ICE_Label_UpdateTexture(ICE_Label * label)
{
	SDL_Surface *surf = TTF_RenderText_Blended(
		asset.font.size[label->size],
		label->text,
		ICE_Color_ToSdl(label->color)
	);

	ICE_Texture texture = { 0 };

	texture.handle = SDL_CreateTextureFromSurface(game.window.render, surf);
	texture.w = surf->w; texture.h = surf->h;
	if (label->texture.exist)
	{
		SDL_DestroyTexture(label->texture.handle);
	}
	label->texture = texture;
	label->texture.exist = ICE_True;
	SDL_FreeSurface(surf);
}
