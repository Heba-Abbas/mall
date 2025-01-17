#include "MakeUp.h"

// Constructor
MakeUp::MakeUp(
    GLuint makeupfloor, GLuint makeuproof, GLuint makeupwalls, GLuint columnTex,GLuint columnTexMake, GLuint shelfTex, GLuint shelfTexMake,
    GLuint makeup1, GLuint makeup2, GLuint makeup3, GLuint frontTexture3, GLuint frontTexture4, GLuint frontTexture5, GLuint frontTexture6,
    GLuint backTexture, GLuint topTexture, GLuint bottomTexture, GLuint rightTexture, GLuint leftTexture,
    GLuint mirror1, GLuint darkWood, GLuint chairTex, GLuint frontTex, GLuint backTex, GLuint topTex, GLuint bottomTex, GLuint rightTex, GLuint leftTex
) {
    this->makeupfloor = makeupfloor;
    this->makeuproof = makeuproof;
    this->makeupwalls = makeupwalls;
    this->columnTexMake = columnTexMake;
    this->shelfTex = shelfTex;
    this->shelfTexMake = shelfTexMake;
	this ->columnTex =columnTex;
    this->makeup1 = makeup1;
    this->makeup2 = makeup2;
    this->makeup3 = makeup3;
    this->frontTexture3 = frontTexture3;
    this->frontTexture4 = frontTexture4;
    this->frontTexture5 = frontTexture5;
    this->frontTexture6 = frontTexture6;
    this->backTexture = backTexture;
    this->topTexture = topTexture;
    this->bottomTexture = bottomTexture;
    this->rightTexture = rightTexture;
    this->leftTexture = leftTexture;
    this->mirror1 = mirror1;
    this->darkWood = darkWood;
    this->chairTex = chairTex;
    this->frontTex = frontTex;
    this->backTex = backTex;
    this->topTex = topTex;
    this->bottomTex = bottomTex;
    this->rightTex = rightTex;
    this->leftTex = leftTex;
}

// Function to draw the restaurant
void MakeUp::drawMackupStore() {
    // Draw the floor
    glPushMatrix();
    glTranslatef(0.0, 50.0, 0);
    glBindTexture(GL_TEXTURE_2D, makeupfloor);
    glBegin(GL_QUADS);
    glScaled(3, 2, 3);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-850, -850, -850); // -x, -y, -z
    glTexCoord2f(1.0f, 0.0f); glVertex3f(850, -850, -850);  // x, -y, -z
    glTexCoord2f(1.0f, 1.0f); glVertex3f(850, -850, 850);   // x, -y, z
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-850, -850, 850);  // -x, -y, z
    glEnd();
    glPopMatrix();

    //  roof 
    glPushMatrix();
    glTranslatef(0.0, 800.0, 0);
    glBindTexture(GL_TEXTURE_2D, makeuproof);
    glBegin(GL_QUADS);
    glScaled(4, 2, 4);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-850, -850, -850); // -x, -y, -z
    glTexCoord2f(1.0f, 0.0f); glVertex3f(850, -850, -850);  // x, -y, -z
    glTexCoord2f(1.0f, 1.0f); glVertex3f(850, -850, 850);   // x, -y, z
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-850, -850, 850);  // -x, -y, z
    glEnd();
    glPopMatrix();

    //  right wall 
    glPushMatrix();
    glTranslatef(0.0, -400.0, 0);
    glBindTexture(GL_TEXTURE_2D, makeupwalls);
    glBegin(GL_QUADS);
    glScaled(4, 2, 4);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(850, 400, 850);   // x, y, z
    glTexCoord2f(1.0f, 1.0f); glVertex3f(850, 400, -850);  // x, y, -z
    glTexCoord2f(1.0f, 0.0f); glVertex3f(850, -400, -850); // x, -y, -z
    glTexCoord2f(0.0f, 0.0f); glVertex3f(850, -400, 850);  // x, -y, z
    glEnd();
    glPopMatrix();

    //  left wall 
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, makeupwalls);
    glBegin(GL_QUADS);
    glScaled(4, 2, 4);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-850, 400, -850);  // -x, y, -z
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-850, 400, 850);   // -x, y, z
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-850, -400, 850);  // -x, -y, z
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-850, -400, -850); // -x, -y, -z
    glEnd();
    glPopMatrix();

    // backwall 
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, makeupwalls);
    glBegin(GL_QUADS);
    glScaled(4, 2, 4);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-850, -400, -850); // -x, -y, -z
    glTexCoord2f(1.0f, 0.0f); glVertex3f(850, -400, -850);  // x, -y, -z
    glTexCoord2f(1.0f, 1.0f); glVertex3f(850, 400, -850);   // x, y, -z
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-850, 400, -850);  // -x, y, -z
    glEnd();
    glPopMatrix();

    // Draw shelves on the left wall
    float columnWidth = 30.0f;
    float columnHeight = 300.0f;
    float columnDepth = 30.0f;
    float shelfWidth = 300.0f;
    float shelfHeight = 20.0f;
    float shelfDepth = 50.0f;
    float spacing = 200.0f;
    int numShelves = 3;
    float columnSpacing = 460.0f;

    for (int i = 0; i < 2; ++i) {
        float columnZ = 600.0f - i * columnSpacing;

        // Draw columns
        glPushMatrix();
        glTranslatef(-800.0f + columnWidth / 2, columnHeight / 2 - 600.0f, columnZ - 700);
        glBindTexture(GL_TEXTURE_2D, columnTexMake);
        Cube column(columnWidth, columnHeight, columnDepth, columnTex, columnTex, columnTex, columnTex, columnTex, columnTex, false);
        column.draw();
        glPopMatrix();

        if (i < 1) {
            float startZ = columnZ - columnSpacing / 2 + columnDepth / 2;
            float endZ = startZ + columnSpacing - columnDepth;
            float shelfCenterZ = (startZ + endZ) / 2;

            for (int j = 0; j < numShelves; ++j) {
                float yOffset = j * (shelfHeight + spacing);

                // Draw shelves
                glPushMatrix();
                glTranslatef(-800.0f + shelfDepth / 2, -400.0f + shelfHeight / 2 + yOffset - 300, shelfCenterZ - 950);
                glBindTexture(GL_TEXTURE_2D, shelfTex);
                Cube shelf(shelfDepth, shelfHeight, shelfWidth, shelfTexMake, shelfTexMake, shelfTexMake, shelfTexMake, shelfTexMake, shelfTexMake, false);
                shelf.draw();
                glPopMatrix();

                // Draw cubes on the shelves
                float cubeWidth = shelfDepth * 0.8f;
                float cubeHeight = shelfHeight * 2.0f;
                float cubeDepth = shelfWidth / 6.0f;
                int numCubes = 4;
                int textureOffset = j * numCubes;
                unsigned int cubeTextures[] = {makeup1, makeup2, makeup3};
                size_t numTextures = sizeof(cubeTextures) / sizeof(cubeTextures[0]);
                for (int k = 0; k < numCubes; ++k) {
                    float cubeZ = shelfCenterZ - shelfWidth / 2 + k * cubeDepth * 1.1f;
                    glPushMatrix();
                    glTranslatef(-800.0f + shelfDepth / 2, -400.0f + shelfHeight + yOffset + cubeHeight / 2 - 275, cubeZ - 900);
                    unsigned int cubeTex = cubeTextures[(k + textureOffset) % numTextures];
                    Cube cube(cubeDepth, cubeHeight, cubeWidth, cubeTex, cubeTex, cubeTex, cubeTex, cubeTex, cubeTex, false);
                    cube.draw();
                    glPopMatrix();
                }
            }
        }
    }

    // Draw placards
    float width = 600.0f / 2.0f;
    float height = 800.0f / 2.0f;
    float depth = 110.0f / 2.0f;

    // Placard 1
    Cube rectangle2(width, height, depth, frontTexture3, backTexture, topTexture, bottomTexture, rightTexture, leftTexture, false);
    glPushMatrix();
    glTranslatef(-700.0f + columnWidth / 2, columnHeight / 2 - 600.0f, 300);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    rectangle2.draw();
    glPopMatrix();

    // Placard 2
    Cube rectangle3(width, height, depth, frontTexture4, backTexture, topTexture, bottomTexture, rightTexture, leftTexture, false);
    glPushMatrix();
    glTranslatef(500.0f + columnWidth / 2, columnHeight / 2 - 600.0f, -800);
    rectangle3.draw();
    glPopMatrix();

    // Placard 3
    Cube rectangle4(width, height, depth, frontTexture5, backTexture, topTexture, bottomTexture, rightTexture, leftTexture, false);
    glPushMatrix();
    glTranslatef(-500.0f + columnWidth / 2, columnHeight / 2 - 600.0f, -800);
    rectangle4.draw();
    glPopMatrix();

    // Placard 4
    Cube rectangle5(width, height - 250, depth, frontTexture6, backTexture, topTexture, bottomTexture, rightTexture, leftTexture, false);
    glPushMatrix();
    glTranslatef(750.0f + columnWidth / 2, columnHeight / 2 - 850.0f, -300);
    glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
    rectangle5.draw();
    glPopMatrix();

    // Mirror
    glPushMatrix();
    glTranslatef(-5.0, -250.0, -300);
    glScalef(1.0, 0.5, 0.7);
    glBindTexture(GL_TEXTURE_2D, mirror1);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(853, 450, 360);   // x, y, z
    glTexCoord2f(1.0f, 1.0f); glVertex3f(853, 450, -360);  // x, y, -z
    glTexCoord2f(1.0f, 0.0f); glVertex3f(853, -450, -360); // x, -y, -z
    glTexCoord2f(0.0f, 0.0f); glVertex3f(853, -450, 360);  // x, -y, z
    glEnd();
    glPopMatrix();

    // Draw table and chair
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