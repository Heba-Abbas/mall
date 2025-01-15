#ifdef __cplusplus
#include <cstdlib>
#else
#include <stdlib.h>
#endif
#include <stdio.h>                         // Header File For Standard Input/Output ( NEW )
#include <cmath>
#include <math.h>
#include "PolygonQ.h"
#include "Sphere.h"
#include "Cube.h"
#include "Texture.h"
#include "Cylinder.h"
#include "Square.h"
#include "Skybox.h"
#include "Table.h"
#include "Chair.h"
#include <glut.h>
#include <Model_3ds.h>
#include <3DTexture.h>
#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <GLAUX.H>		// Header File For The Glaux Library
#include <Model_3DS.h>
#include "camera.h"
#include <mmsystem.h> 
#pragma comment(lib, "winmm.lib")
#define M_PI 3.14159265358979323846

HDC			hDC=NULL;		// Private GDI Device Context
HGLRC		hRC=NULL;		// Permanent Rendering Context
HWND		hWnd=NULL;		// Holds Our Window Handle
HINSTANCE	hInstance;		// Holds The Instance Of The Application

bool	keys[256];			// Array Used For The Keyboard Routine
bool	active=TRUE;		// Window Active Flag Set To TRUE By Default
bool	fullscreen=TRUE;	// Fullscreen Flag Set To Fullscreen Mode By Default

float moonPosition;

		GLfloat light_pos [] = {0.0, 500.0, 0.0, 1.0};
		GLfloat light_pos2 [] = {0.0, 1000.0, -200.0, 1.0};
		GLfloat light_pos3 [] = {-150.0, 900.0, 0.0, 1.0};
		GLfloat lightAmbient [] = {1.0, 1.0, 1.0, 1.0};
		GLfloat lightDiffuse [] = {1.0, 1.0, 1.0, 1.0};
		
LRESULT	CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	// Declaration For WndProc

int DrawGLScene();

GLvoid ReSizeGLScene(GLsizei width, GLsizei height)		// Resize And Initialize The GL Window
{
	if (height==0)										// Prevent A Divide By Zero By
	{
		height=1;										// Making Height Equal One
	}

	glViewport(0,0,width,height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,10.0f,50000.0f);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	//glLoadIdentity();									// Reset The Modelview Matrix
	DrawGLScene();
}

//Model_3DS *tvModel;
//GLTexture Match;

GLuint
	skyUp,
	skyFront,
	skyBack,
	skyRight,
	skyLeft,
	skyBottom,

	skyNightUp,
	skyNightFront, 
	skyNightBack,  
	skyNightRight, 
	skyNightLeft,  
	skyNightBottom,

	tableTex,
	chairTex,
	woodTex,
	darkWood,
	wallTex,
	frontTopWallTex,
	frontWallTex,
	restaurantFloor,
	roofTex,
	doorTex,
	leftHandle,
	rightHandle,
	outsideWall,
	frontTopWallOutside,
	frontRightWallOutside,
	frontLeftWallOutside,
	tvTex,
	art1,
	art2,
	art3,
	frontLogo,
	greenSyria,
	shukr1,
	grassTex,
	mallFloor,
	mallStreet,
	concrete,
	buildingTex,
	buildingFront,
	mallFrontTop,
	mallFrontLR,
	mallWallOutside


	;

bool isDayTime = true;
float r_translateX = 283.0;
float l_translateX = -283.0;
bool doorOpen = false;

Camera MyCamera;
bool  isClicked,isRClicked;
double movX, movY, movZ,lX,lY;
float mouseX = 0, mouseY = 0;
float LastX , LastY ;

void mouse(float mouseX, float mouseY, bool isClicked, bool isRClicked)
{
    if (isClicked) // Rotate only when left mouse button is clicked
    {
        // Calculate the difference in mouse position
        float deltaX = mouseX - LastX;
        float deltaY = mouseY - LastY;

        // Adjust sensitivity
        float sensitivity = 0.1f;
        deltaX *= sensitivity;
        deltaY *= sensitivity;

        // Apply rotation to the camera
        MyCamera.RotateY(-deltaX); // Rotate around Y-axis
        MyCamera.RotateX(-deltaY); // Rotate around X-axis
    }

    // Update the last position
    LastX = mouseX;
    LastY = mouseY;
}


void Key(bool* keys, float speed)
{
  if (keys['S'])
    MyCamera.RotateX(-1 * speed);
  if (keys['W'])
    MyCamera.RotateX(1 * speed);
  if (keys['D'])
    MyCamera.RotateY(-1 * speed);
  if (keys['Z'])
    MyCamera.RotateZ(1 * speed);
  if (keys['X'])
    MyCamera.RotateZ(-1 * speed);
  if (keys['A'])
    MyCamera.RotateY(1 * speed);
  if (keys[VK_UP])
    MyCamera.MoveForward(1 * speed);
  if (keys[VK_DOWN])
    MyCamera.MoveForward(-1 * speed);
  if (keys[VK_RIGHT])
    MyCamera.MoveRight(1 * speed);
  if (keys[VK_LEFT])
    MyCamera.MoveRight(-1 * speed);
  if (keys['O'])
    MyCamera.MoveUpward(1 * speed);
  if (keys['L'])
    MyCamera.MoveUpward(-1 * speed);
  
}


// Function to draw the mall street
void drawBuilding(){
	
	// map street
	glPushMatrix();
	Cube building1(1000, 3000, 1000, buildingTex, buildingFront, concrete, concrete, buildingTex, buildingTex, false);
      building1.draw();
	glPopMatrix();

}


// Function to draw the mall
void drawStreet(){
	
	// map street
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, mallStreet);
	glBegin(GL_QUADS);
        // Bottom face
		//glColor4f(0.3f, 0.5f, 0.1f, 0.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-8500, 0, -8500);//-x, -y, -z
        glTexCoord2f(1.0f, 0.0f); glVertex3f(8500,  0, -8500);//x, -y, -z
        glTexCoord2f(1.0f, 1.0f); glVertex3f(8500,  0,  8500);//x, -y, z
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-8500, 0,  8500);//-x, -y, z

    glEnd();
	glPopMatrix();

}


// Function to draw the mall
void drawMall(){
	
	glPushMatrix();


	// mall floor
	glPushMatrix();
	glTranslatef(0.0, 1.0, 0);
	glBindTexture(GL_TEXTURE_2D, mallFloor);
	glBegin(GL_QUADS);
        // Bottom floor
		//glColor4f(0.3f, 0.5f, 0.1f, 0.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-1700, -1700, -1700);//-x, -y, -z
        glTexCoord2f(1.0f, 0.0f); glVertex3f(1700,  -1700, -1700);//x, -y, -z
        glTexCoord2f(1.0f, 1.0f); glVertex3f(1700,  -1700,  1700);//x, -y, z
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1700, -1700,  1700);//-x, -y, z

    glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0.0, 1650.0, 0.0);
	glBindTexture(GL_TEXTURE_2D, concrete);
	glBegin(GL_QUADS);
        // top roof
		//glColor4f(0.3f, 0.5f, 0.1f, 0.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-1700, -1700, -1700);//-x, -y, -z
        glTexCoord2f(1.0f, 0.0f); glVertex3f(1700,  -1700, -1700);//x, -y, -z
        glTexCoord2f(1.0f, 1.0f); glVertex3f(1700,  -1700,  1700);//x, -y, z
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1700, -1700,  1700);//-x, -y, z
    glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-50.0, -850.0, 0);
	glBindTexture(GL_TEXTURE_2D, wallTex);
	glBegin(GL_QUADS);
        // Right wall
		//glColor4f(0.4f, 0.1f, 0.6f, 0.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(1700,  850,  1700);//x, y, z
		glTexCoord2f(1.0f, 1.0f); glVertex3f(1700,  850, -1700);//x, y, -z
        glTexCoord2f(1.0f, 0.0f); glVertex3f(1700, -850, -1700);//x, -y, -z
        glTexCoord2f(0.0f, 0.0f); glVertex3f(1700, -850,  1700);//x, -y, z

	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(50.0, -850.0, 0);
	glBindTexture(GL_TEXTURE_2D, wallTex);
	glBegin(GL_QUADS);
        // Left wall
		//glColor4f(0.1f, 0.3f, 0.5f, 0.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-1700,  850, -1700);//-x, y, -z
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-1700,  850,  1700);//-x, y, z
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-1700, -850,  1700);//-x, -y, z
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-1700, -850, -1700);//-x, -y, -z
		glEnd();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(0.0, -850.0, 75.0);
	glBindTexture(GL_TEXTURE_2D, wallTex);
	glBegin(GL_QUADS);
        // Back face
		//glColor4f(0.3f, 0.4f, 0.6f, 0.0f);
	
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-1700, -850, -1700);//-x, -y, -z
        glTexCoord2f(1.0f, 0.0f); glVertex3f(1700,  -850, -1700);//x, -y, -z
        glTexCoord2f(1.0f, 1.0f); glVertex3f(1700,   850, -1700);//x, y, -z
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1700,  850, -1700);//-x, y, -z
    glEnd();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(0.0, 1700.0, 0.0);
	glBindTexture(GL_TEXTURE_2D, concrete);
	glBegin(GL_QUADS);
        // top roof Outside
		//glColor4f(0.3f, 0.5f, 0.1f, 0.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-1700, -1700, -1700);//-x, -y, -z
        glTexCoord2f(1.0f, 0.0f); glVertex3f(1700,  -1700, -1700);//x, -y, -z
        glTexCoord2f(1.0f, 1.0f); glVertex3f(1700,  -1700,  1700);//x, -y, z
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1700, -1700,  1700);//-x, -y, z
    glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -850.0, 0);
	glBindTexture(GL_TEXTURE_2D, mallWallOutside);
	glBegin(GL_QUADS);
        // Right wall Outside
		//glColor4f(0.4f, 0.1f, 0.6f, 0.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(1700,  850,  1700);//x, y, z
		glTexCoord2f(1.0f, 1.0f); glVertex3f(1700,  850, -1700);//x, y, -z
        glTexCoord2f(1.0f, 0.0f); glVertex3f(1700, -850, -1700);//x, -y, -z
        glTexCoord2f(0.0f, 0.0f); glVertex3f(1700, -850,  1700);//x, -y, z

	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.0, -850.0, 0);
	glBindTexture(GL_TEXTURE_2D, mallWallOutside);
	glBegin(GL_QUADS);
        // Left wall Outside
		//glColor4f(0.1f, 0.3f, 0.5f, 0.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-1700,  850, -1700);//-x, y, -z
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-1700,  850,  1700);//-x, y, z
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-1700, -850,  1700);//-x, -y, z
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-1700, -850, -1700);//-x, -y, -z
		glEnd();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(0.0, -850.0, -0.0);
	glBindTexture(GL_TEXTURE_2D, mallWallOutside);
	glBegin(GL_QUADS);
        // Back face Outside
		//glColor4f(0.3f, 0.4f, 0.6f, 0.0f);
	
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-1700, -850, -1700);//-x, -y, -z
        glTexCoord2f(1.0f, 0.0f); glVertex3f(1700,  -850, -1700);//x, -y, -z
        glTexCoord2f(1.0f, 1.0f); glVertex3f(1700,   850, -1700);//x, y, -z
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1700,  850, -1700);//-x, y, -z
    glEnd();
	glPopMatrix();



	glPushMatrix();
	glTranslatef(0.0, -500.0, 0.0);
	glBindTexture(GL_TEXTURE_2D, mallFrontTop);
    glBegin(GL_QUADS);
    // Front wall top Outside
		//glColor4f(0.7f, 0.2f, 0.3f, 0.0f);
         glTexCoord2f(0.0f, 0.0f); glVertex3f(-1700, -500, 1700);//-x, -y, z
         glTexCoord2f(1.0f, 0.0f); glVertex3f(1700,  -500, 1700);//x, -y, z
         glTexCoord2f(1.0f, 1.0f); glVertex3f(1700,   500, 1700);//x, y, z
         glTexCoord2f(0.0f, 1.0f); glVertex3f(-1700,  500, 1700);//-x, y, z
    glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -500.0, -50.0);
	glBindTexture(GL_TEXTURE_2D, frontTopWallTex);
    glBegin(GL_QUADS);
    // Front wall top
		//glColor4f(0.7f, 0.2f, 0.3f, 0.0f);
         glTexCoord2f(0.0f, 0.0f); glVertex3f(-1700, -500, 1700);//-x, -y, z
         glTexCoord2f(1.0f, 0.0f); glVertex3f(1700,  -500, 1700);//x, -y, z
         glTexCoord2f(1.0f, 1.0f); glVertex3f(1700,   500, 1700);//x, y, z
         glTexCoord2f(0.0f, 1.0f); glVertex3f(-1700,  500, 1700);//-x, y, z
    glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1132.0, -1350.0, 0.0);
	glBindTexture(GL_TEXTURE_2D, mallFrontLR);
    glBegin(GL_QUADS);
    // Front wall left Outside
		//glColor4f(0.7f, 0.2f, 0.3f, 0.0f);
         glTexCoord2f(0.0f, 0.0f); glVertex3f(-566, -350, 1700);//-x, -y, z
         glTexCoord2f(1.0f, 0.0f); glVertex3f(566,  -350, 1700);//x, -y, z
         glTexCoord2f(1.0f, 1.0f); glVertex3f(566,   350, 1700);//x, y, z
         glTexCoord2f(0.0f, 1.0f); glVertex3f(-566,  350, 1700);//-x, y, z
    glEnd();
	glPopMatrix();

		
	glPushMatrix();
	glTranslatef(-1132.0, -1350.0, -50.0);
	glBindTexture(GL_TEXTURE_2D, frontWallTex);
    glBegin(GL_QUADS);
    // Front wall left 
		//glColor4f(0.7f, 0.2f, 0.3f, 0.0f);
         glTexCoord2f(0.0f, 0.0f); glVertex3f(-566, -350, 1700);//-x, -y, z
         glTexCoord2f(1.0f, 0.0f); glVertex3f(566,  -350, 1700);//x, -y, z
         glTexCoord2f(1.0f, 1.0f); glVertex3f(566,   350, 1700);//x, y, z
         glTexCoord2f(0.0f, 1.0f); glVertex3f(-566,  350, 1700);//-x, y, z
    glEnd();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(1132.0, -1350.0, 0.0);
	glBindTexture(GL_TEXTURE_2D, mallFrontLR);
    glBegin(GL_QUADS);
    // Front wall right Outside 
		//glColor4f(0.7f, 0.2f, 0.3f, 0.0f);
         glTexCoord2f(0.0f, 0.0f); glVertex3f(-566, -350, 1700);//-x, -y, z
         glTexCoord2f(1.0f, 0.0f); glVertex3f(566,  -350, 1700);//x, -y, z
         glTexCoord2f(1.0f, 1.0f); glVertex3f(566,   350, 1700);//x, y, z
         glTexCoord2f(0.0f, 1.0f); glVertex3f(-566,  350, 1700);//-x, y, z
    glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(1132.0, -1350.0, -50.0);
	glBindTexture(GL_TEXTURE_2D, frontWallTex);
    glBegin(GL_QUADS);
    // Front wall right 
		//glColor4f(0.7f, 0.2f, 0.3f, 0.0f);
         glTexCoord2f(0.0f, 0.0f); glVertex3f(-566, -350, 1700);//-x, -y, z
         glTexCoord2f(1.0f, 0.0f); glVertex3f(566,  -350, 1700);//x, -y, z
         glTexCoord2f(1.0f, 1.0f); glVertex3f(566,   350, 1700);//x, y, z
         glTexCoord2f(0.0f, 1.0f); glVertex3f(-566,  350, 1700);//-x, y, z
    glEnd();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(l_translateX, -1350.0, -25.0);

	glPushMatrix();
	glPushAttrib(GL_ENABLE_BIT | GL_CURRENT_BIT); // Save blending and color state
	glColor4f(1.0f, 1.0f, 0.5f, 0.5f);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_QUADS);
    // left door 
         glVertex3f(-283, -350, 1700);//-x, -y, z
         glVertex3f(283,  -350, 1700);//x, -y, z
         glVertex3f(283,   350, 1700);//x, y, z
         glVertex3f(-283,  350, 1700);//-x, y, z
    glEnd();
	glDisable(GL_BLEND); // Disable blending again
	glPopAttrib();
	glPopMatrix();

	glPushAttrib(GL_ENABLE_BIT | GL_CURRENT_BIT);
	// Draw the frame (dark gray)
	glColor3f(0.2f, 0.2f, 0.2f); // Dark gray color

	// Top frame
	glBegin(GL_QUADS);
	glVertex3f(-283, 350, 1700); // -x, y, z
	glVertex3f(283, 350, 1700);  // x, y, z
	glVertex3f(283, 340, 1700);  // x, y-thick, z
	glVertex3f(-283, 340, 1700); // -x, y-thick, z
	glEnd();

	// Bottom frame
	glBegin(GL_QUADS);
	glVertex3f(-283, -350, 1700); // -x, -y, z
	glVertex3f(283, -350, 1700);  // x, -y, z
	glVertex3f(283, -340, 1700);  // x, -y+thick, z
	glVertex3f(-283, -340, 1700); // -x, -y+thick, z
	glEnd();

	// Left frame
	glBegin(GL_QUADS);
	glVertex3f(-283, -350, 1700); // -x, -y, z
	glVertex3f(-273, -350, 1700); // -x+thick, -y, z
	glVertex3f(-273, 350, 1700);  // -x+thick, y, z
	glVertex3f(-283, 350, 1700);  // -x, y, z
	glEnd();

	// Right frame
	glBegin(GL_QUADS);
	glVertex3f(283, -350, 1700);  // x, -y, z
	glVertex3f(273, -350, 1700);  // x-thick, -y, z
	glVertex3f(273, 350, 1700);   // x-thick, y, z
	glVertex3f(283, 350, 1700);   // x, y, z
	glEnd();

	// Draw the circular handle
	glPushMatrix();
	glTranslatef(230.0f, 0.0f, 1700.0f); // Position the handle on the door
	glColor3f(0.2f, 0.2f, 0.2f);        // Light gray color for the handle
	float radius = 20.0f;
	int numSegments = 50; // Number of segments for the circle
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(0.0f, 0.0f); // Center of the circle
	for (int i = 0; i <= numSegments; i++) {
		float angle = 2.0f * M_PI * i / numSegments; // Angle in radians
		glVertex2f(cos(angle) * radius, sin(angle) * radius);
	}
	glEnd();
	glPopAttrib();
	glPopMatrix();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(r_translateX, -1350.0, -25.0);

	glPushMatrix();
	glPushAttrib(GL_ENABLE_BIT | GL_CURRENT_BIT); // Save blending and color state
	glColor4f(1.0f, 1.0f, 0.5f, 0.5f);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_QUADS);
    // right door 
         glVertex3f(-283, -350, 1700);//-x, -y, z
         glVertex3f(283,  -350, 1700);//x, -y, z
         glVertex3f(283,   350, 1700);//x, y, z
         glVertex3f(-283,  350, 1700);//-x, y, z
    glEnd();
	glDisable(GL_BLEND); // Disable blending again
	glPopAttrib();
	glPopMatrix();

	glPushAttrib(GL_ENABLE_BIT | GL_CURRENT_BIT);
	// Draw the frame (dark gray)
	glColor3f(0.2f, 0.2f, 0.2f); // Dark gray color

	// Top frame
	glBegin(GL_QUADS);
	glVertex3f(-283, 350, 1700); // -x, y, z
	glVertex3f(283, 350, 1700);  // x, y, z
	glVertex3f(283, 340, 1700);  // x, y-thick, z
	glVertex3f(-283, 340, 1700); // -x, y-thick, z
	glEnd();

	// Bottom frame
	glBegin(GL_QUADS);
	glVertex3f(-283, -350, 1700); // -x, -y, z
	glVertex3f(283, -350, 1700);  // x, -y, z
	glVertex3f(283, -340, 1700);  // x, -y+thick, z
	glVertex3f(-283, -340, 1700); // -x, -y+thick, z
	glEnd();

	// Left frame
	glBegin(GL_QUADS);
	glVertex3f(-283, -350, 1700); // -x, -y, z
	glVertex3f(-273, -350, 1700); // -x+thick, -y, z
	glVertex3f(-273, 350, 1700);  // -x+thick, y, z
	glVertex3f(-283, 350, 1700);  // -x, y, z
	glEnd();

	// Right frame
	glBegin(GL_QUADS);
	glVertex3f(283, -350, 1700);  // x, -y, z
	glVertex3f(273, -350, 1700);  // x-thick, -y, z
	glVertex3f(273, 350, 1700);   // x-thick, y, z
	glVertex3f(283, 350, 1700);   // x, y, z
	glEnd();

	// Draw the circular handle
	glPushMatrix();
	glTranslatef(-230.0f, 0.0f, 1700.0f); // Position the handle on the door
	glColor3f(0.2f, 0.2f, 0.2f);        // Light gray color for the handle
	float radius1 = 20.0f;
	int numSegments1 = 50; // Number of segments for the circle
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(0.0f, 0.0f); // Center of the circle
	for (int i = 0; i <= numSegments1; i++) {
		float angle = 2.0f * M_PI * i / numSegments1; // Angle in radians
		glVertex2f(cos(angle) * radius1, sin(angle) * radius);
	}
	glEnd();
	glPopAttrib();
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();

}


// Function to draw the restaurant
void drawRestaurant(){


// restaurant floor
	glPushMatrix();
	glTranslatef(0.0, 50.0, 0);
	glBindTexture(GL_TEXTURE_2D, restaurantFloor);
	glBegin(GL_QUADS);
        // Bottom floor
		//glColor4f(0.3f, 0.5f, 0.1f, 0.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-850, -850, -850);//-x, -y, -z
        glTexCoord2f(1.0f, 0.0f); glVertex3f(850,  -850, -850);//x, -y, -z
        glTexCoord2f(1.0f, 1.0f); glVertex3f(850,  -850,  850);//x, -y, z
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-850, -850,  850);//-x, -y, z

    glEnd();
	
	glPushMatrix();
	glTranslatef(0.0, 800.0, 0);
	glBindTexture(GL_TEXTURE_2D, roofTex);
	glBegin(GL_QUADS);
        // top roof
		//glColor4f(0.3f, 0.5f, 0.1f, 0.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-850, -850, -850);//-x, -y, -z
        glTexCoord2f(1.0f, 0.0f); glVertex3f(850,  -850, -850);//x, -y, -z
        glTexCoord2f(1.0f, 1.0f); glVertex3f(850,  -850,  850);//x, -y, z
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-850, -850,  850);//-x, -y, z
    glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 805.0, 0);
	glBindTexture(GL_TEXTURE_2D, outsideWall);
	glBegin(GL_QUADS);
        // top roof outside
		//glColor4f(0.3f, 0.5f, 0.1f, 0.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-850, -850, -850);//-x, -y, -z
        glTexCoord2f(1.0f, 0.0f); glVertex3f(850,  -850, -850);//x, -y, -z
        glTexCoord2f(1.0f, 1.0f); glVertex3f(850,  -850,  850);//x, -y, z
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-850, -850,  850);//-x, -y, z
    glEnd();
	glPopMatrix();


	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -400.0, 0);
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, wallTex);
	glBegin(GL_QUADS);
        // Right wall
		//glColor4f(0.4f, 0.1f, 0.6f, 0.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(850,  400,  850);//x, y, z
		glTexCoord2f(1.0f, 1.0f); glVertex3f(850,  400, -850);//x, y, -z
        glTexCoord2f(1.0f, 0.0f); glVertex3f(850, -400, -850);//x, -y, -z
        glTexCoord2f(0.0f, 0.0f); glVertex3f(850, -400,  850);//x, -y, z

	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, wallTex);
	glBegin(GL_QUADS);
        // Left wall
		//glColor4f(0.1f, 0.3f, 0.5f, 0.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-850,  400, -850);//-x, y, -z
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-850,  400,  850);//-x, y, z
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-850, -400,  850);//-x, -y, z
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-850, -400, -850);//-x, -y, -z
        
		glEnd();
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, wallTex);
	glBegin(GL_QUADS);
        // Back face
		//glColor4f(0.3f, 0.4f, 0.6f, 0.0f);
	
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-850, -400, -850);//-x, -y, -z
        glTexCoord2f(1.0f, 0.0f); glVertex3f(850,  -400, -850);//x, -y, -z
        glTexCoord2f(1.0f, 1.0f); glVertex3f(850,   400, -850);//x, y, -z
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-850,  400, -850);//-x, y, -z
    glEnd();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(0.0, 250.0, 0.0);
	glBindTexture(GL_TEXTURE_2D, frontTopWallTex);
    glBegin(GL_QUADS);
    // Front wall top 
		//glColor4f(0.7f, 0.2f, 0.3f, 0.0f);
         glTexCoord2f(0.0f, 0.0f); glVertex3f(-850, -150, 850);//-x, -y, z
         glTexCoord2f(1.0f, 0.0f); glVertex3f(850,  -150, 850);//x, -y, z
         glTexCoord2f(1.0f, 1.0f); glVertex3f(850,   150, 850);//x, y, z
         glTexCoord2f(0.0f, 1.0f); glVertex3f(-850,  150, 850);//-x, y, z
    glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(567.0, -150.0, 567.0);
	glBindTexture(GL_TEXTURE_2D, frontWallTex);
    glBegin(GL_QUADS);
    // Front wall right 
		//glColor4f(0.7f, 0.2f, 0.3f, 0.0f);
         glTexCoord2f(0.0f, 0.0f); glVertex3f(-283, -250, 283);//-x, -y, z
         glTexCoord2f(1.0f, 0.0f); glVertex3f(283,  -250, 283);//x, -y, z
         glTexCoord2f(1.0f, 1.0f); glVertex3f(283,   250, 283);//x, y, z
         glTexCoord2f(0.0f, 1.0f); glVertex3f(-283,  250, 283);//-x, y, z
    glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-567.0, -150.0, 567.0);
	glBindTexture(GL_TEXTURE_2D, frontWallTex);
    glBegin(GL_QUADS);
    // Front  wall left
		//glColor4f(0.7f, 0.2f, 0.3f, 0.0f);
         glTexCoord2f(0.0f, 0.0f); glVertex3f(-283, -250, 283);//-x, -y, z
         glTexCoord2f(1.0f, 0.0f); glVertex3f(283,  -250, 283);//x, -y, z
         glTexCoord2f(1.0f, 1.0f); glVertex3f(283,   250, 283);//x, y, z
         glTexCoord2f(0.0f, 1.0f); glVertex3f(-283,  250, 283);//-x, y, z
    glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(141.0, -150.0, 567.0);
	glRotatef(0.0, 0.0f, 1.0f, 0.0f); // Rotate around y axis
		glTranslatef(-141.0, 150.0, -567.0);
	glTranslatef(141.0, -150.0, 567.0);
	glScalef(0.5, 1.0, 1.0);
	glBindTexture(GL_TEXTURE_2D, rightHandle);
    glBegin(GL_QUADS);
    // Front wall door right
		//glColor4f(0.7f, 0.2f, 0.3f, 0.0f);
         glTexCoord2f(0.0f, 0.0f); glVertex3f(-285, -250, 283);//-x, -y, z
         glTexCoord2f(1.0f, 0.0f); glVertex3f(285,  -250, 283);//x, -y, z
         glTexCoord2f(1.0f, 1.0f); glVertex3f(285,   250, 283);//x, y, z
         glTexCoord2f(0.0f, 1.0f); glVertex3f(-285,  250, 283);//-x, y, z
    glEnd();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-141.0, -150.0, 567.0);
	glRotatef(0.0, 0.0f, 1.0f, 0.0f); // Rotate around y axis
		glTranslatef(141.0, 150.0, -567.0);
	glTranslatef(-141.0, -150.0, 567.0);
	glScalef(0.5, 1.0, 1.0);
	glBindTexture(GL_TEXTURE_2D, leftHandle);
    glBegin(GL_QUADS);
    // Front wall door left
		//glColor4f(0.7f, 0.2f, 0.3f, 0.0f);
         glTexCoord2f(0.0f, 0.0f); glVertex3f(-285, -250, 283);//-x, -y, z
         glTexCoord2f(1.0f, 0.0f); glVertex3f(285,  -250, 283);//x, -y, z
         glTexCoord2f(1.0f, 1.0f); glVertex3f(285,   250, 283);//x, y, z
         glTexCoord2f(0.0f, 1.0f); glVertex3f(-285,  250, 283);//-x, y, z
    glEnd();
	glPopMatrix();

	glPopMatrix();
	

	// all the tables
	glPushMatrix();
	glTranslatef(0.0, -700.0, 0);


	//table1
	glPushMatrix();
	
	glTranslatef(-350.0f, 0.0f, -350.0f);

	glPushMatrix();
	glTranslatef(5.0f, 0.0f, 0.0f);
	Table table1(100, 100, 7.0, 10, 50, darkWood);
	table1.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(150.0f, -65.0f, 0.0f);
	glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
	Chair chair1(45.0f, 45.0f, 7.0f, 5.0f, 35.0f, 60.0f, 5.0f, chairTex, darkWood);
	chair1.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, -65.0f, -150.0f);
	Chair chair2(45.0f, 45.0f, 7.0f, 5.0f, 35.0f, 60.0f, 5.0f, chairTex, darkWood);
	chair2.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-150.0f, -65.0f, 0.0f);
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	Chair chair3(45.0f, 45.0f, 7.0f, 5.0f, 35.0f, 60.0f, 5.0f, chairTex, darkWood);
	chair3.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, -65.0f, 150.0f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
	Chair chair4(45.0f, 45.0f, 7.0f, 5.0f, 35.0f, 60.0f, 5.0f, chairTex, darkWood);
	chair4.draw();
	glPopMatrix();

	glPopMatrix();

	//table2
	glPushMatrix();
	
	glTranslatef(-350.0f, 0.0f, 350.0f);

	glPushMatrix();
	glTranslatef(5.0f, 0.0f, 0.0f);
	table1.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(150.0f, -65.0f, 0.0f);
	glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
	chair1.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, -65.0f, -150.0f);
	chair2.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-150.0f, -65.0f, 0.0f);
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	chair3.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, -65.0f, 150.0f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
	chair4.draw();
	glPopMatrix();

	glPopMatrix();

	//table3
	glPushMatrix();
	
	glTranslatef(350.0f, 0.0f, 350.0f);

	glPushMatrix();
	glTranslatef(5.0f, 0.0f, 0.0f);
	table1.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(150.0f, -65.0f, 0.0f);
	glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
	chair1.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, -65.0f, -150.0f);
	chair2.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-150.0f, -65.0f, 0.0f);
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	chair3.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, -65.0f, 150.0f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
	chair4.draw();
	glPopMatrix();

	glPopMatrix();

	//table4
	glPushMatrix();
	
	glTranslatef(350.0f, 0.0f, -350.0f);

	glPushMatrix();
	glTranslatef(5.0f, 0.0f, 0.0f);
	table1.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(150.0f, -65.0f, 0.0f);
	glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
	chair1.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, -65.0f, -150.0f);
	chair2.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-150.0f, -65.0f, 0.0f);
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	chair3.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, -65.0f, 150.0f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
	chair4.draw();
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();

	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5.0, -400.0, 0);
	glBindTexture(GL_TEXTURE_2D, outsideWall);
	glBegin(GL_QUADS);
        // Right wall outside
		//glColor4f(0.4f, 0.1f, 0.6f, 0.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(850,  400,  850);//x, y, z
		glTexCoord2f(1.0f, 1.0f); glVertex3f(850,  400, -850);//x, y, -z
        glTexCoord2f(1.0f, 0.0f); glVertex3f(850, -400, -850);//x, -y, -z
        glTexCoord2f(0.0f, 0.0f); glVertex3f(850, -400,  850);//x, -y, z
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-5.0, -400.0, 0);
	glBindTexture(GL_TEXTURE_2D, outsideWall);
	glBegin(GL_QUADS);
        // Left wall outside
		//glColor4f(0.1f, 0.3f, 0.5f, 0.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-850,  400, -850);//-x, y, -z
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-850,  400,  850);//-x, y, z
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-850, -400,  850);//-x, -y, z
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-850, -400, -850);//-x, -y, -z
        
		glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -400.0, -9.0);
	glBindTexture(GL_TEXTURE_2D, outsideWall);
	glBegin(GL_QUADS);
        // Back face outside
		//glColor4f(0.3f, 0.4f, 0.6f, 0.0f);
	
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-850, -400, -850);//-x, -y, -z
        glTexCoord2f(1.0f, 0.0f); glVertex3f(850,  -400, -850);//x, -y, -z
        glTexCoord2f(1.0f, 1.0f); glVertex3f(850,   400, -850);//x, y, -z
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-850,  400, -850);//-x, y, -z
    glEnd();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(0.0, -150.0, 5.0);
	glBindTexture(GL_TEXTURE_2D, frontTopWallOutside);
    glBegin(GL_QUADS);
    // Front wall top outside
		//glColor4f(0.7f, 0.2f, 0.3f, 0.0f);
         glTexCoord2f(0.0f, 0.0f); glVertex3f(-850, -150, 850);//-x, -y, z
         glTexCoord2f(1.0f, 0.0f); glVertex3f(850,  -150, 850);//x, -y, z
         glTexCoord2f(1.0f, 1.0f); glVertex3f(850,   150, 850);//x, y, z
         glTexCoord2f(0.0f, 1.0f); glVertex3f(-850,  150, 850);//-x, y, z
    glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(567.0, -550.0, 572.0);
	glBindTexture(GL_TEXTURE_2D, frontRightWallOutside);
    glBegin(GL_QUADS);
    // Front wall right  outside
		//glColor4f(0.7f, 0.2f, 0.3f, 0.0f);
         glTexCoord2f(0.0f, 0.0f); glVertex3f(-283, -250, 283);//-x, -y, z
         glTexCoord2f(1.0f, 0.0f); glVertex3f(283,  -250, 283);//x, -y, z
         glTexCoord2f(1.0f, 1.0f); glVertex3f(283,   250, 283);//x, y, z
         glTexCoord2f(0.0f, 1.0f); glVertex3f(-283,  250, 283);//-x, y, z
    glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-567.0, -550.0, 572.0);
	glBindTexture(GL_TEXTURE_2D, frontLeftWallOutside);
    glBegin(GL_QUADS);
    // Front  wall left outside
		//glColor4f(0.7f, 0.2f, 0.3f, 0.0f);
         glTexCoord2f(0.0f, 0.0f); glVertex3f(-283, -250, 283);//-x, -y, z
         glTexCoord2f(1.0f, 0.0f); glVertex3f(283,  -250, 283);//x, -y, z
         glTexCoord2f(1.0f, 1.0f); glVertex3f(283,   250, 283);//x, y, z
         glTexCoord2f(0.0f, 1.0f); glVertex3f(-283,  250, 283);//-x, y, z
    glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -150.0, 573.0);
	glBindTexture(GL_TEXTURE_2D, frontLogo);
    glBegin(GL_QUADS);
    // Front logo outside
		//glColor4f(0.7f, 0.2f, 0.3f, 0.0f);
         glTexCoord2f(0.0f, 0.0f); glVertex3f(-250, -100, 283);//-x, -y, z
         glTexCoord2f(1.0f, 0.0f); glVertex3f(250,  -100, 283);//x, -y, z
         glTexCoord2f(1.0f, 1.0f); glVertex3f(250,   100, 283);//x, y, z
         glTexCoord2f(0.0f, 1.0f); glVertex3f(-250,  100, 283);//-x, y, z
    glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -200.0, 5.0);
	glScalef(0.5, 0.5, 1.0);
	glBindTexture(GL_TEXTURE_2D, tvTex);
	glBegin(GL_QUADS);
        //tv screen
		//glColor4f(0.3f, 0.4f, 0.6f, 0.0f);
	
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-480, -270, -850);//-x, -y, -z
        glTexCoord2f(1.0f, 0.0f); glVertex3f(480,  -270, -850);//x, -y, -z
        glTexCoord2f(1.0f, 1.0f); glVertex3f(480,   270, -850);//x, y, -z
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-480,  270, -850);//-x, y, -z
    glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -550.0, 5.0);
	glScalef(0.7, 0.7, 1.0);
	glBindTexture(GL_TEXTURE_2D, greenSyria);
	glBegin(GL_QUADS);
        //tv screen
		//glColor4f(0.3f, 0.4f, 0.6f, 0.0f);
	
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-275, -165, -850);//-x, -y, -z
        glTexCoord2f(1.0f, 0.0f); glVertex3f(275,  -165, -850);//x, -y, -z
        glTexCoord2f(1.0f, 1.0f); glVertex3f(275,   165, -850);//x, y, -z
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-275,  165, -850);//-x, y, -z
    glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5.0, -300.0, 0);
	glScalef(1.0, 0.25, 0.25);
	glBindTexture(GL_TEXTURE_2D, shukr1);
	glBegin(GL_QUADS);
        // Left wall shukr
		//glColor4f(0.1f, 0.3f, 0.5f, 0.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-850,  477, -853);//-x, y, -z
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-850,  477,  853);//-x, y, z
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-850, -477,  853);//-x, -y, z
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-850, -477, -853);//-x, -y, -z
        
		glEnd();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-5.0, -300.0, -400);
	glScalef(1.0, 0.25, 0.25);
	glBindTexture(GL_TEXTURE_2D, art1);
	glBegin(GL_QUADS);
        // Right wall art1
		//glColor4f(0.4f, 0.1f, 0.6f, 0.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(853,  450,  360);//x, y, z
		glTexCoord2f(1.0f, 1.0f); glVertex3f(853,  450, -360);//x, y, -z
        glTexCoord2f(1.0f, 0.0f); glVertex3f(853, -450, -360);//x, -y, -z
        glTexCoord2f(0.0f, 0.0f); glVertex3f(853, -450,  360);//x, -y, z
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-5.0, -300.0, 400);
	glScalef(1.0, 0.25, 0.25);
	glBindTexture(GL_TEXTURE_2D, art3);
	glBegin(GL_QUADS);
        // Right wall art3
		//glColor4f(0.4f, 0.1f, 0.6f, 0.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(853,  423,  333);//x, y, z
		glTexCoord2f(1.0f, 1.0f); glVertex3f(853,  423, -333);//x, y, -z
        glTexCoord2f(1.0f, 0.0f); glVertex3f(853, -423, -333);//x, -y, -z
        glTexCoord2f(0.0f, 0.0f); glVertex3f(853, -423,  333);//x, -y, z
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-5.0, -300.0, 0);
	glScalef(1.0, 0.25, 0.25);
	glBindTexture(GL_TEXTURE_2D, art2);
	glBegin(GL_QUADS);
        // Right wall art2
		//glColor4f(0.4f, 0.1f, 0.6f, 0.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(853,  885,  1000);//x, y, z
		glTexCoord2f(1.0f, 1.0f); glVertex3f(853,  885, -1000);//x, y, -z
        glTexCoord2f(1.0f, 0.0f); glVertex3f(853, -885, -1000);//x, -y, -z
        glTexCoord2f(0.0f, 0.0f); glVertex3f(853, -885,  1000);//x, -y, z
	glEnd();
	glPopMatrix();


}

int InitGL(GLvoid)										// All Setup For OpenGL Goes Here
{
	
    glEnable(GL_TEXTURE_2D);                        // Enable Texture Mapping

  MyCamera = Camera();
  MyCamera.Position.x = 0;
  MyCamera.Position.y = +100;
  MyCamera.Position.z = +1550;

	skyUp	  = loadGltexture("py.png");
	skyFront  = loadGltexture("pz.png");
	skyBack   = loadGltexture("nz.png");
	skyRight  = loadGltexture("px.png");
	skyLeft   = loadGltexture("nx.png");
	skyBottom = loadGltexture("ny.png");

	skyNightUp	  = loadGltexture("pyN.png");
	skyNightFront  = loadGltexture("pzN.png");
	skyNightBack   = loadGltexture("nzN.png");
	skyNightRight  = loadGltexture("pxN.png");
	skyNightLeft   = loadGltexture("nxN.png");
	skyNightBottom = loadGltexture("nyN.png");

	chairTex = loadGltexture("leather.png");
	darkWood = loadGltexture("darkWood.png");
	woodTex = loadGltexture("wood.png");
	wallTex = loadGltexture("wall.png");
	frontTopWallTex = loadGltexture("frontTopWall.png");
	frontWallTex = loadGltexture("frontLeftWallTex.png");
	restaurantFloor = loadGltexture("restaurantFloor.png");
	roofTex = loadGltexture("roof.png");
	doorTex = loadGltexture("door.png");
	leftHandle = loadGltexture("leftHandle.png");
	rightHandle = loadGltexture("rightHandle.png");
	outsideWall = loadGltexture("outsideWall.png");
	frontTopWallOutside = loadGltexture("frontTopWallOutside.png");
	frontRightWallOutside = loadGltexture("frontRightWallOutside.png");
	frontLeftWallOutside = loadGltexture("frontLeftWallOutside.png");
	tvTex = loadGltexture("tv.png");
	art1 = loadGltexture("art1.png");
	art2 = loadGltexture("art2.png");
	art3 = loadGltexture("art3.png");
	frontLogo = loadGltexture("frontLogo.png");
	greenSyria = loadGltexture("greenSyria.png");
	shukr1 = loadGltexture("shukr1.png");
	grassTex = loadGltexture("grass.png");
	mallStreet = loadGltexture("mall-street-view.png");
	mallFloor = loadGltexture("mallFloor.png");
	concrete = loadGltexture("concrete.png");
	buildingTex =loadGltexture("building.png");
	buildingFront = loadGltexture("buildingFront.png");
	mallFrontTop = loadGltexture("wallOutsideF.png");
	mallFrontLR = loadGltexture("wallOutsideLR.png");
	mallWallOutside = loadGltexture("wallOutside.png");


	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glAlphaFunc ( GL_GREATER, 0.1 ) ;
     glEnable ( GL_ALPHA_TEST ) ;
	glShadeModel(GL_SMOOTH);
     glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);


	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
	
	//glEnable(GL_LIGHTING);
	//glEnable(GL_LIGHT1);
	return TRUE;										// Initialization Went OK
}
float anglex = 0.0f;
float angley = 0.0f;
float anglez = 0.0f;
float zoom = -40.0f;
float xAxis = 0.0f;
float yAxis = 0.0f;



int DrawGLScene(GLvoid)									// Here's Where We Do All The Drawing
{
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
		/*glEnable(GL_BLEND);
		
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		*/glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR,GL_REPLACE);
		//glBlendFunc(GL_SRC_COLOR, GL_SRC_ALPHA_SATURATE);
	glLightfv(GL_LIGHT1, GL_AMBIENT, lightAmbient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightDiffuse);
	glLightfv(GL_LIGHT1, GL_POSITION, light_pos2);

	glLightfv(GL_LIGHT1, GL_AMBIENT_AND_DIFFUSE, lightAmbient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightDiffuse);
    glLightfv(GL_LIGHT1, GL_POSITION, light_pos);

	glLightfv(GL_LIGHT1, GL_SHININESS, lightAmbient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightDiffuse);
    glLightfv(GL_LIGHT1, GL_POSITION, light_pos3);

		MyCamera.Render();

		Key(keys, 0.05);
		mouse(mouseX, mouseY, isClicked, isRClicked);
		LastX = mouseX;
		LastY = mouseY;

	glLoadIdentity();

	glTranslatef(xAxis,yAxis,zoom);

	glRotatef(anglex, 1.0f, 0.0f, 0.0f);
	glRotatef(angley, 0.0f, 1.0f, 0.0f);
	glRotatef(anglez, 0.0f, 0.0f, 1.0f);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	glPushMatrix();
	GLuint dayTex [6] = {skyFront, skyBack, skyUp, skyBottom, skyRight, skyLeft};
	GLuint nightTex [6] = {skyNightFront, skyNightBack, skyNightUp, skyNightBottom, skyNightRight, skyNightLeft};
	Skybox skybox(dayTex, nightTex, isDayTime);
	skybox.daytimeView();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	// Street
	glPushMatrix();
	glTranslatef(0.0, -1700.0, 0.0);
	glRotatef(180, 0.0, 1.0, 0.0);
	drawStreet();
	glPopMatrix();

	// Building 1 right
	glPushMatrix();
	glTranslatef(6040.0, 1230.0, 1600.0);
	glRotatef(180, 0.0, 1.0, 0.0);
	drawBuilding();
	glPopMatrix();

	// Building 2 right
	glPushMatrix();
	glTranslatef(3500.0, 1230.0, 6300.0);
	drawBuilding();
	glPopMatrix();

	// Building 1 left
	glPushMatrix();
	glTranslatef(-6370.0, 1230.0, 1600.0);
	glRotatef(180, 0.0, 1.0, 0.0);
	drawBuilding();
	glPopMatrix();

	// Building 2 left
	glPushMatrix();
	glTranslatef(-3500.0, 1230.0, 6300.0);
	drawBuilding();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(0.0, 0.0, -1000.0);
	drawMall();
	glPopMatrix();

	//glDisable(GL_BLEND);
		return TRUE; // Keep Going
									// Keep Going
}


GLvoid KillGLWindow(GLvoid)								// Properly Kill The Window
{
	if (fullscreen)										// Are We In Fullscreen Mode?
	{
		ChangeDisplaySettings(NULL,0);					// If So Switch Back To The Desktop
		ShowCursor(TRUE);								// Show Mouse Pointer
	}

	if (hRC)											// Do We Have A Rendering Context?
	{
		if (!wglMakeCurrent(NULL,NULL))					// Are We Able To Release The DC And RC Contexts?
		{
			MessageBox(NULL,"Release Of DC And RC Failed.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		}

		if (!wglDeleteContext(hRC))						// Are We Able To Delete The RC?
		{
			MessageBox(NULL,"Release Rendering Context Failed.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		}
		hRC=NULL;										// Set RC To NULL
	}

	if (hDC && !ReleaseDC(hWnd,hDC))					// Are We Able To Release The DC
	{
		MessageBox(NULL,"Release Device Context Failed.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		hDC=NULL;										// Set DC To NULL
	}

	if (hWnd && !DestroyWindow(hWnd))					// Are We Able To Destroy The Window?
	{
		MessageBox(NULL,"Could Not Release hWnd.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		hWnd=NULL;										// Set hWnd To NULL
	}

	if (!UnregisterClass("OpenGL",hInstance))			// Are We Able To Unregister Class
	{
		MessageBox(NULL,"Could Not Unregister Class.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		hInstance=NULL;									// Set hInstance To NULL
	}
}

/*	This Code Creates Our OpenGL Window.  Parameters Are:					*
 *	title			- Title To Appear At The Top Of The Window				*
 *	width			- Width Of The GL Window Or Fullscreen Mode				*
 *	height			- Height Of The GL Window Or Fullscreen Mode			*
 *	bits			- Number Of Bits To Use For Color (8/16/24/32)			*
 *	fullscreenflag	- Use Fullscreen Mode (TRUE) Or Windowed Mode (FALSE)	*/
 
BOOL CreateGLWindow(char* title, int width, int height, int bits, bool fullscreenflag)
{
	GLuint		PixelFormat;			// Holds The Results After Searching For A Match
	WNDCLASS	wc;						// Windows Class Structure
	DWORD		dwExStyle;				// Window Extended Style
	DWORD		dwStyle;				// Window Style
	RECT		WindowRect;				// Grabs Rectangle Upper Left / Lower Right Values
	WindowRect.left=(long)0;			// Set Left Value To 0
	WindowRect.right=(long)width;		// Set Right Value To Requested Width
	WindowRect.top=(long)0;				// Set Top Value To 0
	WindowRect.bottom=(long)height;		// Set Bottom Value To Requested Height

	fullscreen=fullscreenflag;			// Set The Global Fullscreen Flag

	hInstance			= GetModuleHandle(NULL);				// Grab An Instance For Our Window
	wc.style			= CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	// Redraw On Size, And Own DC For Window.
	wc.lpfnWndProc		= (WNDPROC) WndProc;					// WndProc Handles Messages
	wc.cbClsExtra		= 0;									// No Extra Window Data
	wc.cbWndExtra		= 0;									// No Extra Window Data
	wc.hInstance		= hInstance;							// Set The Instance
	wc.hIcon			= LoadIcon(NULL, IDI_WINLOGO);			// Load The Default Icon
	wc.hCursor			= LoadCursor(NULL, IDC_ARROW);			// Load The Arrow Pointer
	wc.hbrBackground	= NULL;									// No Background Required For GL
	wc.lpszMenuName		= NULL;									// We Don't Want A Menu
	wc.lpszClassName	= "OpenGL";								// Set The Class Name

	if (!RegisterClass(&wc))									// Attempt To Register The Window Class
	{
		MessageBox(NULL,"Failed To Register The Window Class.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;											// Return FALSE
	}
	
	if (fullscreen)												// Attempt Fullscreen Mode?
	{
		DEVMODE dmScreenSettings;								// Device Mode
		memset(&dmScreenSettings,0,sizeof(dmScreenSettings));	// Makes Sure Memory's Cleared
		dmScreenSettings.dmSize=sizeof(dmScreenSettings);		// Size Of The Devmode Structure
		dmScreenSettings.dmPelsWidth	= width;				// Selected Screen Width
		dmScreenSettings.dmPelsHeight	= height;				// Selected Screen Height
		dmScreenSettings.dmBitsPerPel	= bits;					// Selected Bits Per Pixel
		dmScreenSettings.dmFields=DM_BITSPERPEL|DM_PELSWIDTH|DM_PELSHEIGHT;

		// Try To Set Selected Mode And Get Results.  NOTE: CDS_FULLSCREEN Gets Rid Of Start Bar.
		if (ChangeDisplaySettings(&dmScreenSettings,CDS_FULLSCREEN)!=DISP_CHANGE_SUCCESSFUL)
		{
			// If The Mode Fails, Offer Two Options.  Quit Or Use Windowed Mode.
			if (MessageBox(NULL,"The Requested Fullscreen Mode Is Not Supported By\nYour Video Card. Use Windowed Mode Instead?","NeHe GL",MB_YESNO|MB_ICONEXCLAMATION)==IDYES)
			{
				fullscreen=FALSE;		// Windowed Mode Selected.  Fullscreen = FALSE
			}
			else
			{
				// Pop Up A Message Box Letting User Know The Program Is Closing.
				MessageBox(NULL,"Program Will Now Close.","ERROR",MB_OK|MB_ICONSTOP);
				return FALSE;									// Return FALSE
			}
		}
	}

	if (fullscreen)												// Are We Still In Fullscreen Mode?
	{
		dwExStyle=WS_EX_APPWINDOW;								// Window Extended Style
		dwStyle=WS_POPUP;										// Windows Style
		ShowCursor(FALSE);										// Hide Mouse Pointer
	}
	else
	{
		dwExStyle=WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;			// Window Extended Style
		dwStyle=WS_OVERLAPPEDWINDOW;							// Windows Style
	}

	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle);		// Adjust Window To True Requested Size

	// Create The Window
	if (!(hWnd=CreateWindowEx(	dwExStyle,							// Extended Style For The Window
								"OpenGL",							// Class Name
								title,								// Window Title
								dwStyle |							// Defined Window Style
								WS_CLIPSIBLINGS |					// Required Window Style
								WS_CLIPCHILDREN,					// Required Window Style
								0, 0,								// Window Position
								WindowRect.right-WindowRect.left,	// Calculate Window Width
								WindowRect.bottom-WindowRect.top,	// Calculate Window Height
								NULL,								// No Parent Window
								NULL,								// No Menu
								hInstance,							// Instance
								NULL)))								// Dont Pass Anything To WM_CREATE
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Window Creation Error.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	static	PIXELFORMATDESCRIPTOR pfd=				// pfd Tells Windows How We Want Things To Be
	{
		sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
		1,											// Version Number
		PFD_DRAW_TO_WINDOW |						// Format Must Support Window
		PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
		PFD_DOUBLEBUFFER,							// Must Support Double Buffering
		PFD_TYPE_RGBA,								// Request An RGBA Format
		bits,										// Select Our Color Depth
		0, 0, 0, 0, 0, 0,							// Color Bits Ignored
		0,											// No Alpha Buffer
		0,											// Shift Bit Ignored
		0,											// No Accumulation Buffer
		0, 0, 0, 0,									// Accumulation Bits Ignored
		16,											// 16Bit Z-Buffer (Depth Buffer)  
		0,											// No Stencil Buffer
		0,											// No Auxiliary Buffer
		PFD_MAIN_PLANE,								// Main Drawing Layer
		0,											// Reserved
		0, 0, 0										// Layer Masks Ignored
	};
	
	if (!(hDC=GetDC(hWnd)))							// Did We Get A Device Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Create A GL Device Context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(PixelFormat=ChoosePixelFormat(hDC,&pfd)))	// Did Windows Find A Matching Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Find A Suitable PixelFormat.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if(!SetPixelFormat(hDC,PixelFormat,&pfd))		// Are We Able To Set The Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Set The PixelFormat.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(hRC=wglCreateContext(hDC)))				// Are We Able To Get A Rendering Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Create A GL Rendering Context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if(!wglMakeCurrent(hDC,hRC))					// Try To Activate The Rendering Context
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Activate The GL Rendering Context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	ShowWindow(hWnd,SW_SHOW);						// Show The Window
	SetForegroundWindow(hWnd);						// Slightly Higher Priority
	SetFocus(hWnd);									// Sets Keyboard Focus To The Window
	ReSizeGLScene(width, height);					// Set Up Our Perspective GL Screen

	if (!InitGL())									// Initialize Our Newly Created GL Window
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Initialization Failed.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	return TRUE;									// Success
}

LRESULT CALLBACK WndProc(	HWND	hWnd,			// Handle For This Window
							UINT	uMsg,			// Message For This Window
							WPARAM	wParam,			// Additional Message Information
							LPARAM	lParam)			// Additional Message Information
{
	switch (uMsg)									// Check For Windows Messages
	{
		case WM_MOUSEMOVE:
			mouseX = (float)LOWORD(lParam);
			mouseY = (float)HIWORD(lParam);
			break;
		case WM_LBUTTONDOWN:
			isClicked = true;
			break;
		case WM_LBUTTONUP:
			isClicked = false;
			break;

		case WM_RBUTTONUP:
		    isRClicked = false;   break;
		case WM_RBUTTONDOWN:
		    isRClicked = true;  break;
		case WM_ACTIVATE:							// Watch For Window Activate Message
		{
			if (!HIWORD(wParam))					// Check Minimization State
			{
				active=TRUE;						// Program Is Active
			}
			else
			{
				active=FALSE;						// Program Is No Longer Active
			}

			return 0;								// Return To The Message Loop
		}

		case WM_SYSCOMMAND:
		{
			switch (wParam)
			{
				case SC_SCREENSAVE:
				case SC_MONITORPOWER:
					return 0;
			}
			break;
		}

		case WM_CLOSE:								// Did We Receive A Close Message?
		{
			PostQuitMessage(0);						// Send A Quit Message
			return 0;								// Jump Back
		}

		case WM_KEYDOWN:							// Is A Key Being Held Down?
		{
			keys[wParam] = TRUE;					// If So, Mark It As TRUE
			return 0;								// Jump Back
		}

		case WM_KEYUP:								// Has A Key Been Released?
		{
			keys[wParam] = FALSE;					// If So, Mark It As FALSE
			return 0;								// Jump Back
		}

		case WM_SIZE:								// Resize The OpenGL Window
		{
			ReSizeGLScene(LOWORD(lParam),HIWORD(lParam));  // LoWord=Width, HiWord=Height
			return 0;								// Jump Back
		}
	}

	// Pass All Unhandled Messages To DefWindowProc
	return DefWindowProc(hWnd,uMsg,wParam,lParam);
}

int WINAPI WinMain(	HINSTANCE	hInstance,			// Instance
					HINSTANCE	hPrevInstance,		// Previous Instance
					LPSTR		lpCmdLine,			// Command Line Parameters
					int			nCmdShow)			// Window Show State
{
	MSG		msg;									// Windows Message Structure
	BOOL	done=FALSE;								// Bool Variable To Exit Loop

	// Ask The User Which Screen Mode They Prefer
	if (MessageBox(NULL,"Would You Like To Run In Fullscreen Mode?", "Start FullScreen?",MB_YESNO|MB_ICONQUESTION)==IDNO)
	{
		fullscreen=FALSE;							// Windowed Mode
	}
	
	// Create Our OpenGL Window
	if (!CreateGLWindow("Mall",640,480,16,fullscreen))
	{
		return 0;									// Quit If Window Was Not Created
	}

	
	
				
	while(!done)									// Loop That Runs While done=FALSE
	{
		if (PeekMessage(&msg,NULL,0,0,PM_REMOVE))	// Is There A Message Waiting?
		{
			if (msg.message==WM_QUIT)				// Have We Received A Quit Message?
			{
				done=TRUE;							// If So done=TRUE
			}
			else									// If Not, Deal With Window Messages
			{
				TranslateMessage(&msg);				// Translate The Message
				DispatchMessage(&msg);				// Dispatch The Message
			}
		}
		else										// If There Are No Messages
		{
			// Draw The Scene.  Watch For ESC Key And Quit Messages From DrawGLScene()
			if ((active && !DrawGLScene()) || keys[VK_ESCAPE])	// Active?  Was There A Quit Received?
			{
				done=TRUE;							// ESC or DrawGLScene Signalled A Quit
			}
			else									// Not Time To Quit, Update Screen
			{
				SwapBuffers(hDC);					// Swap Buffers (Double Buffering)
			}
			if (keys['E'])						// Is E Being Pressed?
			{
				anglex+=0.5f;
			}
			if (keys['C'])						// Is C Being Pressed?
			{
				anglex-=0.5f;
			}
			if (keys['R'])						// Is R Being Pressed?
			{
				angley+=0.5f;
			}
			if (keys[VK_SHIFT]&&keys['R'])						// Is R shift Being Pressed?
			{
				angley+=1.0f;
			}
			if (keys['Q'])						// Is Q Being Pressed?
			{
				angley-=0.5f;
			}
			if (keys[VK_SHIFT]&&keys['Q'])						// Is Q shift Being Pressed?
			{
				angley-=1.0f;
			}
			if (keys['T'])						// Is T Being Pressed?
			{
				anglez+=0.5f;
			}
			if (keys['V'])						// Is V Being Pressed?
			{
				anglez-=0.5f;
			}
			if (keys['A'])						// Is A Being Pressed?
			{
				xAxis+=1.5f;
			}
			if (keys['D'])						// Is D Being Pressed?
			{
				xAxis-=1.5f;
			}
			if (keys['W'])						// Is W Being Pressed?
			{
				yAxis-=1.5f;
			}
			if (keys['S'])						// Is S Being Pressed?
			{
				yAxis+=1.5f;
			}
			if (keys['Z'])						// Is Z Being Pressed?
			{
				zoom+=1.5f;
			}
			if (keys[VK_SHIFT]&&keys['Z'])						// Is Z Being Pressed?
			{
				zoom+=2.7f;
			}
			if (keys['X'])						// Is X Being Pressed?
			{
				zoom-=1.5f;
			}
			if (keys[VK_SHIFT]&&keys['X'])						// Is X Being Pressed?
			{
				zoom-=2.7f;
			}
			if (keys['F'])						// Is F Being Pressed?
			{
				yAxis = 50;
				anglex = 45;
				zoom = -50;
			}
			if (keys['G'])						// Is G Being Pressed?
			{
				yAxis = 150;
				anglex = 0;
				zoom = -100;
			}
			if (keys['N'])						// Is N Being Pressed?
			{
				isDayTime = false;
				glEnable(GL_LIGHTING);
				glEnable(GL_LIGHT_MODEL_AMBIENT);
				glEnable(GL_AMBIENT);
				glEnable(GL_DIFFUSE);
				glEnable(GL_LIGHT1);
				glEnable(GL_SHADE_MODEL);
			}
			if (keys['M'])						// Is M Being Pressed?
			{
				isDayTime = true;
				glDisable(GL_LIGHTING);
				glDisable(GL_LIGHT_MODEL_AMBIENT);
				glDisable(GL_AMBIENT);
				glDisable(GL_DIFFUSE);
				glDisable(GL_LIGHT1);
				glDisable(GL_SHADE_MODEL);
			}

			if (keys['P'])
			{
				if ( r_translateX < 750 ){
					doorOpen = true;
					l_translateX -= 3;
					r_translateX += 3;
				}
			}

			if (keys['O'])
			{
				if ( r_translateX > 283 ){
					doorOpen = false;
					l_translateX += 3;
					r_translateX -= 3;
				}
			}

			
			if (keys[VK_F1])						// Is F1 Being Pressed?
			{
				keys[VK_F1]=FALSE;					// If So Make Key FALSE
				KillGLWindow();						// Kill Our Current Window
				fullscreen=!fullscreen;				// Toggle Fullscreen / Windowed Mode
				// Recreate Our OpenGL Window
				if (!CreateGLWindow("Mall",1920,1080,1024,fullscreen))
				{
					return 0;						// Quit If Window Was Not Created
				}
			}
		}
	}
	

	// Shutdown
	KillGLWindow();									// Kill The Window
	return (msg.wParam);							// Exit The Program
}

