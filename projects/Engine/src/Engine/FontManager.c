#include "FontManager_private.h"
#include "../Framework/Memory_.h"
#include "../Framework/Log.h"
#include "Font.h"

ICE_FontManager ICE_GLOBJ_FONTMANAGER = {0};

ICE_FontManager * ICE_FontManager_GetPtr()
{
	return &ICE_GLOBJ_FONTMANAGER;
}

void ICE_FontManager_Init()
{
	ICE_FontManager font_manager = { 0 };
	font_manager.font_size = ICE_DEFAULT_FONT_MNGR_SIZE;
	font_manager.font_array = ICE_Calloc(font_manager.font_size, sizeof(ICE_Font));

	ICE_GLOBJ_FONTMANAGER = font_manager;

	ICE_Log(ICE_LOGTYPE_SUCCES, "Init FontManager");
}

void ICE_FontManager_Destroy()
{

	for (ICE_ID i = 0; i < ICE_GLOBJ_FONTMANAGER.font_contain; i++)
	{
		//Free everything to free in Font
		ICE_Font_Destroy(ICE_GLOBJ_FONTMANAGER.font_array[i].id);
	}

	ICE_Free(ICE_GLOBJ_FONTMANAGER.font_array);
	ICE_Log(ICE_LOGTYPE_SUCCES, "Destroy FontManager");
}