#ifndef DEF_ICE_DATA
#define DEF_ICE_DATA
#include "Game.h"

void* iceAddData(iceGame *game, size_t _size);
void* iceGetData(iceGame *game, int nb_data);
void iceDestroyData(iceGame *game, int nb_data);

#endif
