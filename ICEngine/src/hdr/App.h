#ifndef DEF_ICE_APP
#define DEF_ICE_APP
#include "Input.h"

typedef struct
{
    SDL_Window *window;
    SDL_Renderer *render;
    ICE_Input *input;
    unsigned int w, h;

} ICE_App;

ICE_App ICE_CreateApp(char *window_title, unsigned int width_window, unsigned int height_window);
void ICE_DestroyApp(ICE_App *app);


#endif