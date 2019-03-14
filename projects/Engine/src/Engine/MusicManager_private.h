#ifndef DEF_ICE_MUSICMANAGER_PRIVATE_H
#define DEF_ICE_MUSICMANAGER_PRIVATE_H

#include "../Framework/BasicTypes.h"
#include "Music_private.h"

struct ICE_MusicManager
{
	ICE_Bool isFree;
	unsigned short music_size;
	unsigned short music_contain;
	ICE_Music* music;

}; typedef struct ICE_MusicManager ICE_MusicManager;

void ICE_MusicManager_Init();
void ICE_MusicManager_Destroy();

#endif