#include "Music.h"

#include "../Framework/Memory_.h"
#include "../Framework/Log.h"
#include "../External/physfs/physfs.h"
#include "../External/physfs/physfsrwops.h"
#include "MusicManager_private.h"
#include "Pack.h"

#include "IO_private.h"

ICE_ID last_loaded_music = (ICE_ID)-1;

/* MUSIC */

ICE_TextureID ICE_Music_GetLastLoaded()
{
	return last_loaded_music;
}

ICE_MusicID ICE_Music_Load(ICE_StringStd path_)
{
	ICE_IO ops = NULL;

	if(ICE_Pack_isPathFromPak(path_))
	{
		PHYSFS_File * ph_file = PHYSFS_openRead(path_ + 6);
		ops = (ICE_IO)ICE_IO_MakeFromSDL2((void*)PHYSFSRWOPS_makeRWops(ph_file));
	}
	else
	{
		ops = (ICE_IO)ICE_IO_MakeFromSDL2((void*)SDL_RWFromFile(path_, "rb"));
	}

	ICE_ID temp_id = ICE_Music_Load_RW(ops);

	if(temp_id != (ICE_ID)-1)
		ICE_Log_Succes("Music loaded from path : ID(%ld), Path(\"%s\")",temp_id, path_);
	else
		ICE_Log_Error("Music didn't loaded from file : %s", path_);

	return temp_id;
}


ICE_Music ICE_Music_Build_RW(ICE_IO ops)
{
	ICE_Music music = {0};
	// Assigne
	music.sdl_handle = Mix_LoadMUS_RW((SDL_RWops*)ops, 1);
	if(music.sdl_handle == NULL)
		ICE_Log(ICE_LOGTYPE_ERROR, "Load Music : %s", Mix_GetError());
	return music;
}

ICE_MusicID ICE_Music_Load_RW(ICE_IO ops)
{
	ICE_MusicManager_GetPtr()->music[ICE_MusicManager_GetPtr()->music_contain] = ICE_Music_Build_RW(ops);

	ICE_MusicManager_GetPtr()->music_contain++;

	if (ICE_MusicManager_GetPtr()->music_size <= ICE_MusicManager_GetPtr()->music_contain) {
		ICE_Music* tmp = ICE_Realloc(ICE_MusicManager_GetPtr()->music, sizeof(ICE_Music)*(ICE_MusicManager_GetPtr()->music_size * 2));
		ICE_MusicManager_GetPtr()->music = tmp;
		ICE_MusicManager_GetPtr()->music_size *= 2;
	}
	return ICE_MusicManager_GetPtr()->music_contain - 1;
}


void ICE_Music_Clear(ICE_MusicID music_)
{
	memset(ICE_MusicManager_GetPtr()->music, 0, sizeof(ICE_Music));
}

void ICE_Music_Destroy(ICE_MusicID music_)
{
	ICE_String_Free(ICE_MusicManager_GetPtr()->music[music_].filename);
	Mix_FreeMusic(ICE_MusicManager_GetPtr()->music[music_].sdl_handle);
}

// PLAY

int ICE_Music_Play(ICE_MusicID music_, ICE_Float volume_)
{
	if (ICE_MusicManager_GetPtr()->music[music_].sdl_handle != NULL) 
	{
		Mix_PlayMusic(ICE_MusicManager_GetPtr()->music[music_].sdl_handle, -1);
		Mix_VolumeMusic((int)volume_*128);
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
	return &ICE_MusicManager_GetPtr()->music[music_];
}