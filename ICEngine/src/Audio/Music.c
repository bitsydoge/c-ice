#include "Music.h"

#include "../Core/TypesCore.h"
#include "../Framework/Memory_.h"
#include "../Framework/Log.h"

extern ICE_Asset asset;

// MANAGER

ICE_Index ICE_MusicManager_Insert()
{
	ICE_MusicManager musicmanager = { 0 };
	musicmanager.music_size = ICE_DEFAULT_MUSIC_SIZE;
	musicmanager.music = ICE_Calloc(musicmanager.music_size, sizeof(ICE_Music));

	asset.music_mngr_nb++;
	asset.music_mngr = ICE_Realloc(asset.music_mngr, asset.music_mngr_nb * sizeof(ICE_MusicManager));
	asset.music_mngr[asset.music_mngr_nb - 1] = musicmanager;

	ICE_Log(ICE_LOG_SUCCES, "MusicManager]::[%d]::[Create", asset.music_mngr_nb - 1);

	return asset.music_mngr_nb - 1;
}

void ICE_MusicManager_Destroy(const ICE_Index man)
{
	ICE_MusicManager *manager = &asset.music_mngr[man];

	for (ICE_Index i = 0; i < manager->music_contain; i++)
	{
		//Free everything to free in Label
		ICE_Music_Destroy(&manager->music[i]);
	}

	ICE_Free(manager->music);
	ICE_Log(ICE_LOG_SUCCES, "MusicManager]::[%d]::[Free", man);
}

void ICE_MusicManager_DestroyAll()
{
	ICE_MusicManager *manager = asset.music_mngr;
	ICE_Index nb_manager = asset.music_mngr_nb;

	for (ICE_Index i = 0; i < nb_manager; i++)
	{
		if (!manager[i].isFree)
		{
			ICE_MusicManager_Destroy(i);
			manager[i].isFree = ICE_True;
		}
	}
	free(manager);
}

// MUSIC

ICE_Music ICE_Music_Create(char *path)
{
	ICE_Music music = { 0 };

	// Assigne
	music.filename = ICE_WString_Init(path);
	music.music = Mix_LoadMUS(path);
	if(music.music == NULL)
	{
		ICE_Log(ICE_LOG_ERROR, "%s", Mix_GetError());
	}

	return music;
}

ICE_Index ICE_Music_Load(ICE_Index man, char *path)
{
	// Insert label in array
	asset.music_mngr[man].music[asset.music_mngr[man].music_contain] = ICE_Music_Create(path);
	asset.music_mngr[man].music_contain++;

	ICE_Log(ICE_LOG_SUCCES, "MusicManager]::[%d]::[Label]::[%d]::[Create", man, asset.music_mngr[man].music_contain - 1);

	// Test size to realloc more space
	if (asset.music_mngr[man].music_size <= asset.music_mngr[man].music_contain) {
		ICE_Music* tmp = ICE_Realloc(asset.music_mngr[man].music, sizeof(ICE_Music)*(asset.music_mngr[man].music_size * 2));
		// Test if realloc succes
		ICE_Log(ICE_LOG_WARNING, "MusicManager]::[%d]::[Resized]::[%d", man, asset.music_mngr[man].music_size * 2);
		asset.music_mngr[man].music = tmp;
		asset.music_mngr[man].music_size *= 2;
	}

	return asset.music_mngr[man].music_contain - 1;
}

void ICE_Music_Clear(ICE_Music * music)
{
	memset(music, 0, sizeof(ICE_Music));
}

void ICE_Music_Destroy(ICE_Music * ptr)
{
	ICE_WString_Delete(ptr->filename);
	Mix_FreeMusic(ptr->music);
}

// GET

ICE_Music * ICE_Music_Get(ICE_Index man, ICE_Index nb)
{
	return &asset.music_mngr[man].music[nb];
}

// PLAY

int ICE_Music_Play(ICE_Music * music, const int volume)
{
	if (music->music != NULL) 
	{
		Mix_PlayMusic(music->music, -1);
		Mix_VolumeMusic(volume);
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