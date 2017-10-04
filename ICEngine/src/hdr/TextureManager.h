#include "Texture.h"
#include "App.h"

typedef struct
{
    unsigned short array_size;
    unsigned short nb_existing_texture;
    ICE_Texture* texturepack;

} ICE_TextureManager;

const char *_get_filename_ext(const char *filename);
void ICE_CreateTexture(ICE_App *app, ICE_TextureManager texturemanager, char* path, Uint32 color_hex);