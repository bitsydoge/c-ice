#include "hdr/TextureManager.h"
#include <stdio.h>
#include <string.h>

const char* _get_filename_ext(const char *filename)
{
    const char *dot = strrchr(filename, '.');
    if(!dot || dot == filename) return "";
    return dot+1;
}

ICE_TextureManager ICE_CreateTextureManager()
{
    
}

void ICE_CreateTexture(ICE_App *app, ICE_TextureManager texturemanager, char* path, Uint32 color_hex)
{
    const char* ext = _get_filename_ext(path);
    ICE_Texture *text = {0};

    if(ext == "png")
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