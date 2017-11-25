#ifndef DEF_ICE_BOX
#define DEF_ICE_BOX

#include <SDL2/SDL.h>
#include "TypesMaths.h"
#include "StructMaths.h"

// Creation
iceBox iceBoxNew(iceFloat x, iceFloat y, iceFloat w, iceFloat h);

// Math
iceBox iceBoxScale(iceBox rect, iceFloat scale);

// Edit
void iceBoxSetPos(iceBox * rect, iceFloat x, iceFloat y);
void iceBoxSetSize(iceBox * rect, iceFloat w, iceFloat h);
void iceBoxShift(iceBox * rect, iceFloat x, iceFloat y);

#endif
