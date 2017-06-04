//
//  spring.h
//  physical-trial3
//
//  Created by OSAWASatoru on 6/4/17.
//
//

#pragma once

#include "ofMain.h"
#include "Particle.h"

class Spring {
 public:
  Spring();
  Spring(float distance, float springiness);
  void setup(float distance, float springiness);
  void update();
  void draw();

  // setter
  void setParticles(Particle *a, Particle *b) {
    particleA_ = a;
    particleB_ = b;
  }

 private:
  Particle *particleA_;
  Particle *particleB_;
  float distance_;
  float springiness_;
};
