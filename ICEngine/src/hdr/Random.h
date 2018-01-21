#ifndef DEF_ICE_TIME
#define DEF_ICE_TIME

#include <stdlib.h>
#include "TypesMaths.h"

/// Init Random / Only to use by user
/// when it's not used in the engine

void iceRandomInit();
int iceRandomInt(int min, int max);
iceFloat iceRandomFloat();

#endif
