#ifndef TABLE_H
#define TABLE_H

#include "Cube.h"
#include <glut.h>
#include <gl\gl.h>      // Header File For The OpenGL32 Library
#include <gl\glu.h>      // Header File For The GLu32 Library

class Table {
private:
	GLuint tableTex;
	float topLength, topWidth, topHeight, legThickness, legHeight;

public:
	Table(float topLength, float topWidth, float topHeight, float legThickness, float legHeight, GLuint tableTex){

		this->topLength = topLength; 
		this->topWidth = topWidth; 
		this->topHeight = topHeight; 
		this->legThickness = legThickness; 
		this->legHeight = legHeight; 
		this->tableTex = tableTex; 
	}
	void drawGlass() {

		glPushAttrib(GL_ENABLE_BIT | GL_CURRENT_BIT); // Save blending and color state

		// Set color for the glass (transparent)
		glColor4f(1.0f, 1.0f, 1.0f, 0.5f); // RGBA: Red, Green, Blue, Alpha (transparency)

		// Enable blending for transparency
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		// Draw the main cylinder of the glass
		glBegin(GL_QUAD_STRIP);
			for (int i = 0; i <= 36; i++) {
				float angle = (float)i / 36.0f * 2.0f * 3.14159f;
				float x = 50.0f * cos(angle);
				float z = 50.0f * sin(angle);

				// Bottom circle
				glVertex3f(x, -100.0f, z);
				// Top circle
				glVertex3f(x, 0.0f, z);
			}
		glEnd();

		// Draw the glass base (circle)
		glBegin(GL_TRIANGLE_FAN);
		glVertex3f(0.0f, -100.0f, 0.0f); // Center point
			for (int i = 0; i <= 36; i++) {
				float angle = (float)i / 36.0f * 2.0f * 3.14159f;
				float x = 50.0f * cos(angle);
				float z = 50.0f * sin(angle);
				glVertex3f(x, -100.0f, z);
			}
		glEnd();

		// Draw the rim of the glass (circle)
			glBegin(GL_TRIANGLE_FAN);
		glVertex3f(0.0f, 0.0f, 0.0f); // Center point
			for (int i = 0; i <= 36; i++) {
				float angle = (float)i / 36.0f * 2.0f * 3.14159f;
				float x = 50.0f * cos(angle);
				float z = 50.0f * sin(angle);
				glVertex3f(x, 0.0f, z);
			}
		glEnd();
		glDisable(GL_BLEND); // Disable blending again
	}
	void draw(){
	
    glPushMatrix();
      // Move the whole table to the desired location
      glTranslatef(0.0f, 0.0f, -5.0f); 


     // Draw the legs (four legs)
     //Leg 1 Front Left
     glPushMatrix();
      glTranslatef(-topWidth/2 + legThickness/2, -legHeight-topHeight/2, -topLength/2 + legThickness/2); // Translate to leg position
     
      Cube leg(legThickness, legHeight, legThickness, tableTex, tableTex, tableTex, tableTex, tableTex, tableTex, false);
      leg.draw();
      glPopMatrix();


    //Leg 2 Front Right
     glPushMatrix();
      glTranslatef(topWidth/2 - legThickness/2, -legHeight-topHeight/2, -topLength/2 + legThickness/2); // Translate to leg position
    
      Cube leg2(legThickness, legHeight, legThickness, tableTex, tableTex, tableTex, tableTex, tableTex, tableTex, false);
      leg2.draw();
       glPopMatrix();
    
    
    //Leg 3 Back Right
    glPushMatrix();
      glTranslatef(topWidth/2 - legThickness/2, -legHeight-topHeight/2, topLength/2 - legThickness/2); // Translate to leg position
    
      Cube leg3(legThickness, legHeight, legThickness, tableTex, tableTex, tableTex, tableTex, tableTex, tableTex, false);
      leg3.draw();
      glPopMatrix();

    //Leg 4 Back Left
     glPushMatrix();
       glTranslatef(-topWidth/2 + legThickness/2, -legHeight-topHeight/2, topLength/2 - legThickness/2); // Translate to leg position
       Cube leg4(legThickness, legHeight, legThickness, tableTex, tableTex, tableTex, tableTex, tableTex, tableTex, false);
      leg4.draw();
      glPopMatrix();


    // Draw the top surface
    glTranslatef(0.0f, 1.0f,0.0f);
    Cube topSurface(topWidth, topHeight, topLength, tableTex, tableTex, tableTex, tableTex, tableTex, tableTex, false);
    topSurface.draw();
    
    glPopMatrix();

	glPushMatrix();
	glTranslatef(topWidth/2, legHeight, 0.0);
	glScalef(0.3, 0.5, 0.3);
    drawGlass();
    glPopMatrix();

	glPushMatrix();
	glTranslatef(-topWidth/2, legHeight, 0.0);
	glScalef(0.3, 0.5, 0.3);
    drawGlass();
    glPopMatrix();


	glPushMatrix();
	glTranslatef(0.0, legHeight, topWidth/2);
	glScalef(0.3, 0.5, 0.3);
    drawGlass();
    glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, legHeight, -topWidth/2);
	glScalef(0.3, 0.5, 0.3);
    drawGlass();
    glPopMatrix();

  }

	}; // Function to draw the entire table


#endif
