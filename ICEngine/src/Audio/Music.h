#ifndef DEF_ICE_MUSIC
#define DEF_ICE_MUSIC

#define ICE_DEFAULT_MUSIC_SIZE 4

#include "TypesAudio.h"

size_t ICE_MusicManager_Insert();
void ICE_MusicManager_Destroy(const size_t man);
void ICE_MusicManager_DestroyAll();

// MUSIC

ICE_Music ICE_Music_Create(char *path);
size_t ICE_Music_Insert(size_t man, char *path);
void ICE_Music_Clear(ICE_Music * music);
void ICE_Music_Destroy(ICE_Music * ptr);

// GET

ICE_Music * ICE_Music_Get(size_t man, size_t nb);

// PLAY

int ICE_Music_Play(ICE_Music * music, const int volume);
void ICE_Music_Pause();
void ICE_Music_Resume();

#endif