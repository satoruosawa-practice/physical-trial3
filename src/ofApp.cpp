#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
//  ofSetFrameRate(60);
    ofSetVerticalSync(false);
    ofSetFrameRate(0);
  ofBackground(63);
  
  for(int i = 0; i < 100; i++) {
    Particle p;
    float x = ofGetWidth()/2 + 100 * cos ( (i / 200.0) * TWO_PI);
    float y = ofGetHeight()/5 + 100 * sin ( (i / 200.0) * TWO_PI);
    p.setup(ofVec2f(x, y), ofVec2f(0,0));
    p.setFriction(0.04);
    particles_.push_back(p);
  }
  for (int i = 0; i < particles_.size(); i ++) {
    Spring s;
    s.setup(0, 0.6);
    s.setParticles(&particles_[i], &particles_[(i + 1) % particles_.size()]);
    springs_.push_back(s);
  }
}

//--------------------------------------------------------------
void ofApp::update() {
  for (auto &p : particles_) {
    p.resetForce();
  }
  
  for (int i = 0; i < particles_.size(); i++){
//      particles_[i].addAttractionForce(ofVec2f(mouseX, mouseY), 200, 1.0);
      particles_[i].addRepulsionForce(ofVec2f(mouseX, mouseY), 200, 3.0);
    particles_[i].addRepulsionForce(ofVec2f(0, ofGetHeight()),
                                    ofVec2f(ofGetWidth(), ofGetHeight()),
                                    20, 1.0);
    
    for (int j = 0; j < 3; j++) {
      particles_[i].addRepulsionForce(ofVec2f(0, ofGetHeight() * float(j) / 3.0),
                                      ofVec2f(ofGetWidth(), ofGetHeight() * (float(j) / 3.0 + 1.0 / 12.0)),
                                      20, 1.0);
      particles_[i].addRepulsionForce(ofVec2f(ofGetWidth(), ofGetHeight() * (float(j) / 3.0 + 1.0 / 12.0)),
                                      ofVec2f(0, ofGetHeight() * (float(j) / 3.0 + 2.0 / 12.0)),
                                      20, 1.0);
      particles_[i].addRepulsionForce(ofVec2f(0, ofGetHeight() * (float(j) / 3.0 + 3.0 / 12.0)),
                                      ofVec2f(ofGetWidth(), ofGetHeight() * (float(j) / 3.0 + 2.0 / 12.0)),
                                      20, 1.0);
      particles_[i].addRepulsionForce(ofVec2f(ofGetWidth(), ofGetHeight() * (float(j) / 3.0 + 4.0 / 12.0)),
                                      ofVec2f(0, ofGetHeight() * (float(j) / 3.0 + 3.0 / 12.0)),
                                      20, 1.0);
    }
    
    for (int j = 0; j < i; j++){
      particles_[i].addRepulsionForce(&particles_[j], 50, 0.1);
    }
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

  
  ofSetColor(255);
  ofBeginShape();
  for (int i = 0; i < particles_.size(); i++){
    ofVertex(particles_[i].getPosition().x, particles_[i].getPosition().y);
  }
  ofEndShape();

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
  particles_[0].setPosition(ofVec2f(x, y));
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
  particles_[0].setBFixed(true);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
  particles_[0].setBFixed(false);
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
