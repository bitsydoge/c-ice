#include "Terminal.h"

#include "../External/rlutil.h"

#include "TypesFramework.h"
#include "Log.h"
#include <time.h>

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
		ICE_Term_SetColor(ICE_T_LIGHTCYAN);
		printf("[%.3f s]", clock());
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