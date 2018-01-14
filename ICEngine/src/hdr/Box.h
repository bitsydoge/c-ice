#ifndef DEF_ICE_BOX
#define DEF_ICE_BOX

#include "TypesMaths.h"

// Creation
iceBox iceBoxNew(iceFloat x, iceFloat y, iceFloat w, iceFloat h);

// Math
iceBox iceBoxScale(iceBox rect, iceFloat scale);

iceBool iceBoxCompare(iceBox box1, iceBox box2);
iceBool iceBoxCompareSize(iceBox box1, iceBox box2);
iceBool iceBoxComparePos(iceBox box1, iceBox box2);

// Edit
void iceBoxSetPos(iceBox * rect, iceFloat x, iceFloat y);
void iceBoxSetSize(iceBox * rect, iceFloat w, iceFloat h);
void iceBoxShift(iceBox * rect, iceFloat x, iceFloat y);

#endif
