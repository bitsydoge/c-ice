#include "hdr/Window.h"

#include <SDL2/SDL.h>
#include "hdr/TypesCore.h"

extern ICE_Game game;

void ICE_WindowSetSize(int w, int h)
{
	SDL_SetWindowSize(game.window.handle, w, h);
	game.window.w = w; game.window.h = h;
	game.camera.w = w; game.camera.h = h;
}

void ICE_WindowResizable(ICE_Bool yn)
{
	SDL_SetWindowResizable(game.window.handle, yn);
}

void ICE_WindowFullscreen(ICE_Bool yn)
{
	SDL_SetWindowFullscreen(game.window.handle, yn);
}

void ICE_WindowTitle(const char *title)
{
	SDL_SetWindowTitle(game.window.handle, title);
}

void ICE_WindowSetIcon(char * path)
{
	if (!path) {

#include "raw/Raw_icon.c"
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
		int shift = (ice_raw_img_icon.bytes_per_pixel == 3) ? 8 : 0;
		Uint32 rmask = 0xff000000 >> shift;
		Uint32 gmask = 0x00ff0000 >> shift;
		Uint32 bmask = 0x0000ff00 >> shift;
		Uint32 amask = 0x000000ff >> shift;
#else // little endian, like x86
		Uint32 rmask = 0x000000ff;
		Uint32 gmask = 0x0000ff00;
		Uint32 bmask = 0x00ff0000;
		Uint32 amask = (ice_raw_img_icon.bytes_per_pixel == 3) ? 0 : 0xff000000;
#endif

		SDL_Surface* icon = SDL_CreateRGBSurfaceFrom((void*)ice_raw_img_icon.pixel_data, ice_raw_img_icon.width,
			ice_raw_img_icon.height, ice_raw_img_icon.bytes_per_pixel * 8, ice_raw_img_icon.bytes_per_pixel*ice_raw_img_icon.width,
			rmask, gmask, bmask, amask);

		SDL_SetWindowIcon(game.window.handle, icon);

		SDL_FreeSurface(icon);
	}
	else
	{
		SDL_Surface *icon = SDL_LoadBMP(path);
		SDL_SetWindowIcon(game.window.handle, icon);
		SDL_FreeSurface(icon);
	}
}

int ICE_WindowGetW()
{
	return game.window.w;
}
int ICE_WindowGetH()
{
	return game.window.h;
}