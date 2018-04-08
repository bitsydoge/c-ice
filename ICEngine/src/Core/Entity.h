#ifndef DEF_ICE_ENTITY
#define DEF_ICE_ENTITY

#define ICE_DEFAULT_ENTITY_MNGR_SIZE 4

#include "TypesCore.h"

/* ENTITY MANAGER */

unsigned int ICE_EntityManager_Insert(ICE_State * state);
void ICE_EntityManager_Destroy(ICE_State * state, const unsigned int man);
void ICE_EntityManager_DestroyAll(ICE_State * state);

/* ENTITY */

ICE_Entity ICE_Entity_Create(ICE_Box pos);
unsigned int ICE_Entity_Insert(ICE_State * state, const unsigned int man, ICE_Box pos);
void ICE_Entity_Clear(ICE_Entity * entity);
void ICE_Entity_Destroy(ICE_Entity * ptr);

/* ENTITY GET FUNCTION */

ICE_Entity * ICE_Entity_Get(ICE_State * state, const unsigned man, const unsigned nb);
unsigned int ICE_Entity_GetNumber(ICE_State * state, unsigned int manager);
unsigned int ICE_EntityManager_GetNumber(ICE_State * state);
ICE_Vect ICE_Entity_GetPosition(ICE_Entity * entity);

/* ENTITY SET FUNCTION */

void ICE_Entity_SetTexture(ICE_Entity * entity, unsigned int texture_manager, unsigned int texture_nb);
void ICE__Entity_RemoveTexture(ICE_Entity * entity);
void ICE_Entity_SetPos(ICE_Entity * entity, ICE_Float x, ICE_Float y);
void ICE_Entity_ShiftPos(ICE_Entity * entity, ICE_Float x, ICE_Float y);
void ICE_Entity_MovePos(ICE_Entity * entity, ICE_Vect pos, ICE_Float r);
void ICE_Entity_SetSize(ICE_Entity * entity, ICE_Vect size);
void ICE_Entity_SetAngle(ICE_Entity * entity, ICE_Float angle);
void ICE_Entity_AddAngle(ICE_Entity * entity, ICE_Float angle);
void ICE_Entity_LookAt(ICE_Entity * entity, ICE_Vect pos);
ICE_Box ICE_Entity_GetBox(ICE_Entity * entity);

#endif