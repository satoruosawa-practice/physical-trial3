//
//  particle.cpp
//  physical-trial3
//
//  Created by OSAWASatoru on 6/3/17.
//
//

#include "./particle.h"

Particle::Particle() {
  friction_ = 0.01;
  gravity_.set(0, 0.1);
  mass_ = ofRandom(10);
}

Particle::Particle(float f, const ofVec2f &g, float m)
:friction_(f),
gravity_(g),
mass_(m) {}

void Particle::setup(const ofVec2f &p, const ofVec2f &v) {
  position_ = p;
  velocity_ = v;
}

void Particle::update() {
  addForce(gravity_);
  updateForce();
  updatePos();
  bounceOfWalls();
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

void Particle::bounceOfWalls() {
  bool bDidICollide = false;
  
  float xmin = 0;
  float xmax = ofGetWidth();
  float ymin = 0;
  float ymax = ofGetHeight();
  
  if (position_.x < xmin) {
    position_.x = xmin + (xmin - position_.x);
    velocity_.x *= -1;
    bDidICollide = true;
  } else if (position_.x > xmax) {
    position_.x = xmax - (position_.x - xmax);
    velocity_.x *= -1;
    bDidICollide = true;
  }
  if (position_.y < ymin) {
    position_.y = ymin + (ymin - position_.y);
    velocity_.y *= -1;
    bDidICollide = true;
  } else if (position_.y > ymax) {
    position_.y = ymax - (position_.y - ymax);
    velocity_.y *= -1;
    bDidICollide = true;
  }
  if (bDidICollide == true) {
    velocity_ *= 1.0;
  }
}
