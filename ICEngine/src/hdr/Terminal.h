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

void ICE_Term_ResetColor();
void ICE_Term_SetColor(const int c);
void ICE_Term_SetBgColor(const int c);
void ICE_Term_Clear();
void ICE_Term_Clock();
void ICE_Term_Wait();

#endif