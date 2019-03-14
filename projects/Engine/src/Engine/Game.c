#include "Game.h"

#include "Texture.h"
#include "Sound.h"

#include "Config_private.h"
#include "Scene_private.h"
#include "Time_private.h"
#include "GlobalData_private.h"
#include "MusicManager_private.h"
#include "Resources_private.h"
#include "Data.h"

ICE_GLOBALDATA_CONFIG
ICE_GLOBALDATA_SCENE_CURRENT
ICE_GLOBALDATA_SCENE_MAIN
ICE_GLOBALDATA_TIME

ICE_Float ICE_Game_GetDelta()
{
	return ICE_GLOBJ_TIME.delta;
}

ICE_Float ICE_Game_GetFps()
{
	return ICE_GLOBJ_TIME.fps;
}

ICE_StringStd ICE_Game_GetVersion()
{
	return ICE_GLOBJ_CONFIG.game_version;
}