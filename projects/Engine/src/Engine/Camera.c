#include "Camera_private.h"
#include "Camera.h"
#include "Vector.h"
#include "Box.h"

#include "Window_private.h"
#include "Scene_private.h"

extern ICE_Scene * ICE_GLOBJ_SCENE_CURRENT;
extern ICE_Window ICE_GLOBJ_WINDOW;

///////////////////////////////////////////////////////////////////////////////////////////
// ------------------------------------------------------------------------------------- //
// --------------------------------    Set       --------------------------------------- //
// ------------------------------------------------------------------------------------- //
///////////////////////////////////////////////////////////////////////////////////////////

void ICE_Camera_SetPos(ICE_Vect vect)
{
	
	ICE_GLOBJ_SCENE_CURRENT->camera.x = vect.x;
	ICE_GLOBJ_SCENE_CURRENT->camera.y = vect.y;
}

void ICE_Camera_MovePos(ICE_Vect vect, ICE_Float r)
{
	const ICE_Float xdif = vect.x - ICE_GLOBJ_SCENE_CURRENT->camera.x;
	const ICE_Float ydif = vect.y - ICE_GLOBJ_SCENE_CURRENT->camera.y;

	const ICE_Float angle = atan2(ydif, xdif);
	const ICE_Float distance_r_r = xdif * xdif + ydif * ydif;

	ICE_GLOBJ_SCENE_CURRENT->camera.x += r * cos(angle);
	ICE_GLOBJ_SCENE_CURRENT->camera.y += r * sin(angle);

	if (distance_r_r < r)
	{
		ICE_GLOBJ_SCENE_CURRENT->camera.x = vect.x;
		ICE_GLOBJ_SCENE_CURRENT->camera.y = vect.y;
	}
}

void ICE_Camera_ShiftPos(ICE_Vect delta_)
{
	ICE_GLOBJ_SCENE_CURRENT->camera.x += delta_.x;
	ICE_GLOBJ_SCENE_CURRENT->camera.y += delta_.y;
}




///////////////////////////////////////////////////////////////////////////////////////////
// ------------------------------------------------------------------------------------- //
// --------------------------------    Get       --------------------------------------- //
// ------------------------------------------------------------------------------------- //
///////////////////////////////////////////////////////////////////////////////////////////

ICE_Vect ICE_Camera_PositionGet()
{
	ICE_Scene* scene_ = ICE_GLOBJ_SCENE_CURRENT;

	return ICE_Vect_New(scene_->camera.x, scene_->camera.y);
}

ICE_Float ICE_Camera_PositionGetX()
{
	ICE_Scene* scene_ = ICE_GLOBJ_SCENE_CURRENT;
	return scene_->camera.x;
}

ICE_Float ICE_Camera_PositionGetY()
{
	ICE_Scene* scene_ = ICE_GLOBJ_SCENE_CURRENT;
	return scene_->camera.y;
}


///////////////////////////////////////////////////////////////////////////////////////////
// ------------------------------------------------------------------------------------- //
// --------------------------------    Converter    ------------------------------------ //
// ------------------------------------------------------------------------------------- //
///////////////////////////////////////////////////////////////////////////////////////////

ICE_Box ICE_Camera_WorldScreen(ICE_Box rect)
{
	ICE_Box rect2 = {
		(ICE_GLOBJ_WINDOW.w / 2) + rect.x - ICE_GLOBJ_SCENE_CURRENT->camera.x,
		(ICE_GLOBJ_WINDOW.h / 2) + rect.y - ICE_GLOBJ_SCENE_CURRENT->camera.y,
		rect.w,
		rect.h
	};
	return rect2;
}

ICE_Box ICE_Camera_ScreenWorld(ICE_Box rect)
{
	ICE_Box rect2 = {
		-ICE_GLOBJ_WINDOW.w / 2 + ICE_GLOBJ_SCENE_CURRENT->camera.x + rect.x,
		-ICE_GLOBJ_WINDOW.h / 2 + ICE_GLOBJ_SCENE_CURRENT->camera.y + rect.y,
		rect.w,
		rect.h
	};
	return rect2;
}
