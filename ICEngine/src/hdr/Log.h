#ifndef DEF_ICE_LOG
#define DEF_ICE_LOG

enum ICE_LogTypes
{
	ICE_LOG_CRITICAL = -3,
	ICE_LOG_ERROR = -2,
	ICE_LOG_WARNING = -1,

	ICE_LOG_NONE = 0,

	ICE_LOG_SUCCES = 1,

	ICE_LOG_RUNNING = 2
}; typedef enum ICE_LogTypes ICE_LogTypes;

void ICE_Log(ICE_LogTypes type, const char * format, ...);
void ICE_Log_NoReturn(ICE_LogTypes type, const char * format, ...);

#endif
