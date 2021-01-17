
#pragma once
#include "ofMain.h"
#include "ofxBox2dBaseShape.h"
#include "ofxBox2dPolygonUtils.h"

class ofxBox2dPolygon : public ofxBox2dBaseShape, public ofPolyline {

private:
	
	bool	bIsSimplified;
	bool    bIsTriangulated;
	float   area;
	glm::vec3 center;
	void    calculateCentroid();
	float   calculateArea();
    void    makeConvexPoly();

public:
	
	ofVboMesh				mesh;
	ofRectangle				bounds;
	vector <TriangleShape>	triangles;
	
	//----------------------------------------
	ofxBox2dPolygon();
	~ofxBox2dPolygon();
	void destroy();
	void clear();
    
	//----------------------------------------
	void addTriangle(const glm::vec3 &a, const glm::vec3 &b, const glm::vec3 &c);
	void addVertexes(vector <glm::vec3> &pts);
	void addVertexes(vector <glm::vec2> &pts);
	void addVertexes(ofPolyline &polyline);

	//----------------------------------------
	// Polygon helper functions
	//----------------------------------------
	void simplify(float tolerance=0.3);
    void simplifyToMaxVerts();
	void triangulatePoly(float resampleAmt=20, int nPointsInside=-1);
    
	//----------------------------------------
	vector <glm::vec3> &getPoints();
	bool	isGoodShape() { return calculateArea() > 15; }
    
	//------------------------------------------------
	void addAttractionPoint(glm::vec2 pt, float amt=1);
	void addAttractionPoint(glm::vec3 pt, float amt=1);
	void addAttractionPoint(float x, float y, float amt=1);
	void addRepulsionForce(float x, float y, float amt);
	void addRepulsionForce(glm::vec2 pt, float amt);

	//----------------------------------------
	void create(b2World * b2dworld);
	void draw();
	
};
