#include "Shelves.h"
#include "Texture.h"
#include <gl.h>
#include <glu.h>
#include <glut.h>

Shelves::Shelves(float width, float height, float depth, float spacing, int numShelves,
                 unsigned int leftTex, unsigned int rightTex, unsigned int shelfTex, 
                 const std::vector<unsigned int>& cubeTextures)
    : shelfWidth(width), shelfHeight(height), shelfDepth(depth), spacing(spacing),
      numberOfShelves(numShelves), leftTex(leftTex), rightTex(rightTex), shelfTex(shelfTex), 
      cubeTextures(cubeTextures) {
    columnWidth = 0.1f;  
    columnHeight = shelfHeight * numberOfShelves + (numberOfShelves - 1) * spacing;
}


void Shelves::draw() {
    // Draw left column
    glPushMatrix();
    glTranslatef(-shelfWidth - columnWidth / 2, columnHeight / 2 - shelfHeight / 2, 0.0f);
    Cube columnLeft(columnWidth, columnHeight, shelfDepth, leftTex, leftTex, leftTex, leftTex, leftTex, leftTex, false);
    columnLeft.draw();
    glPopMatrix();

    // Draw right column
    glPushMatrix();
    glTranslatef(shelfWidth + columnWidth / 2, columnHeight / 2 - shelfHeight / 2, 0.0f);
    Cube columnRight(columnWidth, columnHeight, shelfDepth, rightTex, rightTex, rightTex, rightTex, rightTex, rightTex, false);
    columnRight.draw();
    glPopMatrix();

    // Draw shelves 
    for (int i = 0; i < numberOfShelves; ++i) {
        float yOffset = i * (shelfHeight + spacing);

        glPushMatrix();
        glTranslatef(0.0f, yOffset, 0.0f);
        Cube shelf(shelfWidth, shelfHeight, shelfDepth, shelfTex, shelfTex, shelfTex, shelfTex, shelfTex, shelfTex, false);
        shelf.draw();
        glPopMatrix();

        // Add cubes on the shelf
        float cubeWidth = 0.2f * shelfWidth;  // Cube width as 20% of the shelf width
        float cubeHeight = shelfHeight * 0.8f; // Cube height smaller than shelf height
        float cubeDepth = shelfDepth * 0.8f;   // Cube depth smaller than shelf depth
        int numCubes = static_cast<int>(shelfWidth / (cubeWidth * 1.2f)); // Number of cubes fitting on the shelf
        float startX = -shelfWidth + cubeWidth; // Starting position for cubes

        for (int j = 0; j < numCubes; ++j) {
            float xOffset = startX + j * (cubeWidth * 1.2f); // Offset for each cube

            // Select texture for this cube
            unsigned int cubeTex;
            if (!cubeTextures.empty()) {
                cubeTex = cubeTextures[j % cubeTextures.size()];  // Use cubeTextures list
            } else {
                cubeTex = shelfTex;  // Fallback texture if cubeTextures is empty
            }

            glPushMatrix();
            glTranslatef(xOffset, yOffset + shelfHeight / 2 + cubeHeight / 2, 0.0f);
            Cube cube(cubeWidth / 2, cubeHeight / 2, cubeDepth / 2, cubeTex, cubeTex, cubeTex, cubeTex, cubeTex, cubeTex, false);
            cube.draw();
            glPopMatrix();
        }
    }
}
