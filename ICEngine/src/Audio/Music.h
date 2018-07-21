#ifndef DEF_ICE_MUSIC
#define DEF_ICE_MUSIC

#define ICE_DEFAULT_MUSIC_SIZE 4

#include "TypesAudio.h"
#include "../Framework/TypesFramework.h"

ICE_Index ICE_MusicManager_Insert();
void ICE_MusicManager_Destroy(const ICE_Index man);
void ICE_MusicManager_DestroyAll();

// MUSIC

ICE_Music ICE_Music_Create(char *path);
ICE_Index ICE_Music_Load(ICE_Index man, char *path);
void ICE_Music_Clear(ICE_Music * music);
void ICE_Music_Destroy(ICE_Music * ptr);

// GET

ICE_Music * ICE_Music_Get(ICE_Index man, ICE_Index nb);

// PLAY

int ICE_Music_Play(ICE_Music * music, const int volume);
void ICE_Music_Pause();
void ICE_Music_Resume();

#endif