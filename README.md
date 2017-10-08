# ICE : Indie "C" Engine - A basic SDL2 and C game engine.
_A simple Game Engine with basic Camera, Entity, Texture, Audio, Map etc ..._
> ##### **STATUS : WIP [▓▓▓▓----------------------------------------------] 8%**
	
## Feature :

**Supported Format :** 

	- Image : PNG and BMP (Probably JPEF in the futur)
	
	- Sound : OGG and WAV (And basicaly everything SDL_mixer support, but my function will focus on those)
	
	- Text : TTF (And basicaly everything SDL_ttf support)
	
	- Map : JSON from Tiled (I'll focus with the compatibility of it)

**Tools** :

	- Terminal Color : with rlutil, providing cross platform for terminal color; it will be usefull for debugging.
	
	- File exploring : with tinyfiles, providing cross platform for file listing


Made with Visual Studio Community 2017 and Visual Studio Code on linux
a CMakeLists.txt is avaible for compiling on other os or compiler.

## Dependancy : 

	-SDL2 (Main lib for the engine)  
	
	-SDL2 mixer (for the sound)   
	
	-SDL2 ttf (for the text)   
	
	-chipmunk2d (for physics)
	
	-lodepng (for png decode)   
	
	-tinyfiles (for directory listing)   
	
	-rlutil.h (for console color)    
	
