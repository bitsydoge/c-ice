#include "Memory_.h"

#include <stdlib.h>
#include "Log.h"
#include "Assert_.h"

#if defined(_DEBUG)
size_t _thing_to_free_ = 0;
#endif
void* ICE_Malloc(size_t size_)
{
	void* ptr = malloc(size_);
#if defined(_DEBUG)
	if (ptr == NULL)
	{
		ICE_Log(ICE_LOGTYPE_CRITICAL, "(Malloc) Failed to allocate memory");
		ICE_Assert(ptr != NULL, "(Malloc) Failed to allocate memory");
	}
	_thing_to_free_++;
#endif
	return ptr;
}

void* ICE_Calloc(size_t nb_elem_, size_t size_)
{
	void* ptr = calloc(nb_elem_, size_);
#if defined(_DEBUG)
	if (ptr == NULL)
	{
		ICE_Log(ICE_LOGTYPE_CRITICAL, "(Calloc) Failed to allocate memory");
		ICE_Assert(ptr != NULL, "(Calloc) Failed to allocate memory");
	}
	_thing_to_free_++;
#endif
	return ptr;
}

void* ICE_Realloc(void* block_, size_t size_)
{
	void* ptr = realloc(block_, size_);
#if defined(_DEBUG)
	if (ptr == NULL)
	{
		ICE_Log(ICE_LOGTYPE_CRITICAL, "(Realloc) Failed to reallocate memory");
		ICE_Assert(ptr != NULL, "(Realloc) Failed to reallocate memory");
	}
#endif
	return ptr;
}

void* ICE_ReallocZero(void* Bloc_, size_t oldSize_, size_t newSize_) 
{
	void* pNew = realloc(Bloc_, newSize_);
	if (newSize_ > oldSize_ && pNew) 
	{
		size_t diff = newSize_ - oldSize_;
		void* pStart = ((char*)pNew) + oldSize_;
		memset(pStart, 0, diff);
	}
	else
	{
		ICE_Log_Critical("(ReallocZero) Failed to reallocate memory");
		ICE_Assert(pNew != NULL, "(ReallocZero) Failed to reallocate memory");
	}
	return pNew;
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