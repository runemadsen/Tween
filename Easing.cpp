#include "Easing.h"

// back
float Easing::BackEaseIn(float t,float b , float c, float d) 
{
	float s = 1.70158f;
	float postFix = t/=d;
	return c*(postFix)*t*((s+1)*t - s) + b;
}

float Easing::BackEaseOut(float t,float b , float c, float d) 
{
	float s = 1.70158f;
	return c*((t=t/d-1)*t*((s+1)*t + s) + 1) + b;
}

float Easing::BackEaseInOut(float t,float b , float c, float d) 
{
	float s = 1.70158f;
	if ((t/=d/2) < 1) return c/2*(t*t*(((s*=(1.525f))+1)*t - s)) + b;
	float postFix = t-=2;
	return c/2*((postFix)*t*(((s*=(1.525f))+1)*t + s) + 2) + b;
}

// bounce
float Easing::BounceEaseIn(float t,float b , float c, float d) 
{
	return c - BounceEaseOut (d-t, 0, c, d) + b;
}

float Easing::BounceEaseOut(float t,float b , float c, float d) 
{
	if ((t/=d) < (1/2.75f)) {
		return c*(7.5625f*t*t) + b;
	} else if (t < (2/2.75f)) {
		float postFix = t-=(1.5f/2.75f);
		return c*(7.5625f*(postFix)*t + .75f) + b;
	} else if (t < (2.5/2.75)) {
		float postFix = t-=(2.25f/2.75f);
		return c*(7.5625f*(postFix)*t + .9375f) + b;
	} else {
		float postFix = t-=(2.625f/2.75f);
		return c*(7.5625f*(postFix)*t + .984375f) + b;
	}
}

float Easing::BounceEaseInOut(float t,float b , float c, float d) 
{
	if (t < d/2) return BounceEaseIn (t*2, 0, c, d) * .5f + b;
	else return BounceEaseOut (t*2-d, 0, c, d) * .5f + c*.5f + b;
}

// circ
float Easing::CircEaseIn(float t,float b , float c, float d) 
{
	return -c * (sqrt(1 - (t/=d)*t) - 1) + b;
}

float Easing::CircEaseOut(float t,float b , float c, float d) 
{
	return c * sqrt(1 - (t=t/d-1)*t) + b;
}

float Easing::CircEaseInOut(float t,float b , float c, float d) 
{
	if ((t/=d/2) < 1) return -c/2 * (sqrt(1 - t*t) - 1) + b;
	return c/2 * (sqrt(1 - t*(t-=2)) + 1) + b;
}

// cubic
float Easing::CubicEaseIn(float t,float b , float c, float d) 
{
	return c*(t/=d)*t*t + b;
}

float Easing::CubicEaseOut(float t,float b , float c, float d) 
{
	return c*((t=t/d-1)*t*t + 1) + b;
}

float Easing::CubicEaseInOut(float t,float b , float c, float d) 
{
	if ((t/=d/2) < 1) return c/2*t*t*t + b;
	return c/2*((t-=2)*t*t + 2) + b;	
}

// elastic
float Easing::ElasticEaseIn(float t,float b , float c, float d) 
{
	if (t==0) return b;  if ((t/=d)==1) return b+c;  
	float p=d*.3f;
	float a=c; 
	float s=p/4;
	float postFix =a*pow(2,10*(t-=1)); // this is a fix, again, with post-increment operators
	return -(postFix * sin((t*d-s)*(2*PI)/p )) + b;
}

float Easing::ElasticEaseOut(float t,float b , float c, float d) 
{
	if (t==0) return b;  if ((t/=d)==1) return b+c;  
	float p=d*.3f;
	float a=c; 
	float s=p/4;
	return (a*pow(2,-10*t) * sin( (t*d-s)*(2*PI)/p ) + c + b);	
}

float Easing::ElasticEaseInOut(float t,float b , float c, float d) 
{
	if (t==0) return b;  if ((t/=d/2)==2) return b+c; 
	float p=d*(.3f*1.5f);
	float a=c; 
	float s=p/4;
	
	if (t < 1) {
		float postFix =a*pow(2,10*(t-=1)); // postIncrement is evil
		return -.5f*(postFix* sin( (t*d-s)*(2*PI)/p )) + b;
	} 
	float postFix =  a*pow(2,-10*(t-=1)); // postIncrement is evil
	return postFix * sin( (t*d-s)*(2*PI)/p )*.5f + c + b;
}
// expo
float Easing::ExpoEaseIn(float t,float b , float c, float d) 
{
	return (t==0) ? b : c * pow(2, 10 * (t/d - 1)) + b;
}

float Easing::ExpoEaseOut(float t,float b , float c, float d) 
{
	return (t==d) ? b+c : c * (-pow(2, -10 * t/d) + 1) + b;	
}

float Easing::ExpoEaseInOut(float t,float b , float c, float d) 
{
	if (t==0) return b;
	if (t==d) return b+c;
	if ((t/=d/2) < 1) return c/2 * pow(2, 10 * (t - 1)) + b;
	return c/2 * (-pow(2, -10 * --t) + 2) + b;
}

// linear
float Easing::LinearEaseIn(float t,float b , float c, float d) 
{
	return c*t/d + b;
}

float Easing::LinearEaseOut(float t,float b , float c, float d) 
{
	return c*t/d + b;
}

float Easing::LinearEaseInOut(float t,float b , float c, float d) 
{
	return c*t/d + b;
}

// quad
float Easing::QuadEaseIn(float t,float b , float c, float d) 
{
	return c*(t/=d)*t + b;
}

float Easing::QuadEaseOut(float t,float b , float c, float d) 
{
	return -c *(t/=d)*(t-2) + b;
}

float Easing::QuadEaseInOut(float t,float b , float c, float d) 
{
	if ((t/=d/2) < 1) return ((c/2)*(t*t)) + b;
	return -c/2 * (((t-2)*(--t)) - 1) + b;
	/*
	 originally return -c/2 * (((t-2)*(--t)) - 1) + b;
	 
	 I've had to swap (--t)*(t-2) due to diffence in behaviour in 
	 pre-increment operators between java and c++, after hours
	 of joy
	 */
	
}

// quart
float Easing::QuartEaseIn(float t,float b , float c, float d) 
{
	return c*(t/=d)*t*t*t + b;
}

float Easing::QuartEaseOut(float t,float b , float c, float d) 
{
	return -c * ((t=t/d-1)*t*t*t - 1) + b;
}

float Easing::QuartEaseInOut(float t,float b , float c, float d) 
{
	if ((t/=d/2) < 1) return c/2*t*t*t*t + b;
	return -c/2 * ((t-=2)*t*t*t - 2) + b;
}

// quint
float Easing::QuintEaseIn(float t,float b , float c, float d) 
{
	return c*(t/=d)*t*t*t*t + b;
}

float Easing::QuintEaseOut(float t,float b , float c, float d) 
{
	return c*((t=t/d-1)*t*t*t*t + 1) + b;
}

float Easing::QuintEaseInOut(float t,float b , float c, float d) 
{
	if ((t/=d/2) < 1) return c/2*t*t*t*t*t + b;
	return c/2*((t-=2)*t*t*t*t + 2) + b;
}

// sine
float Easing::SineEaseIn(float t,float b , float c, float d) 
{
	return -c * cos(t/d * (PI/2)) + c + b;
}

float Easing::SineEaseOut(float t,float b , float c, float d) 
{
	return c * sin(t/d * (PI/2)) + b;	
}

float Easing::SineEaseInOut(float t,float b , float c, float d) 
{
	return -c/2 * (cos(PI*t/d) - 1) + b;
}


