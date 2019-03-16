#ifndef DEF_ICE_ENTITY_H
#define DEF_ICE_ENTITY_H

#include "Box.h"
#include "Types.h"
#include "Graphics2D.h"
#include "Control2D.h"

typedef struct ICE_Entity ICE_Entity;

ICE_Entity ICE_Entity_Build(ICE_Vect vect_);
ICE_ID ICE_Entity_Create(ICE_Vect vect_);
void ICE_Entity_Clear(ICE_Entity* entity);
void ICE_Entity_Destroy(ICE_Entity* ptr);

// Data

void* ICE_Entity_DataAdd_(ICE_Entity* entity_, ICE_ID size_);
void* ICE_Entity_DataGet(ICE_Entity* entity_, ICE_DataID id_data_);
void ICE_Entity_DataDestroy(ICE_Entity* entity_, ICE_DataID id_data_);
void ICE_Entity_DataDestroyAll(ICE_Entity* entity_);

// Graphics2D
ICE_Graphics2D* ICE_Entity_GetGraphics2D(ICE_EntityID entity_id_);

// Control2D
ICE_Control2D* ICE_Entity_GetControl2D(ICE_EntityID entity_id_);

#endif