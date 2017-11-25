#include "hdr/Game.h"

iceGame iceGameCreate(char *window_title, const unsigned int width_window, const unsigned int height_window)
{
	iceGame game = {0};

	// Window and Render
	game.drawer.window = SDL_CreateWindow(
		window_title,
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		width_window,
		height_window,
		SDL_WINDOW_OPENGL | SDL_RENDERER_PRESENTVSYNC | SDL_WINDOW_RESIZABLE
	);
	game.drawer.render = SDL_CreateRenderer(game.drawer.window, -1, SDL_RENDERER_ACCELERATED);
	game.background = iceColorNew(0, 0, 0);
	// Render Info
	SDL_RendererInfo info;
	SDL_GetRendererInfo(game.drawer.render, &info);
	printf("Graphic API : %s \n", info.name);
	SDL_SetRenderDrawBlendMode(game.drawer.render, SDL_BLENDMODE_BLEND);

	// Input
	game.input = (iceInput*)calloc(1, sizeof(iceInput));

	// TextureManager
	game.texturemanager_size = 0;
	iceTextureManagerCreate(&game);

	// Time
	memset(&game.time, 0, sizeof(iceTime));
	game.time.fps = 120; game.time.ticks = (double)1000 / game.time.fps;

	// Sound
	iceSoundManagerCreate(&game); // Create the Sound Manager

	game.camera.x = 0; game.camera.y = 0;
	game.camera.w = width_window; game.camera.h = height_window;
	iceDrawerSetIcon(game.drawer.window, 0);

	game.data = malloc(0);
	game.nb_data = 0;
	return game;
}

void iceGameDestroy(iceGame *app)
{
	SDL_DestroyWindow(app->drawer.window);
	SDL_DestroyRenderer(app->drawer.render);
	free(app->input);
}

void iceDrawerResizable(iceGame *game, iceBool yn)
{
	SDL_SetWindowResizable(game->drawer.window, yn);
}

void iceDrawerTitle(iceGame *game, const char *title)
{
	SDL_SetWindowTitle(game->drawer.window, title);
}

void iceDrawerSetIcon(iceWindow *window, char * path)
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

		SDL_SetWindowIcon(window, icon);

		SDL_FreeSurface(icon);
	}
	else
	{
		SDL_Surface *icon = SDL_LoadBMP(path);
		SDL_SetWindowIcon(window, icon);
		SDL_FreeSurface(icon);
	}
}