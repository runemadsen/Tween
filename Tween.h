#pragma once

#include "ofMain.h"
#include "Back.h"
#include "Bounce.h"
#include "Circ.h"
#include "Cubic.h"
#include "Elastic.h"
#include "Expo.h"
#include "Linear.h"
#include "Quad.h"
#include "Quart.h"
#include "Quint.h"
#include "Sine.h"

#define BACK_EASEIN "Back.easeIn"
#define BACK_EASEOUT "Back.easeOut"
#define BACK_EASEINOUT "Back.easeInOut"

#define BOUNCE_EASEIN "Bounce.easeIn"
#define BOUNCE_EASEOUT "Bounce.easeOut"
#define BOUNCE_EASEINOUT "Bounce.easeInOut"

#define CIRC_EASEIN "Circ.easeIn"
#define CIRC_EASEOUT "Circ.easeOut"
#define CIRC_EASEINOUT "Circ.easeInOut"

#define CUBIC_EASEIN "Cubic.easeIn"
#define CUBIC_EASEOUT "Cubic.easeOut"
#define CUBIC_EASEINOUT "Cubic.easeInOut"

#define ELASTIC_EASEIN "Elastic.easeIn"
#define ELASTIC_EASEOUT "Elastic.easeOut"
#define ELASTIC_EASEINOUT "Elastic.easeInOut"

#define EXPO_EASEIN "Expo.easeIn"
#define EXPO_EASEOUT "Expo.easeOut"
#define EXPO_EASEINOUT "Expo.easeInOut"

#define LINEAR_EASEIN "Linear.easeIn"
#define LINEAR_EASEOUT "Linear.easeOut"
#define LINEAR_EASEINOUT "Linear.easeInOut"

#define QUAD_EASEIN "Quad.easeIn"
#define QUAD_EASEOUT "Quad.easeOut"
#define QUAD_EASEINOUT "Quad.easeInOut"

#define QUART_EASEIN "Quart.easeIn"
#define QUART_EASEOUT "Quart.easeOut"
#define QUART_EASEINOUT "Quart.easeInOut"

#define QUINT_EASEIN "qQuint.easeIn"
#define QUINT_EASEOUT "Quint.easeOut"
#define QUINT_EASEINOUT "Quint.easeInOut"

#define SINE_EASEIN "Sine.easeIn"
#define SINE_EASEOUT "Sine.easeOut"
#define SINE_EASEINOUT "Sine.easeInOut"

/*	TweenTimer
 ___________________________________________________ */

class TweenTimer 
{
public:
	
	int state; 
	float time, duration;
	int loop;
	
	TweenTimer() 
	{
		loop = 0;
		time = 0.0; 
		duration = 0.0; 
		state = 0;
	}
	
	void tick()
	{
		time += state;
		
		if (time > duration) 
		{
			time = duration;
			
			if(loop == 0)
				state = 0;
			else if(loop == 1)
				state = time = 0;
			else if(loop == 2)
				state -1;
		}
		else if(time < 0)
		{
			time = 0;
			
			if(loop == 0)
				state = 0;
			else if(loop == 2)
				state = 1;
		}
	}
};

/*	Tween
 ___________________________________________________ */

class Tween {
	
public:
	
	Tween();
	void setup(int duration, float start, float change, string ease);
	void setup(int duration, float start, float change, string ease, int delay);
	void setup(int duration, float start, float change, string ease, int delay, int loop);
	void play();
	void pause();
	void stop();
	
	bool finished();
	
	void update();
	
	float num;
	float percent;
	
private:
	
	TweenTimer _tween;
	TweenTimer _delay;
	
	float _start;
	float _change;
	string _ease;
	
	void runEasing();
};