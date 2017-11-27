#ifndef DEF_ICE_DATA
#define DEF_ICE_DATA
#include "Game.h"

void* iceDataAdd(iceGame *game, size_t _size);
void* iceDataGet(iceGame *game, int nb_data);
void iceDataDestroy(iceGame *game, int nb_data);

void* iceDataEntityAdd(iceGame *game, int entity_man, int entity_nb, size_t _size);
/// Return pointer to a Data
void* iceDataEntityGet(iceGame *game, int entity_man, int entity_nb, int nb_data);
/// Destroy a Data
void iceDataEntityDestroy(iceGame *game, int entity_man, int entity_nb, int nb_data);

#endif
