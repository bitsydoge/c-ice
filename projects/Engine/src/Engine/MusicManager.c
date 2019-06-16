#include "MusicManager_private.h"
#include "../Framework/Memory_.h"
#include "../Framework/Log.h"
#include "Music.h"

ICE_MusicManager * ICE_MusicManager_GetPtr()
{
	static ICE_MusicManager ICE_GLOBJ_MUSICMANAGER = { 0 };
	return &ICE_GLOBJ_MUSICMANAGER;
}

/* MANAGER */

void ICE_MusicManager_Init()
{
	ICE_MusicManager * ptr_manager = ICE_MusicManager_GetPtr();
	ICE_MusicManager musicmanager = { 0 };
	musicmanager.music_size = ICE_DEFAULT_MUSIC_SIZE;
	musicmanager.music = ICE_Calloc(musicmanager.music_size, sizeof(ICE_Music));
	*ptr_manager = musicmanager;
	ICE_Log(ICE_LOGTYPE_SUCCES, "Init MusicManager");
}

void ICE_MusicManager_Destroy()
{
	for (ICE_ID i = 0; i < ICE_MusicManager_GetPtr()->music_contain; i++)
		ICE_Music_Destroy(i);

	ICE_Free(ICE_MusicManager_GetPtr()->music);
	ICE_MusicManager_GetPtr()->music = NULL;
	ICE_Log(ICE_LOGTYPE_SUCCES, "Free MusicManager");
}