#ifndef DEF_ICE_CONVERTER
#define DEF_ICE_CONVERTER

////////////////////////////////////
//      Converter ice<->sdl        //
////////////////////////////////////

#include "TypesMaths.h"
#include <SDL2/SDL.h>

/// iceRect to SDL_Rect
iceRect sdlRectToICE(SDL_Rect *rect);
/// SDL_Rect to iceRect
SDL_Rect iceRectToSDL(iceRect *rect);

////////////////////////////////////

#endif
