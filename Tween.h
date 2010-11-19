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

/*	Tween
 ___________________________________________________ */

class Tween {
	
public:
	
	Tween();
	void setup(int duration, float start, float change, string ease);
	void setup(int duration, float start, float change, string ease, int delay);
	void setup(int duration, float start, float change, string ease, int delay, int loop);
	void start();
	void pause();
	void stop();
	bool finished();
	bool tweening();
	
	float get
	
	
private:
	
	TweenTimer _timer;
};

/*	TweenTimer
 ___________________________________________________ */

class TweenTimer 
{
public:
	
	int state; 
	float time, duration;
	bool upDown;
	
	TweenTimer() 
	{
		upDown = false;
		time = 0.0; 
		duration = 0.0; 
		state = 1;
	}
	
	void tick()
	{
		time += state;
		
		if (time > duration) 
		{
			time = duration;
			state = upDown ? -1 : 0;
		}
		else if(time < 0)
		{
			time = 0;
			state = upDown ? 1 : 0;
		}
	}
};