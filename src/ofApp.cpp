#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  ofSetFrameRate(60);
//    ofSetVerticalSync(false);
//    ofSetFrameRate(0);
  ofBackground(63);
//  ofSetCircleResolution(4);
  
//  mesh_.setMode(OF_PRIMITIVE_POINTS);
//  glEnable(GL_POINT_SMOOTH);
//  glPointSize(2.0);

}

//--------------------------------------------------------------
void ofApp::update() {
  while(particles_.size() > 2500) {
    particles_.erase(particles_.begin(), particles_.begin() + 100);
  }
  
  for (int i = 0; i < particles_.size(); i++){
    particles_[i].resetForce();
    for (int j = 0; j < i; j++){
      float strength = particles_[j].getMass() * particles_[i].getMass() * 0.001;
      particles_[i].addAttractionForce(&particles_[j], 200.0, strength);
    }
//    particles_[i].addAttractionForce(ofVec2f(ofGetWidth() / 2,
//                                             ofGetHeight() / 2),
//                                     1000, 0.13);
    particles_[i].update();
  }
}

//--------------------------------------------------------------
void ofApp::draw() {
  ofSetColor(255);
    for (auto &p: particles_) {
      p.draw();
    }
//  mesh_.clear();
//  for (auto &p: particles_) {
//    mesh_.addVertex(ofVec3f(p.getPosition().x, p.getPosition().y, 0));
//  }
//  mesh_.draw();
  
  ofSetColor(200);
  ofDrawBitmapString("particle num = " + ofToString(particles_.size()), 10, 20);
  ofDrawBitmapString("frameRate = " + ofToString(ofGetFrameRate()), 10, 40);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
  if (key == 'c') {
    particles_.clear();
  } if (key == 'r') {
  for(int i = 0; i < 1000; i++) {
    Particle p = Particle();
    float x = ofRandom(ofGetWidth());
    float y = ofRandom(ofGetHeight());
    p.setup(ofVec2f(x, y), ofVec2f(0, 0));
    particles_.push_back(p);
  }
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
  for(int i = 0; i < 10; i++) {
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
