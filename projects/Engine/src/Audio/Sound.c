#include "Sound.h"

#include "../Core/State.h"
#include "../Framework/Memory_.h"
#include "../Framework/Log.h"

extern ICE_Asset ASSET;

/* SOUNDMANAGER */

void ICE_SoundManager_Init()
{
	ICE_SoundManager soundmanager = { 0 };
	soundmanager.sound_size = ICE_DEFAULT_SOUND_SIZE;
	soundmanager.sound = ICE_Calloc(soundmanager.sound_size, sizeof(ICE_Sound));
	ASSET.sound_mngr = soundmanager;
	ICE_Log(ICE_LOGTYPE_SUCCES, "Init SoundManager");
}

void ICE_SoundManager_Destroy()
{
	for (ICE_ID i = 0; i < ASSET.sound_mngr.sound_contain; i++)
		ICE_Sound_Destroy(i);

	ICE_Free(ASSET.sound_mngr.sound);
	ASSET.sound_mngr.sound = NULL;
	ICE_Log(ICE_LOGTYPE_SUCCES, "Free SoundManager");
}

/* SOUND */

ICE_Sound ICE_Sound_Create(char *path)
{
	ICE_Sound sound = { 0 };

	sound.filename = ICE_String_Init(path);
	sound.sdl_handle = Mix_LoadWAV(path);

	return sound;
}

ICE_ID ICE_Sound_Load(char *path_) 
{
	ASSET.sound_mngr.sound[ASSET.sound_mngr.sound_contain] = ICE_Sound_Create(path_);
	ASSET.sound_mngr.sound_contain++;
	ICE_Log(ICE_LOGTYPE_SUCCES, "Load Sound %d from \"%s\"", ASSET.sound_mngr.sound_contain - 1, path_);
	
	if (ASSET.sound_mngr.sound_size <= ASSET.sound_mngr.sound_contain) {
		ICE_Sound* tmp = ICE_Realloc(ASSET.sound_mngr.sound, sizeof(ICE_Sound)*(ASSET.sound_mngr.sound_size * 2));
		ASSET.sound_mngr.sound = tmp;
		ASSET.sound_mngr.sound_size *= 2;
	}
	return ASSET.sound_mngr.sound_contain - 1;
}

void ICE_Sound_Clear(ICE_ID sound_)
{
	memset(ASSET.sound_mngr.sound[sound_].sdl_handle, 0, sizeof(ICE_Sound));
}

void ICE_Sound_Destroy(ICE_ID sound_)
{
	ICE_String_Delete(ASSET.sound_mngr.sound[sound_].filename);
	Mix_FreeChunk(ASSET.sound_mngr.sound[sound_].sdl_handle);
}

// PLAY

int ICE_Sound_Play(ICE_ID sound_, ICE_Float volume_) 
{
	if (ASSET.sound_mngr.sound[sound_].sdl_handle != NULL) 
	{
		Mix_Volume(Mix_PlayChannel(-1, ASSET.sound_mngr.sound[sound_].sdl_handle, 0), volume_*128);
		return 1;
	}
	return -1;
}

ICE_Sound* ICE_Sound_Get(ICE_ID sound_)
{
	return &ASSET.sound_mngr.sound[sound_];
}