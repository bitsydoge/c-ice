#ifndef DEF_ICE_CONVERTER
#define DEF_ICE_CONVERTER

////////////////////////////////////
//      Converter ice<->sdl       //
////////////////////////////////////

#include <SDL2/SDL.h>
#include "StructMaths.h"

/// iceBox to SDL_Rect
iceBox sdlRectToICE(SDL_Rect *rect);
/// SDL_Rect to iceBox
SDL_Rect iceRectToSDL(iceBox *rect);

////////////////////////////////////

#endif
