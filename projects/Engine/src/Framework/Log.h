#ifndef DEF_ICE_LOG
#define DEF_ICE_LOG

/**
 * \brief Different log types and how they are showed
 */
enum ICE_LogTypes
{
	ICE_LOGTYPE_CRITICAL = -3,
	ICE_LOGTYPE_ERROR = -2,
	ICE_LOGTYPE_WARNING = -1,

	ICE_LOGTYPE_INFO = 0,

	ICE_LOGTYPE_SUCCES = 1,
	ICE_LOGTYPE_RUNNING = 2,
	ICE_LOGTYPE_FINISH = 3

}; typedef enum ICE_LogTypes ICE_LogTypes;

#if defined(_DEBUG)

	#define ICE_Log_Error(FORMAT, ...) ICE_Log(ICE_LOGTYPE_ERROR, FORMAT, __VA_ARGS__ )
	#define ICE_Log_Critical(FORMAT, ...) ICE_Log(ICE_LOGTYPE_CRITICAL, FORMAT, ...)
	#define ICE_Log_Warning(FORMAT, ...) ICE_Log(ICE_LOGTYPE_WARNING, FORMAT, ...)
	#define ICE_Log_Info(FORMAT, ...) ICE_Log(ICE_LOGTYPE_INFO, FORMAT, ...)
	#define ICE_Log_Succes(FORMAT, ...) ICE_Log(ICE_LOGTYPE_SUCCES, FORMAT, ...)
	#define ICE_Log_Running(FORMAT, ...) ICE_Log(ICE_LOGTYPE_RUNNING, FORMAT, ...)
	#define ICE_Log_Finish(FORMAT, ...) ICE_Log(ICE_LOGTYPE_FINISH, FORMAT, ...)
	#define ICE_Log(TYPE, FORMAT, ...) ICE_Log_(0, __FILE__, __LINE__, TYPE, FORMAT, __VA_ARGS__)
	void ICE_Log_(int nb_tab, const char* file, int line, ICE_LogTypes type, const char * format, ...);

	#define ICE_Log_NoReturn(TYPE, FORMAT, ...) ICE_Log_NoReturn_(__FILE__, __LINE__, TYPE, FORMAT, __VA_ARGS__)
	void ICE_Log_NoReturn_(const char* file, int line, ICE_LogTypes type, const char * format, ...);

	#define ICE_Log_Printf(A, ...) printf(A, __VA_ARGS__)
	
	void ICE_Log_Line();

#else
	#define ICE_Log_Error(FORMAT, ...) 
	#define ICE_Log_Critical(FORMAT, ...) 
	#define ICE_Log_Warning(FORMAT, ...) 
	#define ICE_Log_Info(FORMAT, ...) 
	#define ICE_Log_Succes(FORMAT, ...) 
	#define ICE_Log_Running(FORMAT, ...) 
	#define ICE_Log_Finish(FORMAT, ...) 
	#define ICE_Log(...)
	#define ICE_Log_NoReturn(...)
	#define ICE_Log_Line()	
	#define ICE_Log_Printf(...)
#endif


#endif
