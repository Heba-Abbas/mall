#include "supermarket.h"

// Constructor with parameters
Supermarket::Supermarket(
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
) {
    this->restaurantFloor = restaurantFloor;
    this->roofTex = roofTex;
    this->wallTex = wallTex;
    this->frontTopWallTex = frontTopWallTex;
    this->frontWallTex = frontWallTex;
    this->columnTex = columnTex;
    this->shelfTex = shelfTex;
    this->chairTex = chairTex;
    this->texture1 = texture1;
    this->texture2 = texture2;
    this->texture3 = texture3;
    this->texture4 = texture4;
    this->texture5 = texture5;
    this->texture6 = texture6;
    this->texture7 = texture7;
    this->texture8 = texture8;
    this->texture9 = texture9;
    this->texture10 = texture10;
    this->texture11 = texture11;
    this->texture12 = texture12;
    this->texture13 = texture13;
    this->texture14 = texture14;
    this->texture15 = texture15;
    this->texture16 = texture16;
    this->texture17 = texture17;
    this->texture18 = texture18;
    this->texture19 = texture19;
    this->texture20 = texture20;
    this->texture21 = texture21;
    this->texture22 = texture22;
    this->texture23 = texture23;
    this->texture24 = texture24;
    this->frontTexture = frontTexture;
    this->backTexture = backTexture;
    this->topTexture = topTexture;
    this->bottomTexture = bottomTexture;
    this->rightTexture = rightTexture;
    this->leftTexture = leftTexture;
    this->frontTexture2 = frontTexture2;
    this->frontTextureIce = frontTextureIce;
    this->backTextureIce = backTextureIce;
    this->topTextureIce = topTextureIce;
    this->bottomTextureIce = bottomTextureIce;
    this->rightTextureIce = rightTextureIce;
    this->leftTextureIce = leftTextureIce;
    this->darkWood = darkWood;
    this->frontTex = frontTex;
    this->backTex = backTex;
    this->topTex = topTex;
    this->bottomTex = bottomTex;
    this->rightTex = rightTex;
    this->leftTex = leftTex;
}

// Default constructor
Supermarket::Supermarket() {
    // Initialize default values if needed
}

// Function to draw the restaurant
void Supermarket::drawSupermarket() {
    //  floor
    glPushMatrix();
    glTranslatef(0.0, 50.0, 0);
    glBindTexture(GL_TEXTURE_2D, restaurantFloor);
    glBegin(GL_QUADS);
    glScaled(3, 2, 3);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-850, -850, -850); // -x, -y, -z
    glTexCoord2f(1.0f, 0.0f); glVertex3f(850, -850, -850);  // x, -y, -z
    glTexCoord2f(1.0f, 1.0f); glVertex3f(850, -850, 850);   // x, -y, z
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-850, -850, 850);  // -x, -y, z
    glEnd();
    glPopMatrix();

    // right
    glPushMatrix();
    glTranslatef(0.0, -400.0, 0);
    glBindTexture(GL_TEXTURE_2D, wallTex);
    glBegin(GL_QUADS);
    glScaled(4, 2, 4);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(850, 400, 850);   // x, y, z
    glTexCoord2f(1.0f, 1.0f); glVertex3f(850, 400, -850);  // x, y, -z
    glTexCoord2f(1.0f, 0.0f); glVertex3f(850, -400, -850); // x, -y, -z
    glTexCoord2f(0.0f, 0.0f); glVertex3f(850, -400, 850);  // x, -y, z
    glEnd();
    glPopMatrix();

    // left
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, wallTex);
    glBegin(GL_QUADS);
    glScaled(4, 2, 4);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-850, 400, -850);  // -x, y, -z
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-850, 400, 850);   // -x, y, z
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-850, -400, 850);  // -x, -y, z
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-850, -400, -850); // -x, -y, -z
    glEnd();
    glPopMatrix();

    // back face
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, wallTex);
    glBegin(GL_QUADS);
    glScaled(4, 2, 4);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-850, -400, -850); // -x, -y, -z
    glTexCoord2f(1.0f, 0.0f); glVertex3f(850, -400, -850);  // x, -y, -z
    glTexCoord2f(1.0f, 1.0f); glVertex3f(850, 400, -850);   // x, y, -z
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-850, 400, -850);  // -x, y, -z
    glEnd();
    glPopMatrix();

    // shelves
    float columnWidth = 30.0f;
    float columnHeight = 400.0f;
    float columnDepth = 30.0f;
    float shelfWidth = 300.0f;
    float shelfHeight = 20.0f;
    float shelfDepth = 50.0f;
    float spacing = 100.0f;
    int numShelves = 6;
    float columnSpacing = 460.0f;

    for (int i = 0; i < 4; ++i) {
        float columnX = -600.0f + i * columnSpacing;

        // draw column
        glPushMatrix();
        glTranslatef(columnX, columnHeight / 2 - 600.0f, -800.0f);
        glBindTexture(GL_TEXTURE_2D, columnTex);
        Cube column(columnWidth, columnHeight, columnDepth, columnTex, columnTex, columnTex, columnTex, columnTex, columnTex, false);
        column.draw();
        glPopMatrix();

        if (i < 3) {
            float startX = columnX + columnWidth / 2;
            float endX = startX + columnSpacing - columnWidth;
            float shelfCenterX = (startX + endX) / 2;

            for (int j = 0; j < numShelves; ++j) {
                float yOffset = j * (shelfHeight + spacing);

                // draw shelf
                glPushMatrix();
                glTranslatef(shelfCenterX, -400.0f + shelfHeight / 2 + yOffset - 280, -800.0f + shelfDepth / 2);
                glBindTexture(GL_TEXTURE_2D, shelfTex);
                Cube shelf(shelfWidth, shelfHeight, shelfDepth, shelfTex, shelfTex, shelfTex, shelfTex, shelfTex, shelfTex, false);
                shelf.draw();
                glPopMatrix();

                // draw cubes on the shelf
                float cubeWidth = shelfWidth / 6.0f;
                float cubeHeight = shelfHeight * 2.0f;
                float cubeDepth = shelfDepth * 0.8f;
                int numCubes = 6;
                int textureOffset = j * numCubes;
                unsigned int cubeTextures[] = {texture1, texture2, texture3, texture4, texture5, texture6, texture7, texture8, texture9, texture10, texture11, texture12, texture13, texture14, texture15, texture16, texture17, texture18, texture19, texture20, texture21, texture22, texture23, texture24};
                size_t numTextures = sizeof(cubeTextures) / sizeof(cubeTextures[0]);
                for (int k = 0; k < numCubes; ++k) {
                    float cubeX = shelfCenterX - shelfWidth / 2 + k * cubeWidth * 1.1f;
                    glPushMatrix();
                    glTranslatef(cubeX, -400.0f + shelfHeight + yOffset + cubeHeight / 2 - 280, -800.0f + shelfDepth / 2);
                    unsigned int cubeTex = cubeTextures[(k + textureOffset) % numTextures];
                    Cube cube(cubeWidth, cubeHeight, cubeDepth, cubeTex, cubeTex, cubeTex, cubeTex, cubeTex, cubeTex, false);
                    cube.draw();
                    glPopMatrix();
                }
            }
        }
    }

    // fridge1
    float width = 400.0f / 2.0f;
    float height = 800.0f / 2.0f;
    float depth = 220.0f / 2.0f;
    Cube rectangle(width, height, depth, frontTexture, backTexture, topTexture, bottomTexture, rightTexture, leftTexture, false);
    glPushMatrix();
    glTranslatef(-700.0f + columnWidth / 2, columnHeight / 2 - 600.0f, 650);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    rectangle.draw();
    glPopMatrix();

    // fridge2
    Cube rectangle2(width, height, depth, frontTexture2, backTexture, topTexture, bottomTexture, rightTexture, leftTexture, false);
    glPushMatrix();
    glTranslatef(-700.0f + columnWidth / 2, columnHeight / 2 - 600.0f, 200);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    rectangle2.draw();
    glPopMatrix();

    // ice cream fridge
    Cube rectangleIce(width - 90, height - 300, depth, frontTextureIce, backTextureIce, topTextureIce, bottomTextureIce, rightTextureIce, leftTextureIce, false);
    glPushMatrix();
    glTranslatef(columnWidth / 2, columnHeight / 2 - 900.0f, 100);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    rectangleIce.draw();
    glPopMatrix();

    // table and chair /cachier
    glPushMatrix();
    glTranslatef(450.0, -600.0, 700);
    glScaled(1, 2, 1.5);
    glRotated(-90, 0, 1, 0);
    Cachier table1(100, 100, 7.0, 10, 50, darkWood);
    table1.draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(700.0f, -730.0f, 700.0f);
    glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
    Chair chair1(45.0f, 45.0f, 7.0f, 5.0f, 35.0f, 60.0f, 5.0f, chairTex, darkWood);
    glScaled(1.2, 2, 1.2);
    chair1.draw();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(450.0, -550.0, 700);
    glScalef(0.7, 0.5, 0.7);
    Cube cube(50.0f, 50.0f, 50.0f, frontTex, backTex, topTex, bottomTex, rightTex, leftTex, false);
    cube.draw();
    glPopMatrix();
    
}