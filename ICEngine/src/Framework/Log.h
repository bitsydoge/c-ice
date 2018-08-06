#ifndef DEF_ICE_LOG
#define DEF_ICE_LOG

/**
 * \brief Different log types and how they are showed
 */
enum ICE_LogTypes
{
	ICE_LOG_CRITICAL = -3,
	ICE_LOG_ERROR = -2,
	ICE_LOG_WARNING = -1,

	ICE_LOG_NONE = 0,

	ICE_LOG_SUCCES = 1,

	ICE_LOG_RUNNING = 2
}; typedef enum ICE_LogTypes ICE_LogTypes;

#if defined(_DEBUG)

/**
 * \brief Show a log with time and can be formated
 * \param type Log type
 * \param format Formated string
 * \param ... Args of the formated string
 */
void ICE_Log(ICE_LogTypes type, const char * format, ...);
void ICE_Log_NoReturn(ICE_LogTypes type, const char * format, ...);

#else
#define ICE_Log(...)
#define ICE_Log_NoReturn()
#endif

#endif
