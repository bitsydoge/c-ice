#include "hdr/Label.h"

#include <string.h>
#include <stdio.h>
#include "hdr/Terminal.h"
#include "hdr/Gui.h"
#include "hdr/Color_private.h"
#include "hdr/Color.h"


extern iceGame game;

// Create manager of Text Object
void iceLabelManagerCreate()
{
	iceLabelManager text_manager = { 0 };
	text_manager.array_size = ICE_DEFAULT_TEXT_SIZE;
	text_manager.text = calloc(text_manager.array_size, sizeof(iceLabel));
	game.labelmanager_nb++;
	game.labelmanager = realloc(game.labelmanager, game.labelmanager_nb * sizeof(iceLabelManager));
	game.labelmanager[game.labelmanager_nb - 1] = text_manager;


	printf("LabelManager number %d created \n", game.labelmanager_nb - 1);
}

// Create a text object in manager
void iceLabelCreate(unsigned int man, iceVect pos, char *label)
{
	iceLabel text = { 0 };

	text.exist = iceTrue;
	text.isFixedToWorld = iceFalse;

	text.color = iceColorNew(255, 255, 255);
	text.old_color = iceColorNew(255, 255, 255);
	text.text = _strdup(label);
	text.old_text = _strdup(label);
	text.size = 200;
	text.old_size = 200;
	text.pos.x = pos.x;
	text.pos.y = pos.y;

	game.labelmanager[man].text[game.labelmanager[man].nb_existing] = text;
	iceLabelUpdateTexture(man, game.labelmanager[man].nb_existing);
	game.labelmanager[man].nb_existing++;

	
	if (game.labelmanager[man].array_size <= game.labelmanager[man].nb_existing) {
		iceTermSetColor(iceLIGHTCYAN);
		printf("Extending TextManager size to %d \n", game.labelmanager[man].array_size * 2);
		iceTermResetColor();
		game.labelmanager[man].text = realloc(game.labelmanager[man].text, sizeof(iceLabel)*(game.labelmanager[man].array_size * 2));
		game.labelmanager[man].array_size *= 2;
	}
}

void iceLabelUpdateTexture(int man, int text)
{		
		SDL_Surface *surf = TTF_RenderText_Blended(
			game.fontmanager.size[game.labelmanager[man].text[text].size], 
			game.labelmanager[man].text[text].text, 
			iceColorToSdl(game.labelmanager[man].text[text].color)
		);
		iceTexture texture = { 0 };
		texture.handle = SDL_CreateTextureFromSurface(game.drawer.render, surf);
		texture.w = surf->w; texture.h = surf->h;
		if(game.labelmanager[man].text[text].texture.exist)
		{
			SDL_DestroyTexture(game.labelmanager[man].text[text].texture.handle);
		}
		game.labelmanager[man].text[text].texture = texture;
		game.labelmanager[man].text[text].texture.exist = iceTrue;
		SDL_FreeSurface(surf);
}

void iceLabelSetPos(int man, int text, iceVect vect)
{
	game.labelmanager[man].text[text].pos = vect;
}

void iceLabelSetSize(int man, int text, int size)
{
	game.labelmanager[man].text[text].size = size;
}

void iceLabelSetColor(const int man, int text, iceColor color)
{
	game.labelmanager[man].text[text].color = color;
}

void iceLabelSetText(int man, int text, char * string)
{
	free(game.labelmanager[man].text[text].text);
	game.labelmanager[man].text[text].text = STRDUP(string);
}

void iceLabelIsInWorld(int man, int text, iceBool bool)
{
	game.labelmanager[man].text[text].isFixedToWorld = bool;
}