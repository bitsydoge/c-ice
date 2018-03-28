#include "hdr/Log.h"

#include "hdr/Terminal.h"
#include "hdr/TypesCore.h"

#include <stdarg.h>
#include <stdio.h>

extern ICE_Game game;
extern ICE_Bool debug_ok;

// Log

void ICE_Log(ICE_LogTypes type, const char * format, ...)
{
	if (debug_ok)
	{
		va_list args;
		va_start(args, format);

		switch (type)
		{
		case ICE_LOG_SUCCES:
			ICE_Term_Clock();
			ICE_Term_SetColor(ICE_T_LIGHTGREEN);
			printf("[SUCCES]");
			break;
		case ICE_LOG_NONE:
			ICE_Term_Clock();
			printf("[LOG]");
			break;
		case ICE_LOG_WARNING:
			ICE_Term_Clock();
			ICE_Term_SetColor(ICE_T_YELLOW);
			printf("[WARNING]");
			break;
		case ICE_LOG_ERROR:
			ICE_Term_Clock();
			ICE_Term_SetColor(ICE_T_LIGHTRED);

			printf("[ERROR]");
			break;
		case ICE_LOG_CRITICAL:
			ICE_Term_Clock();
			ICE_Term_SetColor(ICE_T_RED);
			printf("[CRITICAL]");
			break;
		case ICE_LOG_RUNNING:
			ICE_Term_Clock();
			ICE_Term_SetColor(ICE_T_LIGHTMAGENTA);
			printf("[RUNNING...]");
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
		printf("\n");
		va_end(args);
	}
}

void ICE_Log_NoReturn(ICE_LogTypes type, const char * format, ...)
{
	if (debug_ok)
	{
		va_list args;
		va_start(args, format);

		switch (type)
		{
		case ICE_LOG_SUCCES:
			ICE_Term_Clock();
			ICE_Term_SetColor(ICE_T_LIGHTGREEN);
			printf("[SUCCES]");
			break;
		case ICE_LOG_NONE:
			ICE_Term_Clock();
			printf("[LOG]");
			break;
		case ICE_LOG_WARNING:
			ICE_Term_Clock();
			ICE_Term_SetColor(ICE_T_YELLOW);
			printf("[WARNING]");
			break;
		case ICE_LOG_ERROR:
			ICE_Term_Clock();
			ICE_Term_SetColor(ICE_T_LIGHTRED);

			printf("[ERROR]");
			break;
		case ICE_LOG_CRITICAL:
			ICE_Term_Clock();
			ICE_Term_SetColor(ICE_T_RED);
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
}