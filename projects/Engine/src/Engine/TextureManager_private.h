#ifndef DEF_ICE_TEXTUREMANAGER_PRIVATE_H
#define DEF_ICE_TEXTUREMANAGER_PRIVATE_H

#include "TextureManager.h"
#include "Texture_private.h"

#define ICE_DEFAULT_TEXTUREMNGR_SIZE 4

/**
 * \brief Texture Manager
 */
struct ICE_TextureManager
{
	ICE_Bool isFree;

	ICE_ID texture_size;
	ICE_ID texture_contain;
	ICE_Texture * texture;
};
typedef struct ICE_TextureManager ICE_TextureManager;

void ICE_TextureManager_Init();
void ICE_TextureManager_Destroy();

#endif