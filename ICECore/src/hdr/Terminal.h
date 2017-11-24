#ifndef DEF_ICE_TERMINALCOLOR
#define DEF_ICE_TERMINALCOLOR

#include "../external/rlutil.h"

void iceTermSaveColor();
void iceTermResetColor();
void iceTermSetColor(int c);
void iceTermSetBgColor(int c);

#endif