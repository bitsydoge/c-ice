#ifndef DEF_ICE_TYPESAUDIO
#define DEF_ICE_TYPESAUDIO 
#include <SDL2/SDL_mixer.h>

#ifndef ICE_BOOL_DEFINED
#define ICE_BOOL_DEFINED
typedef int iceBool;
#define iceTrue 1
#define iceTRUE 1
#define icetrue 1
#define iceFalse 0
#define iceFALSE 0
#define icefalse 0
#endif

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
