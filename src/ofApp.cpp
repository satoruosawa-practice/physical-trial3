#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  ofSetFrameRate(60);
//  ofSetVerticalSync(false);
//  ofSetFrameRate(0);
  ofBackground(63);
  ofSetCircleResolution(4);
}

//--------------------------------------------------------------
void ofApp::update() {
  for (auto &p: particles_) {
    p.update();
  }
}

//--------------------------------------------------------------
void ofApp::draw() {
  ofSetColor(255);
  for (auto &p: particles_) {
    p.draw();
  }
  ofNoFill();
  ofBeginShape();
  for (auto &p: particles_) {
  ofCurveVertex(p.getPosition().x, p.getPosition().y);
  }
  ofEndShape();

  ofDrawBitmapString("particle num = " + ofToString(particles_.size()), 10, 20);
  ofDrawBitmapString("frameRate = " + ofToString(ofGetFrameRate()), 10, 40);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
  if (key == 'c') {
    particles_.clear();
  }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
  
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ) {
  
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
//  for(int i = 0; i < 100; i ++) {
  Particle p;
  p.setFriction(0.01);
  p.setGravity(0, 0.1);
  p.setInit(ofVec2f(x, y));
  float length = ofRandom(30.0);
  float angle = ofRandom(PI * 2);
  p.setVelocity(cos(angle) * length, sin(angle) * length);
  particles_.push_back(p);
//  }
}
//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
  
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
  
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
