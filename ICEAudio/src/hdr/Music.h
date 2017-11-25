#ifndef DEF_ICE_MUSIC
#define DEF_ICE_MUSIC
#include "Game.h"

void iceMusicCreate(iceGame* game, char* path);
int iceMusicPlay(iceGame* game, const int nb, const int volume);

#endif