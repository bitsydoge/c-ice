#ifndef DEF_ICE_TEXTURE
#define DEF_ICE_TEXTURE

#define ICE_DEFAULT_TEXTURE_SIZE 4

/// Create the texture manager with a default number of texture, everytime the number of texture is too high, it will double
void iceTextureManagerCreate();
/// Create a Texture in the choosed manager; Return the texture number
int iceTextureCreate(int manager, char* path);
/// Get a texture width
int iceTextureGetWidth(int manager, int texture);
/// Get a texture height
int iceTextureGetHeight(int manager, int texture);

#endif
