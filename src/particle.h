//
//  particle.h
//  physical-trial3
//
//  Created by OSAWASatoru on 6/3/17.
//
//

#pragma once
#include "ofMain.h"

class Particle {
 public:
  Particle();
  Particle(float f, const ofVec2f &g, float m, float r);
  void setup(const ofVec2f &p, const ofVec2f &v);
  void update();
  void draw();
  void resetForce();
  void addForce(const ofVec2f &f);
  void updateForce();
  void updatePos();

  void addAttractionForce(const ofVec2f &posOfForce, float radius, float scale);
  void addRepulsionForce(const ofVec2f &posOfForce,float radius, float scale);

  void addAttractionForce(Particle * targetP, float radius, float scale);
  void addRepulsionForce(Particle * targetP, float radius, float scale);

  void addRepulsionForce(const ofVec2f &posOfFrcLineA,
                         const ofVec2f &posOfFrcLineB,
                         float radius, float scale);

  void bounceOfWalls();

  // setter
  void setFriction(float f) { friction_ = f; }
  void setPosition(const ofVec2f &p) { position_ = p; }
  void setBFixed(bool b) { bFixed_ = b;}
  // getter
  const ofVec2f getPosition() { return position_; }
  const float getMass() { return mass_; }

 private:
  ofVec2f position_;
  ofVec2f velocity_;
  ofVec2f force_;
  float friction_;
  ofVec2f gravity_;
  float mass_;
  float radius_;

  bool bFixed_;
};
