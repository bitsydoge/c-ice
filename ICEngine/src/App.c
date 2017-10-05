#include "hdr/App.h"
#include "hdr/Render.h"

ICE_App ICE_CreateApp(char *window_title, const unsigned int width_window, const unsigned int height_window)
{
    ICE_App app = {0};

    app.window = SDL_CreateWindow(window_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width_window, height_window, SDL_RENDERER_PRESENTVSYNC | SDL_WINDOW_RESIZABLE);
    app.render = SDL_CreateRenderer(app.window, -1, SDL_RENDERER_ACCELERATED);
    app.input = (ICE_Input*)malloc(sizeof(ICE_Input)); 
    ICE_SetRenderClearColor(app.render, 0x2bccf4ff);    
    ICE_InputReset(app.input);

    return app;    
}

void ICE_DestroyApp(ICE_App *app)
{
    SDL_DestroyWindow(app->window);
    SDL_DestroyRenderer(app->render);
    free(app->input);
}