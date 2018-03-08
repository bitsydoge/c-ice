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
			ICE_TermClock();
			ICE_TermSetColor(iceLIGHTGREEN);
			printf("[SUCCES]");
			break;
		case ICE_LOG_NONE:
			ICE_TermClock();
			printf("[LOG]");
			break;
		case ICE_LOG_WARNING:
			ICE_TermClock();
			ICE_TermSetColor(iceYELLOW);
			printf("[WARNING]");
			break;
		case ICE_LOG_ERROR:
			ICE_TermClock();
			ICE_TermSetColor(iceLIGHTRED);

			printf("[ERROR]");
			break;
		case ICE_LOG_CRITICAL:
			ICE_TermClock();
			ICE_TermSetColor(iceRED);
			printf("[CRITICAL]");
			break;
		case ICE_LOG_RUNNING:
			ICE_TermClock();
			ICE_TermSetColor(iceLIGHTMAGENTA);
			printf("[RUNNING...]");
			break;
		default:
			ICE_TermClock();
			printf("[NOLOGTYPE]");
			break;
		}
		ICE_TermResetColor();
		printf("::[");
		vprintf(format, args);
		printf("]");
		printf("\n");
		va_end(args);
	}
}

void ICE_Log_no_n(ICE_LogTypes type, const char * format, ...)
{
	if (debug_ok)
	{
		va_list args;
		va_start(args, format);

		switch (type)
		{
		case ICE_LOG_SUCCES:
			ICE_TermClock();
			ICE_TermSetColor(iceLIGHTGREEN);
			printf("[SUCCES]");
			break;
		case ICE_LOG_NONE:
			ICE_TermClock();
			printf("[LOG]");
			break;
		case ICE_LOG_WARNING:
			ICE_TermClock();
			ICE_TermSetColor(iceYELLOW);
			printf("[WARNING]");
			break;
		case ICE_LOG_ERROR:
			ICE_TermClock();
			ICE_TermSetColor(iceLIGHTRED);

			printf("[ERROR]");
			break;
		case ICE_LOG_CRITICAL:
			ICE_TermClock();
			ICE_TermSetColor(iceRED);
			printf("[CRITICAL]");
			break;
		default:
			ICE_TermClock();
			printf("[NOLOGTYPE]");
			break;
		}
		ICE_TermResetColor();
		printf("::[");
		vprintf(format, args);
		printf("]");
		va_end(args);
	}
}