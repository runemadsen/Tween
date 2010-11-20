#include "testApp.h"

void testApp::setup()
{
	ofSetVerticalSync(true);
	
	myTween.setup(100, 0, ofGetWidth(), "Elastic.easeOut");
	myTween.play();
	
	myTween2.setup(100, 0, ofGetWidth(), "Quad.easeInOut", 50); // this is a delayed tweeb
	myTween2.play();
}

//--------------------------------------------------------------
void testApp::update()
{
	myTween.update();
	myTween2.update();
}

//--------------------------------------------------------------
void testApp::draw()
{
	ofRect(myTween.num,200,60,60);
	
	ofRect(myTween2.num,200,100,60);
	
	if(myTween.finished())
	{
		cout << "Yeah, Finished Tween" << endl;
	}
	
	if(myTween2.finished())
	{
		cout << "Yeah, Finished Tween 2" << endl;
	}
}

void testApp::keyPressed  (int key){}

void testApp::keyReleased  (int key){}

void testApp::mouseMoved(int x, int y ){}

void testApp::mouseDragged(int x, int y, int button){}

void testApp::mousePressed(int x, int y, int button){}

void testApp::mouseReleased(int x, int y, int button){}
