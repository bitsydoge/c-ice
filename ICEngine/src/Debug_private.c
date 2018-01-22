#include "hdr/Terminal.h"
#include <stdio.h>
#include <stdlib.h>

void iceAssert_(const char* expr_str, int expr, const char* file, int line, const char* msg)
{
	if (!expr)
	{
		iceTermSetColor(iceLIGHTRED);
		printf("\n\n\t\t-------------------[ERROR]-------------------\t\t\n\n");
		iceTermResetColor();
		printf("Assert Msg\t:\t");
		iceTermSetColor(iceLIGHTGREEN);
		printf("%s\n", msg);
		iceTermResetColor();
		printf("Expected\t:\t");
		iceTermSetColor(iceLIGHTMAGENTA);
		printf("%s\n", expr_str);
		iceTermResetColor();
		printf("Source File\t:\t");
		iceTermSetColor(iceYELLOW);
		printf("%s\n", file);
		iceTermResetColor();
		printf("At the Line\t:\t");
		iceTermSetColor(iceLIGHTCYAN);
		printf("%d\n\n", line);
		iceTermSetColor(iceLIGHTRED);
		printf("\t\t-------------------[ERROR]-------------------\t\t\n");
		abort();
	}
}
