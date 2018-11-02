#include "SDL2_Includer.h"

#include ICE_INCLUDE_SDL2
#include ICE_INCLUDE_SDL2_TTF

#include "TypesCore.h"
#include "../Graphics/Color_private.h"
#include "../Framework/Assert_.h"

extern ICE_Asset ASSET;
extern ICE_Core CORE;

void ICE_Label_UpdateTexture(ICE_Label * label)
{
	ICE_Assert(ASSET.font.size[100] != 0, "Font is probably not loaded or with an error");
	SDL_Surface *surf;
	if(label->wrap_width == 0)
	{
		surf = TTF_RenderText_Blended(
			ASSET.font.size[label->size],
			label->text,
			ICE_Color_ToSdl(label->color)
		);
	}
	else
	{
		surf = TTF_RenderText_Blended_Wrapped(
			ASSET.font.size[label->size],
			label->text,
			ICE_Color_ToSdl(label->color),
			label->wrap_width
		);
	}

	ICE_Texture texture = { 0 };

	texture.handle = SDL_CreateTextureFromSurface(CORE.window.render, surf);
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
