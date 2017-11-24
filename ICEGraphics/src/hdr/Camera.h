#ifndef DEF_ICE_CAMERA
#define DEF_ICE_CAMERA

#include "Struct.h"
#include "Types.h"

/// Set camera to position
void iceCameraSetPos(iceGame *game, iceVect vect);
/// Move camera to a position from a r value
void iceCameraMovePos(iceGame *game, iceVect vect, iceFloat r);
/// Move camera from X and Y pixel
void iceCameraShiftPos(iceGame *game, iceVect Dvect);
/// Convert a rect in the virtual coordinate to a screen coordinate with the camera position
iceRect iceCameraWorldScreen(iceRect rect, iceCamera *camera);
/// Convert a rect in the screen coordinate to a virtual coordinate with the camera position
iceRect iceCameraScreenWorld(iceRect rect, iceCamera *camera);

#endif