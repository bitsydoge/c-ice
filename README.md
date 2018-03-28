
# ICE : Indie "C" Engine
<img alt="ICE Logo" src="TestProject/Test/res/img/ice_logo.png" width=20% height=20%> 

_A simple Game Engine with basic Camera, Entity, Texture, Audio, Map ..._
	
## Feature :

**Supported Format :** 

	- Image : JPG, PNG, BMP (And everything stb image support)
	- Sound : OGG and WAV (And everything SDL mixer support)
	- Font  : TTF (And everything SDL ttf support)

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

ICE_PRELOAD() // Load assets here, if the game "restart" they are not gonna be reload{
	ICE_Font_Load("font.ttf");
}

ICE_CREATE(){
	ICE_Render_Color( ICE_Color_New( 200, 200, 200 ) ); // Background color
	ICE_Debug_FontSetColorBg(100, 100, 100); // Text Background Color
	ICE_Debug_FontSetColorFg(0, 0, 50); // Text Color
}

ICE_UPDATE(){
	ICE_Debug_FontDraw(1, " Hello World from ICE %s ", ICE_VERSION);		
}

ICE_DESTROY(){}

int main(){
	ICE_Debug(ICE_True);
	ICE_START( "Hello World", 800, 480 );
	return 0;
}
```