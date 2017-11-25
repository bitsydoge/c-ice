#ifndef DEF_ICE_SOUND
#define DEF_ICE_SOUND 

#include "StructCore.h"
#include "stdio.h"

#define ICE_DEFAULT_MUSIC_SIZE 4
#define ICE_DEFAULT_SOUND_SIZE 4

void iceSoundManagerCreate(iceGame* game);

void iceSoundCreate(iceGame* game, char* path);

int iceSoundPlay(iceGame* game, const int chunk, const int volume);

#endif
