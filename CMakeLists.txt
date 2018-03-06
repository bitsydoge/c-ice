cmake_minimum_required(VERSION 3.9)
project(ICE)

set(CMAKE_CXX_STANDARD 11)

set(SDL2_INCLUDE_DIR /usr/include/SDL2)
set(SDL2_LIBRARY /usr/lib/x86_64-linux-gnu/libSDL2.so)
set(SDL2_LIBRARY_ttf /usr/lib/x86_64-linux-gnu/libSDL2_ttf.so)
set(SDL2_LIBRARY_mixer /usr/lib/x86_64-linux-gnu/libSDL2_mixer.so)
include_directories(ICEngine/src/hdr)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY .)

add_executable(ICE
        ICEngine/src/external/icestd.c
        ICEngine/src/external/icestd.h
        ICEngine/src/external/rlutil.c
        ICEngine/src/external/rlutil.h
        ICEngine/src/external/rnd.h
        ICEngine/src/external/SDL2_framerate.c
        ICEngine/src/external/SDL2_framerate.h
        ICEngine/src/external/SDL2_gfxPrimitives.c
        ICEngine/src/external/SDL2_gfxPrimitives.h
        ICEngine/src/external/SDL2_gfxPrimitives_font.h
        ICEngine/src/external/SDL2_imageFilter.c
        ICEngine/src/external/SDL2_imageFilter.h
        ICEngine/src/external/SDL2_rotozoom.c
        ICEngine/src/external/SDL2_rotozoom.h
        ICEngine/src/external/stb_image.h
        ICEngine/src/external/vec.c
        ICEngine/src/external/vec.h
        ICEngine/src/hdr/Array.h
        ICEngine/src/hdr/Asset_private.h
        ICEngine/src/hdr/Box.h
        ICEngine/src/hdr/Camera.h
        ICEngine/src/hdr/Color.h
        ICEngine/src/hdr/Color_private.h
        ICEngine/src/hdr/Converter_private.h
        ICEngine/src/hdr/Core.h
        ICEngine/src/hdr/Core_private.h
        ICEngine/src/hdr/Debug.h
        ICEngine/src/hdr/Debug_private.h
        ICEngine/src/hdr/Font.h
        ICEngine/src/hdr/Game.h
        ICEngine/src/hdr/Game_private.h
        ICEngine/src/hdr/Input.h
        ICEngine/src/hdr/Input_private.h
        ICEngine/src/hdr/Log.h
        ICEngine/src/hdr/Node.h
        ICEngine/src/hdr/Primitive.h
        ICEngine/src/hdr/Random.h
        ICEngine/src/hdr/Render.h
        ICEngine/src/hdr/Render_private.h
        ICEngine/src/hdr/String_.h
        ICEngine/src/hdr/Terminal.h
        ICEngine/src/hdr/Terminal_private.h
        ICEngine/src/hdr/Time_.h
        ICEngine/src/hdr/Time_private.h
        ICEngine/src/hdr/TypesAudio.h
        ICEngine/src/hdr/TypesCore.h
        ICEngine/src/hdr/TypesGraphics.h
        ICEngine/src/hdr/TypesMaths.h
        ICEngine/src/hdr/TypesPhysics.h
        ICEngine/src/hdr/Vector.h
        ICEngine/src/hdr/Window.h
        ICEngine/src/raw/raw_error.c
        ICEngine/src/raw/raw_icon.c
        ICEngine/src/Array.c
        ICEngine/src/Asset_private.c
        ICEngine/src/Camera.c
        ICEngine/src/Core.c
        ICEngine/src/Core_private.c
        ICEngine/src/Debug.c
        ICEngine/src/Debug_private.c
        ICEngine/src/Font.c
        ICEngine/src/Game.c
        ICEngine/src/Game_private.c
        ICEngine/src/Input.c
        ICEngine/src/Input_private.c
        ICEngine/src/Log.c
        ICEngine/src/Primitive.c
        ICEngine/src/Random.c
        ICEngine/src/Render.c
        ICEngine/src/Render_private.c
        ICEngine/src/String_.c
        ICEngine/src/Terminal.c
        ICEngine/src/Terminal_private.c
        ICEngine/src/Time_.c
        ICEngine/src/Time_private.c
        ICEngine/src/Window.c
)
