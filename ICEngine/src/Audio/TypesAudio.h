#ifndef DEF_ICE_TYPESAUDIO
#define DEF_ICE_TYPESAUDIO

#if defined(__APPLE__)
#include <SDL2_mixer/SDL_mixer.h>
#else
#include <SDL2/SDL_mixer.h>
#endif

#include "../Framework/String_.h"

#ifndef ICE_BOOL_DEFINED
#define ICE_BOOL_DEFINED
/**
* \brief A special bool that can be equal to 0(ICE_False) 1(ICE_True) or -1(ICE_BoolNone).
* The last one is for some function where the use of ICE_BoolNone is documented
*/
	typedef int ICE_Bool;
	#define ICE_True 1
	#define ICE_TRUE 1
	#define ICE_true 1
	#define ICE_False 0
	#define ICE_FALSE 0
	#define ICE_false 0
	#define ICE_BOOLNONE -1	
	#define ICE_BoolNone -1
	#define ICE_boolnone -1

#endif

#ifndef ICE_FLOAT_DEFINED
#define ICE_FLOAT_DEFINED
typedef double ICE_Float;
#endif

typedef struct {

	Mix_Music* music;
	ICE_WString filename;

} ICE_Music;

typedef struct
{
	ICE_Bool isFree;
	unsigned short music_size;
	unsigned short music_contain;
	ICE_Music* music;

} ICE_MusicManager;

typedef struct {

	Mix_Chunk* sound;
	ICE_WString filename;

} ICE_Sound;

typedef struct {

	ICE_Bool isFree;
	unsigned short sound_size;
	unsigned short sound_contain;
	ICE_Sound *sound;

} ICE_SoundManager;

#endif
