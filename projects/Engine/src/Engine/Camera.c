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

// --------------------------------    Position  --------------------------------------- //
void ICE_Camera_SetPosition(ICE_Vect new_position_)
{
	ICE_GLOBJ_SCENE_CURRENT->camera.x = new_position_.x;
	ICE_GLOBJ_SCENE_CURRENT->camera.y = new_position_.y;
}

void ICE_Camera_SetPositionX(ICE_Float new_position_y)
{
	ICE_GLOBJ_SCENE_CURRENT->camera.x = new_position_y;
}

void ICE_Camera_SetPositionY(ICE_Float new_position_y)
{
	ICE_GLOBJ_SCENE_CURRENT->camera.y = new_position_y;
}

void ICE_Camera_MoveTo(ICE_Vect position_to_move_, ICE_Float value_to_move_)
{
	const ICE_Float xdif = position_to_move_.x - ICE_GLOBJ_SCENE_CURRENT->camera.x;
	const ICE_Float ydif = position_to_move_.y - ICE_GLOBJ_SCENE_CURRENT->camera.y;

	const ICE_Float angle = atan2(ydif, xdif);
	const ICE_Float distance_r_r = xdif * xdif + ydif * ydif;

	ICE_GLOBJ_SCENE_CURRENT->camera.x += value_to_move_ * cos(angle);
	ICE_GLOBJ_SCENE_CURRENT->camera.y += value_to_move_ * sin(angle);

	if (distance_r_r < value_to_move_)
	{
		ICE_GLOBJ_SCENE_CURRENT->camera.x = position_to_move_.x;
		ICE_GLOBJ_SCENE_CURRENT->camera.y = position_to_move_.y;
	}
}

void ICE_Camera_AddPosition(ICE_Vect add_to_position_)
{
	ICE_GLOBJ_SCENE_CURRENT->camera.x += add_to_position_.x;
	ICE_GLOBJ_SCENE_CURRENT->camera.y += add_to_position_.y;
}

void ICE_Camera_AddPositionX(ICE_Float add_to_position_x_)
{
	ICE_GLOBJ_SCENE_CURRENT->camera.x += add_to_position_x_;
}

void ICE_Camera_AddPositionY(ICE_Float add_to_position_y_)
{
	ICE_GLOBJ_SCENE_CURRENT->camera.y += add_to_position_y_;
}

// --------------------------------    Scale     --------------------------------------- //
void ICE_Camera_SetScale(ICE_Vect scale_)
{
	ICE_GLOBJ_SCENE_CURRENT->camera.scale_w = scale_.x;
	ICE_GLOBJ_SCENE_CURRENT->camera.scale_h = scale_.y;
}

void ICE_Camera_SetScaleW(ICE_Float scale_w_)
{
	ICE_GLOBJ_SCENE_CURRENT->camera.scale_w = scale_w_;
}

void ICE_Camera_SetScaleH(ICE_Float scale_h_)
{
	ICE_GLOBJ_SCENE_CURRENT->camera.scale_h = scale_h_;
}

void ICE_Camera_AddScale(ICE_Vect add_scale_)
{
	ICE_GLOBJ_SCENE_CURRENT->camera.scale_w += add_scale_.x;
	ICE_GLOBJ_SCENE_CURRENT->camera.scale_h += add_scale_.y;
}

void ICE_Camera_AddScaleW(ICE_Float add_scale_w_)
{
	ICE_GLOBJ_SCENE_CURRENT->camera.scale_w += add_scale_w_;
}

void ICE_Camera_AddScaleH(ICE_Float add_scale_h_)
{
	ICE_GLOBJ_SCENE_CURRENT->camera.scale_h += add_scale_h_;
}

void ICE_Camera_MultiplyScaleW(ICE_Float multiply_scale_w_)
{
	ICE_GLOBJ_SCENE_CURRENT->camera.scale_w *= multiply_scale_w_;
}

void ICE_Camera_MultiplyScaleH(ICE_Float multiply_scale_h_)
{
	ICE_GLOBJ_SCENE_CURRENT->camera.scale_h *= multiply_scale_h_;
}

void ICE_Camera_MultiplyScale(ICE_Float multiply_scale_)
{
	ICE_GLOBJ_SCENE_CURRENT->camera.scale_h *= multiply_scale_;
	ICE_GLOBJ_SCENE_CURRENT->camera.scale_w *= multiply_scale_;
}




///////////////////////////////////////////////////////////////////////////////////////////
// ------------------------------------------------------------------------------------- //
// --------------------------------    Get       --------------------------------------- //
// ------------------------------------------------------------------------------------- //
///////////////////////////////////////////////////////////////////////////////////////////

ICE_Vect ICE_Camera_GetPosition()
{
	ICE_Scene* scene_ = ICE_GLOBJ_SCENE_CURRENT;

	return ICE_Vect_New(scene_->camera.x, scene_->camera.y);
}

ICE_Float ICE_Camera_GetPositionX()
{
	ICE_Scene* scene_ = ICE_GLOBJ_SCENE_CURRENT;
	return scene_->camera.x;
}

ICE_Float ICE_Camera_GetPositionY()
{
	ICE_Scene* scene_ = ICE_GLOBJ_SCENE_CURRENT;
	return scene_->camera.y;
}

ICE_Vect ICE_Camera_GetScale()
{
	ICE_Scene* scene_ = ICE_GLOBJ_SCENE_CURRENT;

	return ICE_Vect_New(scene_->camera.scale_w, scene_->camera.scale_h);
}

ICE_Float ICE_Camera_GetScaleW()
{
	ICE_Scene* scene_ = ICE_GLOBJ_SCENE_CURRENT;
	return scene_->camera.scale_w;
}

ICE_Float ICE_Camera_GetScaleH()
{
	ICE_Scene* scene_ = ICE_GLOBJ_SCENE_CURRENT;
	return scene_->camera.scale_h;
}


///////////////////////////////////////////////////////////////////////////////////////////
// ------------------------------------------------------------------------------------- //
// --------------------------------    Converter    ------------------------------------ //
// ------------------------------------------------------------------------------------- //
///////////////////////////////////////////////////////////////////////////////////////////

ICE_Box ICE_Camera_World_to_Screen(ICE_Box rect)
{
	ICE_Box rect2 = 
	{
		(ICE_GLOBJ_WINDOW.w / 2) + rect.x - ICE_GLOBJ_SCENE_CURRENT->camera.x,
		(ICE_GLOBJ_WINDOW.h / 2) + rect.y - ICE_GLOBJ_SCENE_CURRENT->camera.y,
		rect.w,
		rect.h
	};
	return rect2;
}

ICE_Box ICE_Camera_Screen_to_World(ICE_Box rect)
{
	ICE_Box rect2 = 
	{
		-ICE_GLOBJ_WINDOW.w / 2 + ICE_GLOBJ_SCENE_CURRENT->camera.x + rect.x,
		-ICE_GLOBJ_WINDOW.h / 2 + ICE_GLOBJ_SCENE_CURRENT->camera.y + rect.y,
		rect.w,
		rect.h
	};
	return rect2;
}
