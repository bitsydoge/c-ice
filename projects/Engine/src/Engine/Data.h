#ifndef DEF_ICE_DATA
#define DEF_ICE_DATA

#include "Scene_private.h"
#include "Types.h"

#define ICE_Data_Insert(STATE, DATATYPE) ICE_Data_Insert_(STATE, sizeof(DATATYPE))

void* ICE_Data_Insert_(ICE_Scene* state, ICE_DataID _size);
void* ICE_Data_Get(ICE_Scene* scene_, ICE_ID data_nb_);
void ICE_Data_Destroy(ICE_Scene* scene_, ICE_ID nb_data);
void ICE_Data_DestroyAll(ICE_Scene* scene_);

#endif