#ifndef DEF_ICE_SOUND
#define DEF_ICE_SOUND 

#define ICE_DEFAULT_MUSIC_SIZE 4
#define ICE_DEFAULT_SOUND_SIZE 4

void iceSoundManagerCreate();
void iceSoundCreate(char* path);
int iceSoundPlay(const int chunk, const int volume);

#endif
