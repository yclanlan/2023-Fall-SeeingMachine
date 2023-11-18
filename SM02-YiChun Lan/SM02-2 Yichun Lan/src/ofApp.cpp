#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

ofVideoGrabber cam;
ofImage image;
ofxCv::ObjectFinder finder;
ofxPanel gui;
ofParameter<int> moveAmount = 40;
ofParameter<int> pixelSize = 1;

void ofApp::setup() {
    ofSetVerticalSync(true);
    ofSetWindowShape(1280, 720);
    ofSetFrameRate(12);
    
    cam.setup(1280, 720);
    finder.setup("haarcascade_frontalface_default.xml");
    finder.setPreset(ObjectFinder::Fast);

    
    image.allocate(cam.getWidth(), cam.getHeight(), OF_IMAGE_COLOR);
    
    moveAmount.set("Pixel Move Amount",10,0,100);
    pixelSize.set("Pixel Size",1,0.2,10);
    gui.setup();
    gui.add(moveAmount);
    gui.add(pixelSize);
    
}

void ofApp::update() {
    cam.update();
    if (cam.isFrameNew()) {
        finder.update(cam);
    }
    
   
    image.setFromPixels(cam.getPixels());
 
    for (int i = 0; i < finder.size(); i++) {
        ofRectangle faceRect = finder.getObjectSmoothed(i);
        for (int x = faceRect.getX(); x < faceRect.getX() + faceRect.getWidth(); x++) {
            for (int y = faceRect.getY(); y < faceRect.getY() + faceRect.getHeight(); y++) {
                int xOffset = ofRandom(-moveAmount, moveAmount);
                int yOffset = ofRandom(-moveAmount,moveAmount);
                ofColor pixelColor = image.getColor(x, y);
                image.setColor(x + xOffset, y + yOffset, pixelColor);
                
                
                int scale = pixelSize;
                for (int dx = 0; dx < scale; dx++) {
                    for (int dy = 0; dy < scale; dy++) {
                        image.setColor(x + xOffset + dx, y + yOffset + dy, pixelColor);
                    }
                }
            }
        }
    }
    

    image.update();
}

void ofApp::draw() {
    image.draw(0, 0);
//    finder.draw();
    gui.draw();
//    ofDrawBitmapStringHighlight(ofToString(finder.size()), 10, 20);
}
