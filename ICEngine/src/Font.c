#include "hdr/Font.h"

void ICE_FontLoad(ICE_Game* game, char *path)
{
	for (int i = 0; i < 256; i++)
	{
		game->fontmanager.size[i] = TTF_OpenFont(path, i);
		if(!game->fontmanager.size)
		 printf("%s\n", TTF_GetError());
	}
}

void ICE_FontDraw(ICE_Game* game, char* text,int size, ICE_Rect rect)
{
	SDL_Color col; col.r = 255; col.g = 255; col.b = 255; col.a = 255;
	SDL_Surface *surf = TTF_RenderText_Blended(game->fontmanager.size[size], text, col);
	rect.w = surf->w; rect.h = surf->h;
	SDL_Texture *texture = SDL_CreateTextureFromSurface(game->render, surf);
	SDL_RenderCopy(game->render, texture, NULL, &rect);
	SDL_FreeSurface(surf);
	SDL_DestroyTexture(texture);
}
