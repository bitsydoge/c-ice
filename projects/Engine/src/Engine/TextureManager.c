#include "TextureManager_private.h"

#include "../Framework/Log.h"
#include "../Framework/Memory_.h"
#include "Texture_private.h"

ICE_TextureManager ICE_GLOBJ_TEXTUREMANAGER = {0};

/* TEXTUREMANAGER */

ICE_TextureManager * ICE_TextureManager_GetPtr()
{
	return &ICE_GLOBJ_TEXTUREMANAGER;
}

void ICE_TextureManager_Init()
{
	ICE_TextureManager texture_manager = { 0 };
	texture_manager.texture_size = ICE_DEFAULT_TEXTUREMNGR_SIZE;
	texture_manager.texture = ICE_Calloc(ICE_DEFAULT_TEXTUREMNGR_SIZE, sizeof(ICE_Texture));
	ICE_GLOBJ_TEXTUREMANAGER = texture_manager;
	ICE_Log(ICE_LOGTYPE_SUCCES, "Init TextureManager");
}

void ICE_TextureManager_Destroy()
{
	for (ICE_ID i = 0; i < ICE_GLOBJ_TEXTUREMANAGER.texture_contain; i++)
		ICE_Texture_Destroy(i);

	ICE_Free(ICE_GLOBJ_TEXTUREMANAGER.texture);
	ICE_GLOBJ_TEXTUREMANAGER.texture = NULL;
	ICE_Log(ICE_LOGTYPE_SUCCES, "Free TextureManager");
}