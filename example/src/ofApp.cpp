#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofNoFill();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // draw points
    ofSetColor(0);
    for (int i=0; i<points.size(); i++) {
        ofCircle(points.at(i),2);
    }
    
    // draw hull
    ofBeginShape();
    for (int i=0; i<hull.size(); i++) {
        ofVertex(hull[i]);
    }
    ofEndShape();
    
    // get area of convex hull
    float area = convexHull.getArea(hull);
    ofDrawBitmapString("area = "+ofToString(area), 5, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key=='c') {
        points.clear();
        hull.clear();
    }
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
    points.push_back(ofPoint(x,y));
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    hull = convexHull.getConvexHull(points);
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
