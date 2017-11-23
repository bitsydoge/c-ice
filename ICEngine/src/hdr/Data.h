#ifndef DEF_iceDATA
#define DEF_iceDATA
#include "Game.h"

void* iceAddData(iceGame *game, size_t _size);
void* iceGetData(iceGame *game, int nb_data);
void iceDestroyData(iceGame *game, int nb_data);

#endif
