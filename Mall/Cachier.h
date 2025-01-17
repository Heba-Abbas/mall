#ifndef CACHIER_H
#define CACHIER_H

#include "Cube.h"
#include <glut.h>
#include <gl\gl.h>      // Header File For The OpenGL32 Library
#include <gl\glu.h>      // Header File For The GLu32 Library

class Cachier {
private:
    GLuint tableTex;
    float topLength, topWidth, topHeight, legThickness, legHeight;

public:
    Cachier(float topLength, float topWidth, float topHeight, float legThickness, float legHeight, GLuint tableTex) {
        this->topLength = topLength; 
        this->topWidth = topWidth; 
        this->topHeight = topHeight; 
        this->legThickness = legThickness; 
        this->legHeight = legHeight; 
        this->tableTex = tableTex; 
    }

    void draw() {
        glPushMatrix();
        // Move the whole table to the desired location
        glTranslatef(0.0f, 0.0f, -5.0f); 

        // Draw the legs (four legs)
        // Leg 1 Front Left
        glPushMatrix();
        glTranslatef(-topWidth/2 + legThickness/2, -legHeight-topHeight/2, -topLength/2 + legThickness/2); // Translate to leg position
        Cube leg(legThickness, legHeight, legThickness, tableTex, tableTex, tableTex, tableTex, tableTex, tableTex, false);
        leg.draw();
        glPopMatrix();

        // Leg 2 Front Right
        glPushMatrix();
        glTranslatef(topWidth/2 - legThickness/2, -legHeight-topHeight/2, -topLength/2 + legThickness/2); // Translate to leg position
        Cube leg2(legThickness, legHeight, legThickness, tableTex, tableTex, tableTex, tableTex, tableTex, tableTex, false);
        leg2.draw();
        glPopMatrix();

        // Leg 3 Back Right
        glPushMatrix();
        glTranslatef(topWidth/2 - legThickness/2, -legHeight-topHeight/2, topLength/2 - legThickness/2); // Translate to leg position
        Cube leg3(legThickness, legHeight, legThickness, tableTex, tableTex, tableTex, tableTex, tableTex, tableTex, false);
        leg3.draw();
        glPopMatrix();

        // Leg 4 Back Left
        glPushMatrix();
        glTranslatef(-topWidth/2 + legThickness/2, -legHeight-topHeight/2, topLength/2 - legThickness/2); // Translate to leg position
        Cube leg4(legThickness, legHeight, legThickness, tableTex, tableTex, tableTex, tableTex, tableTex, tableTex, false);
        leg4.draw();
        glPopMatrix();

        // Draw the top surface
        glTranslatef(0.0f, 1.0f, 0.0f);
        Cube topSurface(topWidth, topHeight, topLength, tableTex, tableTex, tableTex, tableTex, tableTex, tableTex, false);
        topSurface.draw();

        glPopMatrix();
    }
};

#endif