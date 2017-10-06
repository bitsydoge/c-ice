#include <stdio.h>
#include <string.h>
#include "hdr/TextureManager.h"
#include "external/icestd.h"
#include "hdr/TerminalColor.h"

ICE_TextureManager ICE_CreateTextureManager()
{
	ICE_TextureManager texture_manager = {0};

	return texture_manager;
}

void ICE_CreateTexture(ICE_App *app, ICE_TextureManager texturemanager, char* path, const Uint32 color_hex)
{
	char path2[500]; strcpy(path2, path);
    char* ext = icestd_ext(path2);
    icestd_sup(ext);

    ICE_Texture *text;
    if(!strcmp(ext, "PNG"))
    {
        text = ICE_LoadPNG(app->render, path);
        printf("It's a PNG\n");
    }
    else if (!strcmp(ext, "BMP"))
    {
        if(color_hex != 0)
        {
            text = ICE_LoadBMPAlpha(app->render, path, color_hex); 
			printf("Texture created from : %s\n", path);
        }
        else
        {
            text = ICE_LoadBMP(app->render, path);   
			printf("Texture created from : %s\n", path);
		}
    }
	else
	{
		ICE_TC_SetColor(RED);
		printf("ERROR ");
		ICE_TC_ResetColor();
		printf(": %s is not a valid filetype for loading texture.\n", ext);

	}
    text->exist=1;
}
