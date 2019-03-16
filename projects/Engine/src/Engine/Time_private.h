#ifndef DEF_ICE_TIME_PRIVATE
#define DEF_ICE_TIME_PRIVATE

struct ICE_Time 
{

	ICE_Float fps;
	ICE_Float delta;

}; typedef struct ICE_Time ICE_Time;

/**
 * \brief Init everything related to time
 */
void ICE_Time_Init();

/**
 * \brief Save everything before the main loop to measure time
 */
void ICE_Time_Start();

/**
 * \brief Return and calcul everything in need for time in GAME
 */
void ICE_Time_End();

#endif