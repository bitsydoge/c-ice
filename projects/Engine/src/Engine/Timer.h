#ifndef DEF_ICE_TIMER_PRIVATE
#define DEF_ICE_TIMER_PRIVATE

#include "../Framework/BasicTypes.h"

struct ICE_Timer
{
	ICE_Uint32 start_ticks;
	ICE_Uint32 pause_ticks;
	ICE_Bool paused;
	ICE_Bool started;

};
typedef struct ICE_Timer ICE_Timer;

void ICE_Timer_Start(ICE_Timer * timer_);
void ICE_Timer_Stop(ICE_Timer * timer_);
void ICE_Timer_Pause(ICE_Timer * timer_);
void ICE_Timer_Unpause(ICE_Timer * timer_);
ICE_Uint32 ICE_Timer_GetTicks(ICE_Timer * timer_);
ICE_Bool ICE_Timer_isStarted(ICE_Timer * timer_);
ICE_Bool ICE_Timer_isPaused(ICE_Timer * timer_);

#endif