#include "ofApp.h"

ofVideoGrabber grabber;
ofImage resultImg;
//ofImage: ofPixels + ofTexture

//ofPixels as the CPU side representation of pixel data
//can be sent to the GPU as an ofTexture object.

//To draw pixels, you need to put them into an ofTexture and
//to manipulate an ofTextures pixel data you need an ofPixels object.

int brightnessThreshold;
ofParameter<int> moveAmount = 10;
ofParameter<int> threshold = 127;
ofParameter<bool> saveBackground;

ofxPanel gui;

//--------------------------------------------------------------
void ofApp::setup(){
    
    //the window setting
    ofSetWindowShape(1280, 720);
    ofSetFrameRate(12);
    
    //turn on the grabber aka our webcam
    grabber.setup(1280, 720);
    
    resultImg.allocate(grabber.getWidth(), grabber.getHeight(), OF_IMAGE_COLOR);

    threshold.set("Controlled Pixel Brightness Value",127,0,255);
    moveAmount.set("Pixel Move Amount",10,0,100);

    
    gui.setup("threshold");
    gui.add(threshold);
    gui.add(moveAmount);

    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    grabber.update();

      brightnessThreshold = ofMap(mouseX, 0, ofGetWidth(), 255, 0);
      // & operator. The reference ofPixels from the ofImage are then modified directly.  avoid making a copy there too.
      ofPixels& grabberPix = grabber.getPixels();
      ofPixels& resultPix = resultImg.getPixels();
    
//    int moveAmount=10;
    
      for (int y = 0; y < grabberPix.getHeight(); y++)
      {
        for (int x = 0; x < grabberPix.getWidth(); x++)
        {
          ofColor pixColor = grabberPix.getColor(x, y);
            
//          ⬇️this follow the mouseX
//          if (pixColor.getBrightness() > brightnessThreshold)
            
            
            if (pixColor.getBrightness() > threshold) {
                // Adjust the probability of movement
                int xOffset = ofRandom(-moveAmount, moveAmount);
                int yOffset = ofRandom(-moveAmount, moveAmount);
                
                int newX = ofClamp(x + xOffset, 0, grabberPix.getWidth() - 1);
                int newY = ofClamp(y + yOffset, 0, grabberPix.getHeight() - 1);
                
                ofColor pixColor = grabberPix.getColor(x, y);
                resultPix.setColor(newX, newY, pixColor);
                }

        
        }
      }
      resultImg.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    resultImg.draw(0, 0, ofGetWidth(), ofGetHeight());
    gui.draw();
    
}

//--------------------------------------------------------------
//void ofApp::exit(){
//
//}
//
////--------------------------------------------------------------
//void ofApp::keyPressed(int key){
//
//}
//
////--------------------------------------------------------------
//void ofApp::keyReleased(int key){
//
//}
//
////--------------------------------------------------------------
//void ofApp::mouseMoved(int x, int y ){
//
//}
//
////--------------------------------------------------------------
//void ofApp::mouseDragged(int x, int y, int button){
//
//}
//
////--------------------------------------------------------------
//void ofApp::mousePressed(int x, int y, int button){
//
//}
//
////--------------------------------------------------------------
//void ofApp::mouseReleased(int x, int y, int button){
//
//}
//
////--------------------------------------------------------------
//void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){
//
//}
//
////--------------------------------------------------------------
//void ofApp::mouseEntered(int x, int y){
//
//}
//
////--------------------------------------------------------------
//void ofApp::mouseExited(int x, int y){
//
//}

//--------------------------------------------------------------
//void ofApp::windowResized(int w, int h){
//
//}
//
////--------------------------------------------------------------
//void ofApp::gotMessage(ofMessage msg){
//
//}
//
////--------------------------------------------------------------
//void ofApp::dragEvent(ofDragInfo dragInfo){
//
//}
