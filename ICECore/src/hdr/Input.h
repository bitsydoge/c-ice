#ifndef DEF_ICE_INPUT
#define DEF_ICE_INPUT

#include "Struct.h"
#include <string.h>
#include <stdio.h>
#include "Terminal.h"
#include "../external/rlutil.h"

int iceInputReturn(iceGame *game, iceInput *input);
void iceInputReset(iceInput *input);

#endif