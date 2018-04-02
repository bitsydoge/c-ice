#ifndef DEF_ICE_DATA
#define DEF_ICE_DATA
#include "State.h"

// Make a Data and create a pointer in the game->data array (return the pointer created)
void* ICE_Data_Insert(ICE_State * state, size_t _size);

/// Return pointer to a Data
void* ICE_Data_Get(ICE_State * state, unsigned int nb_data);

/// Destroy a Data
void ICE_Data_Destroy(ICE_State * state, unsigned int nb_data);

void ICE_Data_DestroyAll(ICE_State * state);

#endif