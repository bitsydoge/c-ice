#ifndef DEF_ICE_SOUND_H
#define DEF_ICE_SOUND_H

#include "../Framework/BasicTypes.h"
#include "Types.h"

typedef struct ICE_Sound ICE_Sound;

ICE_SoundID ICE_Sound_Load(char* path_);
void ICE_Sound_Destroy(ICE_SoundID sound_);
void ICE_Sound_Play(ICE_SoundID sound_, ICE_Float volume_);

#endif