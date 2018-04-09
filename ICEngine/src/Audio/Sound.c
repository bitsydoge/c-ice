#include "Sound.h"

#include "../Core/State.h"
#include "../Framework/Memory_.h"
#include "../Framework/Log.h"

extern ICE_Asset asset;

// MANAGER

size_t ICE_SoundManager_Insert()
{
	ICE_SoundManager soundmanager = { 0 };
	soundmanager.sound_size = ICE_DEFAULT_SOUND_SIZE;
	soundmanager.sound = ICE_Calloc(soundmanager.sound_size, sizeof(ICE_Sound));

	asset.sound_mngr_nb++;
	asset.sound_mngr = ICE_Realloc(asset.sound_mngr, asset.sound_mngr_nb * sizeof(ICE_SoundManager));
	asset.sound_mngr[asset.sound_mngr_nb - 1] = soundmanager;

	ICE_Log(ICE_LOG_SUCCES, "SoundManager]::[%d]::[Create", asset.sound_mngr_nb-1);

	return asset.sound_mngr_nb - 1;
}

void ICE_SoundManager_Destroy(const size_t man)
{
	ICE_SoundManager *manager = &asset.sound_mngr[man];

	for (size_t i = 0; i < manager->sound_contain; i++)
	{
		//Free everything to free in Label
		ICE_Sound_Destroy(&manager->sound[i]);
	}

	ICE_Free(manager->sound);
	ICE_Log(ICE_LOG_SUCCES, "SoundManager]::[%d]::[Free", man);
}

void ICE_SoundManager_DestroyAll()
{
	ICE_SoundManager *manager = asset.sound_mngr;
	size_t nb_manager = asset.sound_mngr_nb;

	for (size_t i = 0; i < nb_manager; i++)
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

size_t ICE_Sound_Insert(size_t man, char *path) 
{
	// Insert label in array
	asset.sound_mngr[man].sound[asset.sound_mngr[man].sound_contain] = ICE_Sound_Create(path);
	asset.sound_mngr[man].sound_contain++;

	ICE_Log(ICE_LOG_SUCCES, "SoundManager]::[%d]::[Label]::[%d]::[Create", man, asset.sound_mngr[man].sound_contain - 1);

	// Test size to realloc more space
	if (asset.sound_mngr[man].sound_size <= asset.sound_mngr[man].sound_contain) {
		ICE_Sound* tmp = ICE_Realloc(asset.sound_mngr[man].sound, sizeof(ICE_Sound)*(asset.sound_mngr[man].sound_size * 2));
		// Test if realloc succes
		ICE_Log(ICE_LOG_WARNING, "SoundManager]::[%d]::[Resized]::[%d", man, asset.sound_mngr[man].sound_size * 2);
		asset.sound_mngr[man].sound = tmp;
		asset.sound_mngr[man].sound_size *= 2;
	}

	return asset.sound_mngr[man].sound_contain - 1;
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

ICE_Sound * ICE_Sound_Get(size_t man, size_t nb)
{
	return &asset.sound_mngr[man].sound[nb];
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