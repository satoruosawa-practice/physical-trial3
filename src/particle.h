//
//  particle.h
//  physical-trial3
//
//  Created by OSAWASatoru on 6/3/17.
//
//

#pragma once // インクルードガード（コンパイルの際に一度しか読みこまれないように）
#include "ofMain.h" // openFrameworksの機能を使えるように

class Particle {
 public:
  void setInit(const ofVec2f &initPos);
  void update();
  void draw();
  void resetForce();
  void addForce(const ofVec2f &f);
  void updateForce();
  void updatePos();
  void checkBounds(float xmin, float ymin, float xmax, float ymax);
  void constrain(float xmin, float ymin, float xmax, float ymax);
  // setter
  void setFriction(float f) {
    friction_ = f;
  }
  void setGravity(float x, float y) {
    gravity_.set(x, y);
  }
  void setVelocity(float x, float y) {
    velocity_.set(x, y);
  }

 private:
  ofVec2f position_;
  ofVec2f velocity_;
  ofVec2f force_;
  float friction_;
  ofVec2f gravity_;
};
