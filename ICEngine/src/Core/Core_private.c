#include "Core_private.h"

#include "Time_private.h"
#include "TypesCore.h"
#include "Label.h"
#include "MacOS_.h"
#include "SDL2_Includer.h"

#include "../Framework/Terminal_private.h"
#include "../Framework/Log.h"
#include "../Graphics/Gui.h"
#include "../Graphics/Texture.h"

#include ICE_INCLUDE_SDL2
#include ICE_INCLUDE_SDL2_TTF

#include <stdio.h>

#include "../Audio/Audio.h"
#include "../Audio/Sound.h"
#include "../Audio/Music.h"
#include "Data.h"
#include "Entity.h"
#include "Asset_private.h"

extern ICE_Game game;

int ICE_Core_Init() {

	// Other
	ICE_Term_SaveColor();
	ICE_Log(ICE_LOG_RUNNING, "Engine]::[Init]::[Start");
	ICE_Term_HideCursor();

	// SDL
	SDL_Init(SDL_INIT_VIDEO);
	ICE_Audio_Init();
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
	TTF_Init();
	
	// SDL_gfx
	ICE_Time_Init();

	ICE_Core_Info();

	return 0;
}

void ICE_Core_Info()
{
		// SDL
		printf("\nExecution Path: %s\n", SDL_GetBasePath());
		printf("Data Path: %s\n", SDL_GetPrefPath("coldragon", "ice"));
        //ICE_MacOS_SetWorkingDirectory(SDL_GetBasePath());
		printf("MacOS Resources Directory: %s\n\n", ICE_MacOS_GetResourcesDirectory());
		
	
		//SDL_Version
		printf("SDL Compiled: %d.%d.%d\n", SDL_MAJOR_VERSION, SDL_MINOR_VERSION, SDL_PATCHLEVEL);
		SDL_version linked;
		SDL_GetVersion(&linked);
		printf("SDL Linked: %d.%d.%d\n", linked.major, linked.minor, linked.patch);
			//ttf
		const SDL_version *link_version_ttf = TTF_Linked_Version();
		printf("SDL_ttf Compiled: %d.%d.%d\n", SDL_TTF_MAJOR_VERSION, SDL_TTF_MINOR_VERSION, SDL_TTF_PATCHLEVEL);
		printf("SDL_ttf Linked: %d.%d.%d\n", link_version_ttf->major, link_version_ttf->minor, link_version_ttf->patch);
			//mixer
		const SDL_version *link_version_mixer = Mix_Linked_Version();
		printf("SDL_mixer Compiled: %d.%d.%d\n", SDL_MIXER_MAJOR_VERSION, SDL_MIXER_MINOR_VERSION, SDL_MIXER_PATCHLEVEL);
		printf("SDL_mixer Linked: %d.%d.%d\n", link_version_mixer->major, link_version_mixer->minor, link_version_mixer->patch);
		
		// Hardware
		printf("\nPlatform: %s\n", SDL_GetPlatform());
		printf("CPU: %d CORE %d MB L1\n", SDL_GetCPUCount(), SDL_GetCPUCacheLineSize());
		printf("RAM: %d MB \n", SDL_GetSystemRAM());


		int mode = 0; const char * profile;
		SDL_GL_GetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, &mode);
		if (mode == SDL_GL_CONTEXT_PROFILE_CORE)
			profile = "Core";
		else if (mode == SDL_GL_CONTEXT_PROFILE_COMPATIBILITY)
			profile = "Compatibility";
		else if (mode == SDL_GL_CONTEXT_PROFILE_ES)
			profile = "ES";
		else
			profile = "Unknown";

		printf("OpenGL Profile: %s\n", profile);
		printf("Screen: %d\n\n", SDL_GetNumVideoDisplays());
}

int ICE_Core_Close() 
{
	ICE_Log(ICE_LOG_RUNNING, "Engine]::[Close]::[Start");
	
	// Manager Clean
	ICE_LabelManager_DestroyAll(NULL);
	ICE_GuiManager_DestroyAll(NULL);
	ICE_EntityManager_DestroyAll(NULL);
	ICE_Data_DestroyAll(NULL);

	ICE_TextureManager_DestroyAll();
	ICE_SoundManager_DestroyAll();
	ICE_MusicManager_DestroyAll();

	ICE_Asset_Quit();

	// SDL
	TTF_Quit();
	ICE_Audio_Close();
	SDL_Quit();

	ICE_Log(ICE_LOG_SUCCES, "Engine]::[Close]::[Finish");

	return 0;
}
