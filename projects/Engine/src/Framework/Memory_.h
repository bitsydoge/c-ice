#ifndef DEF_ICE_MEMORY
#define DEF_ICE_MEMORY

#include <string.h>

void* ICE_Malloc(size_t size_);
void* ICE_Calloc(size_t nb_elem_, size_t size_);
void* ICE_Realloc(void* block_, size_t size_);
void* ICE_ReallocZero(void* Bloc_, size_t oldSize_, size_t newSize_);
void ICE_Free(void* _Block);
#if defined(_DEBUG)
size_t ICE_Memory_NbFreeToDo();
#else
#define ICE_Memory_NbFreeToDo()
#endif

#endif