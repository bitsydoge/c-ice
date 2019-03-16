#ifndef DEF_ICE_SCENE_PRIVATE_H
#define DEF_ICE_SCENE_PRIVATE_H

#include "Color.h"
#include "Camera_private.h"
#include "EntityManager_private.h"

struct ICE_Scene
{
	ICE_String				name;

	ICE_Bool				quit;
	ICE_Bool				isPaused;
	ICE_Bool				isFree;

	void					(*func_create)(void);
	void					(*func_update)(void);
	void					(*func_destroy)(void);

	void					(*func_OnPause)(void);
	void					(*func_OnResume)(void);

	// Camera
	ICE_Camera				camera;

	// Gui
	// ICE_GuiManager		gui_mngr;

	// Entity
	ICE_EntityManager		entity_mngr;

	// Data
	ICE_ID					data_nb;
	void**					data;

	ICE_Color				background_color;

	struct ICE_Scene *		parent;

}; typedef struct ICE_Scene ICE_Scene;


ICE_Scene ICE_Scene_Init(void(*call_create)(void), void(*call_update)(void), void(*call_destroy)(void), ICE_Scene* parent_, ICE_StringStd name_);
void ICE_Scene_Destroy(ICE_Scene* scene_);
void ICE_Scene_Run(ICE_Scene* scene_);

#endif