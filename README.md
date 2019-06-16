[![AppVeyor Status](https://ci.appveyor.com/api/projects/status/403d2539ebdvglj7?svg=true)](https://ci.appveyor.com/project/coldragon/ice) Windows

[![Travus CI Status](https://travis-ci.org/Coldragon/ICE.svg?branch=master)](https://travis-ci.org/Coldragon/ICE) Linux & MacOS 

# ICE : Indie "C" Engine
<img alt="ICE Logo" src="logo/logo_hq.png" width=20% height=20%> 

_A simple Game Engine with basic Camera, Entity, Texture, Audio, Map ..._
	
## Feature :

**Supported Format :** 

- Image   : JPG, PNG, BMP ... ( And everything stb_image support )
- Sound   : OGG, WAV ... ( And everything SDL_mixer support )
- Font    : TTF ... ( And everything SDL_ttf support )
- Archive : ZIP, 7Z ... ( And everything PhysFS support ) 

**Tools** :

- bin2c : Convert file to static array in C to load them from the binary

## Dependancy : 

- SDL2 ( Platform wrapper for Graphics, Window, Input ... )  
- SDL2_mixer ( Sound )   
- SDL2_ttf ( Text drawing ) 

## Included : 

- stb_image ( Image decode : https://github.com/nothings/stb )
- stb_image_write ( Image save : https://github.com/nothings/stb )
- SDL_stbimage ( stb_image SDL integration : https://github.com/DanielGibson/Snippets/)
- SDL2_gfx ( AA primitives : https://sourceforge.net/projects/sdl2gfx/ )
- PhysFS ( Abstract acces to archives : https://icculus.org/physfs/ )
- cute_files ( Crossplatform folder access : https://github.com/RandyGaul/cute_headers/blob/master/cute_files.h )
- rlutil.h ( Crossplatform terminal color : https://github.com/tapio/rlutil )
- chipmunk2d ( Physics : https://github.com/slembcke/Chipmunk2D )
- duktape ( Embeddable Javascript engine : https://duktape.org/ )

## TODO :
See the	[Trello](https://trello.com/b/HOWcrZRM/ice/)

## Hello World

```c
#include <ICE.h>

#define ICE_CONFIG_TITLE "Hello World"

ICE_Game_Create()
{
	ICE_Font_Load("font.ttf");
	ICE_LabelID nbr = ICE_Label_Create(
		ICE_State_Current, 
		"Hello World",
		ICE_Vect_Zero,
		50, 
		ICE_LABELTYPE_WORLD
	);
}

ICE_Game_Update()
{
	if (ICE_Input_Pressed(ICE_KEY_ESCAPE)) 
		ICE_Input_Quit();
}

ICE_Game_Destroy() {}
```
