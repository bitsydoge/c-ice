#ifndef DEF_ICE_RENDER
#define DEF_ICE_RENDER 
#include <SDL2/SDL_mixer.h>
#include "Game.h"

struct ICE_SoundSystem
{
	unsigned short size_music;
	Mix_Music *music;
	unsigned short tofill_music;
	unsigned short size_sound;
	Mix_Chunk *sound;
	unsigned short tofill_sound;
};

void ICE_CreateSoundSystem(ICE_Game *game);

#endif