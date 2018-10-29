#ifndef DEF_ICE_MUSIC
#define DEF_ICE_MUSIC

#define ICE_DEFAULT_MUSIC_SIZE 4

#include "TypesAudio.h"
#include "../Framework/TypesFramework.h"

void ICE_MusicManager_Create();
void ICE_MusicManager_Destroy();

// MUSIC

ICE_Music ICE_Music_Create(char *path);
ICE_Id ICE_Music_Load(char *path);
void ICE_Music_Clear(ICE_Id music_);
void ICE_Music_Destroy(ICE_Id music_);
ICE_Music* ICE_Music_Get(ICE_Id music_);

// PLAY

int ICE_Music_Play(ICE_Id music_, const int volume_);
void ICE_Music_Pause();
void ICE_Music_Resume();

#endif