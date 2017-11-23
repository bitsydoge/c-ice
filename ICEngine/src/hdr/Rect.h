#ifndef DEF_iceRECT
#define DEF_iceRECT

#include <SDL2/SDL.h>
#include "Types.h"

/// iceRect to SDL_Rect
iceRect sdlRectToICE(SDL_Rect *rect);

/// SDL_Rect to iceRect
SDL_Rect iceRectToSDL(iceRect *rect);


#endif
