#include "hdr/Debug_private.h"

#include <stdlib.h>
#include <stdio.h>
#include "hdr/Terminal.h"
#include "hdr/Debug.h"


void ICE_Assert_(const char* expr_str, int expr, const char* file, int line, const char* msg)
{
	if (!expr)
	{
		ICE_Log(ICE_LOG_CRITICAL, "ASSERT");
		//ICE_TermSetColor(iceLIGHTRED);
		//printf("\n\n\t\t-------------------[ERROR]-------------------\t\t\n\n");
		//ICE_TermResetColor();
		printf("Assert Msg\t:\t");
		ICE_TermSetColor(iceLIGHTGREEN);
		printf("%s\n", msg);
		ICE_TermResetColor();
		printf("Expected\t:\t");
		ICE_TermSetColor(iceLIGHTMAGENTA);
		printf("%s\n", expr_str);
		ICE_TermResetColor();
		printf("Source File\t:\t");
		ICE_TermSetColor(iceYELLOW);
		printf("%s\n", file);
		ICE_TermResetColor();
		printf("At the Line\t:\t");
		ICE_TermSetColor(iceLIGHTCYAN);
		printf("%d\n\n", line);
		ICE_TermResetColor();
		//ICE_TermSetColor(iceLIGHTRED);
		//printf("\t\t-------------------[ERROR]-------------------\t\t\n");
		abort();
	}
}
