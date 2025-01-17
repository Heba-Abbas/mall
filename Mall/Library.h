#ifndef LIBRARY_H
#define LIBRARY_H

#include "Cube.h"
#include "Chair.h"
#include "Cachier.h"
#include <glut.h>
#include <gl/gl.h>      // Header File For The OpenGL32 Library
#include <gl/glu.h>     // Header File For The GLu32 Library

class Library {
public:
    // Textures
    GLuint libraryfloor, libraryroof, librarywalls, columnTexMake, shelfTex, shelfTexMake ,columnTex;
    GLuint book1, book2, book3, book4, book5, book6, book7, book8, book9, book10, book11, book12, book13, book14, book15, book16, book17, book18, book19, book20, book21, book22;
    GLuint frontTextureL1, frontTextureL2, frontTextureL3, frontTextureL4;
    GLuint backTexture, topTexture, bottomTexture, rightTexture, leftTexture;
    GLuint picture1, darkWood, chairTex, frontTex, backTex, topTex, bottomTex, rightTex, leftTex;

    // Constructor
    Library(
        GLuint libraryfloor, GLuint libraryroof, GLuint librarywalls, GLuint columnTexMake,GLuint columnTex, GLuint shelfTex, GLuint shelfTexMake,GLuint frontTextureL1,
        GLuint makeup1, GLuint makeup2, GLuint makeup3, GLuint frontTextureL2, GLuint frontTextureL3, GLuint frontTextureL4,
        GLuint backTexture, GLuint topTexture, GLuint bottomTexture, GLuint rightTexture, GLuint leftTexture,
		GLuint book1,GLuint book2,GLuint book3,GLuint book4,GLuint book5,GLuint book6,GLuint book7,GLuint book8,GLuint book9,GLuint book10,GLuint book11,GLuint book12,GLuint book13,GLuint book14,GLuint book15,GLuint book16,GLuint book17,GLuint book18,GLuint book19,GLuint book20,GLuint book21,GLuint book22
        ,GLuint picture1, GLuint darkWood, GLuint chairTex, GLuint frontTex, GLuint backTex, GLuint topTex, GLuint bottomTex, GLuint rightTex, GLuint leftTex
    );

    
    void drawBookStore();
};

#endif 