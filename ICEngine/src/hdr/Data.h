#ifndef DEF_ICE_DATA
#define DEF_ICE_DATA
#include "Game.h"

void* ICE_AddData(ICE_Game *game, size_t _size);
void* ICE_GetData(ICE_Game *game, int nb_data);
void ICE_DestroyData(ICE_Game *game, int nb_data);

#endif
