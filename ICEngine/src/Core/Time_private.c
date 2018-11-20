#include "Time_private.h"
#include "TypesCore.h"

#include "../External/SDL2_gfx/SDL2_framerate.h"
#include "Timer.h"

extern ICE_Game GAME;
extern ICE_Core CORE;
extern ICE_Config CONFIG;

FPSmanager fps_manager_global;
ICE_Timer limiter;
ICE_Uint32 fps = 60;

void ICE_Time_Init()
{
	SDL_initFramerate(&fps_manager_global);
	if(SDL_setFramerate(&fps_manager_global, CONFIG.refresh_rate) == -1)
		ICE_Log(ICE_LOG_ERROR, "SDL_Gfx -> SDL_setFramerate");
}

void ICE_Time_Start()
{	
	ICE_Timer_Start(&limiter);
}

void ICE_Time_End()
{

#define NB_COUNT_FPS 25
#define TIME_BETWEEN_UPDATE 6.9444444444444

	static double fps_count[NB_COUNT_FPS];
	static int fps_actual_to_fill = 0;
	static ICE_Bool trigger_fpsblock = ICE_False;
	Uint32 elapsedMS = SDL_framerateDelay(&fps_manager_global);
	CORE.time.delta = (ICE_Float) elapsedMS / 1000.0;
	
	fps_count[fps_actual_to_fill] = 1000.0 / (ICE_Float)elapsedMS;
	fps_actual_to_fill++;
	if (fps_actual_to_fill > NB_COUNT_FPS || fps_actual_to_fill < 0)
	{
		fps_actual_to_fill = 0;
		trigger_fpsblock = ICE_True;
	}
		
	static int time_to_refresh = 0;
	time_to_refresh += elapsedMS;

	if(time_to_refresh > 1000 || !trigger_fpsblock)
	{
		ICE_Float somme = 0;
		for (int i = 0; i < NB_COUNT_FPS; i++)
			somme += fps_count[i];
		CORE.time.fps = (ICE_Float)somme / NB_COUNT_FPS;
		time_to_refresh = 0;
	}
}
