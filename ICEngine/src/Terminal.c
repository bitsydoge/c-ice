#include "hdr/Terminal.h"
#include "external/rlutil.h"
#include "hdr/TypesCore.h"
#include "hdr/Time_.h"
#include "hdr/Log.h"

extern ICE_Game game;

extern ICE_Bool debug_ok;

void ICE_Term_ResetColor(){
	if (debug_ok)
		resetColor();
}
void ICE_Term_SetColor(const int c){
	if (debug_ok)
		setColor(c);
}
void ICE_Term_SetBgColor(const int c){
	if (debug_ok)
		setBackgroundColor(c);
}

void ICE_Term_Clear(){
	if (debug_ok)
		cls();
}

void ICE_Term_Clock(){
	if (debug_ok)
	{
		ICE_Term_SetColor(iceLIGHTCYAN);
		printf("[%.3f s]", ICE_Time_Clock());
		ICE_Term_ResetColor();
		printf("::");
	}
}

void ICE_Term_Wait(){
	if (debug_ok)
	{
		ICE_Log_NoReturn(ICE_LOG_NONE, "TERMINAL]::[PRESSRETURNTOCONTINUE");
		#ifdef getch
		getch();
		puts("");
		#else
		getchar();
		#endif
	}
}