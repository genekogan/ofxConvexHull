# ofxPointInPolyline

This is a simple openFrameworks addon for determining if a given ofPoint lies inside a polygon (specified by an ofPolyline). polygons can be convex/concave, and have any number of vertices. See included example. Usage is simple:

	bool isInside(ofPolyline poly, ofPoint p);
	
Code is adapted from [this link](http://www.geeksforgeeks.org/how-to-check-if-a-given-point-lies-inside-a-polygon/).