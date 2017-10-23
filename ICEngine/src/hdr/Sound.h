#ifndef DEF_ICE_SOUND
#define DEF_ICE_SOUND 
#include "Struct.h"

void ICE_CreateSoundSystem(ICE_Game *game);
void ICE_CreateMusic(ICE_SoundManager *manager, char *path);
void ICE_CreateSound(ICE_SoundManager *manager, char *path);
void ICE_PlayMusic(ICE_SoundManager *manager, const int nb);

#endif