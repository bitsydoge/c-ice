#include "hdr/App.h"

ICE_App ICE_CreateApp(char *window_title, unsigned int width_window, unsigned int height_window)
{
    ICE_App app = {0};
    app.window = SDL_CreateWindow(window_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width_window, height_window, SDL_RENDERER_PRESENTVSYNC | SDL_WINDOW_RESIZABLE);
    app.render = SDL_CreateRenderer(app.window, -1, SDL_RENDERER_ACCELERATED);
    return app;    
}