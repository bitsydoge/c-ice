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

/* Code can have been altered by ***REMOVED*** for integrating it */

#ifndef DEF_ICE_INTERPOLATE
#define DEF_ICE_INTERPOLATE

/**
 * \brief 
 * \param from Start value
 * \param to Finish value
 * \param amount Progress in function
 * \param easing Function to use
 * \return Where it is on the function
 */
float ICE_Interpolate(float from, float to, float amount, float(*easing)(float));

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
float ICE_Interpolate_Linear(float p);

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
float ICE_Interpolate_QuadraticIn(float p);

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
float ICE_Interpolate_QuadraticOut(float p);

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
float ICE_Interpolate_QuadraticInOut(float p);

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
float ICE_Interpolate_CubicIn(float p);

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
float ICE_Interpolate_CubicOut(float p);

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
float ICE_Interpolate_CubicInOut(float p);

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
float ICE_Interpolate_QuarticIn(float p);

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
float ICE_Interpolate_QuarticOut(float p);

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
float ICE_Interpolate_QuarticInOut(float p);

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
float ICE_Interpolate_QuinticIn(float p);

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
float ICE_Interpolate_QuinticOut(float p);

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
float ICE_Interpolate_QuinticInOut(float p);

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
float ICE_Interpolate_SineIn(float p);

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
float ICE_Interpolate_SineOut(float p);

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
float ICE_Interpolate_SineInOut(float p);

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
float ICE_Interpolate_CircularIn(float p);

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
float ICE_Interpolate_CircularOut(float p);

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
float ICE_Interpolate_CircularInOut(float p);

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
float ICE_Interpolate_ExponentialIn(float p);

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
float ICE_Interpolate_ExponentialOut(float p);

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
float ICE_Interpolate_ExponentialInOut(float p);

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
float ICE_Interpolate_ElasticIn(float p);

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
float ICE_Interpolate_ElasticOut(float p);

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
float ICE_Interpolate_ElasticInOut(float p);

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
float ICE_Interpolate_BackIn(float p);

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
float ICE_Interpolate_BackOut(float p);

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
float ICE_Interpolate_BackInOut(float p);

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
float ICE_Interpolate_BounceIn(float p);

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
float ICE_Interpolate_BounceOut(float p);

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
float ICE_Interpolate_BounceInOut(float p);

#endif