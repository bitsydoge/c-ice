#include "Control2D_private.h"

#include "Vector.h"
#include "Maths.h"
#include "Color.h"

#define _POLAR_MOVEMENT_TYPE_1

struct ICE_Control2D ICE_Control2D_Build(ICE_Vect position_)
{
	struct ICE_Control2D temp = 
	{ 
		1, 
		position_.x,
		position_.y,
		0,
		1,
		1,
		0,
		0,
		0,
		0,0,
		0,
		0
	};

	return temp;
}

void ICE_Control2D_Destroy(ICE_Control2D* control2d_)
{
	
}


//////                    //////////////////////////                                  /////////// ////////////////////////////////////////////////////////////////////////////////////////
//////                             SET  														  ////////////////////////////////////////////////////////////////////////////////////////
//////                    //////////////////////////                                  /////////// ////////////////////////////////////////////////////////////////////////////////////////




// ------------------------------------- Active ------------------------------------------- //

void ICE_Control2D_Active(ICE_Control2D* control2d_, ICE_Bool isActive_)
{
	control2d_->isActive = isActive_;
}



// ------------------------------------- Position ------------------------------------------- //

void ICE_Control2D_SetPosition(ICE_Control2D* control2d_, ICE_Float x, ICE_Float y)
{
	control2d_->x = x;
	control2d_->y = y;
}

void ICE_Control2D_SetPositionX(ICE_Control2D* control2d_, ICE_Float x)
{
	control2d_->x = x;
}

void ICE_Control2D_SetPositionY(ICE_Control2D* control2d_, ICE_Float y)
{
	control2d_->y = y;
}

void ICE_Control2D_ShiftPosition(ICE_Control2D* control2d_, ICE_Float value_to_shift_x_, ICE_Float value_to_shift_y_)
{
	control2d_->x += value_to_shift_x_;
	control2d_->y += value_to_shift_y_;
}

void ICE_Control2D_MovePosition(ICE_Control2D * control2d_, ICE_Vect vect_pos_, ICE_Float value_to_move_)
{
#ifdef _POLAR_MOVEMENT_TYPE_1

	// Check if it's a new movement
	if (!control2d_->already_moved_polar ||
		control2d_->x_polar_destination_move != vect_pos_.x ||
		control2d_->y_polar_destination_move != vect_pos_.y
		)
	{
		// Calculate the movement
		const ICE_Float xdif = vect_pos_.x - control2d_->x;
		const ICE_Float ydif = vect_pos_.y - control2d_->y;
		const ICE_Float angle = atan2(ydif, xdif);
		control2d_->x_polar_shift_move = cos(angle);
		control2d_->y_polar_shift_move = sin(angle);
		control2d_->polar_distance_r_r = xdif * xdif + ydif * ydif;

		// Save for later check
		control2d_->already_moved_polar = 1;
		control2d_->r_polar_destination_move = value_to_move_;
		control2d_->x_polar_destination_move = vect_pos_.x;
		control2d_->y_polar_destination_move = vect_pos_.y;
	}

	// Movement
	control2d_->x += value_to_move_ * control2d_->x_polar_shift_move;
	control2d_->y += value_to_move_ * control2d_->y_polar_shift_move;

	// Check if is close to destination
	if (control2d_->polar_distance_r_r < value_to_move_)
	{
		control2d_->x = vect_pos_.x;
		control2d_->y = vect_pos_.y;
	}

#endif

#ifdef _POLAR_MOVEMENT_TYPE_2

	float xdif = vect_pos_.x - control2d_->x; float ydif = vect_pos_.y - control2d_->y;
	float angle = atan2(ydif, xdif);
	float distance_r_r = xdif * xdif + ydif * ydif;
	control2d_->x += value_to_move_ * cos(angle); control2d_->y += value_to_move_ * sin(angle);
	if (distance_r_r < value_to_move_)
	{
		control2d_->x = vect_pos_.x;
		control2d_->y = vect_pos_.y;
	}

#endif
}




// ------------------------------------- Rotation ------------------------------------------- //

void ICE_Control2D_SetRotation(ICE_Control2D * control2d_, ICE_Float angle_)
{

	control2d_->rotation = fmod(angle_, 360.00);
}

void ICE_Control2D_AddRotation(ICE_Control2D * control2d_, ICE_Float angle_)
{
	control2d_->rotation = fmod(control2d_->rotation + angle_, 360.0);
}

void ICE_Control2D_LookAt(ICE_Control2D* control2d_, ICE_Vect pos)
{
	const ICE_Float result = ICE_Maths_AngleCalculatDegree
	(
		control2d_->x,
		control2d_->y, 
		pos.x, 
		pos.y
	);

	control2d_->rotation = result;
}




// ------------------------------------- Scale ------------------------------------------- //

void ICE_Control2D_SetScale(ICE_Control2D * control2D_, ICE_Vect scale_)
{
	control2D_->scale_h = scale_.y;
	control2D_->scale_w = scale_.x;
}

void ICE_Control2D_SetScaleW(ICE_Control2D* control2D_, ICE_Float scale_w_)
{
	control2D_->scale_w = scale_w_;
}

void ICE_Control2D_SetScaleH(ICE_Control2D* control2D_, ICE_Float scale_h_)
{
	control2D_->scale_h = scale_h_;
}

void ICE_Control2D_MultiplyScale(ICE_Control2D* control2d_, ICE_Float coef_)
{
	control2d_->scale_w = control2d_->scale_w * coef_;
	control2d_->scale_h = control2d_->scale_h * coef_;
}

void ICE_Control2D_MultiplyScaleW(ICE_Control2D* control2d_, ICE_Float coef_w_)
{
	control2d_->scale_w = control2d_->scale_w * coef_w_;
}

void ICE_Control2D_MultiplyScaleH(ICE_Control2D* control2d_, ICE_Float coef_h_)
{
	control2d_->scale_h = control2d_->scale_h * coef_h_;
}





//////                    //////////////////////////                                  /////////// ////////////////////////////////////////////////////////////////////////////////////////
//////                             GET                                                /////////// ////////////////////////////////////////////////////////////////////////////////////////
//////                    //////////////////////////                                  /////////// ////////////////////////////////////////////////////////////////////////////////////////


// ------------------------------------- Active ------------------------------------------- //

ICE_Bool ICE_Control2D_GetActive(ICE_Control2D* control2d_)
{
	return control2d_->isActive;
}



// ------------------------------------- Position ------------------------------------------- //

ICE_Vect ICE_Control2D_GetPosition(ICE_Control2D* control2D_)
{
	return ICE_Vect_New(control2D_->x, control2D_->y);
}

ICE_Float ICE_Control2D_GetPositionX(ICE_Control2D* control2D_)
{
	return control2D_->x;
}

ICE_Float ICE_Control2D_GetPositionY(ICE_Control2D* control2D_)
{
	return control2D_->y;
}





// ------------------------------------- Rotation ------------------------------------------- //

ICE_Float ICE_Control2D_GetRotation(ICE_Control2D* control2D_)
{
	return control2D_->rotation;
}




// ------------------------------------- Scale ------------------------------------------- //

ICE_Vect ICE_Control2D_GetScale(ICE_Control2D * control2D_)
{
	return ICE_Vect_New(control2D_->scale_w, control2D_->scale_h);
}

ICE_Float ICE_Control2D_GetScaleW(ICE_Control2D* control2D_)
{
	return control2D_->scale_w;
}

ICE_Float ICE_Control2D_GetScaleH(ICE_Control2D* control2D_)
{
	return control2D_->scale_h;
}