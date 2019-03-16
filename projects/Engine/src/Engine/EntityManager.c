#include "EntityManager_private.h"

#include "Scene_private.h"
#include "../Framework/Memory_.h"
#include "../Framework/Log.h"
#include "Entity.h"

extern ICE_Scene* ICE_GLOBJ_SCENE_CURRENT;

void ICE_EntityManager_Init(ICE_EntityManager* entitymanager_)
{
	ICE_EntityManager entity_manager = { 0 };
	entity_manager.entity_size = ICE_DEFAULT_ENTITY_MNGR_SIZE;
	entity_manager.entity = ICE_Calloc(entity_manager.entity_size, sizeof(ICE_Entity));

	*entitymanager_ = entity_manager;

	ICE_Log(ICE_LOGTYPE_SUCCES, "Create EntityManager");
}

void ICE_EntityManager_Destroy(ICE_EntityManager* entitymanager_)
{

	for (ICE_ID i = 0; i < entitymanager_->entity_contain; i++)
	{
		//Free everything to free in Entity
		ICE_Entity_Destroy(entitymanager_->entity[i].id);
	}

	ICE_Free(entitymanager_->entity);
	ICE_Log(ICE_LOGTYPE_SUCCES, "Destroy EntityManager");
}