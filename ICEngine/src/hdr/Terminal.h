#ifndef DEF_ICE_TERMINALCOLOR
#define DEF_ICE_TERMINALCOLOR

#include "../external/rlutil.h"

void ICE_TermSaveColor();
void ICE_TermResetColor();
void ICE_TermSetColor(int c);
void ICE_TermSetBgColor(int c);

#endif