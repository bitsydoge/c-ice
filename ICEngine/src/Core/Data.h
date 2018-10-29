#ifndef DEF_ICE_DATA
#define DEF_ICE_DATA
#include "State.h"

#define ICE_Data_Insert(STATE, DATATYPE) ICE_Data_Insert_(STATE, sizeof(DATATYPE))

// Make a Data and create a pointer in the GAME->data array (return the pointer created)
void* ICE_Data_Insert_(ICE_State * state, ICE_ID _size);

/// Return pointer to a Data
void* ICE_Data_Get(ICE_State * state, ICE_ID nb_data);

/// Destroy a Data
void ICE_Data_Destroy(ICE_State * state, ICE_ID nb_data);

void ICE_Data_DestroyAll(ICE_State * state);

#endif