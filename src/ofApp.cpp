#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  ofSetFrameRate(60);
//    ofSetVerticalSync(false);
//    ofSetFrameRate(0);
  ofBackground(63);
  
  particle_a_.setup(ofVec2f(400, 400), ofVec2f(0,0));
  particle_a_.setFriction(0.04);
  
  particle_b_.setup(ofVec2f(400, 400), ofVec2f(0,0));
  particle_b_.setFriction(0.04);
  

  mySpring_.setup(100, 0.1);
  
  mySpring_.setParticles(&particle_a_, &particle_b_);
}

//--------------------------------------------------------------
void ofApp::update() {
  particle_a_.resetForce();
  particle_b_.resetForce();
  
  mySpring_.update();
  
  particle_a_.bounceOfWalls();
  particle_a_.update();
  
  particle_b_.bounceOfWalls();
  particle_b_.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
  ofSetColor(255);
  
  ofSetColor(191);
  mySpring_.draw();
  
  ofSetHexColor(0x3399ff);
  particle_a_.draw();
  particle_b_.draw();

  ofSetColor(200);
  ofDrawBitmapString("frameRate = " + ofToString(ofGetFrameRate()), 10, 20);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
  
}
//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
  particle_a_.setPosition(ofVec2f(x, y));
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
  particle_a_.setBFixed(true);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
  particle_a_.setBFixed(false);
}


//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {
  
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {
  
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {
  
}
