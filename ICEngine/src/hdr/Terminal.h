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

void iceTermSaveColor();
void iceTermResetColor();
void iceTermSetColor(int c);
void iceTermSetBgColor(int c);

#endif