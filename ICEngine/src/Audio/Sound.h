#ifndef DEF_ICE_SOUND
#define DEF_ICE_SOUND

#define ICE_DEFAULT_SOUND_SIZE 4
#include "TypesAudio.h"


// MANAGER

unsigned int ICE_SoundManager_Insert();

void ICE_SoundManager_Destroy(const unsigned int man);

void ICE_SoundManager_DestroyAll();

// SOUND

ICE_Sound ICE_Sound_Create(char *path);

unsigned int ICE_Sound_Insert(unsigned int man, char *path);

void ICE_Sound_Clear(ICE_Sound * sound);

void ICE_Sound_Destroy(ICE_Sound * ptr);

// GET

ICE_Sound * ICE_Sound_Get(unsigned int man, unsigned int nb);

// PLAY

int ICE_Sound_Play(ICE_Sound * sound, const int volume);



#endif