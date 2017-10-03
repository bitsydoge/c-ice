#ifndef DEF_ICE_APP
#define DEF_ICE_APP

typedef struct
{
    SDL_Window *window;
    SDL_Renderer *render;
    ICE_Input *input;
    unsigned int w, h;

} ICE_App;

#endif