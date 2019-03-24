#ifndef DEF_ICE_CONTROL2D_H
#define DEF_ICE_CONTROL2D_H

#include "../Framework/BasicTypes.h"
#include "Vect2D.h"

typedef struct ICE_Control2D ICE_Control2D;

///////////////////////////////////////////////////////////////////////////////////////////
// ------------------------------------------------------------------------------------- //
// ------------------------------------- Set ------------------------------------------- //
// ------------------------------------------------------------------------------------- //
///////////////////////////////////////////////////////////////////////////////////////////

// ------------------------------------- Active ---------------------------------------- //
void ICE_Control2D_Active(ICE_Control2D* control2d_, ICE_Bool isActive_);
// ------------------------------------- Position -------------------------------------- //
void ICE_Control2D_SetPosition(ICE_Control2D* control2d_, ICE_Float x, ICE_Float y);
void ICE_Control2D_SetPositionX(ICE_Control2D* control2d_, ICE_Float x);
void ICE_Control2D_SetPositionY(ICE_Control2D* control2d_, ICE_Float y);
void ICE_Control2D_ShiftPosition(ICE_Control2D* control2d_, ICE_Float value_to_shift_x_, ICE_Float value_to_shift_y_);
void ICE_Control2D_MovePosition(ICE_Control2D* control2d_, ICE_Vect2D vect_pos_, ICE_Float value_to_move_);
// ------------------------------------- Rotation -------------------------------------- //
void ICE_Control2D_SetRotation(ICE_Control2D* control2d_, ICE_Float angle_);
void ICE_Control2D_AddRotation(ICE_Control2D* control2d_, ICE_Float angle_);
void ICE_Control2D_LookAt(ICE_Control2D* control2d_, ICE_Vect2D pos);
// ------------------------------------- Scale ----------------------------------------- //
void ICE_Control2D_SetScale(ICE_Control2D* control2D_, ICE_Vect2D scale_);
void ICE_Control2D_SetScaleW(ICE_Control2D* control2D_, ICE_Float scale_w_);
void ICE_Control2D_SetScaleH(ICE_Control2D* control2D_, ICE_Float scale_h_);
void ICE_Control2D_MultiplyScale(ICE_Control2D* control2d_, ICE_Float coef_);
void ICE_Control2D_MultiplyScaleW(ICE_Control2D* control2d_, ICE_Float coef_w_);
void ICE_Control2D_MultiplyScaleH(ICE_Control2D* control2d_, ICE_Float coef_h_);

///////////////////////////////////////////////////////////////////////////////////////////     
// ------------------------------------------------------------------------------------- //
// ------------------------------------- Get ------------------------------------------- //
// ------------------------------------------------------------------------------------- //
///////////////////////////////////////////////////////////////////////////////////////////

// ------------------------------------- Active ---------------------------------------- //
ICE_Bool ICE_Control2D_GetActive(ICE_Control2D* control2d_);
// ------------------------------------- Position -------------------------------------- //
ICE_Vect2D ICE_Control2D_GetPosition(ICE_Control2D* control2D_);
ICE_Float ICE_Control2D_GetPositionX(ICE_Control2D* control2D_);
ICE_Float ICE_Control2D_GetPositionY(ICE_Control2D* control2D_);
// ------------------------------------- Rotation -------------------------------------- //
ICE_Float ICE_Control2D_GetRotation(ICE_Control2D* control2D_);
// ------------------------------------- Scale ----------------------------------------- //
ICE_Vect2D ICE_Control2D_GetScale(ICE_Control2D* control2D_);
ICE_Float ICE_Control2D_GetScaleW(ICE_Control2D* control2D_);
ICE_Float ICE_Control2D_GetScaleH(ICE_Control2D* control2D_);

#endif