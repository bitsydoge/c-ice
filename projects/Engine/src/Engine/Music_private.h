#ifndef DEF_ICE_MUSIC_PRIVATE_H
#define DEF_ICE_MUSIC_PRIVATE_H

#include "SDL2_Includer_private.h"
#include ICE_INCLUDE_SDL2_MIXER

#include "../Framework/String_.h"
#include "IO.h"

struct ICE_Music
{

	Mix_Music* sdl_handle;
	ICE_String filename;

}; typedef struct ICE_Music ICE_Music;

ICE_Music ICE_Music_Build_RW(ICE_IO ops);
ICE_Music* ICE_Music_Get(ICE_ID music_);

#endif