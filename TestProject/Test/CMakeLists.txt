cmake_minimum_required(VERSION 3.12)
project(Test C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/../../cmake")

find_package(SDL2 REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${SDL2_INCLUDE_DIR}
        ${SDL2_MIXER_INCLUDE_DIR}
        ${SDL2_TTF_INCLUDE_DIR})

include_directories(../../ICEngine/src)
include_directories(../../ICEngine/src/Audio)
include_directories(../../ICEngine/src/Core)
include_directories(../../ICEngine/src/External/chipmunk)
include_directories(../../ICEngine/src/External/mattiasgustavsson)
include_directories(../../ICEngine/src/External/rlutil)
include_directories(../../ICEngine/src/External/SDL2_gfx)
include_directories(../../ICEngine/src/External/stb)
include_directories(../../ICEngine/src/Framework)
include_directories(../../ICEngine/src/Graphics)
include_directories(../../ICEngine/src/Maths)
include_directories(../../ICEngine/src/Physics)

add_executable(Test
        src/main.c)

target_link_libraries(Test ${SDL2_LIBRARY}
        ${SDL2_MIXER_LIBRARIES}
        ${SDL2_TTF_LIBRARIES}
        ${CMAKE_SOURCE_DIR}/../../cmake-build-debug/libICEngine.a)
