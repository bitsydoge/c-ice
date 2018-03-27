#ifndef DEF_ICE__CAMERA
#define DEF_ICE__CAMERA

#include "TypesMaths.h"

/// Set camera to position
void ICE_Camera_SetPos(ICE_Vect vect);
/// Move camera to a position from a r value
void ICE_Camera_MovePos(ICE_Vect vect, ICE_Float r);
/// Move camera from X and Y pixel
void ICE_Camera_ShiftPos(ICE_Vect Dvect);
/// Convert a rect in the virtual coordinate to a screen coordinate with the camera position
ICE_Box ICE_Camera_WorldScreen(ICE_Box rect);
/// Convert a rect in the screen coordinate to a virtual coordinate with the camera position
ICE_Box ICE_Camera_ScreenWorld(ICE_Box rect);
///

int ICE_Camera_GetW();
int ICE_Camera_GetH();

#endif