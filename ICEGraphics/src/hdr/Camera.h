#ifndef DEF_ICE_CAMERA
#define DEF_ICE_CAMERA

#include "StructMaths.h"
#include "StructCore.h"
#include "Vector.h"

/// Set camera to position
void iceCameraSetPos(iceGame *game, iceVect vect);
/// Move camera to a position from a r value
void iceCameraMovePos(iceGame *game, iceVect vect, iceFloat r);
/// Move camera from X and Y pixel
void iceCameraShiftPos(iceGame *game, iceVect Dvect);
/// Convert a rect in the virtual coordinate to a screen coordinate with the camera position
iceBox iceCameraWorldScreen(iceBox rect, iceCamera *camera);
/// Convert a rect in the screen coordinate to a virtual coordinate with the camera position
iceBox iceCameraScreenWorld(iceBox rect, iceCamera *camera);
///
void iceCameraAttachToEntity(iceGame *game, int entity_manager, int entity);
///
void iceCameraDetach(iceGame *game);
///
void _iceCameraUpdateAttach(iceGame *game);
///
iceBool iceCameraBoxOnScreen(iceGame *game, iceBox box);
#endif