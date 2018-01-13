#ifndef DEF_ICE_DATA
#define DEF_ICE_DATA
#include "Game.h"

void* iceDataAdd(size_t _size);
void* iceDataGet(int nb_data);
void iceDataDestroy(int nb_data);

void* iceDataEntityAdd(int entity_man, int entity_nb, size_t _size);
void* iceDataEntityGet(int entity_man, int entity_nb, int nb_data);
void iceDataEntityDestroy(int entity_man, int entity_nb, int nb_data);

#endif
