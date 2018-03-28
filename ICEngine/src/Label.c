#include "hdr/Label.h"

#include "hdr/TypesCore.h"
#include "hdr/Log.h"
#include "hdr/Color.h"

#include <string.h>
#include "hdr/Memory_.h"
#include "hdr/Label_private.h"

extern ICE_Game game;

void ICE_Label_Select_ptr(ICE_Label * set_this)
{
	game.label_select.isFromMan = 0;
	game.label_select.object_selected = set_this;
}

void ICE_Label_Select_mgr(const unsigned int man, const unsigned int nb)
{
	game.label_select.object_selected = &game.label_mngr[man].label[nb];
	game.label_select.isFromMan = 1;
	game.label_select.man = man;
	game.label_select.nb = nb;
}

void ICE_LabelManager_Insert()
{
	ICE_LabelManager text_manager = { 0 };
	text_manager.label_size = ICE_DEFAULT_LABEL_MNGR_SIZE;
	text_manager.label = ICE_Calloc(text_manager.label_size, sizeof(ICE_Label)); // Label Array
	game.label_mngr_nb++;
	game.label_mngr = ICE_Realloc(game.label_mngr, game.label_mngr_nb * sizeof(ICE_LabelManager)); // Manager Array
	game.label_mngr[game.label_mngr_nb - 1] = text_manager;

	ICE_Log(ICE_LOG_SUCCES, "LabelManager]::[%d]::[Create", game.label_mngr_nb - 1);
}

ICE_Label ICE_Label_Create(char* text, ICE_Vect pos)
{
	ICE_Label label = { 0 };

	// Assigne
	label.active = ICE_True;
	label.isFixedToWorld = ICE_False;
	label.color = ICE_Color_New(255, 255, 255);
	label.old_color = ICE_Color_New(255, 255, 255);
	label.text = ICE_String_Init(text);
	label.old_text = ICE_String_Init(text);
	label.size = 200;
	label.old_size = 200;
	label.x = pos.x;
	label.y = pos.y;

	return label;
}

void ICE_Label_Insert(const unsigned int man, char *text, const ICE_Vect pos)
{
	// Insert label in array
	game.label_mngr[man].label[game.label_mngr[man].label_contain] = ICE_Label_Create(text, pos);
	//ICE_LabelUpdateTexture(man, game.label_mngr[man].label_contain);
	game.label_mngr[man].label_contain++;

	ICE_Log(ICE_LOG_SUCCES, "LabelManager]::[%d]::[Label]::[%d]::[Create]::[String=\"%s\"", man, game.label_mngr[man].label_contain-1, text);

	// Test size to realloc more space
	if (game.label_mngr[man].label_size <= game.label_mngr[man].label_contain) {
		ICE_Label* tmp = ICE_Realloc(game.label_mngr[man].label, sizeof(ICE_Label)*(game.label_mngr[man].label_size * 2));
		// Test if realloc succes
		ICE_Log(ICE_LOG_WARNING, "LabelManager]::[%d]::[Resized]::[%d", man, game.label_mngr[man].label_size * 2);
		game.label_mngr[man].label = tmp;
		game.label_mngr[man].label_size *= 2;
		ICE_Label_SelectUpdate();
	}
}

void ICE_Label_Clear(const unsigned int man, const unsigned int label)
{
	ICE_String temp = game.label_mngr[man].label[label].text;
	ICE_String temp2 = game.label_mngr[man].label[label].old_text;
	memset(&game.label_mngr[man].label[label], 0, sizeof(ICE_Label));
	game.label_mngr[man].label[label].text = temp;
	game.label_mngr[man].label[label].old_text = temp2;
	ICE_String_Resize(&temp, 1);
	ICE_String_Resize(&temp2, 1);
}

void ICE_LabelManager_Destroy(const unsigned int man)
{
	ICE_LabelManager *manager = &game.label_mngr[man];
	for(int i = 0; i < manager->label_contain; i++)
	{
		//Free everything to free in Label
		ICE_Label_Destroy(&manager->label[i]);
	}
	ICE_Free(manager->label);
	ICE_Log(ICE_LOG_SUCCES, "LabelManager]::[%d]::[Free", man);
}

void ICE_LabelManager_DestroyAll()
{
	ICE_LabelManager *manager = game.label_mngr;
	unsigned int nb_manager = game.label_mngr_nb;
	for (int i = 0; i < nb_manager; i++)
	{
		if (!manager[i].isFree)
		{
			ICE_LabelManager_Destroy(i);
			manager[i].isFree = ICE_True;
		}
	}
	free(manager);
}

ICE_Label * ICE_Label_ReturnPtr(unsigned man, unsigned nb)
{
	return &game.label_mngr[man].label[nb];
}

void ICE_Label_Destroy(ICE_Label * ptr)
{
	ICE_String_Delete(ptr->text);
	ICE_String_Delete(ptr->old_text);
}
