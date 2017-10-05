#include <stdio.h>
#include <string.h>
#include "hdr/TextureManager.h"
#include "external/icestd.h"

ICE_TextureManager ICE_CreateTextureManager()
{
	ICE_TextureManager texture_manager = {0};

	return texture_manager;
}

void ICE_CreateTexture(ICE_App *app, ICE_TextureManager texturemanager, char* path, const Uint32 color_hex)
{
    char* ext = icestd_ext(path);
	//icestd_sup(ext);
	printf("%s\n", ext);
    ICE_Texture *text;

    if(!strcmp("png")
    {
        text = ICE_LoadPNG(app->render, path);
        printf("It's a PNG\n");
    }
    else
    {
        if(color_hex != 0)
        {
            text = ICE_LoadBMPAlpha(app->render, path, color_hex); 
            printf("It's a BMP Alpha\n");
        }
        else
        {
            text = ICE_LoadBMP(app->render, path);   
            printf("It's a BMP\n");
        }
    }
    text->exist=1;
}
