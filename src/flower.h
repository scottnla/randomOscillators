#pragma once

#include "ofMain.h"
#include "oscillator.h"

class Flower {
 public:
  Flower() {
  };

  Flower(float x, float y, int petals, float size, float delta) {
    position.set(x,y);
    noPetals = petals;
    noPoints = int(ofRandom(1,13));
    avgSize = size;
    variation = delta;
    for(int i = 0; i < noPoints*noPetals; i++) {
      Oscillator o = Oscillator(avgSize, variation);
      osc.push_back(o);
    }
  };

  void render(float stepSize) {
    float dAngle = TWO_PI / (noPetals * noPoints);
    ofBeginShape();
    for(int i = 0; i < noPetals*noPoints+3; i++) {
      float radius = osc[i % noPoints].next(stepSize);
      ofCurveVertex(radius*sin(dAngle*i) + position.x, radius*cos(dAngle*i) + position.y);
    }
    ofEndShape();
  };

 protected:
  ofVec2f position;
  int noPetals;
  int noPoints;
  float avgSize;
  float variation;
  vector<Oscillator> osc;
};
