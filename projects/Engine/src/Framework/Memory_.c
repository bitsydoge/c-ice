#include "Memory_.h"

#include <stdlib.h>
#include "Log.h"
#include "Assert_.h"

#if defined(_DEBUG)
size_t _thing_to_free_ = 0;
#endif
void* ICE_Malloc(size_t _Size)
{
	void* ptr = malloc(_Size);
	if (ptr == NULL)
	{
		ICE_Log(ICE_LOGTYPE_CRITICAL, "Memory]::[Malloc]::[Failed");
		ICE_Assert(ptr != NULL, "(Malloc) Failed to allocate memory");
	}
#if defined(_DEBUG)
	_thing_to_free_++;
#endif
	return ptr;
}

void* ICE_Calloc(size_t _Nb_Elem, size_t _Size)
{
	void* ptr = calloc(_Nb_Elem, _Size);
	if (ptr == NULL)
	{
		ICE_Log(ICE_LOGTYPE_CRITICAL, "Memory]::[Calloc]::[Failed");
		ICE_Assert(ptr != NULL, "(Calloc) Failed to allocate memory");
	}
#if defined(_DEBUG)
	_thing_to_free_++;
#endif
	return ptr;
}

void* ICE_Realloc(void* _Block, size_t _Size)
{
	void* ptr = realloc(_Block, _Size);
	if (ptr == NULL)
	{
		ICE_Log(ICE_LOGTYPE_CRITICAL, "Memory]::[Realloc]::[Failed");
		ICE_Assert(ptr != NULL, "(Realloc) Failed to reallocate memory");
	}
	return ptr;
}

void ICE_Free(void* _Block)
{
	free(_Block);
#if defined(_DEBUG)
	_thing_to_free_--;
#endif
}

#if defined(_DEBUG)
size_t ICE_Memory_NbFreeToDo()
{
	if(_thing_to_free_ > 0)
	{
		ICE_Log(ICE_LOGTYPE_ERROR, "There is %d heap(s) to free", _thing_to_free_);
	}
	else
	{
		ICE_Log(ICE_LOGTYPE_SUCCES, "No heaps to free");
	}
	return _thing_to_free_;
}
#endif