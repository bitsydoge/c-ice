#ifndef DEF_iceRECT
#define DEF_iceRECT

#include <SDL2/SDL.h>
#include "Types.h"

////////////////////////////////////
//      Converter ice<->sdl        //
////////////////////////////////////

/// iceRect to SDL_Rect
iceRect sdlRectToICE(SDL_Rect *rect);
/// SDL_Rect to iceRect
SDL_Rect iceRectToSDL(iceRect *rect);

////////////////////////////////////

// Creation
iceRect iceRectNew(iceFloat x, iceFloat y, iceFloat w, iceFloat h);

// Math
iceRect iceRectScale(iceRect rect, iceFloat scale);

// Edit
void iceRectSetPos(iceRect * rect, iceFloat x, iceFloat y);
void iceRectSetSize(iceRect * rect, iceFloat w, iceFloat h);
void iceRectShift(iceRect * rect, iceFloat x, iceFloat y);

#endif
