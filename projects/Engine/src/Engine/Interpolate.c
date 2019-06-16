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

#include "Interpolate.h"

#include <math.h>

#include "../Framework/BasicTypes.h"

static const double Pi = 3.14159265358979323846264338328;
static const double Pi_2 = 3.14159265358979323846264338328 * 2;

ICE_Float ICE_Interpolate(ICE_Float from, ICE_Float to, ICE_Float amount, ICE_Float(*easing)(ICE_Float))
{
	return from + (to - from) * (easing(amount));
}

/*
* Actual code by:
* Warren Moore https://github.com/warrenm
*/

/* modeled after the line y = x */
ICE_Float ICE_Interpolate_Linear(ICE_Float p)
{
	return p;
}

/* modeled after the parabola y = x^2 */
ICE_Float ICE_Interpolate_QuadraticIn(ICE_Float p)
{
	return p * p;
}

/* modeled after the parabola y = -x^2 + 2x */
ICE_Float ICE_Interpolate_QuadraticOut(ICE_Float p)
{
	return -(p * (p - 2));
}

/* modeled after the piecewise quadratic */
/* y = (1/2)((2x)^2)             ; [0, 0.5) */
/* y = -(1/2)((2x-1)*(2x-3) - 1) ; [0.5, 1] */
ICE_Float ICE_Interpolate_QuadraticInOut(ICE_Float p)
{
	if (p < 0.5) {
		return 2 * p * p;
	}
	else {
		return (-2 * p * p) + (4 * p) - 1;
	}
}

/* modeled after the cubic y = x^3 */
ICE_Float ICE_Interpolate_CubicIn(ICE_Float p)
{
	return p * p * p;
}

/* modeled after the cubic y = (x - 1)^3 + 1 */
ICE_Float ICE_Interpolate_CubicOut(ICE_Float p)
{
	ICE_Float f = (p - 1);
	return f * f * f + 1;
}

/* modeled after the piecewise cubic */
/* y = (1/2)((2x)^3)       ; [0, 0.5) */
/* y = (1/2)((2x-2)^3 + 2) ; [0.5, 1] */
ICE_Float ICE_Interpolate_CubicInOut(ICE_Float p)
{
	if (p < 0.5) {
		return 4 * p * p * p;
	}
	else {
		ICE_Float f = ((2 * p) - 2);
		return 0.5 * f * f * f + 1;
	}
}

/* modeled after the quartic x^4 */
ICE_Float ICE_Interpolate_QuarticIn(ICE_Float p)
{
	return p * p * p * p;
}

/* modeled after the quartic y = 1 - (x - 1)^4 */
ICE_Float ICE_Interpolate_QuarticOut(ICE_Float p)
{
	ICE_Float f = (p - 1);
	return f * f * f * (1 - p) + 1;
}

/* modeled after the piecewise quartic */
/* y = (1/2)((2x)^4)        ; [0, 0.5) */
/* y = -(1/2)((2x-2)^4 - 2) ; [0.5, 1] */
ICE_Float ICE_Interpolate_QuarticInOut(ICE_Float p)
{
	if (p < 0.5) {
		return 8 * p * p * p * p;
	}
	else {
		ICE_Float f = (p - 1);
		return -8 * f * f * f * f + 1;
	}
}

/* modeled after the quintic y = x^5 */
ICE_Float ICE_Interpolate_QuinticIn(ICE_Float p)
{
	return p * p * p * p * p;
}

/* modeled after the quintic y = (x - 1)^5 + 1 */
ICE_Float ICE_Interpolate_QuinticOut(ICE_Float p)
{
	ICE_Float f = (p - 1);
	return f * f * f * f * f + 1;
}

/* modeled after the piecewise quintic */
/* y = (1/2)((2x)^5)       ; [0, 0.5) */
/* y = (1/2)((2x-2)^5 + 2) ; [0.5, 1] */
ICE_Float ICE_Interpolate_QuinticInOut(ICE_Float p)
{
	if (p < 0.5) {
		return 16 * p * p * p * p * p;
	}
	else {
		ICE_Float f = ((2 * p) - 2);
		return 0.5 * f * f * f * f * f + 1;
	}
}

/* modeled after quarter-cycle of sine wave */
ICE_Float ICE_Interpolate_SineIn(ICE_Float p)
{
	return sin((p - 1) * Pi_2) + 1;
}

/* modeled after quarter-cycle of sine wave (different phase) */
ICE_Float ICE_Interpolate_SineOut(ICE_Float p)
{
	return sin(p * Pi_2);
}

/* modeled after half sine wave */
ICE_Float ICE_Interpolate_SineInOut(ICE_Float p)
{
	return 0.5 * (1 - cos(p * Pi));
}

/* modeled after shifted quadrant iV of unit circle */
ICE_Float ICE_Interpolate_CircularIn(ICE_Float p)
{
	return 1 - sqrt(1 - (p * p));
}

/* modeled after shifted quadrant iI of unit circle */
ICE_Float ICE_Interpolate_CircularOut(ICE_Float p)
{
	return sqrt((2 - p) * p);
}

/* modeled after the piecewise circular function */
/* y = (1/2)(1 - sqrt(1 - 4x^2))           ; [0, 0.5) */
/* y = (1/2)(sqrt(-(2x - 3)*(2x - 1)) + 1) ; [0.5, 1] */
ICE_Float ICE_Interpolate_CircularInOut(ICE_Float p)
{
	if (p < 0.5) {
		return 0.5 * (1 - sqrt(1 - 4 * (p * p)));
	}
	else {
		return 0.5 * (sqrt(-((2 * p) - 3) * ((2 * p) - 1)) + 1);
	}
}

/* modeled after the exponential function y = 2^(10(x - 1)) */
ICE_Float ICE_Interpolate_ExponentialIn(ICE_Float p)
{
	return (p == 0.0) ? p : pow(2, 10 * (p - 1));
}

/* modeled after the exponential function y = -2^(-10x) + 1 */
ICE_Float ICE_Interpolate_ExponentialOut(ICE_Float p)
{
	return (p == 1.0) ? p : 1 - pow(2, -10 * p);
}

/* modeled after the piecewise exponential */
/* y = (1/2)2^(10(2x - 1))         ; [0,0.5) */
/* y = -(1/2)*2^(-10(2x - 1))) + 1 ; [0.5,1] */
ICE_Float ICE_Interpolate_ExponentialInOut(ICE_Float p)
{
	if (p == 0.0 || p == 1.0) return p;

	if (p < 0.5) {
		return 0.5 * pow(2, (20 * p) - 10);
	}
	else {
		return -0.5 * pow(2, (-20 * p) + 10) + 1;
	}
}

/* modeled after the damped sine wave y = sin(13pi/2*x)*pow(2, 10 * (x - 1)) */
ICE_Float ICE_Interpolate_ElasticIn(ICE_Float p)
{
	return sin(13 * Pi_2 * p) * pow(2, 10 * (p - 1));
}

/* modeled after the damped sine wave y = sin(-13pi/2*(x + 1))*pow(2, -10x) + 1
*/
ICE_Float ICE_Interpolate_ElasticOut(ICE_Float p)
{
	return sin(-13 * Pi_2 * (p + 1)) * pow(2, -10 * p) + 1;
}

/* modeled after the piecewise exponentially-damped sine wave: */
/* y = (1/2)*sin(13pi/2*(2*x))*pow(2, 10 * ((2*x) - 1))      ; [0,0.5) */
/* y = (1/2)*(sin(-13pi/2*((2x-1)+1))*pow(2,-10(2*x-1)) + 2) ; [0.5, 1] */
ICE_Float ICE_Interpolate_ElasticInOut(ICE_Float p)
{
	if (p < 0.5) {
		return 0.5 * sin(13 * Pi_2 * (2 * p)) * pow(2, 10 * ((2 * p) - 1));
	}
	else {
		return 0.5 * (sin(-13 * Pi_2 * ((2 * p - 1) + 1)) *
			pow(2, -10 * (2 * p - 1)) +
			2);
	}
}

/* modeled after the overshooting cubic y = x^3-x*sin(x*pi) */
ICE_Float ICE_Interpolate_BackIn(ICE_Float p)
{
	return p * p * p - p * sin(p * Pi);
}

/* modeled after overshooting cubic y = 1-((1-x)^3-(1-x)*sin((1-x)*pi)) */
ICE_Float ICE_Interpolate_BackOut(ICE_Float p)
{
	ICE_Float f = (1 - p);
	return 1 - (f * f * f - f * sin(f * Pi));
}

/* modeled after the piecewise overshooting cubic function: */
/* y = (1/2)*((2x)^3-(2x)*sin(2*x*pi))           ; [0, 0.5) */
/* y = (1/2)*(1-((1-x)^3-(1-x)*sin((1-x)*pi))+1) ; [0.5, 1] */
ICE_Float ICE_Interpolate_BackInOut(ICE_Float p)
{
	if (p < 0.5) {
		ICE_Float f = 2 * p;
		return 0.5 * (f * f * f - f * sin(f * Pi));
	}
	else {
		ICE_Float f = (1 - (2 * p - 1));
		return 0.5 * (1 - (f * f * f - f * sin(f * Pi))) + 0.5;
	}
}

ICE_Float ICE_Interpolate_BounceIn(ICE_Float p)
{
	return 1 - ICE_Interpolate_BounceOut(1 - p);
}

ICE_Float ICE_Interpolate_BounceOut(ICE_Float p)
{
	if (p < 4 / 11.0) {
		return (121 * p * p) / 16.0;
	}
	else if (p < 8 / 11.0) {
		return (363 / 40.0 * p * p) - (99 / 10.0 * p) + 17 / 5.0;
	}
	else if (p < 9 / 10.0) {
		return (4356 / 361.0 * p * p) - (35442 / 1805.0 * p) + 16061 / 1805.0;
	}
	else {
		return (54 / 5.0 * p * p) - (513 / 25.0 * p) + 268 / 25.0;
	}
}

ICE_Float ICE_Interpolate_BounceInOut(ICE_Float p)
{
	if (p < 0.5) {
		return 0.5 * ICE_Interpolate_BounceIn(p * 2);
	}
	else {
		return 0.5 * ICE_Interpolate_BounceOut(p * 2 - 1) + 0.5;
	}

}