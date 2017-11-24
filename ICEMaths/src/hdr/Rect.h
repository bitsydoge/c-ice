#ifndef DEF_ICE_RECT
#define DEF_ICE_RECT

#include <SDL2/SDL.h>
#include "TypesMaths.h"

// Creation
iceRect iceRectNew(iceFloat x, iceFloat y, iceFloat w, iceFloat h);

// Math
iceRect iceRectScale(iceRect rect, iceFloat scale);

// Edit
void iceRectSetPos(iceRect * rect, iceFloat x, iceFloat y);
void iceRectSetSize(iceRect * rect, iceFloat w, iceFloat h);
void iceRectShift(iceRect * rect, iceFloat x, iceFloat y);

#endif
