#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  ofSetFrameRate(60);
  //  ofSetVerticalSync(false);
  //  ofSetFrameRate(0);
  ofBackground(63);
  ofSetCircleResolution(4);
  
  // メッシュを点で描画
  mesh_.setMode(OF_PRIMITIVE_POINTS);
}

//--------------------------------------------------------------
void ofApp::update() {
  for (auto &p: particles_) {
    p.resetForce();
    p.update();
  }
}

//--------------------------------------------------------------
void ofApp::draw() {
  ofSetColor(255);
  //  for (auto &p: particles_) {
  //    p.draw();
  //  }
  //  ofNoFill();
  //  ofBeginShape();
  //  for (auto &p: particles_) {
  //  ofCurveVertex(p.getPosition().x, p.getPosition().y);
  //  }
  //  ofEndShape();
  mesh_.clear();
  for (auto &p: particles_) {
    mesh_.addVertex(ofVec3f(p.getPosition().x, p.getPosition().y, 0));
  }
  mesh_.draw();
  
  ofSetColor(200);
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
void ofApp::mouseMoved(int x, int y) {
  
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
//    for(int i = 0; particles_.size() < 1000000; i ++) {
  for(int i = 0; i < 100; i++) {
    Particle p = Particle();
    float length = ofRandom(3.0);
    float angle = ofRandom(PI * 2);
    ofVec2f v = ofVec2f(cos(angle) * length, sin(angle) * length);
    p.setup(ofVec2f(x, y), v);
    particles_.push_back(p);
  }
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
