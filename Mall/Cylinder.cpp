#include "Cylinder.h"
#include <glut.h>
#include <cmath>

Cylinder::Cylinder(float cylRadius, float cylHeight, int numSectors, int side, int top, int bottom) :
	sectors(numSectors), radius(cylRadius), height(cylHeight),
	sideTex(side), topTex(top), bottomTex(bottom)
{

}

Cylinder::~Cylinder(){}

void Cylinder::draw() {
    float twoPi = 2.0f * 3.14159f;

    // Draw the body of the cylinder
	glBindTexture(GL_TEXTURE_2D, sideTex);
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= sectors; ++i) {
        float x = radius * cosf(i * twoPi / sectors);
        float z = radius * sinf(i * twoPi / sectors);
		float yTop = height / 2.0;
		float yBottom = -height / 2.0;

		float s = (float) i / (float)sectors;

        glNormal3f(x, 0.0f, z);
		glTexCoord2f(s, 1.0f); glVertex3f(x, yTop, z);
		glTexCoord2f(s, 0.0f); glVertex3f(x, yBottom, z);
    }
    glEnd();

    // Draw the top and bottom of the cylinder
	glBindTexture(GL_TEXTURE_2D, topTex);
    glBegin(GL_POLYGON);
    for (int i = 0; i <= sectors; ++i) {
        float x = radius * cosf(i * twoPi / sectors);
        float z = radius * sinf(i * twoPi / sectors);
		float s = (float) i / (float) sectors;
		float t = 0.5f;

        glNormal3f(0.0, 1.0, 0.0);
        glTexCoord2f(s, t); glVertex3f(x, height / 2.0, z);
    }
    glEnd();

	glBindTexture(GL_TEXTURE_2D, bottomTex);
    glBegin(GL_POLYGON);
    for (int i = 0; i <= sectors; ++i) {
        float x = radius * cosf(i * twoPi / sectors);
        float z = radius * sinf(i * twoPi / sectors);
		float s = (float) i / (float) sectors;
		float t = 0.5f;

        glNormal3f(0.0, -1.0, 0.0);
        glTexCoord2f(s, t); glVertex3f(x, -height / 2.0, z);
    }
    glEnd();
}

void Cylinder::drawWithCone() {
    float twoPi = 2.0f * 3.14159f;

    // Draw the body of the cylinder
    glBindTexture(GL_TEXTURE_2D, sideTex);
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= sectors; ++i) {
        float x = radius * cosf(i * twoPi / sectors);
        float z = radius * sinf(i * twoPi / sectors);
        float yTop = height / 2.0;
        float yBottom = -height / 2.0;

        float s = (float)i / (float)sectors;

        glNormal3f(x, 0.0f, z);
        glTexCoord2f(s, 1.0f); glVertex3f(x, yTop, z);
        glTexCoord2f(s, 0.0f); glVertex3f(x, yBottom, z);
    }
    glEnd();

    // Draw the top of the cylinder
    glBindTexture(GL_TEXTURE_2D, topTex);
    glBegin(GL_POLYGON);
    for (int i = 0; i <= sectors; ++i) {
        float x = radius * cosf(i * twoPi / sectors);
        float z = radius * sinf(i * twoPi / sectors);
        float s = 0.5f * (1 + cosf(i * twoPi / sectors));
        float t = 0.5f * (1 + sinf(i * twoPi / sectors));

        glNormal3f(0.0, 1.0, 0.0);
        glTexCoord2f(s, t); glVertex3f(x, height / 2.0, z);
    }
    glEnd();

    // Draw the cone on top of the cylinder
    glBindTexture(GL_TEXTURE_2D, topTex);
    glBegin(GL_TRIANGLE_FAN);
    glNormal3f(0.0, 1.0, 0.0);
    glTexCoord2f(0.5f, 0.5f); glVertex3f(0.0f, height * 2.0, 0.0f);
    for (int i = 0; i <= sectors; ++i) {
        float x = radius * cosf(i * twoPi / sectors);
        float z = radius * sinf(i * twoPi / sectors);
        glTexCoord2f(0.5f * (1 + cosf(i * twoPi / sectors)), 0.5f * (1 + sinf(i * twoPi / sectors)));
        glVertex3f(x, height / 2.0, z);
    }
    glEnd();
}
