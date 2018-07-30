cmake_minimum_required(VERSION 3.9)
project(ICEngine C)
set(CMAKE_C_STANDARD 11)

#### SDL2       ####     ########################################################################
####################     ########################################################################

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

IF (WIN32)
    add_definitions(-DICE_NO_VLD)

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

include_directories(ICEngine/src)
include_directories(ICEngine/src/Audio)
include_directories(ICEngine/src/Core)
include_directories(ICEngine/src/External/chipmunk)
include_directories(ICEngine/src/External/mattiasgustavsson)
include_directories(ICEngine/src/External/rlutil)
include_directories(ICEngine/src/External/SDL2_gfx)
include_directories(ICEngine/src/External/stb)
include_directories(ICEngine/src/Framework)
include_directories(ICEngine/src/Graphics)
include_directories(ICEngine/src/Maths)
include_directories(ICEngine/src/Physics)

add_library(ICEngine
        ICEngine/src/Audio/Audio.c
        ICEngine/src/Audio/Audio.h
        ICEngine/src/Audio/Music.c
        ICEngine/src/Audio/Music.h
        ICEngine/src/Audio/Sound.c
        ICEngine/src/Audio/Sound.h
        ICEngine/src/Audio/TypesAudio.h
        ICEngine/src/Core/Asset.c
        ICEngine/src/Core/Asset.h
        ICEngine/src/Core/Asset_private.c
        ICEngine/src/Core/Asset_private.h
        ICEngine/src/Core/Converter_private.h
        ICEngine/src/Core/Core.c
        ICEngine/src/Core/Core.h
        ICEngine/src/Core/Core_private.c
        ICEngine/src/Core/Core_private.h
        ICEngine/src/Core/Data.c
        ICEngine/src/Core/Data.h
        ICEngine/src/Core/Debug.c
        ICEngine/src/Core/Debug.h
        ICEngine/src/Core/Entity.c
        ICEngine/src/Core/Entity.h
        ICEngine/src/Core/Game.c
        ICEngine/src/Core/Game.h
        ICEngine/src/Core/Game_private.c
        ICEngine/src/Core/Game_private.h
        ICEngine/src/Core/Input.c
        ICEngine/src/Core/Input.h
        ICEngine/src/Core/Input_private.c
        ICEngine/src/Core/Input_private.h
        ICEngine/src/Core/Label.c
        ICEngine/src/Core/Label.h
        ICEngine/src/Core/Label_private.c
        ICEngine/src/Core/Label_private.h
        ICEngine/src/Core/State.c
        ICEngine/src/Core/State.h
        ICEngine/src/Core/Time_.c
        ICEngine/src/Core/Time_.h
        ICEngine/src/Core/Time_private.c
        ICEngine/src/Core/Time_private.h
        ICEngine/src/Core/TypesCore.h
        ICEngine/src/Core/Window.c
        ICEngine/src/Core/Window.h
        ICEngine/src/External/chipmunk/chipmunk.c
        ICEngine/src/External/chipmunk/chipmunk.h
        ICEngine/src/External/chipmunk/chipmunk_ffi.h
        ICEngine/src/External/chipmunk/chipmunk_private.h
        ICEngine/src/External/chipmunk/chipmunk_structs.h
        ICEngine/src/External/chipmunk/chipmunk_types.h
        ICEngine/src/External/chipmunk/chipmunk_unsafe.h
        ICEngine/src/External/chipmunk/cpArbiter.c
        ICEngine/src/External/chipmunk/cpArbiter.h
        ICEngine/src/External/chipmunk/cpArray.c
        ICEngine/src/External/chipmunk/cpBB.h
        ICEngine/src/External/chipmunk/cpBBTree.c
        ICEngine/src/External/chipmunk/cpBody.c
        ICEngine/src/External/chipmunk/cpBody.h
        ICEngine/src/External/chipmunk/cpCollision.c
        ICEngine/src/External/chipmunk/cpConstraint.c
        ICEngine/src/External/chipmunk/cpConstraint.h
        ICEngine/src/External/chipmunk/cpDampedRotarySpring.c
        ICEngine/src/External/chipmunk/cpDampedRotarySpring.h
        ICEngine/src/External/chipmunk/cpDampedSpring.c
        ICEngine/src/External/chipmunk/cpDampedSpring.h
        ICEngine/src/External/chipmunk/cpGearJoint.c
        ICEngine/src/External/chipmunk/cpGearJoint.h
        ICEngine/src/External/chipmunk/cpGrooveJoint.c
        ICEngine/src/External/chipmunk/cpGrooveJoint.h
        ICEngine/src/External/chipmunk/cpHashSet.c
        ICEngine/src/External/chipmunk/cpHastySpace.c
        ICEngine/src/External/chipmunk/cpHastySpace.h
        ICEngine/src/External/chipmunk/cpMarch.c
        ICEngine/src/External/chipmunk/cpMarch.h
        ICEngine/src/External/chipmunk/cpPinJoint.c
        ICEngine/src/External/chipmunk/cpPinJoint.h
        ICEngine/src/External/chipmunk/cpPivotJoint.c
        ICEngine/src/External/chipmunk/cpPivotJoint.h
        ICEngine/src/External/chipmunk/cpPolyline.c
        ICEngine/src/External/chipmunk/cpPolyline.h
        ICEngine/src/External/chipmunk/cpPolyShape.c
        ICEngine/src/External/chipmunk/cpPolyShape.h
        ICEngine/src/External/chipmunk/cpRatchetJoint.c
        ICEngine/src/External/chipmunk/cpRatchetJoint.h
        ICEngine/src/External/chipmunk/cpRobust.c
        ICEngine/src/External/chipmunk/cpRobust.h
        ICEngine/src/External/chipmunk/cpRotaryLimitJoint.c
        ICEngine/src/External/chipmunk/cpRotaryLimitJoint.h
        ICEngine/src/External/chipmunk/cpShape.c
        ICEngine/src/External/chipmunk/cpShape.h
        ICEngine/src/External/chipmunk/cpSimpleMotor.c
        ICEngine/src/External/chipmunk/cpSimpleMotor.h
        ICEngine/src/External/chipmunk/cpSlideJoint.c
        ICEngine/src/External/chipmunk/cpSlideJoint.h
        ICEngine/src/External/chipmunk/cpSpace.c
        ICEngine/src/External/chipmunk/cpSpace.h
        ICEngine/src/External/chipmunk/cpSpaceComponent.c
        ICEngine/src/External/chipmunk/cpSpaceDebug.c
        ICEngine/src/External/chipmunk/cpSpaceHash.c
        ICEngine/src/External/chipmunk/cpSpaceQuery.c
        ICEngine/src/External/chipmunk/cpSpaceStep.c
        ICEngine/src/External/chipmunk/cpSpatialIndex.c
        ICEngine/src/External/chipmunk/cpSpatialIndex.h
        ICEngine/src/External/chipmunk/cpSweep1D.c
        ICEngine/src/External/chipmunk/cpTransform.h
        ICEngine/src/External/chipmunk/cpVect.h
        ICEngine/src/External/chipmunk/prime.h
        ICEngine/src/External/mattiasgustavsson/rnd.h
        ICEngine/src/External/rlutil/rlutil.c
        ICEngine/src/External/rlutil/rlutil.h
        ICEngine/src/External/SDL2_gfx/SDL2_framerate.c
        ICEngine/src/External/SDL2_gfx/SDL2_framerate.h
        ICEngine/src/External/SDL2_gfx/SDL2_gfxPrimitives.c
        ICEngine/src/External/SDL2_gfx/SDL2_gfxPrimitives.h
        ICEngine/src/External/SDL2_gfx/SDL2_gfxPrimitives_font.h
        ICEngine/src/External/SDL2_gfx/SDL2_imageFilter.c
        ICEngine/src/External/SDL2_gfx/SDL2_imageFilter.h
        ICEngine/src/External/SDL2_gfx/SDL2_rotozoom.c
        ICEngine/src/External/SDL2_gfx/SDL2_rotozoom.h
        ICEngine/src/External/stb/stb_image.h
        ICEngine/src/Framework/Assert_.c
        ICEngine/src/Framework/Assert_.h
        ICEngine/src/Framework/Log.c
        ICEngine/src/Framework/Log.h
        ICEngine/src/Framework/Memory_.c
        ICEngine/src/Framework/Memory_.h
        ICEngine/src/Framework/Random.c
        ICEngine/src/Framework/Random.h
        ICEngine/src/Framework/Std_.c
        ICEngine/src/Framework/Std_.h
        ICEngine/src/Framework/String_.c
        ICEngine/src/Framework/String_.h
        ICEngine/src/Framework/Terminal.c
        ICEngine/src/Framework/Terminal.h
        ICEngine/src/Framework/Terminal_private.c
        ICEngine/src/Framework/Terminal_private.h
        ICEngine/src/Framework/TypesFramework.h
        ICEngine/src/Graphics/Animation.c
        ICEngine/src/Graphics/Animation.h
        ICEngine/src/Graphics/Camera.c
        ICEngine/src/Graphics/Camera.h
        ICEngine/src/Graphics/Color.h
        ICEngine/src/Graphics/Color_private.h
        ICEngine/src/Graphics/Draw.c
        ICEngine/src/Graphics/Draw.h
        ICEngine/src/Graphics/Font.c
        ICEngine/src/Graphics/Font.h
        ICEngine/src/Graphics/Gui.c
        ICEngine/src/Graphics/Gui.h
        ICEngine/src/Graphics/Gui_private.c
        ICEngine/src/Graphics/Gui_private.h
        ICEngine/src/Graphics/Primitive.c
        ICEngine/src/Graphics/Primitive.h
        ICEngine/src/Graphics/Render.c
        ICEngine/src/Graphics/Render.h
        ICEngine/src/Graphics/Render_private.c
        ICEngine/src/Graphics/Render_private.h
        ICEngine/src/Graphics/Sprite.c
        ICEngine/src/Graphics/Sprite.h
        ICEngine/src/Graphics/Texture.c
        ICEngine/src/Graphics/Texture.h
        ICEngine/src/Graphics/Texture_private.c
        ICEngine/src/Graphics/Texture_private.h
        ICEngine/src/Graphics/TypesGraphics.h
        ICEngine/src/Maths/Box.h
        ICEngine/src/Maths/Interpolate.c
        ICEngine/src/Maths/Interpolate.h
        ICEngine/src/Maths/Maths.h
        ICEngine/src/Maths/TypesMaths.h
        ICEngine/src/Maths/Vector.h
        ICEngine/src/Physics/TypesPhysics.h
        ICEngine/src/Raw/Error.c
        ICEngine/src/Raw/Icon.c
        ICEngine/src/ICE.h
        ICEngine/src/Core/MacOS_.c
        ICEngine/src/Core/MacOS_.h ICEngine/src/External/stb/SDL_stbimage.h)

#### TEST PROJECTS #     ########################################################################
####################     ########################################################################
#### TEST PROJECTS #     ########################################################################
####################     ########################################################################
#### TEST PROJECTS #     ########################################################################
####################     ########################################################################



#### HelloWorld ####     ########################################################################
####################     ########################################################################


add_executable(HelloWorld
        TestProject/HelloWorld/src/main.c)

add_dependencies(HelloWorld ICEngine)

IF (WIN32)
    target_link_libraries(HelloWorld ${CMAKE_SOURCE_DIR}/cmake-build-debug/ICEngine.lib)
    target_link_libraries(HelloWorld ${CMAKE_SOURCE_DIR}/external/SDL2/lib/x86/SDL2.lib)
    target_link_libraries(HelloWorld ${CMAKE_SOURCE_DIR}/external/SDL2/lib/x86/SDL2main.lib)
    target_link_libraries(HelloWorld ${CMAKE_SOURCE_DIR}/external/SDL2/lib/x86/SDL2_ttf.lib)
    target_link_libraries(HelloWorld ${CMAKE_SOURCE_DIR}/external/SDL2/lib/x86/SDL2_mixer.lib)
ELSE()
    target_link_libraries(HelloWorld
            ${SDL2_LIBRARY}
            ${SDL2_MIXER_LIBRARIES}
            ${SDL2_TTF_LIBRARIES})
    target_link_libraries(HelloWorld ${CMAKE_SOURCE_DIR}/cmake-build-debug/libICEngine.a)
ENDIF()


#### 2DWatch    ####     ########################################################################
####################     ########################################################################

add_executable(2DWatch
        TestProject/2DWatch/src/main.c
        TestProject/2DWatch/src/data.c
        TestProject/2DWatch/src/data.h
        TestProject/2DWatch/src/inventory.c
        TestProject/2DWatch/src/inventory.h
        TestProject/2DWatch/src/weapon.c
        TestProject/2DWatch/src/weapon.h)

add_dependencies(2DWatch ICEngine)

IF (WIN32)
    target_link_libraries(2DWatch ${CMAKE_SOURCE_DIR}/cmake-build-debug/ICEngine.lib)
    target_link_libraries(2DWatch ${CMAKE_SOURCE_DIR}/external/SDL2/lib/x86/SDL2.lib)
    target_link_libraries(2DWatch ${CMAKE_SOURCE_DIR}/external/SDL2/lib/x86/SDL2main.lib)
    target_link_libraries(2DWatch ${CMAKE_SOURCE_DIR}/external/SDL2/lib/x86/SDL2_ttf.lib)
    target_link_libraries(2DWatch ${CMAKE_SOURCE_DIR}/external/SDL2/lib/x86/SDL2_mixer.lib)
ELSE()
    target_link_libraries(2DWatch
            ${SDL2_LIBRARY}
            ${SDL2_MIXER_LIBRARIES}
            ${SDL2_TTF_LIBRARIES})
    target_link_libraries(2DWatch ${CMAKE_SOURCE_DIR}/cmake-build-debug/libICEngine.a)
ENDIF()


#### Test       ####     ########################################################################
####################     ########################################################################

add_executable(Test
        TestProject/Test/src/main.c)

add_dependencies(Test ICEngine)

IF (WIN32)
    target_link_libraries(Test ${CMAKE_SOURCE_DIR}/cmake-build-debug/ICEngine.lib)
    target_link_libraries(Test ${CMAKE_SOURCE_DIR}/external/SDL2/lib/x86/SDL2.lib)
    target_link_libraries(Test ${CMAKE_SOURCE_DIR}/external/SDL2/lib/x86/SDL2main.lib)
    target_link_libraries(Test ${CMAKE_SOURCE_DIR}/external/SDL2/lib/x86/SDL2_ttf.lib)
    target_link_libraries(Test ${CMAKE_SOURCE_DIR}/external/SDL2/lib/x86/SDL2_mixer.lib)
ELSE()
    target_link_libraries(Test
            ${SDL2_LIBRARY}
            ${SDL2_MIXER_LIBRARIES}
            ${SDL2_TTF_LIBRARIES})
    target_link_libraries(Test ${CMAKE_SOURCE_DIR}/cmake-build-debug/libICEngine.a)
ENDIF()
