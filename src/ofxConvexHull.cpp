#include "ofxConvexHull.h"


vector<ofPoint> ofxConvexHull::getConvexHull(vector<ofPoint> points) {
    vector<ofPoint> hull;
    
    if (points.size() < 3) {
        ofLog(OF_LOG_ERROR, "Error: you need at least three points to calculate the convex hull");
        return hull;
    }
    
    sort(points.begin(), points.end(), &ofxConvexHull::lexicalComparison);
    
    hull.push_back(points.at(0));
    hull.push_back(points.at(1));
    
    int currentPoint = 2;
    int direction = 1;
    
    for (int i=0; i<1000; i++) { //max 1000 tries
        
        hull.push_back(points.at(currentPoint));
        
        // look at the turn direction in the last three points
        h1 = hull.at(hull.size()-3);
        h2 = hull.at(hull.size()-2);
        h3 = hull.at(hull.size()-1);
        
        // while there are more than two points in the hull
        // and the last three points do not make a right turn
        while (!isRightTurn(h1, h2, h3) && hull.size() > 2) {
            
            // remove the middle of the last three points
            hull.erase(hull.end() - 2);
            
            if (hull.size() >= 3) {
                h1 = hull.at(hull.size()-3);
            }
            h2 = hull.at(hull.size()-2);
            h3 = hull.at(hull.size()-1);
        }
        
        // going through left-to-right calculates the top hull
        // when we get to the end, we reverse direction
        // and go back again right-to-left to calculate the bottom hull
        if (currentPoint == points.size() -1 || currentPoint == 0) {
            direction = direction * -1;
        }
        
        currentPoint+= direction;
        
        if (hull.front()==hull.back()) break;
    }
    
    return hull;
}


bool ofxConvexHull::lexicalComparison(const ofPoint& v1, const ofPoint& v2) {
    if (v1.x > v2.x) return true;
    else if (v1.x < v2.x) return false;
    else if (v1.y > v2.y) return true;
    else return false;
}

bool ofxConvexHull::isRightTurn(ofPoint a, ofPoint b, ofPoint c) {
    // use the cross product to determin if we have a right turn
    return ((b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x)) >= 0;
}
