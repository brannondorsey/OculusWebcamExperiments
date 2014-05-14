#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    ofHideCursor();
    
    fontSize = 32;
    noWebcamMessage = "Error connecting to server.";
    font.loadFont("Lato-Lig.ttf", fontSize);
    noWebcamMessageBounds = font.getStringBoundingBox(noWebcamMessage, 0, 0);
    
    mask.loadImage("oculus_mask.png");
    
    string address(ofBufferFromFile("server_address.txt"));
    ofStringReplace(address, "\n", "");
    ofStringReplace(address, "\r\n", "");
    ofStringReplace(address, " ", "");
    
    camWidth = 1138;
    camHeight = 640;

    videoGrabber = IPVideoGrabber::makeShared();
    videoGrabber->setURI("http://" + address + ":8080/ipvideo");
    videoGrabber->connect(); // connect immediately
    deviceFound = true;
    
    webcamY = ofGetHeight()/2 - camHeight/2 + 10;
    xOffset = ofGetWidth()/2 - 800/2;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (deviceFound) {
        videoGrabber->update();
        if (videoGrabber->isConnected() &&
            videoGrabber->isFrameNew()) {
            ofPixels& pixelsRef = videoGrabber->getPixelsRef();
            pixelsRef.resize(camWidth, camHeight);
            texture.loadData(pixelsRef);
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    if (deviceFound) {
        if (videoGrabber->isConnected() &&
            texture.isAllocated()) {
            
            texture.drawSubsection(40,
                                         webcamY,
                                         ofGetWidth()/2,
                                         camHeight,
                                         xOffset,
                                         0,
                                         texture.getWidth()/2,
                                         camHeight);
            
            texture.drawSubsection(ofGetWidth()/2,
                                         webcamY,
                                         ofGetWidth()/2,
                                         camHeight,
                                         xOffset + 80,
                                         0,
                                         texture.getWidth()/2,
                                         camHeight);
        }
        mask.draw(0, 0, ofGetWidth(), ofGetHeight());
        
    } else {
        ofSetColor(0);
        ofRect(0, 0, ofGetWidth(), ofGetHeight());
        ofSetColor(255);
        font.drawString(noWebcamMessage, ofGetWidth()/2 - noWebcamMessageBounds.width/2, ofGetHeight()/2 + fontSize/2);
    }
    
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
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
