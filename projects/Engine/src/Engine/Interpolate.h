/* Copyright (c) 2014, 2015 Ithai Levi @RLofC
*
* This software is provided 'as-is', without any express or implied
* warranty. In no event will the authors be held liable for any damages
* arising from the use of this software.
*
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
*
*    1. The origin of this software must not be misrepresented; you must not
*    claim that you wrote the original software. If you use this software
*    in a product, an acknowledgment in the product documentation would be
*    appreciated but is not required.
*
*    2. Altered source versions must be plainly marked as such, and must not be
*    misrepresented as being the original software.
*
*    3. This notice may not be removed or altered from any source
*    distribution.
*/

/* Code can have been altered by WARLUS Dylan for integrating it */


#ifndef DEF_ICE_INTERPOLATE
#define DEF_ICE_INTERPOLATE

#include "../Framework/BasicTypes.h"

/**
 * \brief 
 * \param from Start value
 * \param to Finish value
 * \param amount Progress in function
 * \param easing Function to use
 * \return Where it is on the function
 */
ICE_Float ICE_Interpolate(ICE_Float from, ICE_Float to, ICE_Float amount, ICE_Float(*easing)(ICE_Float));

/**
* Function Graph:
*
*     |                      _.-'
*     |                 _,,-'
*     |             _.-'
*     |         ,,-'
*     |    _,-''
*     |,.-'
*     +---------------------------
*
*/
ICE_Float ICE_Interpolate_Linear(ICE_Float p);

/**
* Function Graph:
*
*     |                          '
*     |                        ,'
*     |                      ,'
*     |                   _,'
*     |              _,.-'
*     | .........--''
*     +---------------------------
*
*/
ICE_Float ICE_Interpolate_QuadraticIn(ICE_Float p);

/**
* Function Graph:
*
*     |            _..,----''''---
*     |        ,,-'
*     |     ,-'
*     |   ,'
*     | ,'
*     |<
*     +---------------------------
*
*/
ICE_Float ICE_Interpolate_QuadraticOut(ICE_Float p);

/**
* Function Graph:
*
*     |                   _,,..--
*     |                ,-'
*     |              ,'
*     |             '
*     |          _,'
*     |--....,-''
*     +---------------------------
*
*/
ICE_Float ICE_Interpolate_QuadraticInOut(ICE_Float p);

/**
* Function Graph:
*
*     |                          '
*     |                        ,'
*     |                      ,'
*     |                   _,'
*     |              _,.-'
*     | .........--''
*     +---------------------------
*
*/
ICE_Float ICE_Interpolate_CubicIn(ICE_Float p);

/**
* Function Graph:
*
*     |            _..,----''''---
*     |        ,,-'
*     |     ,-'
*     |   ,'
*     | ,'
*     |<
*     +---------------------------
*
*/
ICE_Float ICE_Interpolate_CubicOut(ICE_Float p);

/**
* Function Graph:
*
*     |                   _,,..--
*     |                ,-'
*     |              ,'
*     |             '
*     |          _,'
*     |--....,-''
*     +---------------------------
*
*/
ICE_Float ICE_Interpolate_CubicInOut(ICE_Float p);

/**
* Function Graph:
*
*     |                          /
*     |                         /
*     |                        /
*     |                      ,'
*     |                  _,-'
*     |...________,,..--'
*     +---------------------------
*
*/
ICE_Float ICE_Interpolate_QuarticIn(ICE_Float p);

/**
* Function Graph:
*
*     |          _,..,---------...
*     |     ,,-''
*     |   ,'
*     |  /
*     | /
*     |`
*     +---------------------------
*
*/
ICE_Float ICE_Interpolate_QuarticOut(ICE_Float p);

/**
* Function Graph:
*
*     |                  _..------
*     |                ,'
*     |              .-
*     |              +
*     |            _/
*     |..____,,.--'
*     +---------------------------
*
*/
ICE_Float ICE_Interpolate_QuarticInOut(ICE_Float p);

/**
* Function Graph:
*
*     |                           |
*     |                           |
*     |                          /
*     |                        ,'
*     |                   _,.-'
*     |..............--'''
*     +---------------------------
*
*/
ICE_Float ICE_Interpolate_QuinticIn(ICE_Float p);

/**
* Function Graph:
*
*     |        __..--'''''''''''--
*     |    ,-''
*     |  ,'
*     | /
*     ||
*     ||
*     +---------------------------
*
*/
ICE_Float ICE_Interpolate_QuinticOut(ICE_Float p);

/**
* Function Graph:
*
*     |                 _..-------
*     |               ,'
*     |              |
*     |              '
*     |             /
*     |..__,,....--'
*     +---------------------------
*
*/
ICE_Float ICE_Interpolate_QuinticInOut(ICE_Float p);

/**
* Function Graph:
*
*     |                         _,
*     |                       ,'
*     |                     ,'
*     |                 _.-'
*     |             _.-'
*     |..._,,..,--''
*     +---------------------------
*
*/
ICE_Float ICE_Interpolate_SineIn(ICE_Float p);

/**
* Function Graph:
*
*     |                  __...----
*     |            _,.-''
*     |         ,,'
*     |     _.-'
*     |  ,-'
*     |-'
*     +---------------------------
*
*/
ICE_Float ICE_Interpolate_SineOut(ICE_Float p);

/**
* Function Graph:
*
*     |                      ___..
*     |                  ,-''
*     |               ,-'
*     |             ,-
*     |        __.-'
*     |.,----''
*     +---------------------------
*
*/
ICE_Float ICE_Interpolate_SineInOut(ICE_Float p);

/**
* Function Graph:
*
*     |                          |
*     |                         ,'
*     |                      _,'
*     |                  _,-'
*     |          _,.--'''
*     |__...---''
*     +---------------------------
*
*/
ICE_Float ICE_Interpolate_CircularIn(ICE_Float p);

/**
* Function Graph:
*
*     |                 _,,.....,-
*     |        _,,.---''
*     |    _,-'
*     |  ,'
*     |,'
*     |/
*     +---------------------------
*
*/
ICE_Float ICE_Interpolate_CircularOut(ICE_Float p);

/**
* Function Graph:
*
*     |                  _,..-----
*     |              ,-''
*     |             '.
*     |             ]
*     |        _,,.-
*     |_,.---''
*     +---------------------------
*
*/
ICE_Float ICE_Interpolate_CircularInOut(ICE_Float p);

/**
* Function Graph:
*
*     |                           .
*     |                           |
*     |                           |
*     |                         ,'
*     |                     _,-'
*     |..._________.....--''
*     +---------------------------
*
*/
ICE_Float ICE_Interpolate_ExponentialIn(ICE_Float p);

/**
* Function Graph:
*
*     |       _,.--''''''''''`----
*     |    ,,'
*     |  ,'
*     | /
*     |.'
*     ||
*     +---------------------------
*
*/
ICE_Float ICE_Interpolate_ExponentialOut(ICE_Float p);

/**
* Function Graph:
*
*     1               _,,--'''''--
*     |              /
*     |             |
*     |             |
*     |            ,'
*     |..._,,....--
*     +---------------------------
*
*/
ICE_Float ICE_Interpolate_ExponentialInOut(ICE_Float p);

/**
* Function Graph:
*
*     1                          )
*     |                         .'
*     |                         |
*     |                         |
*     |                _..     |
*     |__...----.   ,--   ;    /
*     +----------`''-------+--+---
*     |                    `-
*/
ICE_Float ICE_Interpolate_ElasticIn(ICE_Float p);

/**
* Function Graph:
*
*     | ,--
*     1 |   `.   <''`.__
*     | |    :_ ,'      `'------'
*     | |      '
*     ||
*     ||
*     ||
*     +---------------------------
*
*/
ICE_Float ICE_Interpolate_ElasticOut(ICE_Float p);

/**
* Function Graph:
*
*     |             _,\      _.._
*     1             /   `._,''
*     |            .'
*     |            |
*     |           |
*     |          .'
*     |_,,-'';   '
*     +-------`=+-----------------
*
*/
ICE_Float ICE_Interpolate_ElasticInOut(ICE_Float p);

/**
* Function Graph:
*
*     1                          ,
*     |                        ,'
*     |                       /
*     |                     ,'
*     |                   ,'
*     |._               ,'
*     +--`..=------=,,-'----------
*     |     `'''''
*/
ICE_Float ICE_Interpolate_BackIn(ICE_Float p);

/**
* Function Graph:
*
*     |        _,.------...__
*     1      ,-'              `--.
*     |    ,'
*     |   /
*     |  /
*     | /
*     |/
*     +---------------------------
*
*/
ICE_Float ICE_Interpolate_BackOut(ICE_Float p);

/**
* Function Graph:
*
*     |               _,----..
*     1               /        `-.
*     |              /
*     |             |
*     |             '
*     |            /
*     |_          /
*     +-`.=-----,'----------------
*     |   ``-''
*/
ICE_Float ICE_Interpolate_BackInOut(ICE_Float p);

/**
* Function Graph:
*
*     |                        _,.
*     |                     ,-'
*     |                    /
*     |              _    .'
*     | _._ ,-'-. ,-' `-. |
*     |-   '     '       '
*     +---------------------------
*
*/
ICE_Float ICE_Interpolate_BounceIn(ICE_Float p);

/**
* Function Graph:
*
*     |         \     `.   ,'. _.
*     |        | `-.-'  `-'   '
*     |        /
*     |       /
*     |     ,'
*     |..--'
*     +---------------------------
*
*/
ICE_Float ICE_Interpolate_BounceOut(ICE_Float p);

/**
* Function Graph:
*
*     |                 /\   '_,'/
*     |                ,' `-'
*     |              ,'
*     |          ,'-'
*     |     .--.|
*     |,-`.'   '|
*     +---------------------------
*
*/
ICE_Float ICE_Interpolate_BounceInOut(ICE_Float p);

#endif