#pragma once

#include "ofMain.h"

class Oscillator {
 public:
  Oscillator(float rad, float amp) {
    radius = rad;
    amplitude = amp;
    angle = ofRandom(0, TWO_PI);
  };

  float next(float stepSize) {
    angle = fmod(angle + 0.4*stepSize*ofRandom(0, PI / 256), TWO_PI);
    value = radius + amplitude*sin(angle);
    return value;
  };

 protected:
  float radius;
  float amplitude;
  float angle;
  float value;
};
