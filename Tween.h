#pragma once

#include "Easing.h"

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
	void setup(int duration, float start, float change, float (* ease)(float, float, float, float));
	void setup(int duration, float start, float change, float (* ease)(float, float, float, float), int delay);
	void setup(int duration, float start, float change, float (* ease)(float, float, float, float), int delay, int loop);
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
	float (* _ease)(float, float, float, float);
	
	void runEasing();
};