#ifndef DEF_ICE_RESOURCES_PRIVATE_H
#define DEF_ICE_RESOURCES_PRIVATE_H

#include "Texture.h"

struct ICE_Resources
{
	// Texture
	ICE_Texture texture_error;
	ICE_Texture texture_gui_default;
	ICE_Texture texture_logo;

}; typedef struct ICE_Resources ICE_Resources;

void ICE_Texture_ErrorInit();
void ICE_Texture_LogoInit();
void ICE_Texture_DefaultGuiInit();
void ICE_Texture_LogoFree();
void ICE_Texture_DefaultGuiFree();
void ICE_Texture_ErrorFree();
void ICE_Texture_DefaultAllFree();

#endif