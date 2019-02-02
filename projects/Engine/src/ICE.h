/*
        ,     \    /      ,        
       / \    )\__/(     / \       
      /   \  (_\  /_)   /   \      
 ____/_____\__\@  @/___/_____\____ 
|             |\../|              |
|              \VV/               |
|            COLDRAGON            |
|_________________________________|
 |    /\ /      \\       \ /\    | 
 |  /   V        ))       V   \  | 
 |/     `       //        '     \| 
 `              V                '

*/

#ifndef DEF_ICE_INCLUDER_0X505050
#define DEF_ICE_INCLUDER_0X505050

#if defined(_DEBUG) && defined (_MSC_VER) && !defined(ICE_NO_VLD)
	#include <vld.h>
#endif

// Framework

#include "Framework/TypesFramework.h"

#include "Framework/Assert_.h"
#include "Framework/Log.h"
#include "Framework/Memory_.h"
#include "Framework/Random.h"
#include "Framework/String_.h"
#include "Framework/Terminal.h"

// Core

#include "Core/TypesCore.h"

#include "Core/Asset.h"
#include "Core/Config.h"
#include "Core/Core.h"
#include "Core/Debug.h"
#include "Core/Game.h"
#include "Core/Input.h"
#include "Core/Label.h"
#include "Core/State.h"
#include "Core/Time_.h"
#include "Core/Window.h"
#include "Core/Data.h"
#include "Core/Entity.h"
#include "Core/MacOS_.h"

// Graphics

#include "Graphics/TypesGraphics.h"

#include "Graphics/Camera.h"
#include "Graphics/Color.h"
#include "Graphics/Font.h"
#include "Graphics/Primitive.h"
#include "Graphics/Render.h"
#include "Graphics/Texture.h"
#include "Graphics/Sprite.h"
#include "Graphics/Gui.h"

// Audio

#include "Audio/TypesAudio.h"
#include "Audio/Audio.h"
#include "Audio/Sound.h"
#include "Audio/Music.h"

// Maths

#include "Maths/TypesMaths.h"

#include "Maths/Box.h"
#include "Maths/Interpolate.h"
#include "Maths/Vector.h"

// Physics

#include "Physics/TypesPhysics.h"

// 

#endif
