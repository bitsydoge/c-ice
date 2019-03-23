#ifndef DEF_ICE_RESOURCES_PRIVATE_H
#define DEF_ICE_RESOURCES_PRIVATE_H

#include "Texture_private.h"
#include "Font_private.h"

struct ICE_Resources
{
	// Texture
	ICE_Texture texture_error;
	ICE_Texture texture_gui_default;
	ICE_Texture texture_logo;
	ICE_FontID font_default;

}; typedef struct ICE_Resources ICE_Resources;

ICE_Resources* ICE_Resources_Get();

void ICE_Resources_TextureLogoInit();
void ICE_Resources_TextureErrorInit();
void ICE_Resources_TextureDefaultGuiInit();
void ICE_Resources_FontDefault();

///////////////////////////////////////////////////////

void ICE_Resources_TextureDefaultGuiFree();
void ICE_Resources_TextureErrorFree();
void ICE_Resources_TextureLogoFree();
void ICE_Resources_FreeAll();

#endif