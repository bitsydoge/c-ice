cmake_minimum_required(VERSION 3.9)
project(ICEngine C)
set(CMAKE_C_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

#### SDL2       ####     ########################################################################
####################     ########################################################################

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/script/cmake/")

IF (WIN32)
    add_definitions(-DICE_NO_VLD)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)

    include_directories(
            ${CMAKE_SOURCE_DIR}/external/SDL2/include/
    )

ELSE()
    find_package(SDL2 REQUIRED)
    find_package(SDL2_mixer REQUIRED)
    find_package(SDL2_ttf REQUIRED)
    include_directories(
            ${SDL2_INCLUDE_DIR}
            ${SDL2_MIXER_INCLUDE_DIR}
            ${SDL2_TTF_INCLUDE_DIR}
    )
ENDIF()


#### ICE ENGINE ####     ########################################################################
####################     ########################################################################

file(GLOB_RECURSE SOURCES
        projects/Engine/src/*.h
        projects/Engine/src/*.c
        )
string(REGEX REPLACE "CMakeFiles/[^;]+;?" "" SOURCES "${SOURCES}")
add_library(ICE STATIC ${SOURCES})