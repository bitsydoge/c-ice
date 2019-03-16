#ifndef DEF_ICE_SOUND_PRIVATE_H
#define DEF_ICE_SOUND_PRIVATE_H

#include "../Framework/String_.h"
#include <SDL2/SDL_mixer.h>
#include "Sound.h"

struct ICE_Sound
{

	struct Mix_Chunk* sdl_handle;
	ICE_String filename;

};

ICE_Sound ICE_Sound_Build(char* path);
ICE_Sound* ICE_Sound_Get(ICE_ID sound_);

#endif