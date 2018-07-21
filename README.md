
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

ICE_PRELOAD()
{
	ICE_Font_Load("font.ttf");
}

ICE_CREATE()
{
	ICE_Render_Color(ICE_Color_New(100, 200, 80));

	ICE_Index man	=	ICE_LabelManager_Insert(NULL);
	ICE_Index nb	=	ICE_Label_Insert(NULL, man, "Hello World", ICE_Vect_New(0, 0));

	ICE_Label_SetSize(ICE_Label_Get(NULL, man, nb), 30);
	ICE_Label_FixToWorld(ICE_Label_Get(NULL, man, nb), ICE_True);
}

ICE_UPDATE()
{
	if (ICE_Input_Key(ICE_KEY_ESCAPE))
		ICE_Input_Quit();
}

ICE_DESTROY() {}

int main()
{
	ICE_START("Hello World", 800, 480);
	return 0;
}
```