#include "hdr/Font.h"

#include <stdio.h>
#include <SDL2/SDL_ttf.h>
#include "hdr/TypesCore.h"
#include "hdr/Window.h"
#include "hdr/TypesGraphics.h"
#include "hdr/Color_private.h"
#include "hdr/Log.h"

extern ICE_Game game;
extern ICE_Asset asset;

// Font load

void ICE_FontLoad(char *path) {
	for (int i = 0; i < 256; i++) {
		asset.font.size[i] = TTF_OpenFont(path, i);
		if (!asset.font.size[i])
			ICE_Log(ICE_LOG_CRITICAL, "%s\n", TTF_GetError());
	}
}

void ICE_FontDraw(char* text, ICE_Vect vect, ICE_Color fg, ICE_Color bg) {
	if (game.debug)
	{
		int size = (int)((ICE_Float)ICE_WindowGetH() / 50.0);
		if (size < 12)
			size = 12;
		SDL_Surface *surf = TTF_RenderText_Shaded(asset.font.size[size], text, ICE_ColorToSdl(fg), ICE_ColorToSdl(bg));
		SDL_Rect rect; rect.x = vect.x; rect.y = vect.y;
		rect.w = surf->w; rect.h = surf->h;
		SDL_Texture *texture = SDL_CreateTextureFromSurface(game.window.render, surf);
		SDL_RenderCopy(game.window.render, texture, NULL, &rect);
		SDL_FreeSurface(surf);
		SDL_DestroyTexture(texture);
	}
}