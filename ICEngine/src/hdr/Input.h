#ifndef DEF_ICE_INPUT
#define DEF_ICE_INPUT

#include "Struct.h"
#include <string.h>
#include <stdio.h>
#include "Terminal.h"
#include "../external/rlutil.h"

int ICE_InputReturn(ICE_Game *game, ICE_Input *input);
void ICE_InputReset(ICE_Input *input);

#endif