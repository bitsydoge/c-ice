#ifndef GAME_H
#define GAME_H

typedef struct
{
	//Assets
	ICE_TextureID texture_tileset, texture_gui, texture_background, texture_items_spritesheet, texture_gui_icons;
	ICE_FontID font;
	ICE_SpriteID sprite_player;
	ICE_SpriteID items_sprite;
	ICE_MusicID main_theme;
	ICE_SoundID explosion;

	//GameObject

	ICE_GuiID rectangle;
	ICE_LabelID hello_world;
	ICE_EntityID player;


	ICE_Bool screenShotDraw;
	ICE_String screenshot_name;

} GAME_DATA;

#endif