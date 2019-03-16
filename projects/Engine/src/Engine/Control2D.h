#ifndef DEF_ICE_CONTROL2D_H
#define DEF_ICE_CONTROL2D_H

#include "../Framework/BasicTypes.h"
#include "Vector.h"

typedef struct ICE_Control2D ICE_Control2D;

///////////////////////////////////////////////////////////////////////////////////////////
// ------------------------------------------------------------------------------------- //
// ------------------------------------- Set ------------------------------------------- //
// ------------------------------------------------------------------------------------- //
///////////////////////////////////////////////////////////////////////////////////////////

// ------------------------------------- Active ---------------------------------------- //
void ICE_Control2D_Active(ICE_Control2D* control2d_, ICE_Bool isActive_);
// ------------------------------------- Position -------------------------------------- //
void ICE_Control2D_PositionSet(ICE_Control2D* control2d_, ICE_Float x, ICE_Float y);
void ICE_Control2D_PositionSetX(ICE_Control2D* control2d_, ICE_Float x);
void ICE_Control2D_PositionSetY(ICE_Control2D* control2d_, ICE_Float y);
void ICE_Control2D_PositionShift(ICE_Control2D* control2d_, ICE_Float value_to_shift_x_, ICE_Float value_to_shift_y_);
void ICE_Control2D_PositionMove(ICE_Control2D* control2d_, ICE_Vect vect_pos_, ICE_Float value_to_move_);
// ------------------------------------- Rotation -------------------------------------- //
void ICE_Control2D_RotationSet(ICE_Control2D* control2d_, ICE_Float angle);
void ICE_Control2D_RotationAdd(ICE_Control2D* control2d_, ICE_Float angle);
void ICE_Control2D_LookAt(ICE_Control2D* control2d_, ICE_Vect pos);
// ------------------------------------- Scale ----------------------------------------- //
void ICE_Control2D_ScaleSet(ICE_Control2D* control2D_, ICE_Vect scale_);
void ICE_Control2D_ScaleSetW(ICE_Control2D* control2D_, ICE_Float scale_w_);
void ICE_Control2D_ScaleSetH(ICE_Control2D* control2D_, ICE_Float scale_h_);
void ICE_Control2D_ScaleMultiply(ICE_Control2D* control2d_, ICE_Float coef_);
void ICE_Control2D_ScaleMultiplyW(ICE_Control2D* control2d_, ICE_Float coef_w_);
void ICE_Control2D_ScaleMultiplyH(ICE_Control2D* control2d_, ICE_Float coef_h_);

///////////////////////////////////////////////////////////////////////////////////////////     
// ------------------------------------------------------------------------------------- //
// ------------------------------------- Get ------------------------------------------- //
// ------------------------------------------------------------------------------------- //
///////////////////////////////////////////////////////////////////////////////////////////

// ------------------------------------- Active ---------------------------------------- //
ICE_Bool ICE_Control2D_ActiveGet(ICE_Control2D* control2d_);
// ------------------------------------- Position -------------------------------------- //
ICE_Vect ICE_Control2D_PositionGet(ICE_Control2D* control2D_);
ICE_Float ICE_Control2D_PositionGetX(ICE_Control2D* control2D_);
ICE_Float ICE_Control2D_PositionGetY(ICE_Control2D* control2D_);
// ------------------------------------- Rotation -------------------------------------- //
ICE_Float ICE_Control2D_RotationGet(ICE_Control2D* control2D_);
// ------------------------------------- Scale ----------------------------------------- //
ICE_Vect ICE_Control2D_ScaleGet(ICE_Control2D* control2D_);
ICE_Float ICE_Control2D_ScaleGetW(ICE_Control2D* control2D_);
ICE_Float ICE_Control2D_ScaleGetH(ICE_Control2D* control2D_);

#endif