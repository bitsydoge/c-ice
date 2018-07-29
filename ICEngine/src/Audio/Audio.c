#include "Audio.h"

#if defined(__APPLE__)
#include <SDL2_mixer/SDL_mixer.h>
#else
#include <SDL2/SDL_mixer.h>
#endif

void ICE_Audio_Init()
{
	Mix_Init(MIX_INIT_OGG);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
	Mix_AllocateChannels(20);
	Mix_VolumeMusic(5);
}

void ICE_Audio_Close()
{
	Mix_CloseAudio();
}
