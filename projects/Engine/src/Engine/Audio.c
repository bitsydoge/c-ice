#include "Audio.h"

#include "SDL2_Includer.h"
#include ICE_INCLUDE_SDL2_MIXER

#include "../Framework/Log.h"

void ICE_Audio_Init()
{
	int error = 1;

	if (!Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
	{
		ICE_Log(ICE_LOGTYPE_ERROR, "SDL_Mixer -> Mix_OpenAudio : %s", Mix_GetError());
		error--;
	}

	if (Mix_Init(MIX_INIT_OGG) == 0)
	{
		ICE_Log(ICE_LOGTYPE_ERROR, "SDL_Mixer -> Mix_Init : %s", Mix_GetError());
		error--;
	}

	if (error == 1)
		ICE_Log(ICE_LOGTYPE_SUCCES, "Init SDL_Mixer : %d audio channels allocated", Mix_AllocateChannels(20));


	Mix_VolumeMusic(5);
}

void ICE_Audio_Close()
{
	Mix_CloseAudio();
}
