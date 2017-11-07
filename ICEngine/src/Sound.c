#include "hdr/Sound.h"
#include <SDL2/SDL_mixer.h>

void ICE_CreateSoundManager(ICE_Game *game) {
	ICE_SoundManager soundmanager = { 0 };
	game->soundmanager = soundmanager;
	// Music
	game->soundmanager.size_musicpack = 4;
	game->soundmanager.tofill_music = 0;
	game->soundmanager.musicpack = calloc(game->soundmanager.size_musicpack, sizeof(ICE_Music));
	//game->soundmanager.musicpack[game->soundmanager.tofill_music].music = calloc(1, sizeof(Mix_Music*));
	// Sound
	game->soundmanager.size_soundpack = 4;
	game->soundmanager.tofill_soundpack = 0;
	game->soundmanager.soundpack = calloc(game->soundmanager.size_soundpack, sizeof(ICE_Sound));
	//game->soundmanager.soundpack[game->soundmanager.tofill_sound].sound = calloc(1, sizeof(Mix_Chunk*));
}

void ICE_CreateMusic(ICE_Game *game, char *path) {
	game->soundmanager.musicpack[game->soundmanager.tofill_music].music = Mix_LoadMUS(path);
	if (game->soundmanager.musicpack[game->soundmanager.tofill_music].music != NULL) {
		printf("Music number : %d loaded from %s \n", game->soundmanager.tofill_music, path);
		game->soundmanager.tofill_music++;
		if (game->soundmanager.tofill_music >= game->soundmanager.size_musicpack) {
			game->soundmanager.size_musicpack *= 2;
			printf("Musicpack size is now : %d \n", game->soundmanager.size_musicpack);
			game->soundmanager.musicpack = realloc(game->soundmanager.musicpack, sizeof(ICE_Music)*(game->soundmanager.size_musicpack));
		}

	}
	else
		printf("ERROR : Can't load music from %s \n", path);
}

void ICE_CreateSound(ICE_Game *game, char *path){
	game->soundmanager.soundpack[game->soundmanager.tofill_soundpack].sound = Mix_LoadWAV(path);
	if (game->soundmanager.soundpack[game->soundmanager.tofill_soundpack].sound != NULL) {
		printf("Sound number : %d loaded from %s \n", game->soundmanager.tofill_soundpack, path);
		game->soundmanager.tofill_soundpack++;
		if (game->soundmanager.tofill_soundpack >= game->soundmanager.size_soundpack) {
			game->soundmanager.size_soundpack *= 2;
			printf("Soundpack size is now : %d \n", game->soundmanager.size_soundpack);
			game->soundmanager.soundpack = realloc(game->soundmanager.soundpack, sizeof(ICE_Sound)*(game->soundmanager.size_soundpack));
		}
	}
	else
		printf("ERROR : Can't load sound from %s \n", path);
}

int ICE_PlayMusic(ICE_Game *game, const int nb, const int volume){
	if (game->soundmanager.musicpack[nb].music != NULL){
		Mix_PlayMusic(game->soundmanager.musicpack[nb].music, -1);
		Mix_VolumeMusic(volume);
		return 1;
	}
return -1;

}

int ICE_PlaySound(ICE_Game *game, const int chunk, const int volume){
	if (game->soundmanager.tofill_soundpack >= chunk){
		if (game->soundmanager.soundpack[chunk].sound != NULL){
			Mix_Volume(Mix_PlayChannel(-1, game->soundmanager.soundpack[chunk].sound, 0), volume);
			return 1;
		}
	}
	return -1;
}