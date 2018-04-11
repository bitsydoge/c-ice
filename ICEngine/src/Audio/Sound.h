#ifndef DEF_ICE_SOUND
#define DEF_ICE_SOUND

#define ICE_DEFAULT_SOUND_SIZE 4
#include "TypesAudio.h"

// MANAGER

size_t ICE_SoundManager_Insert();

void ICE_SoundManager_Destroy(const size_t man);

void ICE_SoundManager_DestroyAll();

// SOUND

ICE_Sound ICE_Sound_Create(char *path);

size_t ICE_Sound_Load(size_t man, char *path);

void ICE_Sound_Clear(ICE_Sound * sound);

void ICE_Sound_Destroy(ICE_Sound * ptr);

// GET

ICE_Sound * ICE_Sound_Get(size_t man, size_t nb);

// PLAY

int ICE_Sound_Play(ICE_Sound * sound, const int volume);

#endif