#ifndef DEF_ICE_ENTITY
#define DEF_ICE_ENTITY

#define ICE_DEFAULT_ENTITY_MNGR_SIZE 4

#include "TypesCore.h"

/////////

/* ENTITY MANAGER */

ICE_Index ICE_EntityManager_Insert(ICE_State * state);
void ICE_EntityManager_Destroy(ICE_State * state, const ICE_Index man);
void ICE_EntityManager_DestroyAll(ICE_State * state);

/* ENTITY */

ICE_Entity ICE_Entity_Create(ICE_Box pos);
ICE_Index ICE_Entity_Insert(ICE_State * state, const ICE_Index man, ICE_Box pos);
void ICE_Entity_Clear(ICE_Entity * entity);
void ICE_Entity_Destroy(ICE_Entity * ptr);

/////////

/* ENTITY INFO */

	//Simple
ICE_Entity * ICE_Entity_Get(ICE_State * state, const unsigned man, const unsigned nb);
ICE_Index ICE_Entity_GetQuantity(ICE_State * state, ICE_Index manager);
ICE_Index ICE_EntityManager_GetQuantity(ICE_State * state);

ICE_Vect ICE_Entity_GetPosition(ICE_Entity * entity);
ICE_Box ICE_Entity_GetBox(ICE_Entity * entity);

/* ENTITY MODIFIER */

	//Texture
void ICE_Entity_SetTexture(ICE_Entity * entity, ICE_Texture * texture);
void ICE__Entity_RemoveTexture(ICE_Entity * entity);

	//Position
void ICE_Entity_SetPos(ICE_Entity * entity, ICE_Float x, ICE_Float y);
void ICE_Entity_ShiftPos(ICE_Entity * entity, ICE_Float x, ICE_Float y);
void ICE_Entity_MovePos(ICE_Entity * entity, ICE_Vect pos, ICE_Float r);

	//Size
void ICE_Entity_SetSize(ICE_Entity * entity, ICE_Vect size);
void ICE_Entity_Scale(ICE_Entity * entity, ICE_Float scale);

	//Rotation
void ICE_Entity_SetAngle(ICE_Entity * entity, ICE_Float angle);
void ICE_Entity_AddAngle(ICE_Entity * entity, ICE_Float angle);
void ICE_Entity_LookAt(ICE_Entity * entity, ICE_Vect pos);

	//Sprite
void ICE_Entity_SetSprite(ICE_Entity * entity, ICE_Sprite * sprite);
void ICE_Entity_SetSpriteFrame(ICE_Entity * entity, ICE_Index frame);

ICE_Sprite * ICE_Entity_GetSprite(ICE_Entity * _entity);

#endif