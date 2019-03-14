#include "Scene_private.h"

ICE_Scene ICE_GLOBJ_SCENE_MAIN = {0};
ICE_Scene * ICE_GLOBJ_SCENE_CURRENT = NULL;

#include "EntityManager_private.h"

ICE_Scene ICE_Scene_Init(void(*call_create)(void), void(*call_update)(void), void(*call_destroy)(void), ICE_Scene * parent_)
{
	ICE_Scene scene = {0};
	ICE_EntityManager_Init(&scene.entity_mngr);
	scene.func_create = call_create;
	scene.func_update = call_update;
	scene.func_destroy = call_destroy;
	scene.parent = parent_;
	return scene;
}

void ICE_Scene_Destroy(ICE_Scene * scene_)
{
	ICE_EntityManager_Destroy(&scene_->entity_mngr);
	scene_->func_create = NULL;
	scene_->func_update = NULL;
	scene_->func_destroy = NULL;
}