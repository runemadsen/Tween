#include "testApp.h"

void testApp::setup()
{
	ofSetVerticalSync(true);
	
	myTween.setup(100, 0, ofGetWidth() - 25, Easing::BounceEaseOut);
	myTween.play();
	
	myTween2.setup(100, 0, ofGetWidth() - 25, Easing::QuadEaseOut, 50); // this is a delayed tweeb
	myTween2.play();
	
	ofBackground(0, 0, 0);
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
	ofSetColor(255, 0, 0);
	ofRect(myTween.num,100,25,25);
	
	ofSetColor(0, 255, 0);
	ofRect(myTween2.num,200,25,25);
	
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

void testApp::windowResized(int w, int h) {}