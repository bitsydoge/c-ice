#include "Memory_.h"

#include <stdlib.h>
#include "Log.h"
#include "Assert.h"

size_t _thing_to_free_ = 0;

void* ICE_Malloc(size_t _Size)
{
	void* ptr = malloc(_Size);
	if (ptr == NULL)
	{
		ICE_Log(ICE_LOG_CRITICAL, "Memory]::[Malloc]::[Failed");
		ICE_Assert(ptr != NULL, "(Malloc) Failed to allocate memory");
	}
	_thing_to_free_++;
	return ptr;
}

void* ICE_Calloc(size_t _Nb_Elem, size_t _Size)
{
	void* ptr = calloc(_Nb_Elem, _Size);
	if (ptr == NULL)
	{
		ICE_Log(ICE_LOG_CRITICAL, "Memory]::[Calloc]::[Failed");
		ICE_Assert(ptr != NULL, "(Calloc) Failed to allocate memory");
	}
	_thing_to_free_++;
	return ptr;
}

void* ICE_Realloc(void* _Block, size_t _Size)
{
	void* ptr = realloc(_Block, _Size);
	if (ptr == NULL)
	{
		ICE_Log(ICE_LOG_CRITICAL, "Memory]::[Realloc]::[Failed");
		ICE_Assert(ptr != NULL, "(Realloc) Failed to reallocate memory");
	}
	return ptr;
}

void ICE_Free(void* _Block)
{
	free(_Block);
	_thing_to_free_--;
}

size_t ICE_ThingToFree()
{
	if(_thing_to_free_ > 0)
	{
		ICE_Log(ICE_LOG_ERROR, "Memory]::[Free]::[ThereIsThingToFree]::[%d]", _thing_to_free_);
	}
	else
	{
		ICE_Log(ICE_LOG_SUCCES, "Memory]::[Free]::[NothingToFree");
	}
	return _thing_to_free_;
}