#include "hdr/Debug_private.h"

#include <stdlib.h>
#include <stdio.h>
#include "hdr/Terminal.h"
#include "hdr/Log.h"


void ICE_Assert_(const char* expr_str, int expr, const char* file, int line, const char* msg)
{
	if (!expr)
	{
		ICE_Log(ICE_LOG_CRITICAL, "ASSERT");
		//ICE_Term_SetColor(ICE_T_LIGHTRED);
		//printf("\n\n\t\t-------------------[ERROR]-------------------\t\t\n\n");
		//ICE_Term_ResetColor();
		printf("Assert Msg\t:\t");
		ICE_Term_SetColor(ICE_T_LIGHTGREEN);
		printf("%s\n", msg);
		ICE_Term_ResetColor();
		printf("Expected\t:\t");
		ICE_Term_SetColor(ICE_T_LIGHTMAGENTA);
		printf("%s\n", expr_str);
		ICE_Term_ResetColor();
		printf("Source File\t:\t");
		ICE_Term_SetColor(ICE_T_YELLOW);
		printf("%s\n", file);
		ICE_Term_ResetColor();
		printf("At the Line\t:\t");
		ICE_Term_SetColor(ICE_T_LIGHTCYAN);
		printf("%d\n\n", line);
		ICE_Term_ResetColor();
		//ICE_Term_SetColor(ICE_T_LIGHTRED);
		//printf("\t\t-------------------[ERROR]-------------------\t\t\n");
		abort();
	}
}
