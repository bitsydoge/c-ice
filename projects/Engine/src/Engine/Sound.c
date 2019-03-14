#include "Sound.h"

#include "../Framework/Memory_.h"
#include "../Framework/Log.h"
#include "SoundManager_private.h"

extern ICE_SoundManager ICE_GLOBJ_SOUNDMANAGER;

/* SOUND */

ICE_Sound ICE_Sound_Build(char *path)
{
	ICE_Sound sound = { 0 };

	sound.filename = ICE_String_Init(path);
	sound.sdl_handle = Mix_LoadWAV(path);

	return sound;
}

ICE_ID ICE_Sound_Load(char *path_) 
{
	ICE_GLOBJ_SOUNDMANAGER.sound[ICE_GLOBJ_SOUNDMANAGER.sound_contain] = ICE_Sound_Build(path_);
	ICE_GLOBJ_SOUNDMANAGER.sound_contain++;
	ICE_Log(ICE_LOGTYPE_SUCCES, "Load Sound %d from \"%s\"", ICE_GLOBJ_SOUNDMANAGER.sound_contain - 1, path_);
	
	if (ICE_GLOBJ_SOUNDMANAGER.sound_size <= ICE_GLOBJ_SOUNDMANAGER.sound_contain) {
		ICE_Sound* tmp = ICE_Realloc(ICE_GLOBJ_SOUNDMANAGER.sound, sizeof(ICE_Sound)*(ICE_GLOBJ_SOUNDMANAGER.sound_size * 2));
		ICE_GLOBJ_SOUNDMANAGER.sound = tmp;
		ICE_GLOBJ_SOUNDMANAGER.sound_size *= 2;
	}
	return ICE_GLOBJ_SOUNDMANAGER.sound_contain - 1;
}

void ICE_Sound_Destroy(ICE_ID sound_)
{
	ICE_String_Free(ICE_GLOBJ_SOUNDMANAGER.sound[sound_].filename);
	Mix_FreeChunk(ICE_GLOBJ_SOUNDMANAGER.sound[sound_].sdl_handle);
}

// PLAY

int ICE_Sound_Play(ICE_ID sound_, ICE_Float volume_) 
{
	if (ICE_GLOBJ_SOUNDMANAGER.sound[sound_].sdl_handle != NULL)
	{
		Mix_Volume(Mix_PlayChannel(-1, ICE_GLOBJ_SOUNDMANAGER.sound[sound_].sdl_handle, 0), volume_*128);
		return 1;
	}
	return -1;
}

ICE_Sound* ICE_Sound_Get(ICE_ID sound_)
{
	return &ICE_GLOBJ_SOUNDMANAGER.sound[sound_];
}