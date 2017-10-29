#include "hdr/Render.h"

int ICE_SetRenderClearColor(SDL_Renderer *render, const Uint32 rgba_hex)
{
	const int r = rgba_hex >> 24 & 255;
	const int g = rgba_hex >> 16 & 255;
	const int b = rgba_hex >> 8 & 255;
	const int a = rgba_hex & 255;
	
	return SDL_SetRenderDrawColor(render, r, g, b, a);
}

int ICE_RenderClear(SDL_Renderer *render)
{
	return SDL_RenderClear(render);
}

void ICE_RenderPresent(SDL_Renderer *render)
{
	SDL_RenderPresent(render);
}
