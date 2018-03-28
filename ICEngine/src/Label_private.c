#include "hdr/Label_private.h"

#include "hdr/TypesCore.h"

#include "hdr/Label.h"

extern ICE_Game game;

void ICE_Label_SelectUpdate()
{
	if (game.label_select.isFromMan)
	{
		ICE_Label_Select_mgr(game.label_select.man, game.label_select.nb);
	}
}