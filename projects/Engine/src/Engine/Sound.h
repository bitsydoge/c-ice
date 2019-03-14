#ifndef DEF_ICE_SOUND_H
#define DEF_ICE_SOUND_H

#include "Sound_private.h"

// MANAGER

void ICE_SoundManager_Init();
void ICE_SoundManager_Destroy();

// SOUND

ICE_Sound ICE_Sound_Build(char *path);
ICE_ID ICE_Sound_Load(char *path);
void ICE_Sound_Clear(ICE_ID sound_);
void ICE_Sound_Destroy(ICE_ID sound_);
ICE_Sound* ICE_Sound_Get(ICE_ID sound_);

// PLAY

int ICE_Sound_Play(ICE_ID sound_, ICE_Float volume_); 

#endif