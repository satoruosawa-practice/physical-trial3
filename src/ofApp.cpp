#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetFrameRate(60);
//  ofSetVerticalSync(false);
//  ofSetFrameRate(0);
  
  ofSetBackgroundAuto(false);
		
  Particle myParticle;
  myParticle.setup(ofVec2f(400,400),ofVec2f(0,0));
  particles_.push_back(myParticle);
  
  myParticle.setup(ofVec2f(400,500),ofVec2f(0,0));
  particles_.push_back(myParticle);
  
  myParticle.setup(ofVec2f(500,500),ofVec2f(0,0));
  particles_.push_back(myParticle);
  
  myParticle.setup(ofVec2f(500,400),ofVec2f(0,0));
  particles_.push_back(myParticle);
  
  Spring mySpring;
		
  for (int i = 0; i < particles_.size(); i++) {
    mySpring.setup(100, 0.2f);
    mySpring.setParticles(&particles_[i],
                          &particles_[(i+1) % particles_.size()]);
    springs_.push_back(mySpring);
  }
  
  mySpring.setup((particles_[0].getPosition() -
                  particles_[2].getPosition()).length(), 0.2f);
  mySpring.setParticles(&particles_[0], &particles_[2]);
  springs_.push_back(mySpring);
  
  mySpring.setup((particles_[1].getPosition() -
                  particles_[3].getPosition()).length(), 0.2f);
  mySpring.setParticles(&particles_[1], &particles_[3]);
  springs_.push_back(mySpring);
}

//--------------------------------------------------------------
void ofApp::update() {
  springs_[0].setDistance(100 + 50 * sin(ofGetElapsedTimef() * 8));
  springs_[2].setDistance(100 + 50 * sin(ofGetElapsedTimef() * 8 + PI));
  
  for (auto &p : particles_) {
    p.resetForce();
  }
  
  for (auto &p : particles_) {
    p.addForce(ofVec2f(0, 0.1f));
    p.addRepulsionForce(ofVec2f(mouseX, mouseY), 300, 0.7f);
  }
  
  for (auto &s : springs_) {
    s.update();
  }
  
  for (auto &p : particles_) {
    p.update();
  }
  
}

//--------------------------------------------------------------
void ofApp::draw() {
  
  ofEnableBlendMode(OF_BLENDMODE_ALPHA);
  ofSetColor(0, 0, 0, 63);
  ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
  
  ofSetColor(255, 255, 255);
  for (auto &s : springs_) {
    s.draw();
  }
  
  ofSetColor(31, 127, 255);
  for (auto &p : particles_) {
    p.draw();
  }
  
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
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
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
