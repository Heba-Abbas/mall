#include "Sphere.h"  
#include <glut.h>
#include <cmath>

Sphere::Sphere(float radius, int sectors, bool isSemiSphere, int tex)
    : m_radius(radius), m_sectors(sectors), m_isSemiSphere(isSemiSphere), texture(tex){}

void Sphere::draw() {
    const float PI = 3.14159265359;
    const float sectorStep = 2 * PI / m_sectors;
    const float stackStep = PI / m_sectors;

	glBindTexture(GL_TEXTURE_2D, texture);
	
    glBegin(GL_QUADS);
    for (int i = 0; i < m_sectors; ++i) {
        for (int j = 0; j < m_sectors; ++j) {

            float x1 = m_radius * sin(i * stackStep) * cos(j * sectorStep);
            float y1 = m_radius * cos(i * stackStep);
            float z1 = m_radius * sin(i * stackStep) * sin(j * sectorStep);

            float x2 = m_radius * sin((i + 1) * stackStep) * cos(j * sectorStep);
            float y2 = m_radius * cos((i + 1) * stackStep);
            float z2 = m_radius * sin((i + 1) * stackStep) * sin(j * sectorStep);

            float x3 = m_radius * sin((i + 1) * stackStep) * cos((j + 1) * sectorStep);
            float y3 = m_radius * cos((i + 1) * stackStep);
            float z3 = m_radius * sin((i + 1) * stackStep) * sin((j + 1) * sectorStep);

            float x4 = m_radius * sin(i * stackStep) * cos((j + 1) * sectorStep);
            float y4 = m_radius * cos(i * stackStep);
            float z4 = m_radius * sin(i * stackStep) * sin((j + 1) * sectorStep);

            if (m_isSemiSphere && i > m_sectors / 2) {
                continue;
            }

			//glColor4f(0.1f, 0.0f, 0.4f, 0.0f);
            glTexCoord2f(0.5f, 0.5f); glVertex3f(x1, y1, z1);
            glTexCoord2f(0.5f, 0.0f); glVertex3f(x2, y2, z2);
			//glColor4f(0.0f, 0.4f, 0.3f, 0.0f);
            glTexCoord2f(0.0f, 0.0f); glVertex3f(x3, y3, z3);
            glTexCoord2f(0.0f, 0.5f); glVertex3f(x4, y4, z4);
        }
    }
    glEnd();
}
