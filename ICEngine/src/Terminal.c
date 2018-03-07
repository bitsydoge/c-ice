#include "hdr/Terminal.h"
#include "external/rlutil.h"
#include "hdr/TypesCore.h"
#include "hdr/Time_.h"
#include "hdr/Log.h"

extern ICE_Game game;

extern ICE_Bool debug_ok;

void ICE_TermResetColor(){
	if (debug_ok)
		resetColor();
}
void ICE_TermSetColor(const int c){
	if (debug_ok)
		setColor(c);
}
void ICE_TermSetBgColor(const int c){
	if (debug_ok)
		setBackgroundColor(c);
}

void ICE_TermClear(){
	if (debug_ok)
		cls();
}

void ICE_TermClock(){
	if (debug_ok)
	{
		ICE_TermSetColor(iceLIGHTCYAN);
		printf("[%.3f s]", ICE_TimeClock());
		ICE_TermResetColor();
		printf("::");
	}
}

void ICE_TermWait(){
	if (debug_ok)
	{
		ICE_Log_no_n(ICE_LOG_NONE, "TERMINAL]::[PRESSRETURNTOCONTINUE");
		#ifdef getch
		getch();
		puts("");
		#else
		getchar();
		#endif
	}
}