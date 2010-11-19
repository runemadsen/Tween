#include "Tween.h"

Tween::Tween()
{
	ofBackground(0, 0, 0);
	
	_img.loadImage("typeyourname.png");
	_font.loadFont("GothamRounded-Book.ttf", 26, true, true);
	
	_nameCounter.duration = 200;
	_titleFade.duration = 100;
	_nameFade.duration = 100;
	
	_userName = "";
	
	_fadeMode = false;
}