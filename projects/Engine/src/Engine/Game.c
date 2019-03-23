#include "Game.h"

#include "Texture.h"
#include "Sound.h"

#include "Config.h"
#include "Time_private.h"

ICE_Float ICE_Game_GetDelta()
{
	return ICE_Time_GetPtr()->delta;
}

ICE_Float ICE_Game_GetFps()
{
	return ICE_Time_GetPtr()->fps;
}

ICE_StringStd ICE_Game_GetVersion()
{
	return ICE_Config_GetPtr()->game_version;
}