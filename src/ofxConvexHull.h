/*
 Convex hull implementation for OpenFrameworks
 from Rick Companje's code found on https://gist.github.com/companje/10677337,
 which is based on Greg Borenstein's Proccessing implementation:
 https://github.com/atduskgreg/Processing-Convex-Hull
*/

#pragma once

#include "ofPoint.h"
#include "ofLog.h"

using std::vector;

class ofxConvexHull
{
public:
    vector<ofPoint> getConvexHull(vector<ofPoint> points);
    float getArea(vector<ofPoint> & hull);
    
private:
    
    static bool lexicalComparison(const ofPoint& v1, const ofPoint& v2);
    bool isRightTurn(ofPoint a, ofPoint b, ofPoint c);
    
    vector<ofPoint> points;
    ofPoint h1,h2,h3;
    int currentPoint, direction;
};

