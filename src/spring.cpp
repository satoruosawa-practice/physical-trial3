//
//  spring.cpp
//  physical-trial3
//
//  Created by OSAWASatoru on 6/4/17.
//
//

#include "./spring.h"

Spring::Spring(){
  particleA_ = NULL;
  particleB_ = NULL;
}

Spring::Spring(float distance, float springiness){
  particleA_ = NULL;
  particleB_ = NULL;
  distance_ = distance;
  springiness_ = springiness;
}

void Spring::setup(float distance, float springiness) {
  distance_ = distance;
  springiness_ = springiness;
}

void Spring::update(){
  if ((particleA_ == NULL) || (particleB_ == NULL)){
    return;
  }
  ofVec2f pta = particleA_->getPosition();
  ofVec2f ptb = particleB_->getPosition();
  float theirDistance = (pta - ptb).length();
  float springForce = (springiness_ * (distance_ - theirDistance));
  ofVec2f frcToAdd = (pta-ptb).getNormalized() * springForce;
  particleA_->addForce(frcToAdd);
  particleB_->addForce(-frcToAdd);
}

void Spring::draw(){
  if ((particleA_ == NULL) || (particleB_ == NULL)){
    return;
  }
  ofDrawLine(particleA_->getPosition(), particleB_->getPosition());
}
