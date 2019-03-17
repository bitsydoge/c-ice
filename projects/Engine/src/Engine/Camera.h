#ifndef DEF_ICE_CAMERA_H
#define DEF_ICE_CAMERA_H

#include "Vector.h"
#include "Box.h"

typedef struct ICE_Camera ICE_Camera;




///////////////////////////////////////////////////////////////////////////////////////////
// ------------------------------------------------------------------------------------- //
// --------------------------------    Set       --------------------------------------- //
// ------------------------------------------------------------------------------------- //
///////////////////////////////////////////////////////////////////////////////////////////

// --------------------------------    Position  --------------------------------------- //
void ICE_Camera_SetPosition(ICE_Vect new_position_);
void ICE_Camera_SetPositionX(ICE_Float new_position_y);
void ICE_Camera_SetPositionY(ICE_Float new_position_y);
void ICE_Camera_MoveTo(ICE_Vect position_to_move_, ICE_Float value_to_move_);
void ICE_Camera_AddPosition(ICE_Vect add_to_position_);
void ICE_Camera_AddPositionX(ICE_Float add_to_position_x_);
void ICE_Camera_AddPositionY(ICE_Float add_to_position_y_);

// --------------------------------    Scale     --------------------------------------- //
void ICE_Camera_SetScale(ICE_Vect scale_);
void ICE_Camera_SetScaleW(ICE_Float scale_w_);
void ICE_Camera_SetScaleH(ICE_Float scale_h_);
void ICE_Camera_AddScale(ICE_Vect add_scale_);
void ICE_Camera_AddScaleW(ICE_Float add_scale_w_);
void ICE_Camera_AddScaleH(ICE_Float add_scale_h_);
void ICE_Camera_MultiplyScaleW(ICE_Float multiply_scale_w_);
void ICE_Camera_MultiplyScaleH(ICE_Float multiply_scale_h_);
void ICE_Camera_MultiplyScale(ICE_Float multiply_scale_);




///////////////////////////////////////////////////////////////////////////////////////////
// ------------------------------------------------------------------------------------- //
// --------------------------------    Get       --------------------------------------- //
// ------------------------------------------------------------------------------------- //
///////////////////////////////////////////////////////////////////////////////////////////

/**
 * \brief Return a Vector with Camera Coordinate
 * \return
 */
ICE_Vect ICE_Camera_GetPosition();
ICE_Float ICE_Camera_GetPositionX();
ICE_Float ICE_Camera_GetPositionY();
ICE_Vect ICE_Camera_GetScale();
ICE_Float ICE_Camera_GetScaleW();
ICE_Float ICE_Camera_GetScaleH();




///////////////////////////////////////////////////////////////////////////////////////////
// ------------------------------------------------------------------------------------- //
// --------------------------------    Converter    ------------------------------------ //
// ------------------------------------------------------------------------------------- //
///////////////////////////////////////////////////////////////////////////////////////////

/**
 * \brief Convert a ICE_Box in World Coordinate to Screen Coordinate
 * \param rect Box in World Coordinate to convert
 * \return Box in Screen Coordinate
 */
ICE_Box ICE_Camera_World_to_Screen(ICE_Box rect);

/**
* \brief Convert a ICE_Box in Screen Coordinate to World Coordinate
* \param rect Box in Screen Coordinate to convert
* \return Box in World Coordinate
*/
ICE_Box ICE_Camera_Screen_to_World(ICE_Box rect);



#endif