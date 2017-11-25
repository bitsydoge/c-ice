#include "hdr/Font.h"

// Font load

void iceFontLoad(iceGame* game, char *path){
	for (int i = 0; i < 256; i++){
		game->fontmanager.size[i] = TTF_OpenFont(path, i);
		if(!game->fontmanager.size)
		 printf("%s\n", TTF_GetError());
	}
}

// Unoptimized

void iceFontDraw(iceGame* game, char* text,int size, iceVect vect){
	SDL_Color col; col.r = 255; col.g = 255; col.b = 255; col.a = 255;
	SDL_Surface *surf = TTF_RenderText_Blended(game->fontmanager.size[size], text, col);
	SDL_Rect rect; rect.x = vect.x; rect.y = vect.y;
	rect.w = surf->w; rect.h = surf->h;
	SDL_Texture *texture = SDL_CreateTextureFromSurface(game->drawer.render, surf);
	SDL_RenderCopy(game->drawer.render, texture, NULL, &rect);
	SDL_FreeSurface(surf);
	SDL_DestroyTexture(texture);
}