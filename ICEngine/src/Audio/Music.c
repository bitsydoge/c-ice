#include "Music.h"

#include "../Core/TypesCore.h"
#include "../Framework/Memory_.h"
#include "../Framework/Log.h"

extern ICE_Asset ASSET;

// MANAGER

ICE_Id ICE_MusicManager_Insert()
{
	ICE_MusicManager musicmanager = { 0 };
	musicmanager.music_size = ICE_DEFAULT_MUSIC_SIZE;
	musicmanager.music = ICE_Calloc(musicmanager.music_size, sizeof(ICE_Music));

	ASSET.music_mngr_nb++;
	ASSET.music_mngr = ICE_Realloc(ASSET.music_mngr, ASSET.music_mngr_nb * sizeof(ICE_MusicManager));
	ASSET.music_mngr[ASSET.music_mngr_nb - 1] = musicmanager;

	ICE_Log(ICE_LOG_SUCCES, "Create MusicManager : %d", ASSET.music_mngr_nb - 1);

	return ASSET.music_mngr_nb - 1;
}

void ICE_MusicManager_Destroy(const ICE_Id man)
{
	ICE_MusicManager *manager = &ASSET.music_mngr[man];

	for (ICE_Id i = 0; i < manager->music_contain; i++)
	{
		//Free everything to free in Label
		ICE_Music_Destroy(&manager->music[i]);
	}

	ICE_Free(manager->music);
	ICE_Log(ICE_LOG_SUCCES, "Free MusicManager : %d", man);
}

void ICE_MusicManager_DestroyAll()
{
	ICE_MusicManager *manager = ASSET.music_mngr;
	const ICE_Id nb_manager = ASSET.music_mngr_nb;

	for (ICE_Id i = 0; i < nb_manager; i++)
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
	ICE_Music music;

	// Assigne
	music.filename = ICE_String_Init(path);
	music.music = Mix_LoadMUS(path);
	if(music.music == NULL)
	{
		ICE_Log(ICE_LOG_ERROR, "%s", Mix_GetError());
	}

	return music;
}

ICE_Id ICE_Music_Load(ICE_Id man, char *path)
{
	// Insert label in array
	ASSET.music_mngr[man].music[ASSET.music_mngr[man].music_contain] = ICE_Music_Create(path);
	ASSET.music_mngr[man].music_contain++;

	ICE_Log(ICE_LOG_SUCCES, "MusicManager]::[%d]::[Label]::[%d]::[Create", man, ASSET.music_mngr[man].music_contain - 1);

	// Test size to realloc more space
	if (ASSET.music_mngr[man].music_size <= ASSET.music_mngr[man].music_contain) {
		ICE_Music* tmp = ICE_Realloc(ASSET.music_mngr[man].music, sizeof(ICE_Music)*(ASSET.music_mngr[man].music_size * 2));
		// Test if realloc succes
		ICE_Log(ICE_LOG_WARNING, "MusicManager]::[%d]::[Resized]::[%d", man, ASSET.music_mngr[man].music_size * 2);
		ASSET.music_mngr[man].music = tmp;
		ASSET.music_mngr[man].music_size *= 2;
	}

	return ASSET.music_mngr[man].music_contain - 1;
}

void ICE_Music_Clear(ICE_Music * music)
{
	memset(music, 0, sizeof(ICE_Music));
}

void ICE_Music_Destroy(ICE_Music * ptr)
{
	ICE_String_Delete(ptr->filename);
	Mix_FreeMusic(ptr->music);
}

// GET

ICE_Music * ICE_Music_Get(ICE_Id man, ICE_Id nb)
{
	return &ASSET.music_mngr[man].music[nb];
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