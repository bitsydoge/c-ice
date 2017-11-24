#ifndef DEF_ICE_STRUCTAUDIO
#define DEF_ICE_STRUCTAUDIO 
#include <SDL2/SDL_mixer.h>

typedef struct {

	Mix_Music* music;
	char *filename;

} iceMusic;

typedef struct {

	Mix_Chunk* sound;
	char *filename;

} iceSound;

typedef struct {

	unsigned short size_musicpack;
	iceMusic* musicpack;
	unsigned short tofill_music;
	unsigned short size_soundpack;
	iceSound* soundpack;
	unsigned short tofill_soundpack;

} iceSoundManager;

#endif
