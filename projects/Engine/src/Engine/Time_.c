#include "Time_.h"

#include "../Framework/BasicTypes.h"

#include "Time_private.h"

#include "../External/SDL2_gfx/SDL2_framerate.h"
#include "../Framework/Log.h"

#include "Config.h"

#include "GlobalData_private.h"
#include <time.h>
ICE_GLOBALDATA_CONFIG

ICE_Time ICE_GLOBJ_TIME = { 0 };

///////////// PRIVATE

FPSmanager fps_manager_global;

void ICE_Time_Init()
{
	SDL_initFramerate(&fps_manager_global);
	if (SDL_setFramerate(&fps_manager_global, ICE_GLOBJ_CONFIG.refresh_rate) == -1)
		ICE_Log(ICE_LOGTYPE_ERROR, "SDL_Gfx -> SDL_setFramerate");
}

void ICE_Time_Start()
{
	/*
	GAME.time.actual = SDL_GetTicks(); // ticks since start of software at the start of loop
	GAME.time.ticksEllapsed = GAME.time.actual - GAME.time.last; // calculate nb of ticks ellapsed
	GAME.time.delta = (double)GAME.time.ticksEllapsed / 1000.0; // update the time.delta
	//if (GAME.time.ticksEllapsed > GAME.time.ticks) {// if the ticks ellapsed is superiore to the ticks for a frame it run the loop
	if (GAME.time.ticksEllapsed)
		GAME.time.fps = (double)(1000.0 / GAME.time.ticksEllapsed); // calculate fps
	*/
}

void ICE_Time_End()
{

#define NB_COUNT_FPS 25
#define TIME_BETWEEN_UPDATE 6.9444444444444

	static double fps_count[NB_COUNT_FPS];
	static int fps_actual_to_fill = 0;
	static ICE_Bool trigger_fpsblock = ICE_False;
	ICE_Uint32 elapsedMS = SDL_framerateDelay(&fps_manager_global);
	ICE_GLOBJ_TIME.delta = (ICE_Float) elapsedMS / 1000.0;

	fps_count[fps_actual_to_fill] = 1000.0 / (ICE_Float)elapsedMS;
	fps_actual_to_fill++;
	if (fps_actual_to_fill >= NB_COUNT_FPS || fps_actual_to_fill < 0)
	{
		fps_actual_to_fill = 0;
		trigger_fpsblock = ICE_True;
	}

	static int time_to_refresh = 0;
	time_to_refresh += elapsedMS;

	if (time_to_refresh > 1000 || !trigger_fpsblock)
	{
		ICE_Float somme = 0;
		for (int i = 0; i < NB_COUNT_FPS; i++)
			somme += fps_count[i];
		ICE_GLOBJ_TIME.fps = (ICE_Float)somme / NB_COUNT_FPS;
		time_to_refresh = 0;
	}

	/*
	GAME.time.last = GAME.time.actual;
	*/
}

// Public

ICE_Uint64 ICE_Time_GetMS()
{
	return (ICE_Float)clock();
}

ICE_Float ICE_Time_GetS()
{
	return (ICE_Float)clock() / 1000.0;
}