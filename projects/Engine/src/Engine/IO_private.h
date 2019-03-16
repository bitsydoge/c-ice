#ifndef DEF_ICE_PRIVATE_IO_H
#define DEF_ICE_PRIVATE_IO_H

#include "IO.h"

#include <SDL2/SDL.h>

struct ICE_RWops
{
	SDL_RWops * sdl2;
};

ICE_IO* ICE_IO_MakeFromSDL2(SDL_RWops* rwops_);

#endif