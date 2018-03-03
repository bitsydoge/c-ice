#ifndef DEF_ICE_TERMINALCOLOR
#define DEF_ICE_TERMINALCOLOR

enum {
	iceBLACK,
	iceBLUE,
	iceGREEN,
	iceCYAN,
	iceRED,
	iceMAGENTA,
	iceBROWN,
	iceGREY,
	iceDARKGREY,
	iceLIGHTBLUE,
	iceLIGHTGREEN,
	iceLIGHTCYAN,
	iceLIGHTRED,
	iceLIGHTMAGENTA,
	iceYELLOW,
	iceWHITE
};

void ICE_TermResetColor();

void ICE_TermSetColor(const int c);

void ICE_TermSetBgColor(const int c);

void ICE_TermClear();

void ICE_TermClock();

void ICE_TermWait();

#endif