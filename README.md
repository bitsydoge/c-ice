
# ICE : Indie "C" Engine
<img alt="ICE Logo" src="TestProject/Test/res/img/ice_logo.png" width=20% height=20%> 

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
	- SDL2 mixer (for the sound)   
	- SDL2 ttf (for the text)   
	- chipmunk2d (for physics)

## Included : 

	- stb image (image decode)
	- rlutil.h (console color)
	- SDL2 gfx (AA primitives)

## Hello World

```c
#include <Core.h>

ICE_PRELOAD()
{
	ICE_Font_Load("font.ttf");
}

ICE_CREATE()
{
	ICE_Render_Color( ICE_Color_New( 200, 200, 200 ) );

	unsigned int man = ICE_LabelManager_Insert(NULL);
	unsigned int nb  = ICE_Label_Insert(NULL, man, "Hello World", ICE_Vect_New(0,0));
	ICE_Label_FixToWorld(ICE_Label_Get(NULL, 0, nb), ICE_True);
}	

ICE_UPDATE()
{
	if(ICE_Input_Key(ICE_KEY_ESCAPE))
		ICE_Input_Quit();
}

ICE_DESTROY() {}

int main()
{
	ICE_START( "Hello World", 800, 480 );
	return 0;
}
```