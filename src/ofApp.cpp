#include "ofApp.h"

//--------------------------------------------------------------
//
//  BLOOM created by Celine Chappert
//
//  Godsmiths, Creative Computing Semester 2, 2018
//
//  Masters Maths+Computing, 'Computational Arts'
//
//  All code my own, unless otherwise noted.
//
//  Sakura flowers inspired by a code sketch published on
//  instagram by Kiyoshinakauchi. Link in readme
//
//  Leap integration done with the help of ofxLeapMotion2,
//  a wrapper for the Leap Motion SDK.
//
//
//--------------------------------------------------------------


//--------------------------------------------------------------


void ofApp::setup(){
    
    ofSetBackgroundAuto(false);
    
    ofSetWindowTitle("Bloom");
    ofSetFrameRate(60);
    
    ofColor red(178,34,34);
    ofColor blue(56,78,80);
    
    ofBackground(red);
    

    ofSetVerticalSync(true);
	ofSetLogLevel(OF_LOG_VERBOSE);
    
	leap.open();
    
    // keep app receiving data from leap motion even when it's in the background
    
    leap.setReceiveBackgroundFrames(true);
    
	cam.setOrientation(ofPoint(-20, 0, 0));
    
    // 3d
    
	glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
}


//--------------------------------------------------------------
void ofApp::update(){
	fingersFound.clear();
    
    
	// getSimpleHands() is a vector function written in the addon code
    // found in the addon's .h file

    handTracking = leap.getSimpleHands();
    
    if(leap.isFrameNew() && handTracking.size() ){
        
        // leap settings config
        
        leap.setMappingX(-230, 230, -ofGetWidth()/2, ofGetWidth()/2);
		leap.setMappingY(90, 490, -ofGetHeight()/2, ofGetHeight()/2);
        leap.setMappingZ(-150, 150, -200, 200);
        
        fingerType fingerTypes[] = {THUMB, INDEX, MIDDLE, RING, PINKY};
        
        for(int i = 0; i < handTracking.size(); i++){
            for (int f=0; f<5; f++) {
                int id = handTracking[i].fingers[ fingerTypes[f] ].id;
                ofPoint mcp = handTracking[i].fingers[ fingerTypes[f] ].mcp; // metacarpal
                ofPoint pip = handTracking[i].fingers[ fingerTypes[f] ].pip; // proximal
                ofPoint dip = handTracking[i].fingers[ fingerTypes[f] ].dip; // distal
                ofPoint tip = handTracking[i].fingers[ fingerTypes[f] ].tip; // fingertip
                fingersFound.push_back(id);
            }
        }
    }
    
    
    

    
	// tell ofxLeapMotion that the frame is no longer new.
	leap.markFrameAsOld();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    //--------------------------------------------------------------
    //
    //  GRID
    //
    //--------------------------------------------------------------

	ofSetColor(255);
	ofDrawBitmapString("Sakura Bloom with ofxLeapMotion \nLeap Connected? " + ofToString(leap.isConnected()), 20, 20);

    ofDrawBitmapString("Frame " + ofToString(ofGetFrameNum() ), 20, 50);

	cam.begin();
    
    // orientation, 3d landscape
    
	ofPushMatrix();
    ofRotate(90, 0, 0, 1);
    
    ofSetColor(255,50);
//    ofDrawGridPlane(800, 20, false);
	ofPopMatrix();
    
    //--------------------------------------------------------------
    //
    //  HAND, TRACKING & TREE
    //
    //--------------------------------------------------------------
    
    //    fingerType fingerTypes[] = {THUMB, INDEX, MIDDLE, RING, PINKY};
    
    for(int i = 0; i < handTracking.size(); i++){
        
        // SDK variables (may be useful for more specific finger gestures)
        
        //        bool isLeft        = simpleHands[i].isLeft;
        //        ofPoint handNormal = simpleHands[i].handNormal;
        
        
        //--------------------------------------------------------------
        // tracking
        
        ofPoint handPos    = handTracking[i].handPos;
        

        //--------------------------------------------------------------
        // branch
        
        ofSetColor(39);
        ofSetLineWidth(ofRandom(9,19));
        line.draw();
        
        // save all the hand tracking positions into points and
        // push those points into ofPolyline class to connect them.
        
        ofPoint pt;
        pt.set(handPos.x, handPos.y);
        line.addVertex(pt);
        
        // x% of the time
        
        if (ofRandom(100) < 10) {
            
        
        // forloop formula, although tweaked,
        // originally found in Kiyoshinakauchi's code sketch.
        
        for (int f = 0; f < pt.length() * 0.5; f+=5) {
            
            //--------------------------------------------------------------
            // cherry blossoms
            
            ofSetColor(255, 239, 239, ofRandom(255));
            ofDrawCircle(handPos.x + ofRandom(-30,30), handPos.y + ofRandom(-30,30), ofRandom(0.5, 4.5));
            
            }
        }
        

        
        //--------------------------------------------------------------
        // fingers
        
//        ofSetColor(255, 255, 0);
//        ofDrawArrow(handPos, handPos + 100*handNormal);
//        
//        for (int f=0; f<5; f++) {
//            ofPoint mcp = simpleHands[i].fingers[ fingerTypes[f] ].mcp;  // metacarpal
//            ofPoint pip = simpleHands[i].fingers[ fingerTypes[f] ].pip;  // proximal
//            ofPoint dip = simpleHands[i].fingers[ fingerTypes[f] ].dip;  // distal
//            ofPoint tip = simpleHands[i].fingers[ fingerTypes[f] ].tip;  // fingertip
//            
//            ofSetColor(255,255,0);
//            
//            ofDrawSphere(mcp.x, mcp.y, mcp.z, 12);
//            ofDrawSphere(pip.x, pip.y, pip.z, 12);
//            ofDrawSphere(dip.x, dip.y, dip.z, 12);
//            ofDrawSphere(tip.x, tip.y, tip.z, 12);
//            
//            ofSetColor(255);
//            ofSetLineWidth(10);
//            ofDrawLine(mcp.x, mcp.y, mcp.z, pip.x, pip.y, pip.z);
//            ofDrawLine(pip.x, pip.y, pip.z, dip.x, dip.y, dip.z);
//            ofDrawLine(dip.x, dip.y, dip.z, tip.x, tip.y, tip.z);
//        }
    }
    


    
	cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    // clear
    
    if (key == ' ') {
        
        ofBackground(178,34,34);
        line.clear();
    }
    
    // save screenshot in bin/data
    
    if (key == 's') {
        ofImage screenshot;
        screenshot.grabScreen(0,0,700,700);
        screenshot.save("save"+ofGetTimestampString()+".png");
    }

    
}

//--------------------------------------------------------------
void ofApp::exit(){
    
    // close down Leap and kill the controller
    
    leap.close();
}
