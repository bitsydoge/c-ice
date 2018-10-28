#include "Time_private.h"
#include "TypesCore.h"

#include "../External/SDL2_gfx/SDL2_framerate.h"
#include "../Framework/Log.h"

extern ICE_Game game;
extern ICE_Core core;

FPSmanager fps_manager_global;

void ICE_Time_Init()
{
	SDL_initFramerate(&fps_manager_global);
	if(SDL_setFramerate(&fps_manager_global, 144) == -1)
		ICE_Log(ICE_LOG_ERROR, "SDL_Gfx -> SDL_setFramerate");
}

void ICE_Time_Start()
{	
	/*
	game.time.actual = SDL_GetTicks(); // ticks since start of software at the start of loop
	game.time.ticksEllapsed = game.time.actual - game.time.last; // calculate nb of ticks ellapsed
	game.time.delta = (double)game.time.ticksEllapsed / 1000.0; // update the time.delta
	//if (game.time.ticksEllapsed > game.time.ticks) {// if the ticks ellapsed is superiore to the ticks for a frame it run the loop
	if (game.time.ticksEllapsed)
		game.time.fps = (double)(1000.0 / game.time.ticksEllapsed); // calculate fps
	*/
}

void ICE_Time_End()
{

#define NB_COUNT_FPS 25
#define TIME_BETWEEN_UPDATE 6.9444444444444

	static double fps_count[NB_COUNT_FPS];
	static int fps_actual_to_fill = 0;
	static ICE_Bool trigger_fpsblock = ICE_False;
	Uint32 elapsedMS = SDL_framerateDelay(&fps_manager_global);
	core.time.delta = (ICE_Float) elapsedMS / 1000.0;
	
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
		core.time.fps = (ICE_Float)somme / NB_COUNT_FPS;
		time_to_refresh = 0;
	}
	
	/*
	game.time.last = game.time.actual;
	*/
}
