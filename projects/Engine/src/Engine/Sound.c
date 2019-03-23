#include "Sound_private.h"

#include "Types.h"
#include "../Framework/Memory_.h"
#include "../Framework/Log.h"
#include "SoundManager_private.h"


///////////////////////////////////////////////////////////////////////////////////////////
// ------------------------------------------------------------------------------------- //
// ------------------------------------   PRIVATE       -------------------------------- //
// ------------------------------------------------------------------------------------- //
///////////////////////////////////////////////////////////////////////////////////////////

ICE_Sound ICE_Sound_Build(char *path)
{
	ICE_Sound sound = { 0 };

	sound.filename = ICE_String_Init(path);
	sound.sdl_handle = Mix_LoadWAV(path);

	return sound;
}

ICE_Sound* ICE_Sound_Get(ICE_ID sound_)
{
	return &ICE_SoundManager_GetPtr()->sound[sound_];
}

///////////////////////////////////////////////////////////////////////////////////////////
// ------------------------------------------------------------------------------------- //
// ------------------------------------   PUBLIC        -------------------------------- //
// ------------------------------------------------------------------------------------- //
///////////////////////////////////////////////////////////////////////////////////////////

ICE_SoundID ICE_Sound_Load(char* path_)
{
	ICE_SoundManager_GetPtr()->sound[ICE_SoundManager_GetPtr()->sound_contain] = ICE_Sound_Build(path_);
	ICE_SoundManager_GetPtr()->sound_contain++;
	ICE_Log(ICE_LOGTYPE_SUCCES, "Load Sound %d from \"%s\"", ICE_SoundManager_GetPtr()->sound_contain - 1, path_);

	if (ICE_SoundManager_GetPtr()->sound_size <= ICE_SoundManager_GetPtr()->sound_contain) {
		ICE_Sound* tmp = ICE_Realloc(ICE_SoundManager_GetPtr()->sound, sizeof(ICE_Sound) * (ICE_SoundManager_GetPtr()->sound_size * 2));
		ICE_SoundManager_GetPtr()->sound = tmp;
		ICE_SoundManager_GetPtr()->sound_size *= 2;
	}
	return ICE_SoundManager_GetPtr()->sound_contain - 1;
}

void ICE_Sound_Destroy(ICE_SoundID sound_)
{
	ICE_String_Free(ICE_SoundManager_GetPtr()->sound[sound_].filename);
	Mix_FreeChunk(ICE_SoundManager_GetPtr()->sound[sound_].sdl_handle);
}


void ICE_Sound_Play(ICE_SoundID sound_, ICE_Float volume_) 
{
	if (ICE_SoundManager_GetPtr()->sound[sound_].sdl_handle != NULL)
	{
		Mix_Volume(Mix_PlayChannel(-1, ICE_SoundManager_GetPtr()->sound[sound_].sdl_handle, 0), (int)volume_*128);
	}
}