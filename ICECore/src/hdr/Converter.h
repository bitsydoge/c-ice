#ifndef DEF_ICE_CONVERTER
#define DEF_ICE_CONVERTER

////////////////////////////////////
//      Converter ice<->sdl       //
////////////////////////////////////

#include <SDL2/SDL.h>
#include "StructMaths.h"

/// iceBox to SDL_Rect
iceBox iceConvertSdlToBox(SDL_Rect *rect);
/// SDL_Rect to iceBox
SDL_Rect iceConvertBoxToSdl(iceBox *rect);

////////////////////////////////////

#endif
