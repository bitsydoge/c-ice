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

	ICE_LOG_INFO = 0,

	ICE_LOG_SUCCES = 1,
	ICE_LOG_RUNNING = 2,
	ICE_LOG_FINISH = 3

}; typedef enum ICE_LogTypes ICE_LogTypes;

#if defined(_DEBUG)

	#define ICE_Log(TYPE, FORMAT, ...) ICE_Log_(0, __FILE__, __LINE__, TYPE, FORMAT, __VA_ARGS__)
	void ICE_Log_(int nb_tab, const char* file, int line, ICE_LogTypes type, const char * format, ...);

	#define ICE_Log_NoReturn(TYPE, FORMAT, ...) ICE_Log_NoReturn_(__FILE__, __LINE__, TYPE, FORMAT, __VA_ARGS__)
	void ICE_Log_NoReturn_(const char* file, int line, ICE_LogTypes type, const char * format, ...);

	#define ICE_Log_Printf(A, ...) printf(A, __VA_ARGS__)
	
	void ICE_Log_Line();

#else
	#define ICE_Log(...)
	#define ICE_Log_NoReturn(...)
	#define ICE_Log_Line()	
	#define ICE_Log_Printf(...)
#endif


#endif
