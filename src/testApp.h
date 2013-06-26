#pragma once

#include "ofMain.h"
#include "flower.h"
#include "ofxMidi.h"

class testApp : public ofBaseApp, public ofxMidiListener {
 public:
  void setup();
  void update();
  void draw();
  
  void keyPressed(int key);
  void keyReleased(int key);
  void mouseMoved(int x, int y);
  void mouseDragged(int x, int y, int button);
  void mousePressed(int x, int y, int button);
  void mouseReleased(int x, int y, int button);
  void windowResized(int w, int h);
  void dragEvent(ofDragInfo dragInfo);
  void gotMessage(ofMessage msg);
  void exit();
  void newMidiMessage(ofxMidiMessage& msg);
 
 private:
  static const int numFlowers = 8;
  Flower flowers[numFlowers];
  float width, height;
  static const float stepSize = 16;
  ofxMidiIn midiIn;
  ofxMidiMessage midiMessage;
  int counter, beatCounter;
    float color;
};
