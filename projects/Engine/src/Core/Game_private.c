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
#include "../Graphics/Texture_private.h"

ICE_Game GAME = { 0 };
extern ICE_Asset ASSET;

void ICE_Game_Init()
{
	GAME.current = &GAME.state_main;
	GAME.state_main.name = ICE_String_Init("Main_State");
	
	// Asset
	ICE_TextureManager_Init();
#include "../Ressources/bin/err512_png.c"
	ASSET.texture_error = ICE_Texture_LoadFromFile_RW(SDL_RWFromMem(ICE_Ressource_err512_png, ICE_Ressource_err512_png_length));
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
	ICE_String_Free(GAME.state_main.name);

	ICE_TextureManager_Destroy();
	ICE_SpriteManager_Destroy();
	ICE_SoundManager_Destroy();
	ICE_MusicManager_Destroy();

	ICE_LabelManager_Destroy(NULL);
	ICE_GuiManager_Destroy(NULL);
	ICE_EntityManager_Destroy(NULL);

	ICE_Data_DestroyAll(NULL);
}