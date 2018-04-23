#pragma once

#include "ofMain.h"
#include "ofxLeapMotion2.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void keyPressed  (int key);
    void exit();
    
    vector <int> fingersFound;
	vector <ofxLeapMotionSimpleHand> handTracking;
    
    // oF classes
    
    ofPolyline line;
	ofEasyCam cam;
    
    // addon
    
    ofxLeapMotion leap;
};
