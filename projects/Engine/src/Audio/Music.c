#include "Music.h"

#include "../Core/TypesCore.h"
#include "../Framework/Memory_.h"
#include "../Framework/Log.h"
#include "../External/physfs/physfs.h"
#include "../External/physfs/physfsrwops.h"
#include "../Core/Asset.h"

extern ICE_Asset ASSET;

ICE_ID last_loaded_music = (ICE_ID)-1;

/* MANAGER */

void ICE_MusicManager_Init()
{
	ICE_MusicManager musicmanager = { 0 };
	musicmanager.music_size = ICE_DEFAULT_MUSIC_SIZE;
	musicmanager.music = ICE_Calloc(musicmanager.music_size, sizeof(ICE_Music));
	ASSET.music_mngr = musicmanager;
	ICE_Log(ICE_LOGTYPE_SUCCES, "Init MusicManager");
}

void ICE_MusicManager_Destroy()
{
	for (ICE_ID i = 0; i < ASSET.music_mngr.music_contain; i++)
		ICE_Music_Destroy(i);

	ICE_Free(ASSET.music_mngr.music);
	ASSET.music_mngr.music = NULL;
	ICE_Log(ICE_LOGTYPE_SUCCES, "Free MusicManager");
}

/* MUSIC */

ICE_TextureID ICE_Music_GetLastLoaded()
{
	return last_loaded_music;
}

ICE_MusicID ICE_Music_Load(char* path_)
{
	SDL_RWops * ops = NULL;

	if(ICE_AssetPak_isPathFromPak(path_))
	{
		PHYSFS_File * ph_file = PHYSFS_openRead(path_ + 6);
		ops = PHYSFSRWOPS_makeRWops(ph_file);
	}
	else
	{
		ops = SDL_RWFromFile(path_, "rb");
	}

	ICE_ID temp_id = ICE_Music_Load_RW(ops);

	if(temp_id != (ICE_ID)-1)
		ICE_Log_Succes("Music loaded from path : ID(%ld), Path(\"%s\")",temp_id, path_);
	else
		ICE_Log_Error("Music didn't loaded from file : %s", path_);

	return temp_id;
}


ICE_Music ICE_Music_Build_RW(SDL_RWops * ops)
{
	ICE_Music music = {0};
	// Assigne
	music.sdl_handle = Mix_LoadMUS_RW(ops, 1);
	if(music.sdl_handle == NULL)
		ICE_Log(ICE_LOGTYPE_ERROR, "Load Music : %s", Mix_GetError());
	return music;
}

ICE_MusicID ICE_Music_Load_RW(SDL_RWops * ops)
{
	ASSET.music_mngr.music[ASSET.music_mngr.music_contain] = ICE_Music_Build_RW(ops);
	ASSET.music_mngr.music_contain++;

	if (ASSET.music_mngr.music_size <= ASSET.music_mngr.music_contain) {
		ICE_Music* tmp = ICE_Realloc(ASSET.music_mngr.music, sizeof(ICE_Music)*(ASSET.music_mngr.music_size * 2));
		ASSET.music_mngr.music = tmp;
		ASSET.music_mngr.music_size *= 2;
	}
	return ASSET.music_mngr.music_contain - 1;
}


void ICE_Music_Clear(ICE_ID music_)
{
	memset(ASSET.music_mngr.music, 0, sizeof(ICE_Music));
}

void ICE_Music_Destroy(ICE_ID music_)
{
	ICE_String_Free(ASSET.music_mngr.music[music_].filename);
	Mix_FreeMusic(ASSET.music_mngr.music[music_].sdl_handle);
}

// PLAY

int ICE_Music_Play(ICE_ID music_, ICE_Float volume_)
{
	if (ASSET.music_mngr.music[music_].sdl_handle != NULL) 
	{
		Mix_PlayMusic(ASSET.music_mngr.music[music_].sdl_handle, -1);
		Mix_VolumeMusic(volume_*128);
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

ICE_Music* ICE_Music_Get(ICE_ID music_)
{
	return &ASSET.music_mngr.music[music_];
}