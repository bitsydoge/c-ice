#ifndef DEF_ICE_TYPESAUDIO
#define DEF_ICE_TYPESAUDIO

#include "../Core/SDL2_Includer.h"
#include ICE_INCLUDE_SDL2_MIXER

#include "../Framework/String_.h"

#ifndef ICE_BOOL_DEFINED
#define ICE_BOOL_DEFINED
typedef _Bool ICE_Bool;
#define ICE_True 1
#define ICE_TRUE 1
#define ICE_true 1
#define ICE_False 0
#define ICE_FALSE 0
#define ICE_false 0
#define ICE_BOOL_BITFIELD(S) ICE_Bool S : 1
#endif

#ifndef ICE_FLOAT_DEFINED
#define ICE_FLOAT_DEFINED
typedef double ICE_Float;
#endif

typedef struct {

	Mix_Music* sdl_handle;
	ICE_String filename;

} ICE_Music;

typedef struct
{
	ICE_Bool isFree;
	unsigned short music_size;
	unsigned short music_contain;
	ICE_Music* music;

} ICE_MusicManager;

typedef struct {

	Mix_Chunk* sdl_handle;
	ICE_String filename;

} ICE_Sound;

typedef struct {

	ICE_Bool isFree;
	unsigned short sound_size;
	unsigned short sound_contain;
	ICE_Sound *sound;

} ICE_SoundManager;

#endif
