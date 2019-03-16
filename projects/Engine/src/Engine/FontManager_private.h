#ifndef DEF_ICE_FONTMANAGER_PRIVATE_H
#define DEF_ICE_FONTMANAGER_PRIVATE_H
#include "../Framework/BasicTypes.h"
#include "Font_private.h"

struct ICE_FontManager
{
	ICE_Bool		isFree;

	ICE_ID			font_size;
	ICE_ID			font_contain;
	ICE_Font*		font_array;

}; typedef struct ICE_FontManager ICE_FontManager;

#define ICE_DEFAULT_FONT_MNGR_SIZE 4

void ICE_FontManager_Init();
void ICE_FontManager_Destroy();

#endif