#ifndef DEF_ICE_DATA
#define DEF_ICE_DATA

#include "Scene_private.h"
#include "Types.h"

#define ICE_Data_Insert(SCENE, DATATYPE) ICE_Data_Insert_(SCENE, sizeof(DATATYPE))

void* ICE_Data_Insert_(ICE_DataID size_);
void* ICE_Data_Get(ICE_ID data_nb_);
void ICE_Data_Destroy(ICE_ID nb_data);
void ICE_Data_DestroyAll();

#endif