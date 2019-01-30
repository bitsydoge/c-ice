#include "Assert_.h"

#include <stdio.h>
#include <stdlib.h>

#include "Log.h"
#include "Terminal.h"

#if defined(_DEBUG)

void ICE_Assert_(const char* expr_str, int expr, const char* file, int line, const char* msg)
{
	if (!expr)
	{
		ICE_Log_Line();
		puts("");
		ICE_Log(ICE_LOGTYPE_CRITICAL, "ASSERT");
		printf("\n Assert Msg\t:\t");
		ICE_Term_SetColor(ICE_TERMCOLOR_LIGHTGREEN);
		printf("%s\n", msg);
		ICE_Term_ResetColor();
		printf(" Expected\t:\t");
		ICE_Term_SetColor(ICE_TERMCOLOR_LIGHTMAGENTA);
		printf("%s\n", expr_str);
		ICE_Term_ResetColor();
		printf(" Source File\t:\t");
		ICE_Term_SetColor(ICE_TERMCOLOR_YELLOW);
		printf("%s\n", file);
		ICE_Term_ResetColor();
		printf(" At the Line\t:\t");
		ICE_Term_SetColor(ICE_TERMCOLOR_LIGHTCYAN);
		printf("%d\n\n", line);
		ICE_Term_ResetColor();
		ICE_Log_Line();
		abort();
	}
}

#endif