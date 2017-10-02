#include <SDL2/SDL.h>
#include "hdr/Texture.h"

int main(int argc, char* args[])
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window *window = SDL_CreateWindow("ICE", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 480, SDL_RENDERER_PRESENTVSYNC);
	SDL_Renderer *render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(render, 25, 200, 79, 255);
	ICE_Texture* texture = ICE_LoadPNG(render, "res/img/test.png");
	
	//ICE_Texture* texture2 = ICE_LoadBMPAlpha(render, "res/img/error.bmp", 0xff00c8ff);
	ICE_Texture* texture2 = ICE_LoadBMPAlpha(render, "res/img/error.bmp", ICE_Rgba(0, 200, 255, 105));

	while(1)
	{
		SDL_RenderClear(render);
		ICE_TextureRender(render, texture, NULL, NULL);
		ICE_TextureRender(render, texture2, NULL, NULL);
		SDL_RenderPresent(render);
	}

	return 0;
}
