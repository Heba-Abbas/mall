#include "PolygonQ.h"

#include <glut.h>
#include <gl\gl.h>      // Header File For The OpenGL32 Library
#include <gl\glu.h>      // Header File For The GLu32 Library
#include <vector>

PolygonQ::PolygonQ(float radius, int sectors, float height, float width, GLuint sideTex[], int topTex, int bottomTex) :
    radius(radius), sectors(sectors), height(height), width(width), topTex(topTex), bottomTex(bottomTex){
    for (int i = 0; i < sectors; i++) {
        this->sideTex.push_back(sideTex[i]);
    }
}

PolygonQ::~PolygonQ(){}

// Method to draw the polygon
void PolygonQ::draw() {
    float M_PI = 3.14159f;

    // Draw the top face
    glBindTexture(GL_TEXTURE_2D, topTex);
    glBegin(GL_POLYGON);
    for (int i = 0; i < sectors; i++) {
        glNormal3f(0.0, 1.0, 0.0);
        glTexCoord2f(0.5 + 0.5 * cos(2.0 * M_PI * (float)i / (float)sectors), 0.5 + 0.5 * sin(2.0 * M_PI * (float)i / (float)sectors));
        glVertex3f(radius * cos(2.0 * M_PI * (float)i / (float)sectors), height, radius * sin(2.0 * M_PI * (float)i / (float)sectors));
    }
    glEnd();

    // Draw the bottom face
    glBindTexture(GL_TEXTURE_2D, bottomTex);
    glBegin(GL_POLYGON);
    for (int i = 0; i < sectors; i++) {
        glNormal3f(0.0, -1.0, 0.0);
        glTexCoord2f(0.5 + 0.5 * cos(2.0 * M_PI * (float)i / (float)sectors), 0.5 + 0.5 * sin(2.0 * M_PI * (float)i / (float)sectors));
        glVertex3f(radius * cos(2.0 * M_PI * (float)i / (float)sectors), 0, radius * sin(2.0 * M_PI * (float)i / (float)sectors));
    }
    glEnd();

    // Draw the side faces
    for (int i = 0; i < sectors; i++) {
        glBindTexture(GL_TEXTURE_2D, sideTex[i]);
        glBegin(GL_QUADS);
        glNormal3f(cos(2.0 * M_PI * (float)i / (float)sectors), 0.0, sin(2.0 * M_PI * (float)i / (float)sectors));
        glTexCoord2f(0, 0); 
        glVertex3f(radius * cos(2.0 * M_PI * (float)i / (float)sectors), 0, radius * sin(2.0 * M_PI * (float)i / (float)sectors));
        glTexCoord2f(1, 0); 
        glVertex3f(radius * cos(2.0 * M_PI * (float)(i+1) / (float)sectors), 0, radius * sin(2.0 * M_PI * (float)(i+1) / (float)sectors));
        glTexCoord2f(1, 1); 
        glVertex3f(radius * cos(2.0 * M_PI * (float)(i+1) / (float)sectors), height, radius * sin(2.0 * M_PI * (float)(i+1) / (float)sectors));
        glTexCoord2f(0, 1); 
        glVertex3f(radius * cos(2.0 * M_PI * (float)i / (float)sectors), height, radius * sin(2.0 * M_PI * (float)i / (float)sectors));
        glEnd();
    }
}
