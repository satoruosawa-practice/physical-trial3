//
//  particle.cpp
//  physical-trial3
//
//  Created by OSAWASatoru on 6/3/17.
//
//

#include "./particle.h"

void Particle::setInit(const ofVec2f &initPos) {
  position_.set(initPos);
  force_.set(0, 0);
}

void Particle::update() {
  resetForce();
  addForce(gravity_);
  updateForce();
  updatePos();
  checkBounds(0, 0, ofGetWidth(), ofGetHeight());
  constrain(0, 0, ofGetWidth(), ofGetHeight());
}

void Particle::draw() {
  ofDrawCircle(position_, 2);
}

void Particle::resetForce() {
  force_.set(0, 0);
}

void Particle::addForce(const ofVec2f &f) {
  force_ += f;
}

void Particle::updateForce() {
  force_ -= velocity_ * friction_;
}

void Particle::updatePos() {
  velocity_ += force_;
  position_ += velocity_;
}

void Particle::checkBounds(float xmin, float ymin, float xmax, float ymax) {
  if (position_.x < xmin || position_.x > xmax) {
    velocity_.x *= -1;
  }
  if (position_.y < ymin || position_.y > ymax) {
    velocity_.y *= -1;
  }
}

void Particle::constrain(float xmin, float ymin, float xmax, float ymax) {
  if (position_.x < xmin) {
    position_.x = xmin + (xmin - position_.x);
  }
  if (position_.x > xmax) {
    position_.x = xmax - (position_.x - xmax);
  }
  if (position_.y < ymin) {
    position_.y = ymin + (ymin - position_.y);
  }
  if (position_.y > ymax) {
    position_.y = ymax - (position_.y - ymax);
  }
}
