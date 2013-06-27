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
  midiIn.listPorts();
  midiIn.openPort(0);
  midiIn.ignoreTypes(false, false, false);
  midiIn.addListener(this);
  midiIn.setVerbose(false);
  for(int i = 0; i < numFlowers; i++) {
    Flower f = Flower(width/2, height/2, 6, 300.0 - 50*i, 75.0);
    flowers[i] = f;
  }
    color = 255;
}

//--------------------------------------------------------------
void testApp::update(){
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(0,255,0);
    for(int i = 0; i < numFlowers; i++) {
      //flowers[i].renderRect(stepSize, width, height);
      flowers[i].renderRadial(stepSize);
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

//--------------------------------------------------------------
void testApp::exit(){ 
  midiIn.closePort();
  midiIn.removeListener(this);
}

//--------------------------------------------------------------
void testApp::newMidiMessage(ofxMidiMessage& msg) {
  // make a copy of the latest message
  midiMessage = msg;
  if(midiMessage.bytes[0] == 0xF8) {
    counter++;
  }
    if(counter % 24 == 0) {
        ofLog() << "Beat!" << counter;
    }
}
