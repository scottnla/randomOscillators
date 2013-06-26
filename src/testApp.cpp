#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
  ofBackground(0,0,0);
  ofEnableSmoothing();
  ofEnableAlphaBlending();
  ofSetFrameRate(30);
  ofNoFill();
  width = ofGetWidth();
  height = ofGetHeight();
  for(int i = 0; i < numFlowers; i++) {
    Flower f = Flower(width/2, height/2, 6, 300.0 - 50*i, 75.0);
    flowers[i] = f;
  }
}

//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){
 for(int i = 0; i < numFlowers; i++) {
   flowers[i].render(stepSize);
  }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
