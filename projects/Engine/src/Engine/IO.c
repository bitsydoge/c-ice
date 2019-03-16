#include "IO_private.h"
#include "../Framework/Memory_.h"
#include "../Framework/String_.h"

ICE_IO * ICE_IO_FromConstMem(const void* mem_, int size_)
{
	ICE_IO * temp = ICE_Malloc(sizeof(ICE_IO));
	temp->sdl2 = SDL_RWFromConstMem(mem_, size_);
	return temp;
}

ICE_IO * ICE_IO_FromFile(ICE_StringStd path_, ICE_StringStd mode)
{
	ICE_IO* temp = ICE_Malloc(sizeof(ICE_IO));
	temp->sdl2 = SDL_RWFromFile(path_, "rb");
	return temp;
}

ICE_IO * ICE_IO_MakeFromSDL2(SDL_RWops * rwops_)
{
	ICE_IO* temp = ICE_Malloc(sizeof(ICE_IO));
	temp->sdl2 = rwops_;
	return temp;
}

void ICE_IO_Destroy(ICE_IO* rwops_)
{
	ICE_Free(rwops_);
}