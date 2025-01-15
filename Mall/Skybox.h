// Skybox.h  
#ifndef SKYBOX_H
#define SKYBOX_H

#include "Cube.h"
#include <glut.h>
#include <gl\gl.h>      // Header File For The OpenGL32 Library
#include <gl\glu.h>      // Header File For The GLu32 Library


class Skybox {
private:

    int dayTexture[6];  // Texture for the "daytime" skybox
    int nightTexture[6];  // Texture for the "nighttime" skybox

    bool isDaytime;

public:
    Skybox(GLuint dayTex[], GLuint nightTex[], bool isDayTime){
		this->isDaytime = isDayTime;  // Initially set to daytime

		for (int i = 0; i < 6; i++) {
			dayTexture[i] = dayTex[i];
			nightTexture[i] = nightTex[i];
    }
    }

    // Function to change the daytime/nighttime view
    void daytimeView() {

        if (isDaytime) {
    glPushMatrix();
		glTranslatef(0.0f, 200.0f, 0.0f);
		
		Cube skyBox(10000, 10000, 10000, dayTexture[0], dayTexture[1], dayTexture[2], dayTexture[3], dayTexture[4], dayTexture[5], false);
			skyBox.drawSkyBox();

	glPopMatrix();

        } else {
            
    glPushMatrix();
		glTranslatef(0.0f, 200.0f, 0.0f);
		
		Cube skyBox(10000, 10000, 10000, nightTexture[0], nightTexture[1], nightTexture[2], nightTexture[3], nightTexture[4], nightTexture[5], false);
			skyBox.drawSkyBox();

	glPopMatrix();
        }
    }
};

#endif // SKYBOX_H
