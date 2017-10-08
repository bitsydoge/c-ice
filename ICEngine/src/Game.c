#include "hdr/Game.h"
#include "hdr/Render.h"
#include "hdr/Type.h"
#include "stdio.h"

ICE_Game ICE_CreateApp(char *window_title, const unsigned int width_window, const unsigned int height_window)
{
	ICE_Game app = {0};
	app.texturemanager_size = 0;
	app.window = SDL_CreateWindow(window_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width_window, height_window, SDL_RENDERER_PRESENTVSYNC | SDL_WINDOW_RESIZABLE);
	app.render = SDL_CreateRenderer(app.window, -1, SDL_RENDERER_ACCELERATED);
	app.input = (ICE_Input*)calloc(1, sizeof(ICE_Input)); 
	ICE_SetRenderClearColor(app.render, 0x2bccf4ff);    

	SDL_RendererInfo info;
	SDL_GetRendererInfo(app.render, &info);
	printf("Graphic API : %s \n", info.name);

	return app;    
}

void ICE_DestroyApp(ICE_Game *app)
{
	SDL_DestroyWindow(app->window);
	SDL_DestroyRenderer(app->render);
	free(app->input);
}