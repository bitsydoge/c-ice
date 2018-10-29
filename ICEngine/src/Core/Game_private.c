#include "Game_private.h"

#include "TypesCore.h"

#include "../Core/Label.h"
#include "../Core/Entity.h"
#include "../Core/Data.h"

#include "../Graphics/Gui.h"

#include "../Graphics/Texture.h"
#include "../Graphics/Sprite.h"

#include "../Audio/Music.h"
#include "../Audio/Sound.h"

ICE_Game GAME = { 0 };

void ICE_Game_Init()
{
	ICE_TextureManager_Init();
	ICE_SpriteManager_Init();
	ICE_SoundManager_Init();
	ICE_MusicManager_Init();
}

void ICE_Game_Quit()
{
	ICE_TextureManager_Free();
	ICE_SpriteManager_Free();
	ICE_SoundManager_Free();
	ICE_MusicManager_Free();

	ICE_LabelManager_DestroyAll(NULL);
	ICE_GuiManager_DestroyAll(NULL);
	ICE_EntityManager_DestroyAll(NULL);
	ICE_Data_DestroyAll(NULL);
}