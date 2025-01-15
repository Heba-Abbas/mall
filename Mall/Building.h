#ifndef BUILDING_H
#define BUILDING_H

#include "Cube.h"
#include <glut.h>
#include <gl\gl.h>      // Header File For The OpenGL32 Library
#include <gl\glu.h>      // Header File For The GLu32 Library


// Function to draw the mall street
void drawBuilding(){
	
	// map street
	glPushMatrix();
	Cube building1(1000, 3000, 1000, buildingTex, buildingFront, concrete, concrete, buildingTex, buildingTex, false);
      building1.draw();
	glPopMatrix();

}

#endif