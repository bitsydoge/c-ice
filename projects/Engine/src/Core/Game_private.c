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
#include "../Graphics/Gui_private.h"

ICE_Game GAME = { 0 };

void ICE_Game_Init()
{
	GAME.current = &GAME.state_main;
	GAME.state_main.name = ICE_String_Init("Main_State");
	
	// Asset
	ICE_TextureManager_Init();
	ICE_SpriteManager_Init();
	ICE_SoundManager_Init();
	ICE_MusicManager_Init();

	// Items
	ICE_EntityManager_Init(NULL);
	ICE_GuiManager_Init(NULL);
	ICE_LabelManager_Init(NULL);

}

void ICE_Game_Quit()
{
	ICE_String_Delete(GAME.state_main.name);

	ICE_TextureManager_Destroy();
	ICE_SpriteManager_Destroy();
	ICE_SoundManager_Destroy();
	ICE_MusicManager_Destroy();

	ICE_LabelManager_Destroy(NULL);
	ICE_GuiManager_Destroy(NULL);
	ICE_EntityManager_Destroy(NULL);

	ICE_Data_DestroyAll(NULL);
}