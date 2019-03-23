#ifndef DEF_ICE_SOUNDMANAGER_PRIVATE_H
#define DEF_ICE_SOUNDMANAGER_PRIVATE_H

#include "SoundManager.h"
#include "Sound_private.h"

#define ICE_DEFAULT_SOUND_SIZE 4

struct ICE_SoundManager
{

	ICE_Bool isFree;
	unsigned short sound_size;
	unsigned short sound_contain;
	ICE_Sound * sound;

}; 

ICE_SoundManager* ICE_SoundManager_GetPtr();

void ICE_SoundManager_Init();
void ICE_SoundManager_Destroy();

#endif