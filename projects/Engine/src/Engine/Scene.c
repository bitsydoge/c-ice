#include "Scene_private.h"
#include "../Framework/Log.h"
#include "Time_private.h"
#include "Input_private.h"
#include "Renderer_private.h"
#include "Draw_private.h"
#include "EntityManager_private.h"
#include "Data.h"

ICE_Scene ICE_GLOBJ_SCENE_MAIN = {0};
ICE_Scene * ICE_GLOBJ_SCENE_CURRENT = NULL;

#include "GlobalData_private.h"
ICE_GLOBALDATA_INPUT
ICE_GLOBALDATA_SCENE_CURRENT
ICE_GLOBALDATA_SCENE_MAIN
ICE_GLOBALDATA_DEBUG_LATEDRAW

ICE_Scene ICE_Scene_Init(void(*call_create)(void), void(*call_update)(void), void(*call_destroy)(void), ICE_Scene * parent_, ICE_StringStd name_)
{
	ICE_Scene scene = {0};

	scene.name = ICE_String_Init(name_);

	scene.camera.scale_w = 1.0;
	scene.camera.scale_h = 1.0;

	scene.func_create = call_create;
	scene.func_update = call_update;
	scene.func_destroy = call_destroy;
	scene.parent = parent_;

	ICE_EntityManager_Init(&scene.entity_mngr);

	return scene;
}

void ICE_Scene_Destroy(ICE_Scene * scene_)
{
	ICE_EntityManager_Destroy(&scene_->entity_mngr);
	ICE_Data_DestroyAll();
	ICE_String_Free(scene_->name);
	scene_->func_create = NULL;
	scene_->func_update = NULL;
	scene_->func_destroy = NULL;
	scene_->parent = NULL;
}

void ICE_Scene_Run(ICE_Scene * scene_)
{
	ICE_Log_Line();
	ICE_Log(ICE_LOGTYPE_RUNNING, "Create : %s ...", scene_->name);
	scene_->func_create();
	ICE_Log(ICE_LOGTYPE_FINISH, "Create : %s", scene_->name);
	ICE_Log_Line();
	
	ICE_Log_Line();
	ICE_Log(ICE_LOGTYPE_RUNNING, "Update : %s ...", scene_->name);
	while (!ICE_GLOBJ_INPUT.quit)
	{
		// LOGIC HERE
		ICE_Time_Start();
		ICE_Input_Return();

		ICE_EntityManager_FunctionUpdate();
		scene_->func_update();

		// RENDER HERE
		ICE_Renderer_SetColor(ICE_GLOBJ_SCENE_CURRENT->background_color);
		ICE_Renderer_Clear();

		ICE_Draw_EntityAll();
		//TODO//ICE_Draw_LabelWorld();
		//TODO//ICE_Draw_AllGui();
		//TODO//ICE_Draw_LabelScreen();

#if defined(_DEBUG)
		if (ICE_GLOBJ_DEBUG_LATEDRAW)
			ICE_GLOBJ_DEBUG_LATEDRAW();
#endif

		ICE_Renderer_Now();
		ICE_Time_End();
	}
	ICE_Log(ICE_LOGTYPE_FINISH, "Update : %s", scene_->name);
	ICE_Log_Line();

	ICE_Log_Line();
	ICE_Log(ICE_LOGTYPE_RUNNING, "Destroy : %s ...", scene_->name);
	scene_->func_destroy();
	ICE_Log(ICE_LOGTYPE_FINISH, "Destroy : %s", scene_->name);
	ICE_Log_Line();
}