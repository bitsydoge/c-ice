cmake_minimum_required(VERSION 3.7)
project(ICE C)

set(SDL2_INCLUDE_DIR /usr/include/SDL2)
set(SDL2_LIBRARY /usr/lib/x86_64-linux-gnu/libSDL2.so)
set(SDL2_LIBRARY_ttf /usr/lib/x86_64-linux-gnu/libSDL2_ttf.so)
set(SDL2_LIBRARY_mixer /usr/lib/x86_64-linux-gnu/libSDL2_mixer.so)
include_directories(ICEngine/src/hdr)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY .)

add_executable(ICE.a
		ICEngine/src/Box.c
		ICEngine/src/Camera.c
		ICEngine/src/Color.c
		ICEngine/src/Converter.c
		ICEngine/src/Core.c
		ICEngine/src/Data.c
		ICEngine/src/Debug.c
		ICEngine/src/Draw.c
		ICEngine/src/Entity.c
		ICEngine/src/Font.c
		ICEngine/src/Game.c
		ICEngine/src/Gui.c
		ICEngine/src/Input.c
		ICEngine/src/Label.c
		ICEngine/src/Map.c
		ICEngine/src/Maths.c
		ICEngine/src/Music.c
		ICEngine/src/Physics.c
		ICEngine/src/Primitive.c
		ICEngine/src/Random.c
		ICEngine/src/Sound.c
		ICEngine/src/Substate.c
		ICEngine/src/Texture.c
		ICEngine/src/Terminal.c
		ICEngine/src/Vector.c
		ICEngine/src/Window.c
		ICEngine/src/hdr/Box.h
		ICEngine/src/hdr/Camera.h
		ICEngine/src/hdr/Color.h
		ICEngine/src/hdr/Converter.h
		ICEngine/src/hdr/Core.h
		ICEngine/src/hdr/Data.h
		ICEngine/src/hdr/Debug.h
		ICEngine/src/hdr/Draw.h
		ICEngine/src/hdr/Entity.h
		ICEngine/src/hdr/Font.h
		ICEngine/src/hdr/Game.h
		ICEngine/src/hdr/Gui.h
		ICEngine/src/hdr/Input.h
		ICEngine/src/hdr/Label.h
		ICEngine/src/hdr/Map.h
		ICEngine/src/hdr/Maths.h
		ICEngine/src/hdr/Music.h
		ICEngine/src/hdr/Physics.h
		ICEngine/src/hdr/Primitive.h
		ICEngine/src/hdr/Random.h
		ICEngine/src/hdr/Sound.h
		ICEngine/src/hdr/Substate.h
		ICEngine/src/hdr/Terminal.h
		ICEngine/src/hdr/Texture.h
		ICEngine/src/hdr/TypesAudio.h
		ICEngine/src/hdr/TypesCore.h
		ICEngine/src/hdr/TypesGraphics.h
		ICEngine/src/hdr/TypesMaths.h
		ICEngine/src/hdr/Vector.h
		ICEngine/src/hdr/Window.h
		ICEngine/src/raw/Raw_error.c
		ICEngine/src/raw/Raw_icon.c
        ICEngine/src/external/icestd.c
        ICEngine/src/external/icestd.h
        ICEngine/src/external/lodepng.c
        ICEngine/src/external/lodepng.h
        ICEngine/src/external/rlutil.h
        ICEngine/src/external/rlutil.c)

target_link_libraries(ICE.bin
        ${SDL2_LIBRARY}
        ${SDL2_LIBRARY_ttf}
		${SDL2_LIBRARY_mixer}
        m)
