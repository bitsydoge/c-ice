#include "hdr/Music.h"

extern iceGame game;

void iceMusicCreate(char *path) {
	game.soundmanager.musicpack[game.soundmanager.tofill_music].music = Mix_LoadMUS(path);
	if (game.soundmanager.musicpack[game.soundmanager.tofill_music].music != NULL) {
		printf("Music number : %d loaded from %s \n", game.soundmanager.tofill_music, path);
		game.soundmanager.tofill_music++;
		if (game.soundmanager.tofill_music >= game.soundmanager.size_musicpack) {
			game.soundmanager.size_musicpack *= 2;
			printf("Musicpack size is now : %d \n", game.soundmanager.size_musicpack);
			game.soundmanager.musicpack = realloc(game.soundmanager.musicpack, sizeof(iceMusic)*(game.soundmanager.size_musicpack));
		}

	}
	else
		printf("ERROR : Can't load music from %s \n", path);
}

int iceMusicPlay(const int nb, const int volume) {
	if (game.soundmanager.musicpack[nb].music != NULL) {
		Mix_PlayMusic(game.soundmanager.musicpack[nb].music, -1);
		Mix_VolumeMusic(volume);
		return 1;
	}
	return -1;
}