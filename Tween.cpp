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

void Tween::setup(int duration, float start, float change, string ease, int delay, int loop)
{
	_tween.duration = duration;
	_tween.loop = loop;
	_delay.duration = delay;
	
	_start = start;
	_change = change;
	
	num = start;
	_ease = ease;
}

void Tween::setup(int duration, float start, float change, string ease)
{
	setup(duration, start, change, ease, 0, 0);
}

void Tween::setup(int duration, float start, float change, string ease, int delay)
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
	if (_ease == BACK_EASEIN)
		num = Back::easeIn(_tween.time, _start, _change, _tween.duration);
	else if(_ease == BACK_EASEOUT)
		num = Back::easeOut(_tween.time, _start, _change, _tween.duration);
	else if(_ease == BACK_EASEINOUT)
		num = Back::easeInOut(_tween.time, _start, _change, _tween.duration);
	else if(_ease == BOUNCE_EASEIN)
		num = Bounce::easeIn(_tween.time, _start, _change, _tween.duration);
	else if(_ease == BOUNCE_EASEOUT)
		num = Bounce::easeOut(_tween.time, _start, _change, _tween.duration);
	else if(_ease == BOUNCE_EASEINOUT)
		num = Bounce::easeInOut(_tween.time, _start, _change, _tween.duration);
	else if(_ease == CIRC_EASEIN)
		num = Circ::easeIn(_tween.time, _start, _change, _tween.duration);
	else if(_ease == CIRC_EASEOUT)
		num = Circ::easeOut(_tween.time, _start, _change, _tween.duration);
	else if(_ease == CIRC_EASEINOUT)
		num = Circ::easeInOut(_tween.time, _start, _change, _tween.duration);
	else if(_ease == CUBIC_EASEIN)
		num = Cubic::easeIn(_tween.time, _start, _change, _tween.duration);
	else if(_ease == CUBIC_EASEOUT)
		num = Cubic::easeOut(_tween.time, _start, _change, _tween.duration);
	else if(_ease == CUBIC_EASEINOUT)
		num = Cubic::easeInOut(_tween.time, _start, _change, _tween.duration);
	else if(_ease == ELASTIC_EASEIN)
		num = Elastic::easeIn(_tween.time, _start, _change, _tween.duration);
	else if(_ease == ELASTIC_EASEOUT)
		num = Elastic::easeOut(_tween.time, _start, _change, _tween.duration);
	else if(_ease == ELASTIC_EASEINOUT)
		num = Elastic::easeInOut(_tween.time, _start, _change, _tween.duration);
	else if(_ease == EXPO_EASEIN)
		num = Expo::easeIn(_tween.time, _start, _change, _tween.duration);
	else if(_ease == EXPO_EASEOUT)
		num = Expo::easeOut(_tween.time, _start, _change, _tween.duration);
	else if(_ease == EXPO_EASEINOUT)
		num = Expo::easeInOut(_tween.time, _start, _change, _tween.duration);
	else if(_ease == LINEAR_EASEIN)
		num = Linear::easeIn(_tween.time, _start, _change, _tween.duration);
	else if(_ease == LINEAR_EASEOUT)
		num = Linear::easeOut(_tween.time, _start, _change, _tween.duration);
	else if(_ease == LINEAR_EASEINOUT)
		num = Linear::easeInOut(_tween.time, _start, _change, _tween.duration);
	else if(_ease == QUAD_EASEIN)
		num = Quad::easeIn(_tween.time, _start, _change, _tween.duration);
	else if(_ease == QUAD_EASEOUT)
		num = Quad::easeOut(_tween.time, _start, _change, _tween.duration);
	else if(_ease == QUAD_EASEINOUT)
		num = Quad::easeInOut(_tween.time, _start, _change, _tween.duration);
	else if(_ease == QUART_EASEIN)
		num = Quart::easeIn(_tween.time, _start, _change, _tween.duration);
	else if(_ease == QUART_EASEOUT)
		num = Quart::easeOut(_tween.time, _start, _change, _tween.duration);
	else if(_ease == QUART_EASEINOUT)
		num = Quart::easeInOut(_tween.time, _start, _change, _tween.duration);
	else if(_ease == QUINT_EASEIN)
		num = Quint::easeIn(_tween.time, _start, _change, _tween.duration);
	else if(_ease == QUINT_EASEOUT)
		num = Quint::easeOut(_tween.time, _start, _change, _tween.duration);
	else if(_ease == QUINT_EASEINOUT)
		num = Quint::easeInOut(_tween.time, _start, _change, _tween.duration);
	else if(_ease == SINE_EASEIN)
		num = Sine::easeIn(_tween.time, _start, _change, _tween.duration);
	else if(_ease == SINE_EASEOUT)
		num = Sine::easeOut(_tween.time, _start, _change, _tween.duration);
	else if(_ease == SINE_EASEINOUT)
		num = Sine::easeInOut(_tween.time, _start, _change, _tween.duration);
	else 	
		cout << "ERROR: Wrong tween specfied\n";
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