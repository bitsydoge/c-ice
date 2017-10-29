#include "hdr/Sound.h"
#include "external/rlutil.h"
#include <SDL2/SDL_mixer.h>

void ICE_CreateSoundManager(ICE_Game *game)
{
	ICE_SoundManager soundmanager = { 0 };
	game->soundmanager = soundmanager;

	// Music
	game->soundmanager.size_musicpack = 2;
	game->soundmanager.tofill_music = 0;
	game->soundmanager.musicpack = calloc(game->soundmanager.size_musicpack, sizeof(ICE_Music*));
	game->soundmanager.musicpack[game->soundmanager.tofill_music].music = calloc(1, sizeof(Mix_Music*));

	// Sound
	game->soundmanager.size_soundpack = 4;
	game->soundmanager.tofill_soundpack = 0;
	game->soundmanager.soundpack = calloc(game->soundmanager.size_soundpack, sizeof(ICE_Sound*));
}

void ICE_CreateMusic(ICE_Game *game, char *path)
{
	game->soundmanager.musicpack[game->soundmanager.tofill_music].music = Mix_LoadMUS(path);
	game->soundmanager.tofill_music++;
	game->soundmanager.size_musicpack++;
	game->soundmanager.musicpack = realloc(game->soundmanager.musicpack, sizeof(ICE_Music*)*(game->soundmanager.size_musicpack));
}

void ICE_CreateSound(ICE_Game *game, char *path)
{
	game->soundmanager.soundpack[game->soundmanager.tofill_soundpack].sound = Mix_LoadWAV(path);
	game->soundmanager.tofill_soundpack++;
	game->soundmanager.size_soundpack++;
	game->soundmanager.soundpack = realloc(game->soundmanager.soundpack, sizeof(ICE_Sound*)*(game->soundmanager.size_soundpack));
}

void ICE_PlayMusic(ICE_Game *game, const int nb)
{
	Mix_PlayMusic(game->soundmanager.musicpack[nb].music, -1);
}

void ICE_PlaySound(ICE_Game *game, const int chunk, const int volume)
{
	Mix_Volume(Mix_PlayChannel(-1, game->soundmanager.soundpack[chunk].sound, 0), volume);
}