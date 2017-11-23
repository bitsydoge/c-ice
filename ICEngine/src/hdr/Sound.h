#ifndef DEF_iceSOUND
#define DEF_iceSOUND 
#include "Struct.h"
#include "../external/rlutil.h"

void iceSoundManagerCreate(iceGame *game);
void iceMusicCreate(iceGame *game, char *path);
void iceSoundCreate(iceGame *game, char *path);
int iceMusicPlay(iceGame *game, const int nb, const int volume);
int iceSoundPlay(iceGame *game, const int chunk, const int volume);

#endif