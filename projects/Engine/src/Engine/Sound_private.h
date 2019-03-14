#ifndef DEF_ICE_SOUND_PRIVATE_H
#define DEF_ICE_SOUND_PRIVATE_H

#include "../Framework/String_.h"
#include <SDL2/SDL_mixer.h>


struct ICE_Sound
{

	struct Mix_Chunk* sdl_handle;
	ICE_String filename;

}; typedef struct ICE_Sound ICE_Sound;

#endif