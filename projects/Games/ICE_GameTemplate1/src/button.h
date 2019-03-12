#pragma once

struct GG_Button
{
	ICE_TextureID texture;
	ICE_TextureID texture_hover;
	ICE_TextureID texture_hover_clicked;
	ICE_GuiID gui_object;
	ICE_LabelID text;
	int size;
	void(*callback)(struct GG_Button*);
};

struct GG_Button GG_Button_Create(ICE_TextureID texture, ICE_TextureID text_hover, ICE_TextureID text_hover_clicked, ICE_Box box, ICE_StringStd string_, int size, void(*callback)(struct GG_Button*));
void GG_Button_Update(struct GG_Button* button);