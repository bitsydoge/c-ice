#ifndef GAME_H
#define GAME_H

typedef struct
{
	//Assets
	ICE_TextureID spritesheet, texture_gui, background, texture_items_spritesheet, texture_gui_icons;
	ICE_FontID font;
	ICE_SpriteID main_sprite;
	ICE_SpriteID items_sprite;
	ICE_MusicID main_theme;
	ICE_SoundID explosion;

	//GameObject

	ICE_GuiID rectangle;
	ICE_LabelID hello_world;
	ICE_EntityID player;

} GAME_DATA;

#endif