#ifndef DEF_ICE_MUSIC
#define DEF_ICE_MUSIC

#define ICE_DEFAULT_MUSIC_SIZE 4

#include "TypesAudio.h"
#include "../Framework/TypesFramework.h"
#include "../Graphics/Camera.h"

void ICE_MusicManager_Init();
void ICE_MusicManager_Destroy();

// MUSIC

ICE_Music ICE_Music_Build(char *path);
ICE_MusicID ICE_Music_Load(char* path);
void ICE_Music_Clear(ICE_ID music_);
void ICE_Music_Destroy(ICE_ID music_);
ICE_Music* ICE_Music_Get(ICE_ID music_);

// PLAY

int ICE_Music_Play(ICE_ID music_, ICE_Float volume_);
void ICE_Music_Pause();
void ICE_Music_Resume();

#endif