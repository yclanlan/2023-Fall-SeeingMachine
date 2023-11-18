// ofApp.h
#pragma once


#include "ofMain.h"
#include "ofxOsc.h"
#include "ofxGui.h"
#include "ofxBox2d.h"
#include "ofxKinect.h"
#include "ofxOpenCv.h"
#include "ofxCv.h"

class ofApp : public ofBaseApp
{
public:
  void setup();
  void update();
  void draw();
    
    void serverIndexChanged(int& val);
    
//    ofxSyphonServerDirectory serverDirectory;
//    ofxSyphonClient client;
    
    ofParameter<int> serverIdx;
    
    
    
    void exit();
    void createContourEdge(ofPolyline polyline);
    
    void keyPressed(int key);
    void mousePressed(int x, int y, int button);
    
    
//  ofVideoGrabber grabber;
//  ofImage thresholdImg;

//
    int recvPort;
     
     // Osc receive mouseXY
     ofxOscReceiver receiver;
    
     int cursorX;
     int cursorY;
    
     int angle;
    
     //send contour back
     
    

    ofParameter<int> thresholdVal;
    ofParameter<bool> sendGrabber;
    ofParameter<bool> sendThreshold;
    
    
    ofxPanel gui;
      
    ofxButton uiLearn;
    ofxButton uiClearCircles;
    ofxButton uiClearContourEdge;
    ofxIntSlider uiThreshold;
    ofxFloatSlider uiNearThreshold;
    ofxFloatSlider uiFarThreshold;
      
    
    ofxKinect kinect;
    
    ofxCvColorImage color;
    ofxCvGrayscaleImage grayscale;
    ofxCvGrayscaleImage background;
    ofxCvGrayscaleImage difference;
    ofxCvContourFinder contour;
    
    ofxBox2d box2d;
    vector <shared_ptr<ofxBox2dCircle>> circles;
    ofxBox2dEdge *contourEdge;
      
    
      
    ofxCvGrayscaleImage thresholdImg;
    ofImage alphaImage;
      
    ofParameter<float> nearThreshold;
    ofParameter<float> farThreshold;
          
};
