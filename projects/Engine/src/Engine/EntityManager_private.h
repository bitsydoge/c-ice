#ifndef DEF_ICE_ENTITYMANAGER_PRIVATE_H
#define DEF_ICE_ENTITYMANAGER_PRIVATE_H

#include "Entity_private.h"

struct ICE_EntityManager
{
	ICE_Bool		isFree;
	
	ICE_Size		entity_size;
	ICE_Size		entity_contain;
	ICE_Size		entity_total;
	struct ICE_Entity *		entity;

}; typedef struct ICE_EntityManager ICE_EntityManager;

#define ICE_DEFAULT_ENTITY_MNGR_SIZE 4

void ICE_EntityManager_Init(ICE_EntityManager* entitymanager_);
void ICE_EntityManager_Destroy(ICE_EntityManager* entitymanager_);
void ICE_EntityManager_FunctionUpdate();

#endif