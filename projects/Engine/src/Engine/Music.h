#ifndef DEF_ICE_MUSIC_H
#define DEF_ICE_MUSIC_H

#define ICE_DEFAULT_MUSIC_SIZE 4

#include "../Framework/BasicTypes.h"
#include "Types.h"
#include "../Framework/Macrotools.h"

#include "IO.h"
#include "Config.h"

#define ICE_Music_Load_MEM(S) ICE_Music_Load_RW(ICE_IO_FromConstMem(S, S##_length));\
	if(ICE_Music_GetLastLoaded() != (ICE_ID)-1)\
		ICE_Log_Succes(ICE_MACROTOOLS_STRINGIZE(Music loaded from memory ID(%ld)\n Token(##S##)), ICE_Music_GetLastLoaded());\
	else\
		ICE_Log_printf(ICE_MACROTOOLS_STRINGIZE(Music didn t loaded from token : ##S));\

// MUSIC
ICE_MusicID ICE_Music_GetLastLoaded();
ICE_MusicID ICE_Music_Load(ICE_StringStd path);
ICE_MusicID ICE_Music_Load_RW(ICE_IO ops);

void ICE_Music_Clear(ICE_MusicID music_);
void ICE_Music_Destroy(ICE_MusicID music_);

// PLAY

int ICE_Music_Play(ICE_MusicID music_, ICE_Float volume_);
void ICE_Music_Pause();
void ICE_Music_Resume();

#endif