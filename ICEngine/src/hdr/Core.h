#ifndef DEF_ICE_CORE
#define DEF_ICE_CORE

#define ICE_VERSION "18.03.00";

#define ICE_START(NAME, WIDTH, HEIGHT) ICE_CoreLoop(NAME, WIDTH, HEIGHT, ICE_User_Preload, ICE_User_Create, ICE_User_Update, ICE_User_Destroy)

#define ICE_PRELOAD() void ICE_User_Preload(void)
#define ICE_CREATE() void ICE_User_Create(void)
#define ICE_UPDATE() void ICE_User_Update(void)
#define ICE_DESTROY() void ICE_User_Destroy(void)

#include "TypesCore.h"
#include "TypesGraphics.h"
#include "TypesMaths.h"
#include "TypesAudio.h"
#include "TypesPhysics.h"

#include "Array.h"
#include "Color.h"
#include "Debug.h"
#include "StringDyn.h"
#include "Game.h"
#include "Input.h"
#include "Render.h"
#include "Render.h"
#include "Terminal.h"
#include "Time.h"

int ICE_CoreLoop(ICE_String title, int window_width, int window_height, void(*call_preload)(void), void(*call_create)(void), void(*call_update)(void), void(*call_destroy)(void));

#endif
