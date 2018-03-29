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

#include "hdr/Interpolate.h"

#include <math.h>

static const double Pi = 3.14159265358979323846264338328;
static const double Pi_2 = 3.14159265358979323846264338328 * 2;

float ICE_Interpolate(float from, float to, float amount, float(*easing)(float))
{
	return from + (to - from) * (easing(amount));
}

/*
* Actual code by:
* Warren Moore https://github.com/warrenm
*/

/* modeled after the line y = x */
float ICE_Interpolate_Linear(float p)
{
	return p;
}

/* modeled after the parabola y = x^2 */
float ICE_Interpolate_QuadraticIn(float p)
{
	return p * p;
}

/* modeled after the parabola y = -x^2 + 2x */
float ICE_Interpolate_QuadraticOut(float p)
{
	return -(p * (p - 2));
}

/* modeled after the piecewise quadratic */
/* y = (1/2)((2x)^2)             ; [0, 0.5) */
/* y = -(1/2)((2x-1)*(2x-3) - 1) ; [0.5, 1] */
float ICE_Interpolate_QuadraticInOut(float p)
{
	if (p < 0.5) {
		return 2 * p * p;
	}
	else {
		return (-2 * p * p) + (4 * p) - 1;
	}
}

/* modeled after the cubic y = x^3 */
float ICE_Interpolate_CubicIn(float p)
{
	return p * p * p;
}

/* modeled after the cubic y = (x - 1)^3 + 1 */
float ICE_Interpolate_CubicOut(float p)
{
	float f = (p - 1);
	return f * f * f + 1;
}

/* modeled after the piecewise cubic */
/* y = (1/2)((2x)^3)       ; [0, 0.5) */
/* y = (1/2)((2x-2)^3 + 2) ; [0.5, 1] */
float ICE_Interpolate_CubicInOut(float p)
{
	if (p < 0.5) {
		return 4 * p * p * p;
	}
	else {
		float f = ((2 * p) - 2);
		return 0.5 * f * f * f + 1;
	}
}

/* modeled after the quartic x^4 */
float ICE_Interpolate_QuarticIn(float p)
{
	return p * p * p * p;
}

/* modeled after the quartic y = 1 - (x - 1)^4 */
float ICE_Interpolate_QuarticOut(float p)
{
	float f = (p - 1);
	return f * f * f * (1 - p) + 1;
}

/* modeled after the piecewise quartic */
/* y = (1/2)((2x)^4)        ; [0, 0.5) */
/* y = -(1/2)((2x-2)^4 - 2) ; [0.5, 1] */
float ICE_Interpolate_QuarticInOut(float p)
{
	if (p < 0.5) {
		return 8 * p * p * p * p;
	}
	else {
		float f = (p - 1);
		return -8 * f * f * f * f + 1;
	}
}

/* modeled after the quintic y = x^5 */
float ICE_Interpolate_QuinticIn(float p)
{
	return p * p * p * p * p;
}

/* modeled after the quintic y = (x - 1)^5 + 1 */
float ICE_Interpolate_QuinticOut(float p)
{
	float f = (p - 1);
	return f * f * f * f * f + 1;
}

/* modeled after the piecewise quintic */
/* y = (1/2)((2x)^5)       ; [0, 0.5) */
/* y = (1/2)((2x-2)^5 + 2) ; [0.5, 1] */
float ICE_Interpolate_QuinticInOut(float p)
{
	if (p < 0.5) {
		return 16 * p * p * p * p * p;
	}
	else {
		float f = ((2 * p) - 2);
		return 0.5 * f * f * f * f * f + 1;
	}
}

/* modeled after quarter-cycle of sine wave */
float ICE_Interpolate_SineIn(float p)
{
	return sin((p - 1) * Pi_2) + 1;
}

/* modeled after quarter-cycle of sine wave (different phase) */
float ICE_Interpolate_SineOut(float p)
{
	return sin(p * Pi_2);
}

/* modeled after half sine wave */
float ICE_Interpolate_SineInOut(float p)
{
	return 0.5 * (1 - cos(p * Pi));
}

/* modeled after shifted quadrant iV of unit circle */
float ICE_Interpolate_CircularIn(float p)
{
	return 1 - sqrt(1 - (p * p));
}

/* modeled after shifted quadrant iI of unit circle */
float ICE_Interpolate_CircularOut(float p)
{
	return sqrt((2 - p) * p);
}

/* modeled after the piecewise circular function */
/* y = (1/2)(1 - sqrt(1 - 4x^2))           ; [0, 0.5) */
/* y = (1/2)(sqrt(-(2x - 3)*(2x - 1)) + 1) ; [0.5, 1] */
float ICE_Interpolate_CircularInOut(float p)
{
	if (p < 0.5) {
		return 0.5 * (1 - sqrt(1 - 4 * (p * p)));
	}
	else {
		return 0.5 * (sqrt(-((2 * p) - 3) * ((2 * p) - 1)) + 1);
	}
}

/* modeled after the exponential function y = 2^(10(x - 1)) */
float ICE_Interpolate_ExponentialIn(float p)
{
	return (p == 0.0) ? p : pow(2, 10 * (p - 1));
}

/* modeled after the exponential function y = -2^(-10x) + 1 */
float ICE_Interpolate_ExponentialOut(float p)
{
	return (p == 1.0) ? p : 1 - pow(2, -10 * p);
}

/* modeled after the piecewise exponential */
/* y = (1/2)2^(10(2x - 1))         ; [0,0.5) */
/* y = -(1/2)*2^(-10(2x - 1))) + 1 ; [0.5,1] */
float ICE_Interpolate_ExponentialInOut(float p)
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
float ICE_Interpolate_ElasticIn(float p)
{
	return sin(13 * Pi_2 * p) * pow(2, 10 * (p - 1));
}

/* modeled after the damped sine wave y = sin(-13pi/2*(x + 1))*pow(2, -10x) + 1
*/
float ICE_Interpolate_ElasticOut(float p)
{
	return sin(-13 * Pi_2 * (p + 1)) * pow(2, -10 * p) + 1;
}

/* modeled after the piecewise exponentially-damped sine wave: */
/* y = (1/2)*sin(13pi/2*(2*x))*pow(2, 10 * ((2*x) - 1))      ; [0,0.5) */
/* y = (1/2)*(sin(-13pi/2*((2x-1)+1))*pow(2,-10(2*x-1)) + 2) ; [0.5, 1] */
float ICE_Interpolate_ElasticInOut(float p)
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
float ICE_Interpolate_BackIn(float p)
{
	return p * p * p - p * sin(p * Pi);
}

/* modeled after overshooting cubic y = 1-((1-x)^3-(1-x)*sin((1-x)*pi)) */
float ICE_Interpolate_BackOut(float p)
{
	float f = (1 - p);
	return 1 - (f * f * f - f * sin(f * Pi));
}

/* modeled after the piecewise overshooting cubic function: */
/* y = (1/2)*((2x)^3-(2x)*sin(2*x*pi))           ; [0, 0.5) */
/* y = (1/2)*(1-((1-x)^3-(1-x)*sin((1-x)*pi))+1) ; [0.5, 1] */
float ICE_Interpolate_BackInOut(float p)
{
	if (p < 0.5) {
		float f = 2 * p;
		return 0.5 * (f * f * f - f * sin(f * Pi));
	}
	else {
		float f = (1 - (2 * p - 1));
		return 0.5 * (1 - (f * f * f - f * sin(f * Pi))) + 0.5;
	}
}

float ICE_Interpolate_BounceIn(float p)
{
	return 1 - ICE_Interpolate_BounceOut(1 - p);
}

float ICE_Interpolate_BounceOut(float p)
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

float ICE_Interpolate_BounceInOut(float p)
{
	if (p < 0.5) {
		return 0.5 * ICE_Interpolate_BounceIn(p * 2);
	}
	else {
		return 0.5 * ICE_Interpolate_BounceOut(p * 2 - 1) + 0.5;
	}

}