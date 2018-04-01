#include "../Core/TypesCore.h"
#include <string.h>

extern ICE_Game game;

/*

void ICE_Draw_LabelScreen()
{
	ICE_State * current = game.state_mngr.current;

	for (int i = 0; i < current->object.label_mngr_nb; i++)
		for (int j = 0; j < current->object.label_mngr[i].label_contain; j++)
		{
			if (current->object.label_mngr[i].label[j].active)
			{
				if (
					strcmp(game.labelmanager[i].text[j].text, game.labelmanager[i].text[j].old_text) ||
					game.labelmanager[i].text[j].size != game.labelmanager[i].text[j].old_size ||
					game.labelmanager[i].text[j].color != game.labelmanager[i].text[j].old_color
					)
				{
					iceLabelUpdateTexture(i, j);
					game.labelmanager[i].text[j].old_color = game.labelmanager[i].text[j].color;
					game.labelmanager[i].text[j].old_size = game.labelmanager[i].text[j].size;
					free(game.labelmanager[i].text[j].old_text);
					game.labelmanager[i].text[j].old_text = STRDUP(game.labelmanager[i].text[j].text);
				}

				iceBox box = iceBoxNew(
					game.labelmanager[i].text[j].pos.x,
					game.labelmanager[i].text[j].pos.y,
					game.labelmanager[i].text[j].texture.w,
					game.labelmanager[i].text[j].texture.h
				);

				// Fixed to screen 
				if (!game.labelmanager[i].text[j].isFixedToWorld)
					iceTextureRenderCenteredTexture(&game.labelmanager[i].text[j].texture, NULL, &box);
			}
		}
}

void ICE_Draw_LabelWorld()
{
	for (int i = 0; i < game.labelmanager_nb; i++)
		for (int j = 0; j < game.labelmanager[i].nb_existing; j++)
		{
			if (game.labelmanager[i].text[j].exist)
			{
				if (
					strcmp(game.labelmanager[i].text[j].text, game.labelmanager[i].text[j].old_text) ||
					game.labelmanager[i].text[j].size != game.labelmanager[i].text[j].old_size ||
					game.labelmanager[i].text[j].color != game.labelmanager[i].text[j].old_color
					)
				{
					iceLabelUpdateTexture(i, j);
					game.labelmanager[i].text[j].old_color = game.labelmanager[i].text[j].color;
					game.labelmanager[i].text[j].old_size = game.labelmanager[i].text[j].size;
					free(game.labelmanager[i].text[j].old_text);
					game.labelmanager[i].text[j].old_text = STRDUP(game.labelmanager[i].text[j].text);
				}

				iceBox box = iceBoxNew(
					game.labelmanager[i].text[j].pos.x,
					game.labelmanager[i].text[j].pos.y,
					game.labelmanager[i].text[j].texture.w,
					game.labelmanager[i].text[j].texture.h
				);

				// Fixed to World 
				if (game.labelmanager[i].text[j].isFixedToWorld)
					iceTextureRenderCenteredTexture(&game.labelmanager[i].text[j].texture, NULL, (iceBox[]) { iceCameraWorldScreen(box) });
			}
		}
}

*/