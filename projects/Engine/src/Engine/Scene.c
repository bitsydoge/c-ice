#include "Scene_private.h"
#include "../Framework/Log.h"
#include "Time_private.h"
#include "Input_private.h"
#include "Renderer_private.h"

ICE_Scene ICE_GLOBJ_SCENE_MAIN = {0};
ICE_Scene * ICE_GLOBJ_SCENE_CURRENT = NULL;

#include "EntityManager_private.h"

#include "GlobalData_private.h"
ICE_GLOBALDATA_INPUT
ICE_GLOBALDATA_SCENE_CURRENT
ICE_GLOBALDATA_SCENE_MAIN
ICE_GLOBALDATA_DEBUG_LATEDRAW

ICE_Scene ICE_Scene_Init(void(*call_create)(void), void(*call_update)(void), void(*call_destroy)(void), ICE_Scene * parent_, ICE_StringStd name_)
{
	ICE_Scene scene = {0};

	scene.name = ICE_String_Init(name_);

	scene.func_create = call_create;
	scene.func_update = call_update;
	scene.func_destroy = call_destroy;
	scene.parent = parent_;

	ICE_EntityManager_Init(&scene.entity_mngr);

	return scene;
}

void ICE_Scene_Destroy(ICE_Scene * scene_)
{
	ICE_String_Free(scene_->name);

	scene_->func_create = NULL;
	scene_->func_update = NULL;
	scene_->func_destroy = NULL;
	scene_->parent = NULL;

	ICE_EntityManager_Destroy(&scene_->entity_mngr);
}

void ICE_Scene_Run(ICE_Scene * scene_)
{
	ICE_Log_Line();
	ICE_Log(ICE_LOGTYPE_RUNNING, "Create ...");
	scene_->func_create();
	ICE_Log(ICE_LOGTYPE_FINISH, "Create");
	ICE_Log_Line();
	
	ICE_Log_Line();
	ICE_Log(ICE_LOGTYPE_RUNNING, "Update ...");
	while (!ICE_GLOBJ_INPUT.quit)
	{
		// LOGIC HERE
		ICE_Time_Start();
		ICE_Input_Return();

		//ICE_Entity_FunctionUpdate(NULL);
		scene_->func_update();

		// RENDER HERE
		ICE_Renderer_SetColor(ICE_GLOBJ_SCENE_CURRENT->background_color);
		ICE_Renderer_Clear();

		//ICE_Draw_AllEntity();
		//ICE_Draw_LabelWorld();
		//ICE_Draw_AllGui();
		//ICE_Draw_LabelScreen();

#if defined(_DEBUG)
		if (ICE_GLOBJ_DEBUG_LATEDRAW)
			ICE_GLOBJ_DEBUG_LATEDRAW();
#endif

		ICE_Renderer_Now();
		ICE_Time_End();
	}
	ICE_Log(ICE_LOGTYPE_FINISH, "Update");
	ICE_Log_Line();

	ICE_Log_Line();
	ICE_Log(ICE_LOGTYPE_RUNNING, "Destroy ...");
	scene_->func_destroy();
	ICE_Log(ICE_LOGTYPE_FINISH, "Destroy");
	ICE_Log_Line();
}