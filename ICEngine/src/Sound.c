#include "hdr/Sound.h"
#include <SDL2/SDL_mixer.h>

extern iceGame game;

//////////
// MANAGER
//////////

void iceSoundManagerCreate() {
	iceSoundManager soundmanager = { 0 };
	game.soundmanager = soundmanager;
	// Music
	game.soundmanager.size_musicpack = ICE_DEFAULT_MUSIC_SIZE;
	game.soundmanager.tofill_music = 0;
	game.soundmanager.musicpack = calloc(game.soundmanager.size_musicpack, sizeof(iceMusic));
	//game->soundmanager.musicpack[game->soundmanager.tofill_music].music = calloc(1, sizeof(Mix_Music*));
	// Sound
	game.soundmanager.size_soundpack = ICE_DEFAULT_SOUND_SIZE;
	game.soundmanager.tofill_soundpack = 0;
	game.soundmanager.soundpack = calloc(game.soundmanager.size_soundpack, sizeof(iceSound));
	//game->soundmanager.soundpack[game->soundmanager.tofill_sound].sound = calloc(1, sizeof(Mix_Chunk*));
}

//////////
// SOUND
//////////

void iceSoundCreate(char *path){
	game.soundmanager.soundpack[game.soundmanager.tofill_soundpack].sound = Mix_LoadWAV(path);
	if (game.soundmanager.soundpack[game.soundmanager.tofill_soundpack].sound != NULL) {
		printf("Sound number : %d loaded from %s \n", game.soundmanager.tofill_soundpack, path);
		game.soundmanager.tofill_soundpack++;
		if (game.soundmanager.tofill_soundpack >= game.soundmanager.size_soundpack) {
			game.soundmanager.size_soundpack *= 2;
			printf("Soundpack size is now : %d \n", game.soundmanager.size_soundpack);
			game.soundmanager.soundpack = realloc(game.soundmanager.soundpack, sizeof(iceSound)*(game.soundmanager.size_soundpack));
		}
	}
	else
		printf("ERROR : Can't load sound from %s \n", path);
}

int iceSoundPlay(const int chunk, const int volume){
	if (game.soundmanager.tofill_soundpack >= chunk){
		if (game.soundmanager.soundpack[chunk].sound != NULL){
			Mix_Volume(Mix_PlayChannel(-1, game.soundmanager.soundpack[chunk].sound, 0), volume);
			return 1;
		}
	}
	return -1;
}