#include "Core_private.h"

#include "Time_private.h"
#include "TypesCore.h"
#include "Label.h"
#include "MacOS_.h"

#include "../Framework/Terminal_private.h"
#include "../Framework/Log.h"

#include "SDL2_Includer.h"
#include ICE_INCLUDE_SDL2
#include ICE_INCLUDE_SDL2_TTF

#include <stdio.h>

#include "../Audio/Audio.h"
#include "../Audio/Sound.h"
#include <string.h>
#include "Core.h"
#include "../Framework/Random.h"

ICE_Core CORE = { 0 } ;
extern ICE_Game GAME;
extern ICE_Config CONFIG;

int ICE_Core_Init() 
{
#if defined(_DEBUG) && defined (_MSC_VER)
	puts("");
#endif

	// Term Save before log
	ICE_Term_SaveColor();
	ICE_Term_HideCursor();
	ICE_Log_Line();
	ICE_Log(ICE_LOG_RUNNING, "Core Init ...");

	// SDL
	if(SDL_Init(SDL_INIT_VIDEO) == 0)
		ICE_Log(ICE_LOG_SUCCES, "Init SDL");
	else
		ICE_Log(ICE_LOG_SUCCES, "Init SDL : %s", SDL_GetError());
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

	// SDL_Mixer
	ICE_Audio_Init();

	// SDL_TTF
	if (TTF_Init() == 0)
		ICE_Log(ICE_LOG_SUCCES, "Init SDL_ttf");
	else
		ICE_Log(ICE_LOG_ERROR, "Init SDL_ttf : %s", TTF_GetError());
	
	// Random
	ICE_Random_Init();

	// SDL_gfx
	ICE_Time_Init();

	// Path
	char * basePath = SDL_GetBasePath();
	char * dataPath = SDL_GetPrefPath(CONFIG.editor_name, CONFIG.product_name);
	strcpy(CORE.basePath, basePath);
	strcpy(CORE.dataPath, dataPath);
	SDL_free(basePath);
	SDL_free(dataPath);

	// Hardware Info
	ICE_Log(ICE_LOG_INFO, "");
	ICE_Log_Printf("\n Platform: %s\n", SDL_GetPlatform());
	ICE_Log_Printf(" CPU: %d CORE %d MB L1\n", SDL_GetCPUCount(), SDL_GetCPUCacheLineSize());
	ICE_Log_Printf(" RAM: %d MB \n", SDL_GetSystemRAM());
	ICE_Log_Printf(" Screen Count : %d\n\n", SDL_GetNumVideoDisplays());
	ICE_Log_Printf(" ICE Compiled : %s\n", ICE_Core_GetCompiledVersion());
	ICE_Log_Printf(" ICE Linked : %s\n", ICE_Core_GetLinkedVersion());
	// SDL_TTF Version print
	const SDL_version *link_version_ttf = TTF_Linked_Version();
	ICE_Log_Printf(" Compiled: %d.%d.%d\n", SDL_TTF_MAJOR_VERSION, SDL_TTF_MINOR_VERSION, SDL_TTF_PATCHLEVEL);
	ICE_Log_Printf(" Linked: %d.%d.%d\n", link_version_ttf->major, link_version_ttf->minor, link_version_ttf->patch);
	// SDL_Mixer Version print
	const SDL_version *link_version_mixer = Mix_Linked_Version();
	ICE_Log_Printf(" Compiled: %d.%d.%d\n", SDL_MIXER_MAJOR_VERSION, SDL_MIXER_MINOR_VERSION, SDL_MIXER_PATCHLEVEL);
	ICE_Log_Printf(" Linked: %d.%d.%d\n", link_version_mixer->major, link_version_mixer->minor, link_version_mixer->patch);
	// SDL Version print
	ICE_Log_Printf(" Compiled: %d.%d.%d\n", SDL_MAJOR_VERSION, SDL_MINOR_VERSION, SDL_PATCHLEVEL);
	SDL_version linked;
	SDL_GetVersion(&linked);
	ICE_Log_Printf(" Linked: %d.%d.%d\n\n", linked.major, linked.minor, linked.patch);
	// SDL
	ICE_Log_Printf(" Execution Path: %s\n", CORE.basePath);
	ICE_Log_Printf(" Data Path: %s\n", CORE.dataPath);

#if defined(__APPLE__)
	//ICE_MacOS_SetWorkingDirectory(SDL_GetBasePath());
	ICE_Log_Printf("MacOS Resources Directory: %s\n\n", ICE_MacOS_GetResourcesDirectory());
#endif
	puts("");
	ICE_Log(ICE_LOG_FINISH, "Core Init");
	ICE_Log_Line();

	return 0;
}

int ICE_Core_Quit() 
{
	ICE_Log_Line();
	ICE_Log(ICE_LOG_RUNNING, "Core Quit ...");
	
	// SDL
	TTF_Quit();
	ICE_Log(ICE_LOG_SUCCES, "Quit SDL_TTF");
	ICE_Audio_Close();
	ICE_Log(ICE_LOG_SUCCES, "Quit SDL_Mixer");
	SDL_Quit();
	ICE_Log(ICE_LOG_SUCCES, "Quit SDL");

	ICE_Log(ICE_LOG_FINISH, "Core Quit");
	ICE_Log_Line();

#if defined(_DEBUG) && defined (_MSC_VER)
	puts("");
#endif

	return 0;
}
