#include "Core_private.h"

#include "Time_private.h"
#include "TypesCore.h"
#include "Label.h"

#include "../Framework/Terminal_private.h"
#include "../Framework/Log.h"
#include "../Graphics/Gui.h"
#include "../Graphics/Texture.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../Audio/Audio.h"
#include "../Audio/Sound.h"
#include "../Audio/Music.h"
#include "Data.h"
#include "Entity.h"

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

	return 0;
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


	// SDL
	TTF_Quit();
	ICE_Audio_Close();
	SDL_Quit();

	ICE_Log(ICE_LOG_SUCCES, "Engine]::[Close]::[Finish");

	return 0;
}