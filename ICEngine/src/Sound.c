#include "hdr/Sound.h"
#include "hdr/TerminalColor.h"
#include "external/rlutil.h"
#include <SDL2/SDL_mixer.h>

void ICE_CreateSoundSystem(ICE_Game *game)
{
	ICE_SoundManager soundmanager = { 0 };
	game->soundmanager = soundmanager;

	// Music
	game->soundmanager.size_musicpack = 2;
	game->soundmanager.tofill_music = 0;
	game->soundmanager.musicpack = calloc(game->soundmanager.size_musicpack, sizeof(ICE_Music*));
	game->soundmanager.musicpack[game->soundmanager.tofill_music].music = calloc(1, sizeof(Mix_Music*));

	// Sound
	game->soundmanager.size_sound = 4;
	game->soundmanager.tofill_sound = 0;
	game->soundmanager.sound = calloc(game->soundmanager.size_sound, sizeof(ICE_Sound*));
}

void ICE_CreateMusic(ICE_SoundManager *manager, char *path)
{
	manager->musicpack[manager->tofill_music].music = Mix_LoadMUS(path);
	manager->tofill_music++;
	manager->size_musicpack++;
	manager->musicpack = realloc(manager->musicpack, sizeof(ICE_Music*)*(manager->size_musicpack));
}

void ICE_CreateSound(ICE_SoundManager *manager, char *path)
{
	
}

void ICE_PlayMusic(ICE_SoundManager *manager, const int nb)
{
	Mix_PlayMusic(manager->musicpack[nb].music, -1);
}




