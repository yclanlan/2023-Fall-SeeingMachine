#include "ofApp.h"

// Variable length array declaration not allowed at file scope
// So add "const" to declare the variable is fixed

const int gridSize = 480;
const int cellSize = 1;

bool grid[gridSize][gridSize];
bool nextGrid[gridSize][gridSize];


int countNeighbors(int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            
            int ni = x + i;
            int nj = y + j;
            
            // x, y , and expect the cell itself
            if (ni >= 0 && ni < gridSize &&
                nj >= 0 && nj < gridSize &&
                !(i == 0 && j == 0)) {
                // if grid == true aka (1), count++
                if (grid[ni][nj]) {
                    count++;
                }
            }
        }
    }
    return count;
}


ofImage image;

//--------------------------------------------------------------
void ofApp::setup(){
//    Img.load("Water Spinach.jpg");
//    ofSetWindowShape(Img.getWidth(), Img.getHeight());
    

//  ====== Random version ========
    ofSetFrameRate(10);
    ofBackground(0);
     //Initialize the grid with random values
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            grid[i][j] = ofRandom(1) > 0.5;
        }
    }
    
    
//   ===== image version =====
    ofSetFrameRate(10);
    image.load("Water Spinach.jpg");
//    image.load("cat-fully-charged.jpg");
    image.resize(gridSize, gridSize);
    cout << "Image width: " << image.getWidth() << " height: " << image.getHeight() << endl;


    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            ofColor pixelColor = image.getColor(i, j);
            int totalRGB = pixelColor.r + pixelColor.g + pixelColor.b;
//            cout << totalRGB << endl;

            if (totalRGB > 255*3/4) {
                grid[i][j] = true;
            } else {
                grid[i][j] = false;

            }
        }
    }


    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    

    // Calculate the next generation based on the rules
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {

            int neighbors = countNeighbors(i, j);

            if (grid[i][j]) {
                     nextGrid[i][j] = (neighbors == 2 || neighbors == 3);
                        // the same meaning ⬇️
//                       if (neighbors == 2 || neighbors == 3) {
//                           nextGrid[i][j] = true;
//                       } else {
//                           nextGrid[i][j] = false;
//                       }
                   } else {
                       nextGrid[i][j] = neighbors == 3;
                        // the same meaning ⬇️
//                       if (neighbors == 3) {
//                           nextGrid[i][j] = true;
//                       } else {
//                           nextGrid[i][j] = false;
//                       }
                   }
        }
    }


    // Copy the next generation to the current grid
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            //update the changes to show them!
            grid[i][j] = nextGrid[i][j];
        }
    }

    
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
// for testing whether the image can display correctly.
// image.draw(0, 0);


    for (int i = 0; i < gridSize; i++) {
       for (int j = 0; j < gridSize; j++) {

           if (grid[i][j]) {
               ofSetColor(255);
           } else {
               ofSetColor(0);
           }
           ofDrawRectangle(i*cellSize , j*cellSize , cellSize, cellSize);
//         ofDrawRectangle(i , j , cellSize, cellSize);
       }
    }

    
    
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

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



