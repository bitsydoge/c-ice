#include <stdio.h>
#include <string.h>
#include "hdr/Game.h"
#include "hdr/TextureManager.h"
#include "external/icestd.h"
#include "hdr/TerminalColor.h"

ICE_TextureManager ICE_CreateTextureManager(ICE_Game *game)
{
	ICE_TextureManager texture_manager = {0};
	texture_manager.array_size = 4;
	texture_manager.texturepack = calloc(texture_manager.array_size, sizeof(ICE_Texture));
	return texture_manager;
}

void ICE_CreateTexture(ICE_Game *app, ICE_TextureManager* texturemanager, char* path, Uint32 color_hex)
{
	char path2[500]; strcpy(path2, path);
	char* ext = icestd_ext(path2);
	icestd_sup(ext);

	ICE_Texture *text;
	if(!strcmp(ext, "PNG"))
	{
		text = ICE_LoadPNG(app->render, path);
		printf("Texture number %d created from : \"", texturemanager->nb_existing_texture);
		ICE_TC_SetColor(YELLOW);
		printf("%s", path);
		ICE_TC_ResetColor();
		printf("\"\n");
	}
	else if (!strcmp(ext, "BMP"))
	{
		if(color_hex != 0)
		{
			text = ICE_LoadBMPAlpha(app->render, path, color_hex); 
			printf("Texture number %d created from : \"", texturemanager->nb_existing_texture);
			ICE_TC_SetColor(YELLOW);
			printf("%s", path);
			ICE_TC_ResetColor();
			printf("\"\n");
		}
		else
		{
			text = ICE_LoadBMP(app->render, path);   
			printf("Texture number %d created from : \"", texturemanager->nb_existing_texture);
			ICE_TC_SetColor(YELLOW);
			printf("%s", path);
			ICE_TC_ResetColor();
			printf("\"\n");
		}
	}
	else
	{
		text = ICE_LoadBMP(app->render, "res/img/error");   
		ICE_TC_SetColor(LIGHTRED);
		printf("ERROR ");
		ICE_TC_ResetColor();
		printf(": %s is not a valid filetype for loading texture.\n", ext);

	}
	text->exist=1;
	texturemanager->texturepack[texturemanager->nb_existing_texture] = *text;
	texturemanager->nb_existing_texture++;
	if(texturemanager->array_size <= texturemanager->nb_existing_texture)
	{
		ICE_TC_SetColor(LIGHTCYAN);
		printf("Extending texturepack size to %d \n", texturemanager->array_size*2);
		ICE_TC_ResetColor();
		texturemanager->texturepack = realloc(texturemanager->texturepack, sizeof(ICE_Texture)*(texturemanager->array_size*2));
		texturemanager->array_size*=2; 
	}
}
