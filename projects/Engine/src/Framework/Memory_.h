#ifndef DEF_ICE_MEMORY
#define DEF_ICE_MEMORY

#include <string.h>

void* ICE_Malloc(size_t _Size);
void* ICE_Calloc(size_t _Nb_Elem, size_t _Size);
void* ICE_Realloc(void* _Block, size_t _Size);
void ICE_Free(void* _Block);
#if defined(_DEBUG)
size_t ICE_Memory_NbFreeToDo();
#else
#define ICE_Memory_NbFreeToDo()
#endif

#endif