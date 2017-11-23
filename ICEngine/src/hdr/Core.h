#ifndef DEF_iceCORE
#define DEF_iceCORE

#define ICE_GAME_RUN iceCoreLoop(GameCreate, GameUpdate, GameDestroy)
#define ICE_CREATE iceGame GameCreate(void)
#define ICE_UPDATE void GameUpdate(iceGame *game)
#define ICE_DESTROY void GameDestroy(iceGame *game)


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

int iceCoreInit();
int iceCoreClose();
int iceCoreLoop(iceGame(*call_create)(void), void(*call_update)(iceGame*), void(*call_destroy)(iceGame*));

#endif
