#ifndef DEF_ICE_CORE
#define DEF_ICE_CORE
#include <time.h>

#include "Camera.h"
#include "Entity.h"
#include "Font.h"
#include "Game.h"
#include "Gui.h"
#include "Input.h"
#include "Map.h"
#include "Math.h"
#include "Physics.h"
#include "Primitive.h"
#include "Render.h"
#include "Sound.h"
#include "Struct.h"
#include "TerminalColor.h"
#include "Texture.h"
#include "Time.h"
#include "Debug.h"

int ICE_InitGameEngine();
int ICE_CloseGameEngine();
int ICE_GameLoop(ICE_Game(*call_create)(void), void(*call_update)(ICE_Game*), void(*call_destroy)(ICE_Game*));
int ICE_SubstateLoop(ICE_Game* game, void(*call_create)(ICE_Game*), void(*call_update)(ICE_Game*), void(*call_destroy)(ICE_Game*));

#endif
