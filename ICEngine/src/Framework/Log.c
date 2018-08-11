#include "Log.h"

#if defined(_DEBUG)

#include "Terminal.h"
#include "TypesFramework.h"

#include <stdarg.h>
#include <stdio.h>

// Log

void ICE_Log(ICE_LogTypes type, const char * format, ...)
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
		case ICE_LOG_RUNNING:
			ICE_Term_Clock();
			ICE_Term_SetColor(ICE_TERMCOLOR_LIGHTMAGENTA);
			printf("[RUNNING...]");
			break;
		default:
			ICE_Term_Clock();
			printf("[NOLOGTYPE]");
			break;
		}
		ICE_Term_ResetColor();
		printf("[");
		vprintf(format, args);
		printf("]");
		printf("\n");
		va_end(args);
}

void ICE_Log_NoReturn(ICE_LogTypes type, const char * format, ...)
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