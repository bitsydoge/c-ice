#include "SoundManager_private.h"
#include "../Framework/Memory_.h"
#include "../Framework/Log.h"
#include "Sound.h"

ICE_SoundManager * ICE_SoundManager_GetPtr()
{
	static ICE_SoundManager ICE_GLOBJ_SOUNDMANAGER = { 0 };
	return &ICE_GLOBJ_SOUNDMANAGER;
}

void ICE_SoundManager_Init()
{
	ICE_SoundManager soundmanager = { 0 };
	soundmanager.sound_size = ICE_DEFAULT_SOUND_SIZE;
	soundmanager.sound = ICE_Calloc(soundmanager.sound_size, sizeof(ICE_Sound));
	*(ICE_SoundManager_GetPtr()) = soundmanager;
	ICE_Log(ICE_LOGTYPE_SUCCES, "Init SoundManager");
}

void ICE_SoundManager_Destroy()
{
	for (ICE_ID i = 0; i < ICE_SoundManager_GetPtr()->sound_contain; i++)
		ICE_Sound_Destroy(i);

	ICE_Free(ICE_SoundManager_GetPtr()->sound);
	ICE_SoundManager_GetPtr()->sound = NULL;
	ICE_Log(ICE_LOGTYPE_SUCCES, "Free SoundManager");
}