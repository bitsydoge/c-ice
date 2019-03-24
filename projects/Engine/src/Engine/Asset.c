#include "MusicManager_private.h"
#include "TextureManager_private.h"

#include "FontManager_private.h"
#include "SoundManager_private.h"
#include "Resources_private.h"
#include "TagManager_private.h"

void ICE_Asset_Init()
{
	// ASSET MANAGER INIT
	ICE_TextureManager_Init();
	ICE_FontManager_Init();
	ICE_SoundManager_Init();
	ICE_MusicManager_Init();
	ICE_TagManager_Init();

	ICE_Resources_TextureErrorInit();
	ICE_Resources_TextureDefaultGuiInit();
	ICE_Resources_FontDefault();
}

void ICE_Asset_Destroy()
{
	ICE_TextureManager_Destroy();
	ICE_FontManager_Destroy();
	ICE_SoundManager_Destroy();
	ICE_MusicManager_Destroy();
	ICE_TagManager_Destroy();
}