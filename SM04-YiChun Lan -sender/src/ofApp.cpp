#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetWindowShape(640, 480);
    // Setup the parameters.
    nearThreshold.set("Near Threshold", 0.001f, 0.0f, 0.1f);
    farThreshold.set("Far Threshold", 0.03f, 0.0f, 0.1f);
    
    // Setup the gui.
    gui.setup("Depth Threshold", "settings.json");
    gui.add(nearThreshold);
    gui.add(farThreshold);
    
    gui.add(uiClearCircles.setup("clear circles"));
    
    

    kinect.setRegistration(true);
    kinect.init();
//    kinect.open();
    
//    color.allocate(kinect.getWidth(), kinect.getHeight());
//    ndiTexture.allocate(kinect.getWidth(), kinect.getHeight(), GL_RGBA);
    
//    box2d.init();
//    box2d.setGravity(0, 30);
//    box2d.createGround();
//    box2d.createBounds(ofRectangle(0, 0, kinect.getWidth()-50, kinect.getHeight()
//            ));
    
    
    // Set up NDI senders.
    // ndiSender.CreateSender("NDI Sender", kinect.getWidth(), kinect.getHeight());
    
    //Osc sender
    sendAddr = "localhost";
    sendPort = 3030;
    sender.setup(sendAddr, sendPort);
    
}



//--------------------------------------------------------------
void ofApp::update(){
//  box2d.update();
//  kinect.update();
  
//  if (kinect.isFrameNew()){
//
//    color.setFromPixels(kinect.getPixels());
//
//
//    //======
//    ofFloatPixels rawDepthPix = kinect.getRawDepthPixels();
//    ofFloatPixels thresholdNear, thresholdFar, thresholdResult;
//
//    ofxCv::threshold(rawDepthPix, thresholdNear, nearThreshold);
//    ofxCv::threshold(rawDepthPix, thresholdFar, farThreshold, true);
//    ofxCv::bitwise_and(thresholdNear, thresholdFar, thresholdResult);
//
//    thresholdImg.setFromPixels(thresholdResult);
//
//    int minimum = thresholdImg.getWidth() * thresholdImg.getHeight() * 0.01;
//    int maximum = thresholdImg.getWidth() * thresholdImg.getHeight() * 1;
//
//    contour.findContours(thresholdImg, minimum, maximum, 1, false);
//
//  }
//
//  if (uiClearCircles){
//    circles.clear();
//  }
  
  //nditexture back
//    ndiReceiver.ReceiveImage(ndiTexture);

}

//--------------------------------------------------------------
void ofApp::draw(){
    
  
  ofBackground(128,128,128);

//  ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
//
//  ndiTexture.draw(0, 0);
//
      color.draw(0,0);
      contour.draw();
      thresholdImg.draw(0,0);
//
//
//      if (!contour.blobs.empty()){
//        createContourEdge(ofPolyline(contour.blobs.at(0).pts));
//        contourEdge->draw();
//      }
//
    
  ofDisableBlendMode();
    
    
  // circles are not affected by blending mode
//  for (auto circle:circles){
//      circle->draw();
//  }
    
  gui.draw();
  


}




//--------------------------------------------------------------
void ofApp::exit(){
  kinect.setCameraTiltAngle(0);
  kinect.close();
}

//--------------------------------------------------------------
void ofApp::createContourEdge(ofPolyline polyline){
  delete contourEdge;
  contourEdge = new ofxBox2dEdge();
  contourEdge->addVertexes(polyline);
  contourEdge->create(box2d.getWorld());
}

//--------------------------------------------------------------
void ofApp::keyPressed (int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    //std::shared_ptr
    auto circle = make_shared<ofxBox2dCircle>();
    circle->setPhysics(3.0, 0.5, 0.1);
    circle->setup(box2d.getWorld(), x, y, 12);


    circles.push_back(circle);
    
    ofxOscMessage msg;
    msg.setAddress("/cursor/click");
    msg.addIntArg(ofGetMouseX());
    msg.addIntArg(ofGetMouseY());
    
    sender.sendMessage(msg);
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}

