#include "Sound.h"

#include "../Core/State.h"
#include "../Framework/Memory_.h"
#include "../Framework/Log.h"

extern ICE_Asset ASSET;

// MANAGER

ICE_Index ICE_SoundManager_Insert()
{
	ICE_SoundManager soundmanager = { 0 };
	soundmanager.sound_size = ICE_DEFAULT_SOUND_SIZE;
	soundmanager.sound = ICE_Calloc(soundmanager.sound_size, sizeof(ICE_Sound));

	ASSET.sound_mngr_nb++;
	ASSET.sound_mngr = ICE_Realloc(ASSET.sound_mngr, ASSET.sound_mngr_nb * sizeof(ICE_SoundManager));
	ASSET.sound_mngr[ASSET.sound_mngr_nb - 1] = soundmanager;

	ICE_Log(ICE_LOG_SUCCES, "Create SoundManager : %d", ASSET.sound_mngr_nb-1);

	return ASSET.sound_mngr_nb - 1;
}

void ICE_SoundManager_Destroy(const ICE_Index man)
{
	ICE_SoundManager *manager = &ASSET.sound_mngr[man];

	for (ICE_Index i = 0; i < manager->sound_contain; i++)
	{
		//Free everything to free in Label
		ICE_Sound_Destroy(&manager->sound[i]);
	}

	ICE_Free(manager->sound);
	ICE_Log(ICE_LOG_SUCCES, "Free SoundManager : %d", man);
}

void ICE_SoundManager_DestroyAll()
{
	ICE_SoundManager *manager = ASSET.sound_mngr;
	const ICE_Index nb_manager = ASSET.sound_mngr_nb;

	for (ICE_Index i = 0; i < nb_manager; i++)
	{
		if (!manager[i].isFree)
		{
			ICE_SoundManager_Destroy(i);
			manager[i].isFree = ICE_True;
		}
	}
	free(manager);
}

// SOUND

ICE_Sound ICE_Sound_Create(char *path)
{
	ICE_Sound sound = { 0 };

	// Assigne
	sound.filename = ICE_String_Init(path);
	sound.sound = Mix_LoadWAV(path);

	return sound;
}

ICE_Index ICE_Sound_Load(ICE_Index man, char *path) 
{
	// Insert label in array
	ASSET.sound_mngr[man].sound[ASSET.sound_mngr[man].sound_contain] = ICE_Sound_Create(path);
	ASSET.sound_mngr[man].sound_contain++;

	ICE_Log(ICE_LOG_SUCCES, "SoundManager]::[%d]::[Label]::[%d]::[Create", man, ASSET.sound_mngr[man].sound_contain - 1);

	// Test size to realloc more space
	if (ASSET.sound_mngr[man].sound_size <= ASSET.sound_mngr[man].sound_contain) {
		ICE_Sound* tmp = ICE_Realloc(ASSET.sound_mngr[man].sound, sizeof(ICE_Sound)*(ASSET.sound_mngr[man].sound_size * 2));
		// Test if realloc succes
		ICE_Log(ICE_LOG_WARNING, "SoundManager]::[%d]::[Resized]::[%d", man, ASSET.sound_mngr[man].sound_size * 2);
		ASSET.sound_mngr[man].sound = tmp;
		ASSET.sound_mngr[man].sound_size *= 2;
	}

	return ASSET.sound_mngr[man].sound_contain - 1;
}

void ICE_Sound_Clear(ICE_Sound * sound)
{
	memset(sound, 0, sizeof(ICE_Sound));
}

void ICE_Sound_Destroy(ICE_Sound * ptr)
{
	ICE_String_Delete(ptr->filename);
	Mix_FreeChunk(ptr->sound);
}

// GET

ICE_Sound * ICE_Sound_Get(ICE_Index man, ICE_Index nb)
{
	return &ASSET.sound_mngr[man].sound[nb];
}

// PLAY

int ICE_Sound_Play(ICE_Sound * sound, const int volume) 
{
	if (sound->sound != NULL) {
		Mix_Volume(Mix_PlayChannel(-1, sound->sound, 0), volume);
		return 1;
	}
	return -1;
}