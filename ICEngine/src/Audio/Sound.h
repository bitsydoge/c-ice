#ifndef DEF_ICE_SOUND
#define DEF_ICE_SOUND

#define ICE_DEFAULT_SOUND_SIZE 4
#include "TypesAudio.h"
#include "../Framework/TypesFramework.h"

// MANAGER

void ICE_SoundManager_Init();
void ICE_SoundManager_Free();

// SOUND

ICE_Sound ICE_Sound_Create(char *path);
ICE_Id ICE_Sound_Load(char *path);
void ICE_Sound_Clear(ICE_Id sound_);
void ICE_Sound_Destroy(ICE_Id sound_);
ICE_Sound* ICE_Sound_Get(ICE_Id sound_);

// PLAY

int ICE_Sound_Play(ICE_Id sound_, const int volume_);

#endif