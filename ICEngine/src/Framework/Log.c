#include "Log.h"

#if defined(_DEBUG)

#include "Terminal.h"
#include "TypesFramework.h"
#include "../External/rlutil/rlutil.h"

#include <stdarg.h>
#include <stdio.h>

void ICE_Log_Line()
{
	int nb = tcols();
	for(int i = 0; i < nb-1; i++)
		putchar('_');
	printf("\n");
}

void ICE_Log__(int nb_tab, const char* file, int line, ICE_LogTypes type, const char * format, ...)
{
		va_list args;
		va_start(args, format);
		ICE_Term_Clock();
		char * type_in_string;
		switch (type)
		{
		case ICE_LOG_NONE:
			ICE_Term_ResetColor();
			type_in_string = "<LOG>";
			break;
		case ICE_LOG_SUCCES:
			ICE_Term_SetColor(ICE_TERMCOLOR_LIGHTGREEN);
			type_in_string = "<SUCCES>";
			break;
		case ICE_LOG_WARNING:
			ICE_Term_SetColor(ICE_TERMCOLOR_YELLOW);
			type_in_string = "<WARNING>";
			break;
		case ICE_LOG_ERROR:
			ICE_Term_SetColor(ICE_TERMCOLOR_LIGHTRED);
			type_in_string = "<ERROR>";
			break;
		case ICE_LOG_CRITICAL:
			ICE_Term_SetColor(ICE_TERMCOLOR_RED);
			type_in_string = "<CRITICAL>";
			break;
		case ICE_LOG_RUNNING:
			ICE_Term_SetColor(ICE_TERMCOLOR_LIGHTMAGENTA);
			type_in_string = "<RUNNING...>";
			break;
		case ICE_LOG_FINISH:
			ICE_Term_SetColor(ICE_TERMCOLOR_LIGHTBLUE);
			type_in_string = "<FINISH>";
			break;
		default:
			ICE_Term_ResetColor();
			type_in_string = "<NOLOGTYPE>";
			break;
		}
		printf(" %s ", type_in_string);
		ICE_Term_ResetColor();
		vprintf(format, args);
		printf("\n");
		ICE_Term_ResetColor();

		va_end(args);
}

void ICE_Log_NoReturn__(ICE_LogTypes type, const char * format, ...)
{
		va_list args;
		va_start(args, format);

		switch (type)
		{
		case ICE_LOG_SUCCES:
			ICE_Term_Clock();
			ICE_Term_SetColor(ICE_TERMCOLOR_LIGHTGREEN);
			printf("[SUCCES]");
			break;
		case ICE_LOG_NONE:
			ICE_Term_Clock();
			printf("[LOG]");
			break;
		case ICE_LOG_WARNING:
			ICE_Term_Clock();
			ICE_Term_SetColor(ICE_TERMCOLOR_YELLOW);
			printf("[WARNING]");
			break;
		case ICE_LOG_ERROR:
			ICE_Term_Clock();
			ICE_Term_SetColor(ICE_TERMCOLOR_LIGHTRED);

			printf("[ERROR]");
			break;
		case ICE_LOG_CRITICAL:
			ICE_Term_Clock();
			ICE_Term_SetColor(ICE_TERMCOLOR_RED);
			printf("[CRITICAL]");
			break;
		default:
			ICE_Term_Clock();
			printf("[NOLOGTYPE]");
			break;
		}
		ICE_Term_ResetColor();
		printf("::[");
		vprintf(format, args);
		printf("]");
		va_end(args);
}

#endif