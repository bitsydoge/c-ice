#ifndef DEF_ICE_MUSIC
#define DEF_ICE_MUSIC

#define ICE_DEFAULT_MUSIC_SIZE 4

#include "TypesAudio.h"

unsigned int ICE_MusicManager_Insert();
void ICE_MusicManager_Destroy(const unsigned int man);
void ICE_MusicManager_DestroyAll();

// MUSIC

ICE_Music ICE_Music_Create(char *path);
unsigned int ICE_Music_Insert(unsigned int man, char *path);
void ICE_Music_Clear(ICE_Music * music);
void ICE_Music_Destroy(ICE_Music * ptr);

// GET

ICE_Music * ICE_Music_Get(unsigned int man, unsigned int nb);

// PLAY

int ICE_Music_Play(ICE_Music * music, const int volume);
void ICE_Music_Pause();
void ICE_Music_Resume();

#endif