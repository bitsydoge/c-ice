#ifndef DEF_ICE_MUSIC_PRIVATE_H
#define DEF_ICE_MUSIC_PRIVATE_H

#include "SDL2_Includer.h"
#include ICE_INCLUDE_SDL2_MIXER

#include "../Framework/String_.h"

struct ICE_Music
{

	Mix_Music* sdl_handle;
	ICE_String filename;

}; typedef struct ICE_Music ICE_Music;


#endif