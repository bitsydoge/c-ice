#include "Font.h"

#include "../Core/SDL2_Includer.h"
#include ICE_INCLUDE_SDL2_TTF

#include "TypesGraphics.h"
#include "Color_private.h"

#include "../Core/Window.h"
#include "../Framework/Log.h"
#include "../Maths/TypesMaths.h"

extern ICE_Game GAME;
extern ICE_Core CORE;
extern ICE_Asset ASSET;

ICE_FontID ICE_Font_Load(char *path)
{
	for (int i = 0; i < 256; i++) {
		ASSET.font.size[i] = TTF_OpenFont(path, i);
		if (!ASSET.font.size[i])
			ICE_Log(ICE_LOGTYPE_CRITICAL, "%s\n", TTF_GetError());
	}

	return 0;
}

#if defined(_DEBUG)
void ICE_Font_Draw(char* text, ICE_Vect vect, ICE_Color fg, ICE_Color bg) 
{
	int size = (int)((ICE_Float)ICE_Window_GetH() / 50.0);
	if (size < 12)
		size = 12;
	SDL_Surface *surf = TTF_RenderText_Shaded(ASSET.font.size[size], text, ICE_Color_ToSdl(fg), ICE_Color_ToSdl(bg));
	SDL_Rect rect; rect.x = (int)vect.x; rect.y = (int)vect.y;
	rect.w = surf->w; rect.h = surf->h;
	SDL_Texture *texture = SDL_CreateTextureFromSurface(CORE.window.render, surf);
	SDL_RenderCopy(CORE.window.render, texture, NULL, &rect);
	SDL_FreeSurface(surf);
	SDL_DestroyTexture(texture);
}
#endif