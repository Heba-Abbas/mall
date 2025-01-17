#ifndef SUPERMARKET_H
#define SUPERMARKET_H

#include "Cube.h"
#include "Chair.h"
#include "Cachier.h"
#include <glut.h>
#include <gl/gl.h>      // Header File For The OpenGL32 Library
#include <gl/glu.h>     // Header File For The GLu32 Library

class MakeUp {
public:
    // Textures
    GLuint makeupfloor, makeuproof, makeupwalls, columnTexMake, shelfTex, shelfTexMake ,columnTex;
    GLuint makeup1, makeup2, makeup3;
    GLuint frontTexture3, frontTexture4, frontTexture5, frontTexture6;
    GLuint backTexture, topTexture, bottomTexture, rightTexture, leftTexture;
    GLuint mirror1, darkWood, chairTex, frontTex, backTex, topTex, bottomTex, rightTex, leftTex;

    // Constructor
    MakeUp(
        GLuint makeupfloor, GLuint makeuproof, GLuint makeupwalls, GLuint columnTexMake,GLuint columnTex, GLuint shelfTex, GLuint shelfTexMake,
        GLuint makeup1, GLuint makeup2, GLuint makeup3, GLuint frontTexture3, GLuint frontTexture4, GLuint frontTexture5, GLuint frontTexture6,
        GLuint backTexture, GLuint topTexture, GLuint bottomTexture, GLuint rightTexture, GLuint leftTexture,
        GLuint mirror1, GLuint darkWood, GLuint chairTex, GLuint frontTex, GLuint backTex, GLuint topTex, GLuint bottomTex, GLuint rightTex, GLuint leftTex
    );

    // Function to draw the restaurant
    void drawMackupStore();
};

#endif // SUPERMARKET_H