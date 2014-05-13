#pragma once

#include "ofMain.h"

#pragma once


#include "ofMain.h"
#include "IPVideoGrabber.h"

using ofx::Video::IPVideoGrabber;
using ofx::Video::SharedIPVideoGrabber;

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    bool streaming;
    bool deviceFound;
    int camWidth;
    int camHeight;
    float webcamY;
    float xOffset;
    float fontSize;
    std::string noWebcamMessage;
    ofTrueTypeFont font;
    ofRectangle noWebcamMessageBounds;
    ofImage mask;
    SharedIPVideoGrabber videoGrabber;
    
    
};
