#ifndef DEF_ICE_CAMERA
#define DEF_ICE_CAMERA

#include "Struct.h"

void ICE_SetCamera(ICE_Game *game, int x, int y);
void ICE_MoveCamera(ICE_Game *game, int dx, int dy);
ICE_Rect position_to_screen(ICE_Rect rect, ICE_Camera *camera);
ICE_Rect screen_to_position(ICE_Rect rect, ICE_Camera *camera);

#endif
