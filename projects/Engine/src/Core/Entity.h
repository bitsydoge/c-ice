#ifndef DEF_ICE_ENTITY
#define DEF_ICE_ENTITY

#define ICE_DEFAULT_ENTITY_MNGR_SIZE 4

#include "TypesCore.h"

/////////

/* ENTITY MANAGER */

void ICE_EntityManager_Init(ICE_State* state);
void ICE_EntityManager_Destroy(ICE_State* state);

/* ENTITY */

ICE_Entity ICE_Entity_Build(ICE_Box pos);
ICE_ID ICE_Entity_Create(ICE_State* state, ICE_Box pos);
void ICE_Entity_Clear(ICE_Entity* entity);
void ICE_Entity_Destroy(ICE_Entity* ptr);

/////////

/* ENTITY INFO */

//Simple
ICE_Entity* ICE_Entity_Get(ICE_State* state, ICE_EntityID entity_id);
ICE_ID ICE_Entity_GetQuantity(ICE_State* state, ICE_ID manager);
ICE_ID ICE_EntityManager_GetQuantity(ICE_State* state);

ICE_Vect ICE_Entity_GetPosition(ICE_Entity* entity);
ICE_Box ICE_Entity_GetBox(ICE_Entity* entity);

/* ENTITY MODIFIER */

//Texture
void ICE_Entity_SetTexture(ICE_Entity* entity_ptr, ICE_TextureID texture_id);
void ICE_Entity_RemoveTexture(ICE_Entity* entity);

//Position
void ICE_Entity_SetPos(ICE_Entity* entity, ICE_Float x, ICE_Float y);
void ICE_Entity_ShiftPos(ICE_Entity* entity, ICE_Float x, ICE_Float y);
void ICE_Entity_MovePos(ICE_Entity* entity, ICE_Vect pos, ICE_Float r);

//Size
void ICE_Entity_SetSize(ICE_Entity* entity, ICE_Vect size);
void ICE_Entity_Scale(ICE_Entity* entity, ICE_Float scale);

//Rotation
void ICE_Entity_SetAngle(ICE_Entity* entity, ICE_Float angle);
void ICE_Entity_AddAngle(ICE_Entity* entity, ICE_Float angle);
void ICE_Entity_LookAt(ICE_Entity* entity, ICE_Vect pos);

//Sprite
void ICE_Entity_SetSprite(ICE_Entity* entity_, ICE_ID sprite_);
void ICE_Entity_SetSpriteFrame(ICE_Entity* entity, ICE_ID frame);

ICE_Sprite* ICE_Entity_GetSprite(ICE_Entity* _entity);


void ICE_Entity_SetFunction(ICE_Entity* entity, void (*call_create)(ICE_Entity*), void (*call_update)(ICE_Entity*),
                            void (*call_destroy)(ICE_Entity*));
void ICE_Entity_FunctionUpdate(ICE_State* state);
ICE_ID ICE_Entity_GetSpriteFrame(ICE_Entity * entity);

/* ENTITY DATA */

#define ICE_Entity_DataAdd(ENTITY, DATATYPE) ICE_Entity_DataAdd_(ENTITY, sizeof(DATATYPE))
void * ICE_Entity_DataAdd_(ICE_Entity * entity_, ICE_ID size_);
void * ICE_Entity_DataGet(ICE_Entity * entity_, ICE_DataID id_data_);
void ICE_Entity_DataDestroy(ICE_Entity * entity_, ICE_DataID id_data_);
void ICE_Entity_DataDestroyAll(ICE_Entity * entity_);
ICE_EntityID ICE_Entity_GetID(ICE_Entity * entity_);

#endif
