#ifndef DEF_ICE_SOUND
#define DEF_ICE_SOUND 
#include "Struct.h"
#include "../external/rlutil.h"

void ICE_SoundManagerCreate(ICE_Game *game);
void ICE_MusicCreate(ICE_Game *game, char *path);
void ICE_SoundCreate(ICE_Game *game, char *path);
int ICE_MusicPlay(ICE_Game *game, const int nb, const int volume);
int ICE_SoundPlay(ICE_Game *game, const int chunk, const int volume);

#endif