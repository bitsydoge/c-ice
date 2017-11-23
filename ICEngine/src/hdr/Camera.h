#ifndef DEF_ICE_CAMERA
#define DEF_ICE_CAMERA

#include "Struct.h"
#include "Types.h"

/// Set camera to position
void ICE_CameraSetPos(ICE_Game *game, iceVect vect);
/// Move camera to a position from a r value
void ICE_CameraMovePos(ICE_Game *game, iceVect vect, iceFloat r);
/// Move camera from X and Y pixel
void ICE_CameraShiftPos(ICE_Game *game, iceVect Dvect);
/// Convert a rect in the virtual coordinate to a screen coordinate with the camera position
iceRect ICE_CameraWorldScreen(iceRect rect, ICE_Camera *camera);
/// Convert a rect in the screen coordinate to a virtual coordinate with the camera position
iceRect ICE_CameraScreenWorld(iceRect rect, ICE_Camera *camera);

#endif