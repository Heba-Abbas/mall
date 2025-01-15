#ifndef POLYGONQ_H   
#define POLYGONQ_H

#ifdef __cplusplus
#include <cstdlib>
#else
#include <stdlib.h>
#endif

#include <glut.h>
#include <gl\gl.h>      // Header File For The OpenGL32 Library
#include <gl\glu.h>      // Header File For The GLu32 Library
#include <vector>

using namespace std;

class PolygonQ {
private:
    float radius;
    int sectors;
    float height;
    float width;
    vector<GLuint> sideTex;
	int topTex;
	int bottomTex;

public:
    // Constructor
    PolygonQ(float radius, int sectors, float height, float width, GLuint sideTex[], int topTex, int bottomTex);
	~PolygonQ();

    // Method to draw the polygon
    void draw();
};

#endif
