#ifndef DEF_ICE_SOUND
#define DEF_ICE_SOUND 
#include "Struct.h"

void ICE_CreateSoundManager(ICE_Game *game);
void ICE_CreateMusic(ICE_Game *game, char *path);
void ICE_CreateSound(ICE_Game *game, char *path);
void ICE_PlayMusic(ICE_Game *game, const int nb);
void ICE_PlaySound(ICE_Game *game, const int chunk, const int volume);

#endif