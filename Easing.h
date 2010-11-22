#include "ofMain.h"

class Easing {
	
	public:
		
	// back
	static float BackEaseIn(float t,float b , float c, float d);
	static float BackEaseOut(float t,float b , float c, float d);
	static float BackEaseInOut(float t,float b , float c, float d);
	
	// bounce
	static float BounceEaseIn(float t,float b , float c, float d);
	static float BounceEaseOut(float t,float b , float c, float d);
	static float BounceEaseInOut(float t,float b , float c, float d);
	
	// circ
	static float CircEaseIn(float t,float b , float c, float d);
	static float CircEaseOut(float t,float b , float c, float d);
	static float CircEaseInOut(float t,float b , float c, float d);
	
	// cubic
	static float CubicEaseIn(float t,float b , float c, float d);
	static float CubicEaseOut(float t,float b , float c, float d);
	static float CubicEaseInOut(float t,float b , float c, float d);
	
	// elastic
	static float ElasticEaseIn(float t,float b , float c, float d);
	static float ElasticEaseOut(float t,float b , float c, float d);
	static float ElasticEaseInOut(float t,float b , float c, float d);
	
	// expo
	static float ExpoEaseIn(float t,float b , float c, float d);
	static float ExpoEaseOut(float t,float b , float c, float d);
	static float ExpoEaseInOut(float t,float b , float c, float d);
	
	// linear
	static float LinearEaseIn(float t,float b , float c, float d);
	static float LinearEaseOut(float t,float b , float c, float d);
	static float LinearEaseInOut(float t,float b , float c, float d);
	
	// quad
	static float QuadEaseIn(float t,float b , float c, float d);
	static float QuadEaseOut(float t,float b , float c, float d);
	static float QuadEaseInOut(float t,float b , float c, float d);
	
	// quart
	static float QuartEaseIn(float t,float b , float c, float d);
	static float QuartEaseOut(float t,float b , float c, float d);
	static float QuartEaseInOut(float t,float b , float c, float d);
	
	// quint
	static float QuintEaseIn(float t,float b , float c, float d);
	static float QuintEaseOut(float t,float b , float c, float d);
	static float QuintEaseInOut(float t,float b , float c, float d);
	
	// sine
	static float SineEaseIn(float t,float b , float c, float d);
	static float SineEaseOut(float t,float b , float c, float d);
	static float SineEaseInOut(float t,float b , float c, float d);
};