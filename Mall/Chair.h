#ifndef CHAIR_H
#define CHAIR_H

#include "Cube.h"
#include <glut.h>
#include <gl\gl.h>      // Header File For The OpenGL32 Library
#include <gl\glu.h>     // Header File For The GLu32 Library

class Chair {
private:
    GLuint seatTex; // Texture for the seat and backrest
    GLuint legTex;  // Texture for the legs (optional, can reuse seatTex if desired)

    float seatWidth, seatDepth, seatHeight;
    float legThickness, legHeight;
    float backrestHeight, backrestThickness;

public:
    Chair(
        float seatWidth,
        float seatDepth,
        float seatHeight,
        float legThickness,
        float legHeight,
        float backrestHeight,
        float backrestThickness,
        GLuint seatTex,
        GLuint legTex
    ) {
        this->seatWidth = seatWidth;
        this->seatDepth = seatDepth;
        this->seatHeight = seatHeight;
        this->legThickness = legThickness;
        this->legHeight = legHeight;
        this->backrestHeight = backrestHeight;
        this->backrestThickness = backrestThickness;
        this->seatTex = seatTex;
        this->legTex = legTex;
    }

    void draw() {
        glPushMatrix();
        
        // Move the entire chair to the desired position
        glTranslatef(0.0f, legHeight, 0.0f);

        // Draw the seat
        Cube seat(seatWidth, seatHeight, seatDepth, seatTex, seatTex, seatTex, seatTex, seatTex, seatTex, false);
        seat.draw();

        // Draw the backrest
        glPushMatrix();
        glTranslatef(0.0f, seatHeight + backrestHeight, -seatDepth - backrestThickness / 2);
		glRotatef(-5.0f, 1.0f, 0.0f, 0.0f);
        Cube backrest(seatWidth, backrestHeight, backrestThickness, seatTex, seatTex, seatTex, seatTex, seatTex, seatTex, false);
        backrest.draw();
        glPopMatrix();

        // Draw the legs (four legs)

        // Leg 1: Front Left
        glPushMatrix();
        glTranslatef(-seatWidth / 2 + legThickness / 2, -legHeight - seatHeight / 2, -seatDepth / 2 + legThickness / 2);
        Cube leg1(legThickness, legHeight, legThickness, legTex, legTex, legTex, legTex, legTex, legTex, false);
        leg1.draw();
        glPopMatrix();

        // Leg 2: Front Right
        glPushMatrix();
        glTranslatef(seatWidth / 2 - legThickness / 2, -legHeight - seatHeight / 2, -seatDepth / 2 + legThickness / 2);
        Cube leg2(legThickness, legHeight, legThickness, legTex, legTex, legTex, legTex, legTex, legTex, false);
        leg2.draw();
        glPopMatrix();

        // Leg 3: Back Right
        glPushMatrix();
        glTranslatef(seatWidth / 2 - legThickness / 2, -legHeight - seatHeight / 2, seatDepth / 2 - legThickness / 2);
        Cube leg3(legThickness, legHeight, legThickness, legTex, legTex, legTex, legTex, legTex, legTex, false);
        leg3.draw();
        glPopMatrix();

        // Leg 4: Back Left
        glPushMatrix();
        glTranslatef(-seatWidth / 2 + legThickness / 2, -legHeight - seatHeight / 2, seatDepth / 2 - legThickness / 2);
        Cube leg4(legThickness, legHeight, legThickness, legTex, legTex, legTex, legTex, legTex, legTex, false);
        leg4.draw();
        glPopMatrix();

        glPopMatrix();
    }
};

#endif
