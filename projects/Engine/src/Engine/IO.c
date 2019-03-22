#include "IO_private.h"
#include "../Framework/String_.h"

#include <SDL2/SDL.h>

ICE_IO ICE_IO_FromConstMem(const void* mem_, int size_)
{	 
	return (ICE_IO)SDL_RWFromConstMem(mem_, size_);
}

ICE_IO ICE_IO_FromFile(ICE_StringStd path_, ICE_StringStd mode_)
{
	return (ICE_IO)SDL_RWFromFile(path_, mode_);
}

ICE_IO ICE_IO_MakeFromSDL2(void * sdl_rwops_)
{
	return (ICE_IO)sdl_rwops_;
}