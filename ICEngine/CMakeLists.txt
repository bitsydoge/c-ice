cmake_minimum_required(VERSION 3.7)
project(ICE C)

set(SDL2_INCLUDE_DIR /usr/include/SDL2)
set(SDL2_LIBRARY /usr/lib/x86_64-linux-gnu/libSDL2.so)
set(SDL2_LIBRARY_ttf /usr/lib/x86_64-linux-gnu/libSDL2_ttf.so)
set(SDL2_LIBRARY_mixer /usr/lib/x86_64-linux-gnu/libSDL2_mixer.so)
include_directories(src/hdr)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY .
        )

add_executable(ICE.bin
        src/Input.c
        src/main.c
        src/Texture.c
        src/Render.c
        src/App.c
        src/hdr/Input.h
        src/hdr/Texture.h
        src/hdr/Render.h
        src/hdr/App.h
        src/external/lodepng.c
        src/external/lodepng.h
        src/external/rlutil.h
        src/external/tinyfiles.h)

target_link_libraries(ICE.bin
        ${SDL2_LIBRARY}
        ${SDL2_LIBRARY_ttf}
	${SDL2_LIBRARY_mixer}
        m)
