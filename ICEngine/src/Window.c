#include "hdr/Window.h"
#include <SDL2/SDL.h>

extern iceGame game;

void iceWindowSetSize(int w, int h)
{
	SDL_SetWindowSize(game.drawer.window, w, h);
	SDL_GetWindowSize(game.drawer.window, &game.camera.w, &game.camera.h);

}

void iceWindowResizable(iceBool yn)
{
	SDL_SetWindowResizable(game.drawer.window, yn);
}

void iceWindowFullscreen(iceBool yn)
{
	SDL_SetWindowFullscreen(game.drawer.window, yn);
}

void iceWindowTitle(const char *title)
{
	SDL_SetWindowTitle(game.drawer.window, title);
}

void iceWindowSetIcon(char * path)
{
	if (!path) {
#include "raw/Raw_icon.c"

		Uint32 rmask, gmask, bmask, amask;
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
		int shift = (iceraw_img_icon.bytes_per_pixel == 3) ? 8 : 0;
		rmask = 0xff000000 >> shift;
		gmask = 0x00ff0000 >> shift;
		bmask = 0x0000ff00 >> shift;
		amask = 0x000000ff >> shift;
#else // little endian, like x86
		rmask = 0x000000ff;
		gmask = 0x0000ff00;
		bmask = 0x00ff0000;
		amask = (iceraw_img_icon.bytes_per_pixel == 3) ? 0 : 0xff000000;
#endif

		SDL_Surface* icon = SDL_CreateRGBSurfaceFrom((void*)iceraw_img_icon.pixel_data, iceraw_img_icon.width,
			iceraw_img_icon.height, iceraw_img_icon.bytes_per_pixel * 8, iceraw_img_icon.bytes_per_pixel*iceraw_img_icon.width,
			rmask, gmask, bmask, amask);

		SDL_SetWindowIcon(game.drawer.window, icon);

		SDL_FreeSurface(icon);
	}
	else
	{
		SDL_Surface *icon = SDL_LoadBMP(path);
		SDL_SetWindowIcon(game.drawer.window, icon);
		SDL_FreeSurface(icon);
	}
}