#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>

#include "TypesCore.h"
#include "../Graphics/Color_private.h"

extern ICE_Asset asset;
extern ICE_Game game;

void ICE_Label_UpdateTexture(ICE_Label * label)
{
	SDL_Surface *surf;
	if(label->wrap_width == 0)
	{
		surf = TTF_RenderUNICODE_Blended(
			asset.font.size[label->size],
			label->text,
			ICE_Color_ToSdl(label->color)
		);
	}
	else
	{
		surf = TTF_RenderUNICODE_Blended_Wrapped(
			asset.font.size[label->size],
			label->text,
			ICE_Color_ToSdl(label->color),
			label->wrap_width
		);
	}

	ICE_Texture texture = { 0 };

	texture.handle = SDL_CreateTextureFromSurface(game.window.render, surf);
	if (texture.handle)
	{
		texture.w = surf->w; texture.h = surf->h;
		if (label->texture.exist)
		{
			SDL_DestroyTexture(label->texture.handle);
		}
		label->texture = texture;
		label->texture.exist = ICE_True;
		SDL_FreeSurface(surf);
	}
}
