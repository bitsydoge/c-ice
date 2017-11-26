#include "hdr/Text.h"
#include <string.h>



// Create manager of Text Object
void iceTextManagerCreate(iceGame *game)
{
	iceTextManager text_manager = { 0 };
	text_manager.array_size = ICE_DEFAULT_TEXT_SIZE;
	text_manager.text = calloc(text_manager.array_size, sizeof(iceText));
	game->textmanager_size++;
	game->textmanager = realloc(game->textmanager, game->textmanager_size * sizeof(iceTextManager));
	game->textmanager[game->texturemanager_size - 1] = text_manager;
	printf("TextManager number %d created \n", game->textmanager_size - 1);
}

// Create a text object in manager
void iceTextCreate(iceGame *game, unsigned int man, iceVect pos, char *label)
{
	iceText text = { 0 };

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

	game->textmanager[man].text[game->textmanager[man].nb_existing] = text;
	iceTextUpdateTexture(game, man, game->textmanager[man].nb_existing);
	game->textmanager[man].nb_existing++;

	
	if (game->textmanager[man].array_size <= game->textmanager[man].nb_existing) {
		iceTermSetColor(iceLIGHTCYAN);
		printf("Extending TextManager size to %d \n", game->textmanager[man].array_size * 2);
		iceTermResetColor();
		game->textmanager[man].text = realloc(game->textmanager[man].text, sizeof(iceText)*(game->textmanager[man].array_size * 2));
		game->textmanager[man].array_size *= 2;
	}
}

void iceTextUpdateTexture(iceGame *game, int man, int text)
{		
		SDL_Surface *surf = TTF_RenderText_Blended(
			game->fontmanager.size[game->textmanager[man].text[text].size], 
			game->textmanager[man].text[text].text, 
			iceColorToSdl(game->textmanager[man].text[text].color)
		);
		iceTexture texture = { 0 };
		texture.handle = SDL_CreateTextureFromSurface(game->drawer.render, surf);
		printf("Oh My Goodness, an error : %s \n", SDL_GetError());
		texture.w = surf->w; texture.h = surf->h;
		if(game->textmanager[man].text[text].texture.exist)
		{
			SDL_DestroyTexture(game->textmanager[man].text[text].texture.handle);
		}
		game->textmanager[man].text[text].texture = texture;
		game->textmanager[man].text[text].texture.exist = iceTrue;
		SDL_FreeSurface(surf);
}

void iceTextSetPos(iceGame *game, int man, int text, iceVect vect)
{
	game->textmanager[man].text[text].pos = vect;
}

void iceTextSetSize(iceGame *game, int man, int text, int size)
{
	game->textmanager[man].text[text].size = size;
}

void iceTextSetColor(iceGame *game, const int man, int text, iceColor color)
{
	game->textmanager[man].text[text].color = color;
}

void iceTextSetLabel(iceGame *game, int man, int text, char * string)
{
	free(game->textmanager[man].text[text].text);
	game->textmanager[man].text[text].text = STRDUP(string);
}

void iceTextIsFixedToWorld(iceGame *game, int man, int text, iceBool bool)
{
	game->textmanager[man].text[text].isFixedToWorld = bool;
}