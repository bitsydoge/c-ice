#include "Music.h"

#include "../Core/TypesCore.h"
#include "../Framework/Memory_.h"
#include "../Framework/Log.h"

extern ICE_Asset ASSET;

// MANAGER

void ICE_MusicManager_Init()
{
	ICE_MusicManager musicmanager = { 0 };
	musicmanager.music_size = ICE_DEFAULT_MUSIC_SIZE;
	musicmanager.music = ICE_Calloc(musicmanager.music_size, sizeof(ICE_Music));
	ASSET.music_mngr = musicmanager;
	ICE_Log(ICE_LOG_SUCCES, "Init MusicManager");
}

void ICE_MusicManager_Free()
{
	for (ICE_Id i = 0; i < ASSET.music_mngr.music_contain; i++)
	{
		//Free everything to free in Label
		ICE_Music_Destroy(i);
	}
	ICE_Free(ASSET.music_mngr.music);
	ICE_Log(ICE_LOG_SUCCES, "Free MusicManager");
}

// MUSIC

ICE_Music ICE_Music_Create(char *path_)
{
	ICE_Music music;
	// Assigne
	music.filename = ICE_String_Init(path_);
	music.sdl_handle = Mix_LoadMUS(path_);
	if(music.sdl_handle == NULL)
		ICE_Log(ICE_LOG_ERROR, "%s", Mix_GetError());
	return music;
}

ICE_Id ICE_Music_Load(char *path_)
{
	// Insert label in array
	ASSET.music_mngr.music[ASSET.music_mngr.music_contain] = ICE_Music_Create(path_);
	ASSET.music_mngr.music_contain++;
	ICE_Log(ICE_LOG_SUCCES, "Create Music %d from %s", ASSET.music_mngr.music_contain - 1, path_);
	// Test size to realloc more space
	if (ASSET.music_mngr.music_size <= ASSET.music_mngr.music_contain) {
		ICE_Music* tmp = ICE_Realloc(ASSET.music_mngr.music, sizeof(ICE_Music)*(ASSET.music_mngr.music_size * 2));
		// Test if realloc succes
		ICE_Log(ICE_LOG_WARNING, "MusicManager Resized to %d", ASSET.music_mngr.music_size * 2);
		ASSET.music_mngr.music = tmp;
		ASSET.music_mngr.music_size *= 2;
	}
	return ASSET.music_mngr.music_contain - 1;
}

void ICE_Music_Clear(ICE_Id music_)
{
	memset(ASSET.music_mngr.music, 0, sizeof(ICE_Music));
}

void ICE_Music_Destroy(ICE_Id music_)
{
	ICE_String_Delete(ASSET.music_mngr.music[music_].filename);
	Mix_FreeMusic(ASSET.music_mngr.music[music_].sdl_handle);
}

// PLAY

int ICE_Music_Play(ICE_Id music_, const int volume_)
{
	if (ASSET.music_mngr.music[music_].sdl_handle != NULL) 
	{
		Mix_PlayMusic(ASSET.music_mngr.music[music_].sdl_handle, -1);
		Mix_VolumeMusic(volume_);
		return 1;
	}
	return -1;
}

void ICE_Music_Pause()
{
	Mix_PauseMusic();
}

void ICE_Music_Resume()
{
	Mix_ResumeMusic();
}

ICE_Music* ICE_Music_Get(ICE_Id music_)
{
	return &ASSET.music_mngr.music[music_];
}