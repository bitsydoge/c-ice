[![AppVeyor Status](https://ci.appveyor.com/api/projects/status/403d2539ebdvglj7?svg=true)](https://ci.appveyor.com/project/coldragon/ice) Windows

[![Travus CI Status](https://travis-ci.org/Coldragon/ICE.svg?branch=master)](https://travis-ci.org/Coldragon/ICE) Linux & MacOS 

# ICE : Indie "C" Engine
<img alt="ICE Logo" src="docs/logo_hq.png" width=20% height=20%> 

_A simple Game Engine with basic Camera, Entity, Texture, Audio, Map ..._
	
## Feature :

**Supported Format :** 

	- Image : JPG, PNG, BMP (And everything stb_image support)
	- Sound : OGG and WAV (And everything SDL_mixer support)
	- Font  : TTF (And everything SDL_ttf support)

**Tools** :

	- Terminal Color : Crossplatform terminal color.

## Dependancy : 

	- SDL2 (Main lib for the engine)  
	- SDL2_mixer (for the sound)   
	- SDL2_ttf (for the text)   

## Included : 

	- stb_image ( Image decode : https://github.com/nothings/stb )
	- rlutil.h ( Crossplatform terminal color : https://github.com/tapio/rlutil )
	- SDL2_gfx ( AA primitives : https://sourceforge.net/projects/sdl2gfx/ )
	- rnd.h ( Random algorithm : https://github.com/mattiasgustavsson/libs )
	- chipmunk2d ( Physics : https://github.com/slembcke/Chipmunk2D )

## Hello World

```c
#include <ICE.h>

ICE_Game_Create("Hello World", 800, 480)
{
	ICE_Font_Load("font_path.ttf");
	ICE_Index man = ICE_LabelManager_Insert(NULL);
	ICE_Index nbr = ICE_Label_Insert(NULL, man, L"Hello World", ICE_Vect_Null, 50, ICE_LabelType_World);
}

ICE_Game_Update()
{
	if (ICE_Input_Key(ICE_KEY_ESCAPE)) ICE_Input_Quit();
}

ICE_Game_Destroy() {}
```
