#ifndef SUPERMARKET_H
#define SUPERMARKET_H

#include "Cube.h"
#include "Chair.h"
#include "Cachier.h"
#include "Table.h"
#include <glut.h>
#include <gl/gl.h>      // Header File For The OpenGL32 Library
#include <gl/glu.h>     // Header File For The GLu32 Library

class Supermarket {
public:
    GLuint restaurantFloor, roofTex, wallTex, frontTopWallTex, frontWallTex, columnTex, shelfTex, chairTex;
    GLuint texture1, texture2, texture3, texture4, texture5, texture6, texture7, texture8, texture9, texture10;
    GLuint texture11, texture12, texture13, texture14, texture15, texture16, texture17, texture18, texture19, texture20;
    GLuint texture21, texture22, texture23, texture24;
    GLuint frontTexture, backTexture, topTexture, bottomTexture, rightTexture, leftTexture;
    GLuint frontTexture2, frontTextureIce, backTextureIce, topTextureIce, bottomTextureIce, rightTextureIce, leftTextureIce;
    GLuint darkWood, frontTex, backTex, topTex, bottomTex, rightTex, leftTex;

    
    Supermarket(
        GLuint restaurantFloor, GLuint roofTex, GLuint wallTex, GLuint frontTopWallTex, GLuint frontWallTex,
        GLuint columnTex, GLuint shelfTex, GLuint chairTex, GLuint texture1, GLuint texture2, GLuint texture3,
        GLuint texture4, GLuint texture5, GLuint texture6, GLuint texture7, GLuint texture8, GLuint texture9,
        GLuint texture10, GLuint texture11, GLuint texture12, GLuint texture13, GLuint texture14, GLuint texture15,
        GLuint texture16, GLuint texture17, GLuint texture18, GLuint texture19, GLuint texture20, GLuint texture21,
        GLuint texture22, GLuint texture23, GLuint texture24, GLuint frontTexture, GLuint backTexture,
        GLuint topTexture, GLuint bottomTexture, GLuint rightTexture, GLuint leftTexture, GLuint frontTexture2,
        GLuint frontTextureIce, GLuint backTextureIce, GLuint topTextureIce, GLuint bottomTextureIce,
        GLuint rightTextureIce, GLuint leftTextureIce, GLuint darkWood, GLuint frontTex, GLuint backTex,
        GLuint topTex, GLuint bottomTex, GLuint rightTex, GLuint leftTex
    );

    
    Supermarket();
    
    void drawSupermarket();
};

#endif // SUPERMARKET_H