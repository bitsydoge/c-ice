#ifndef DEF_ICE_ENTITY_H
#define DEF_ICE_ENTITY_H

#include "Box.h"
#include "Entity_private.h"
#include "Scene_private.h"

ICE_Entity ICE_Entity_Build(ICE_Box pos);
ICE_ID ICE_Entity_Create(ICE_Scene* scene_, ICE_Box pos);
void ICE_Entity_Clear(ICE_Entity* entity);
void ICE_Entity_Destroy(ICE_Entity* ptr);
void* ICE_Entity_DataAdd_(ICE_Entity* entity_, ICE_ID size_);
void* ICE_Entity_DataGet(ICE_Entity* entity_, ICE_DataID id_data_);
void ICE_Entity_DataDestroy(ICE_Entity* entity_, ICE_DataID id_data_);
void ICE_Entity_DataDestroyAll(ICE_Entity* entity_);

#endif