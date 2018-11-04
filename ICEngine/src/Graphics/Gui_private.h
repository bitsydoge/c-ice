#ifndef DEF_ICE_GUI_PRIVATE
#define DEF_ICE_GUI_PRIVATE

#include "Texture.h"
#include "../Core/TypesCore.h"

void ICE_Gui_UpdateTexture(ICE_State* state_, ICE_ID gui);
void ICE_Gui_Rect(ICE_Texture * texture, struct ICE_Box rect);

#endif