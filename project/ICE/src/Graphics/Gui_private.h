#ifndef DEF_ICE_GUI_PRIVATE
#define DEF_ICE_GUI_PRIVATE

#include "../Core/TypesCore.h"

void ICE_GuiManager_Init(ICE_State* state);
void ICE_GuiManager_Destroy(ICE_State * state);
ICE_Gui ICE_Gui_Build(ICE_Box box, ICE_TextureID nb_texture);
void ICE_Gui_UpdateTexture(ICE_State* state_, ICE_ID gui);
void ICE_Gui_Rect(ICE_Texture * texture, struct ICE_Box rect);

#endif