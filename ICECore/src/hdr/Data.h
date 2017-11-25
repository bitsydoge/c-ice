#ifndef DEF_ICE_DATA
#define DEF_ICE_DATA
#include "Game.h"

void* iceDataAdd(iceGame *game, size_t _size);
void* iceDataGet(iceGame *game, int nb_data);
void iceDataDestroy(iceGame *game, int nb_data);

#endif
