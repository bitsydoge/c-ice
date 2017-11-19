#ifndef DEF_ICE_CAMERA
#define DEF_ICE_CAMERA

#include "Struct.h"

/// Set camera to position
void ICE_CameraSetPos(ICE_Game *game, const float x, const float y);
/// Move camera to a position from a r value
void ICE_CameraMovePos(ICE_Game *game, const float x, const float y, const float r);
/// Move camera from X and Y pixel
void ICE_CameraShiftPos(ICE_Game *game, const float dx, const float dy);
/// Convert a rect in the virtual coordinate to a screen coordinate with the camera position
ICE_Rect position_to_screen(ICE_Rect rect, ICE_Camera *camera);
/// Convert a rect in the screen coordinate to a virtual coordinate with the camera position
ICE_Rect screen_to_position(ICE_Rect rect, ICE_Camera *camera);

#endif
