#include "Timer.h"

#include <SDL2/SDL.h>

void ICE_Timer_Start(ICE_Timer * timer_)
{
	timer_->started = ICE_True;
	timer_->paused = ICE_False;
	timer_->start_ticks = SDL_GetTicks();
	timer_->pause_ticks = 0;
}

void ICE_Timer_Stop(ICE_Timer * timer_)
{
	timer_->started = ICE_False;
	timer_->paused = ICE_False;
	timer_->start_ticks = 0;
	timer_->pause_ticks = 0;
}

void ICE_Timer_Pause(ICE_Timer * timer_)
{
	if (timer_->started && !timer_->paused)
	{
		timer_->paused = ICE_True;
		timer_->pause_ticks = SDL_GetTicks() - timer_->start_ticks;
		timer_->start_ticks = 0;
	}
}

void ICE_Timer_Unpause(ICE_Timer * timer_)
{
	if (timer_->started && timer_->paused)
	{
		timer_->paused = ICE_False;
		timer_->start_ticks = SDL_GetTicks() - timer_->pause_ticks;
		timer_->pause_ticks = 0;
	}
}

ICE_Uint32 ICE_Timer_GetTicks(ICE_Timer * timer_)
{
	ICE_Uint32 time = 0;
	if (timer_->started)
	{
		if (timer_->paused)
			time = timer_->pause_ticks;
		else
			time = SDL_GetTicks() - timer_->start_ticks;
	}
	return time;
}

ICE_Bool ICE_Timer_isStarted(ICE_Timer * timer_)
{
	return timer_->started;
}

ICE_Bool ICE_Timer_isPaused(ICE_Timer * timer_)
{
	return timer_->paused;
}