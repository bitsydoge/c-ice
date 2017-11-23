#ifndef DEF_ICE_CORE
#define DEF_ICE_CORE

#define ICE_GAME_RUN ICE_CoreLoop(GameCreate, GameUpdate, GameDestroy)
#define ICE_CREATE ICE_Game GameCreate(void)
#define ICE_UPDATE void GameUpdate(ICE_Game *game)
#define ICE_DESTROY void GameDestroy(ICE_Game *game)


#include <time.h>
#include "Camera.h"
#include "Data.h"
#include "Debug.h"
#include "Entity.h"
#include "Font.h"
#include "Game.h"
#include "Gui.h"
#include "Input.h"
#include "Map.h"
#include "Physics.h"
#include "Primitive.h"
#include "Render.h"
#include "Rect.h"
#include "Sound.h"
#include "Struct.h"
#include "Substate.h"
#include "Terminal.h"
#include "Texture.h"
#include "Time.h"
#include "Types.h"
#include "Vector.h"

int ICE_CoreInit();
int ICE_CoreClose();
int ICE_CoreLoop(ICE_Game(*call_create)(void), void(*call_update)(ICE_Game*), void(*call_destroy)(ICE_Game*));

#endif
