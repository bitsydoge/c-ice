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
	//iceTextureManagerCreate(&game);

	// Time
	memset(&game.time, 0, sizeof(iceTime));
	game.time.fps = 120; game.time.ticks = (double)1000 / game.time.fps;

	// Sound
	iceSoundManagerCreate(&game); // Create the Sound Manager

	game.camera.x = 0; game.camera.y = 0;
	game.camera.w = width_window; game.camera.h = height_window;
	iceWindowSetIcon(game.drawer.window, 0);

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