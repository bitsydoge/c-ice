#ifndef DEF_ICE_DATA
#define DEF_ICE_DATA

#include "Types.h"

void* ICE_Data_Insert(ICE_Size size_use_sizeof_);
void* ICE_Data_Get(ICE_DataID data_id_);
void ICE_Data_Destroy(ICE_DataID data_id_);
void ICE_Data_DestroyAll();

#endif