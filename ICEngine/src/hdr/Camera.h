#ifndef DEF_ICE__CAMERA
#define DEF_ICE__CAMERA

#include "TypesMaths.h"
#include "TypesCore.h"

/// Set camera to position
void ICE_CameraSetPos(ICE_Vect vect);
/// Move camera to a position from a r value
void ICE_CameraMovePos(ICE_Vect vect, ICE_Float r);
/// Move camera from X and Y pixel
void ICE_CameraShiftPos(ICE_Vect Dvect);
/// Convert a rect in the virtual coordinate to a screen coordinate with the camera position
ICE_Box ICE_CameraWorldScreen(ICE_Box rect);
/// Convert a rect in the screen coordinate to a virtual coordinate with the camera position
ICE_Box ICE_CameraScreenWorld(ICE_Box rect);
///
ICE_Bool ICE_CameraBoxOnScreen(ICE_Box box);
int ICE_CameraGetW();
int ICE_CameraGetH();

#endif