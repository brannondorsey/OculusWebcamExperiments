#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(30);
    
    //we can now get back a list of devices.
	vector<ofVideoDevice> devices = webcam.listDevices();
	
    for(int i = 0; i < devices.size(); i++){
		cout << devices[i].id << ": " << devices[i].deviceName;
        if( devices[i].bAvailable ){
            cout << endl;
        }else{
            cout << " - unavailable " << endl;
        }
	}
    
    webcam.setVerbose(true);
    webcam.setDeviceID(0);
    webcam.setDesiredFrameRate(30);
    webcam.initGrabber(1138, 640);
    
    BasicIPVideoServerSettings settings;
    server = BasicIPVideoServer::makeShared();
    server->start();
    cout<<"Server started at: "<<server->getURL()<<endl;
    ofLaunchBrowser(server->getURL());
}

//--------------------------------------------------------------
void ofApp::update(){
    
    webcam.update();
    if (webcam.isFrameNew()) {
        server->send(webcam.getPixelsRef());
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    webcam.draw(0,0);
    ofDrawBitmapStringHighlight("Num clients connected: " + ofToString(server->getNumConnections()), 20,20);
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
