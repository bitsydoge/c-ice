#ifndef DEF_ICE_SOUND
#define DEF_ICE_SOUND

#define ICE_DEFAULT_SOUND_SIZE 4
#include "TypesAudio.h"
#include "../Framework/TypesFramework.h"

// MANAGER

ICE_Id ICE_SoundManager_Insert();

void ICE_SoundManager_Destroy(const ICE_Id man);

void ICE_SoundManager_DestroyAll();

// SOUND

ICE_Sound ICE_Sound_Create(char *path);

ICE_Id ICE_Sound_Load(ICE_Id man, char *path);

void ICE_Sound_Clear(ICE_Sound * sound);

void ICE_Sound_Destroy(ICE_Sound * ptr);

// GET

ICE_Sound * ICE_Sound_Get(ICE_Id man, ICE_Id nb);

// PLAY

int ICE_Sound_Play(ICE_Sound * sound, const int volume);

#endif