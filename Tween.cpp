#include "Tween.h"

/*	Constructor
 ___________________________________________________ */

Tween::Tween()
{
	num = 0;
	percent = 0;
}

/*	Setup methods
 ___________________________________________________ */

void Tween::setup(int duration, float start, float change, float (* ease)(float, float, float, float), int delay, int loop)
{
	_tween.duration = duration;
	_tween.loop = loop;
	_delay.duration = delay;
	
	_start = start;
	_change = change;
	
	num = start;
	_ease = ease;
}

void Tween::setup(int duration, float start, float change, float (* ease)(float, float, float, float))
{
	setup(duration, start, change, ease, 0, 0);
}

void Tween::setup(int duration, float start, float change, float (* ease)(float, float, float, float), int delay)
{
	setup(duration, start, change, ease, delay, 0);
}

/*	Update
 ___________________________________________________ */

void Tween::update()
{
	if(_delay.duration > 0)
	{
		_delay.tick();
		
		if(_delay.time == _delay.duration)
		{
			_tween.state = 1;
		}
	}
	
	_tween.tick();
	
	percent = _tween.time / _tween.duration;

	runEasing();
}

void Tween::runEasing()
{
	num = _ease(_tween.time, _start, _change, _tween.duration);
}

/*	Control methods
 ___________________________________________________ */

void Tween::play()
{
	if(_delay.duration > 0 && _delay.time != _delay.duration)
	{
		_delay.state = 1;
	}
	else 
	{
		_tween.state = 1;
	}
}

void Tween::pause()
{
	_delay.state = 0;
	_tween.state = 0;
}

void Tween::stop()
{
	pause();
	
	_delay.time = 0;
	_tween.time = 0;
}

bool Tween::finished()
{
	return _tween.time == _tween.duration ? true : false;
}