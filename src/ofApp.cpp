#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    
    ofSetFrameRate(60);
    ofSetWindowTitle("Insta");
    
    ofNoFill();
    ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void ofApp::update() {
    
}

//--------------------------------------------------------------
void ofApp::draw() {
    
    if (ofGetMousePressed() == false) {
        
        return;
    }
    
    ofPoint mouse = ofPoint(ofGetMouseX(), ofGetMouseY());
    ofPoint prev_mouse = ofPoint(ofGetPreviousMouseX(), ofGetPreviousMouseY());
    
    ofSetColor(39);
    ofSetLineWidth(10);
    ofDrawLine(mouse, prev_mouse);
    
    if (ofRandom(100) < 50) {
        
        ofPoint target = mouse - prev_mouse;
        target *= 10;
        
        ofPushMatrix();
        ofTranslate(mouse);
        
        ofSetColor(39);
        ofSetLineWidth(5);
        ofDrawLine(ofPoint(0, 0), target);
        
        ofSetColor(255, 239, 239);
        for (int f = 0; f < target.length() * 0.5; f++) {
            
            ofDrawCircle(target * ofRandom(1) + ofPoint(ofRandom(-30, 30), ofRandom(-30, 30)), 3);
        }
        
        ofPopMatrix();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    
    if (key == 'c') {
        
        ofBackground(0);
    }
}

//--------------------------------------------------------------
//int main() {
//    
//    ofSetupOpenGL(720, 720, OF_WINDOW);
//    ofRunApp(new ofApp());
//}