#include "hdr/Label.h"

#include "hdr/TypesCore.h"
#include "hdr/Log.h"
#include "hdr/Color.h"
#include "hdr/Debug_private.h"

#include <string.h>
#include "hdr/Memory_.h"

extern ICE_Game game;

void ICE_LabelManagerCreate()
{
	ICE_LabelManager text_manager = { 0 };
	text_manager.label_size = ICE_DEFAULT_LABEL_MNGR_SIZE;
	text_manager.label = ICE_Calloc(text_manager.label_size, sizeof(ICE_Label)); // Label Array
	game.label_mngr_nb++;
	game.label_mngr = ICE_Realloc(game.label_mngr, game.label_mngr_nb * sizeof(ICE_LabelManager)); // Manager Array
	game.label_mngr[game.label_mngr_nb - 1] = text_manager;

	ICE_Log(ICE_LOG_SUCCES, "LABELMANAGER]::[%d]::[CREATE", game.label_mngr_nb - 1);
}

void ICE_LabelCreate(const unsigned int man, const ICE_Vect pos, char *text)
{
	ICE_Label label = { 0 };

	// Assigne
	label.active = ICE_True;
	label.isFixedToWorld = ICE_False;
	label.color = ICE_ColorNew(255, 255, 255);
	label.old_color = ICE_ColorNew(255, 255, 255);
	label.text = ICE_StringInit(text);
	label.old_text = ICE_StringInit(text);
	label.size = 200;
	label.old_size = 200;
	label.x = pos.x;
	label.y = pos.y;

	// Insert label in array
	game.label_mngr[man].label[game.label_mngr[man].label_contain] = label;
	//ICE_LabelUpdateTexture(man, game.label_mngr[man].label_contain);
	game.label_mngr[man].label_contain++;

	ICE_Log(ICE_LOG_SUCCES, "LABELMANAGER]::[%d]::[LABEL]::[%d]::[CREATE]::[String=\"%s\"", man, game.label_mngr[man].label_contain-1, text);

	// Test size to realloc more space
	if (game.label_mngr[man].label_size <= game.label_mngr[man].label_contain) {
		ICE_Label* tmp = ICE_Realloc(game.label_mngr[man].label, sizeof(ICE_Label)*(game.label_mngr[man].label_size * 2));
		// Test if realloc succes
		if (tmp)
		{
			ICE_Log(ICE_LOG_WARNING, "LABELMANAGER]::[%d]::[RESIZED]::[%d", man, game.label_mngr[man].label_size * 2);
			game.label_mngr[man].label = tmp;
			game.label_mngr[man].label_size *= 2;
		}
		else
		{
			ICE_Log(ICE_LOG_CRITICAL, "LABELMANAGER]::[%d]::[RESIZE]::[FAIL", man);
			ICE_Assert(tmp != NULL, "Label Manager failed to realloc");
		}
	}
}

void ICE_LabelClear(const unsigned int man, const unsigned int label)
{
	ICE_String temp = game.label_mngr[man].label[label].text;
	ICE_String temp2 = game.label_mngr[man].label[label].old_text;
	memset(&game.label_mngr[man].label[label], 0, sizeof(ICE_Label));
	game.label_mngr[man].label[label].text = temp;
	game.label_mngr[man].label[label].old_text = temp2;
	ICE_StringResize(&temp, 1);
	ICE_StringResize(&temp2, 1);
}

void ICE_LabelManagerDestroy(const unsigned int man)
{
	ICE_LabelManager *manager = &game.label_mngr[man];
	for(int i = 0; i < manager->label_contain; i++)
	{
		//Free everything to free in Label
		ICE_StringDelete(manager->label[i].text);
		ICE_StringDelete(manager->label[i].old_text);
	}
	ICE_Free(manager->label);
}

void ICE_LabelManagerDestroyAll()
{
	ICE_LabelManager *manager = game.label_mngr;
	unsigned int nb_manager = game.label_mngr_nb;
	for (int i = 0; i < nb_manager; i++)
	{
		if (!manager[i].isFree)
		{
			ICE_LabelManagerDestroy(i);
			manager[i].isFree = ICE_True;
		}
	}
	free(manager);
}
