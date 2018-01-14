#ifndef DEF_ICE_CAMERA
#define DEF_ICE_CAMERA

#include "TypesMaths.h"

/// Set camera to position
void iceCameraSetPos(iceVect vect);
/// Move camera to a position from a r value
void iceCameraMovePos(iceVect vect, iceFloat r);
/// Move camera from X and Y pixel
void iceCameraShiftPos(iceVect Dvect);
/// Convert a rect in the virtual coordinate to a screen coordinate with the camera position
iceBox iceCameraWorldScreen(iceBox rect);
/// Convert a rect in the screen coordinate to a virtual coordinate with the camera position
iceBox iceCameraScreenWorld(iceBox rect);
///
void iceCameraAttachToEntity(int entity_manager, int entity);
///
void iceCameraDetach();
///
void iceCameraUpdateAttach();
///
iceBool iceCameraBoxOnScreen(iceBox box);
int iceCameraGetW();
int iceCameraGetH();

#endif