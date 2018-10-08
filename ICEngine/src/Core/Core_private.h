#ifndef DEF_ICE_CORE_PRIVATE
#define DEF_ICE_CORE_PRIVATE

/**
 * \brief Init everything for the engine
 * \return 0
 */
int ICE_Core_Init();

#if defined(_DEBUG)
void ICE_Core_Info(char * title);
#else
void ICE_Core_Info(char * title);
#endif

/**
 * \brief Close everything for the engine
 * \return 0
 */
int ICE_Core_Close();

#endif
