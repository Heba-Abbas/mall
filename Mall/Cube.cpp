#include "Cube.h"
#include "Texture.h"
#include <gl.h>
#include <glu.h>
#include <glut.h>

Cube::Cube(float edgeSizeWidth, float edgeSizeHeight, float edgeSizeDepth, int front, int back, int top, int bottom, int right, int left, bool hasRoof): 
	edgeSizeWidth(edgeSizeWidth), edgeSizeHeight(edgeSizeHeight), edgeSizeDepth(edgeSizeDepth), 
	frontTex(front), backTex(back), topTex(top), bottomTex(bottom), rightTex(right), leftTex(left) , hasRoof(hasRoof)
{
    // Constructor implementation (if needed)
}

Cube::~Cube() {
    // Destructor implementation (if needed)
}

void Cube::draw() {
	//Texture texture1("res/textures/gray.png", true);  // Non-transparent texture
	//Texture texture2("res/texture/gray.png", true);
	
	glBindTexture(GL_TEXTURE_2D, frontTex);
    glBegin(GL_QUADS);
    // Front face

	//texture1.bind(GL_TEXTURE0);

		//glColor4f(0.7f, 0.2f, 0.3f, 0.0f);
         glTexCoord2f(0.0f, 0.0f); glVertex3f(-edgeSizeWidth, -edgeSizeHeight, edgeSizeDepth);//-x, -y, z
         glTexCoord2f(1.0f, 0.0f); glVertex3f(edgeSizeWidth,  -edgeSizeHeight, edgeSizeDepth);//x, -y, z
         glTexCoord2f(1.0f, 1.0f); glVertex3f(edgeSizeWidth,   edgeSizeHeight, edgeSizeDepth);//x, y, z
         glTexCoord2f(0.0f, 1.0f); glVertex3f(-edgeSizeWidth,  edgeSizeHeight, edgeSizeDepth);//-x, y, z
    glEnd();

	
	glBindTexture(GL_TEXTURE_2D, backTex);
	glBegin(GL_QUADS);
        // Back face
		//glColor4f(0.3f, 0.4f, 0.6f, 0.0f);
	
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-edgeSizeWidth, -edgeSizeHeight, -edgeSizeDepth);//-x, -y, -z
        glTexCoord2f(1.0f, 0.0f); glVertex3f(edgeSizeWidth,  -edgeSizeHeight, -edgeSizeDepth);//x, -y, -z
        glTexCoord2f(1.0f, 1.0f); glVertex3f(edgeSizeWidth,   edgeSizeHeight, -edgeSizeDepth);//x, y, -z
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-edgeSizeWidth,  edgeSizeHeight, -edgeSizeDepth);//-x, y, -z
    glEnd();

	
	glBindTexture(GL_TEXTURE_2D, topTex);

	glBegin(GL_QUADS);
        // Top face
		//glColor4f(0.2f, 0.8f, 0.5f, 0.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-edgeSizeWidth, edgeSizeHeight, -edgeSizeDepth);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-edgeSizeWidth, edgeSizeHeight,  edgeSizeDepth);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(edgeSizeWidth,  edgeSizeHeight,  edgeSizeDepth);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(edgeSizeWidth,  edgeSizeHeight, -edgeSizeDepth);
    glEnd();

	
	glBindTexture(GL_TEXTURE_2D, bottomTex);
	glBegin(GL_QUADS);
        // Bottom face
		//glColor4f(0.3f, 0.5f, 0.1f, 0.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-edgeSizeWidth, -edgeSizeHeight, -edgeSizeDepth);//-x, -y, -z
        glTexCoord2f(1.0f, 0.0f); glVertex3f(edgeSizeWidth,  -edgeSizeHeight, -edgeSizeDepth);//x, -y, -z
        glTexCoord2f(1.0f, 1.0f); glVertex3f(edgeSizeWidth,  -edgeSizeHeight,  edgeSizeDepth);//x, -y, z
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-edgeSizeWidth, -edgeSizeHeight,  edgeSizeDepth);//-x, -y, z

    glEnd();

	
	glBindTexture(GL_TEXTURE_2D, rightTex);
	glBegin(GL_QUADS);
        // Right face
		//glColor4f(0.4f, 0.1f, 0.6f, 0.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(edgeSizeWidth,  edgeSizeHeight,  edgeSizeDepth);//x, y, z
		glTexCoord2f(1.0f, 1.0f); glVertex3f(edgeSizeWidth,  edgeSizeHeight, -edgeSizeDepth);//x, y, -z
        glTexCoord2f(1.0f, 0.0f); glVertex3f(edgeSizeWidth, -edgeSizeHeight, -edgeSizeDepth);//x, -y, -z
        glTexCoord2f(0.0f, 0.0f); glVertex3f(edgeSizeWidth, -edgeSizeHeight,  edgeSizeDepth);//x, -y, z

	glEnd();

	
	glBindTexture(GL_TEXTURE_2D, leftTex);
	glBegin(GL_QUADS);
        // Left face
		//glColor4f(0.1f, 0.3f, 0.5f, 0.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-edgeSizeWidth,  edgeSizeHeight, -edgeSizeDepth);//-x, y, -z
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-edgeSizeWidth,  edgeSizeHeight,  edgeSizeDepth);//-x, y, z
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-edgeSizeWidth, -edgeSizeHeight,  edgeSizeDepth);//-x, -y, z
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-edgeSizeWidth, -edgeSizeHeight, -edgeSizeDepth);//-x, -y, -z
        
        
        

    glEnd();

	if (hasRoof) {
        glBindTexture(GL_TEXTURE_2D, topTex);
        
        // First trapezoidal face
        glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-edgeSizeWidth, edgeSizeHeight, edgeSizeDepth);
    glTexCoord2f(2.0f, 0.0f); glVertex3f(-edgeSizeWidth, edgeSizeHeight, -edgeSizeDepth);
    glTexCoord2f(2.0f - 0.2f, 2.0f); glVertex3f(0.0f, edgeSizeHeight*2 - 0.2*edgeSizeHeight, -edgeSizeDepth + 0.2*edgeSizeDepth);
    glTexCoord2f(0.2f, 2.0f); glVertex3f(0.0f, edgeSizeHeight*2 - 0.2*edgeSizeHeight, edgeSizeDepth - 0.2*edgeSizeDepth);
glEnd();

		
        glBindTexture(GL_TEXTURE_2D, topTex);
        // Second trapezoidal face
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 0.0f);  glVertex3f(edgeSizeWidth, edgeSizeHeight, edgeSizeDepth);
            glTexCoord2f(2.0f, 0.0f);  glVertex3f(edgeSizeWidth, edgeSizeHeight, -edgeSizeDepth);
			glTexCoord2f(2.0f - 0.2f, 2.0f);  glVertex3f(0.0f, edgeSizeHeight*2 - 0.2*edgeSizeHeight, -edgeSizeDepth + 0.2*edgeSizeDepth);
			glTexCoord2f(0.2f, 2.0f);  glVertex3f(0.0f, edgeSizeHeight*2 - 0.2*edgeSizeHeight, edgeSizeDepth - 0.2*edgeSizeDepth );
        glEnd();

		
        glBindTexture(GL_TEXTURE_2D, topTex);
        // First triangular face
        glBegin(GL_TRIANGLES);
            glTexCoord2f(0.0f, 0.0f); glVertex3f(-edgeSizeWidth, edgeSizeHeight, edgeSizeDepth);
            glTexCoord2f(2.0f, 0.0f); glVertex3f(edgeSizeWidth, edgeSizeHeight, edgeSizeDepth);
			glTexCoord2f(1.0f, 2.0f); glVertex3f(0.0f, edgeSizeHeight*2 - 0.2*edgeSizeHeight, edgeSizeDepth - 0.2*edgeSizeDepth);
        glEnd();

		
        glBindTexture(GL_TEXTURE_2D, topTex);
        // Second triangular face
        glBegin(GL_TRIANGLES);
            glTexCoord2f(0.0f, 0.0f); glVertex3f(-edgeSizeWidth, edgeSizeHeight, -edgeSizeDepth);
            glTexCoord2f(2.0f, 0.0f); glVertex3f(edgeSizeWidth, edgeSizeHeight, -edgeSizeDepth);
			glTexCoord2f(1.0f, 2.0f); glVertex3f(0.0f, edgeSizeHeight*2 - 0.2*edgeSizeHeight, -edgeSizeDepth + 0.2*edgeSizeDepth);
        glEnd();
    }

}

void Cube::drawSkyBox() {
	glPushMatrix();
    glCullFace(GL_FRONT);  // Cull front faces

    glBindTexture(GL_TEXTURE_2D, frontTex);
    glBegin(GL_QUADS);
    // Front face

	//texture1.bind(GL_TEXTURE0);

		//glColor4f(0.7f, 0.2f, 0.3f, 0.0f);
         glTexCoord2f(0.0f, 0.0f); glVertex3f(-edgeSizeWidth, -edgeSizeHeight, edgeSizeDepth);//-x, -y, z
         glTexCoord2f(1.0f, 0.0f); glVertex3f(edgeSizeWidth,  -edgeSizeHeight, edgeSizeDepth);//x, -y, z
         glTexCoord2f(1.0f, 1.0f); glVertex3f(edgeSizeWidth,   edgeSizeHeight, edgeSizeDepth);//x, y, z
         glTexCoord2f(0.0f, 1.0f); glVertex3f(-edgeSizeWidth,  edgeSizeHeight, edgeSizeDepth);//-x, y, z
    glEnd();

	
	glBindTexture(GL_TEXTURE_2D, backTex);
	glBegin(GL_QUADS);
        // Back face
		//glColor4f(0.3f, 0.4f, 0.6f, 0.0f);
	
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-edgeSizeWidth, -edgeSizeHeight, -edgeSizeDepth);//-x, -y, -z
        glTexCoord2f(0.0f, 0.0f); glVertex3f(edgeSizeWidth,  -edgeSizeHeight, -edgeSizeDepth);//x, -y, -z
        glTexCoord2f(0.0f, 1.0f); glVertex3f(edgeSizeWidth,   edgeSizeHeight, -edgeSizeDepth);//x, y, -z
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-edgeSizeWidth,  edgeSizeHeight, -edgeSizeDepth);//-x, y, -z
    glEnd();

	
	glBindTexture(GL_TEXTURE_2D, topTex);

	glBegin(GL_QUADS);
        // Top face
		//glColor4f(0.2f, 0.8f, 0.5f, 0.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-edgeSizeWidth, edgeSizeHeight, -edgeSizeDepth);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-edgeSizeWidth, edgeSizeHeight,  edgeSizeDepth);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(edgeSizeWidth,  edgeSizeHeight,  edgeSizeDepth);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(edgeSizeWidth,  edgeSizeHeight, -edgeSizeDepth);
    glEnd();

	
	glBindTexture(GL_TEXTURE_2D, bottomTex);
	glBegin(GL_QUADS);
        // Bottom face
		//glColor4f(0.3f, 0.5f, 0.1f, 0.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-edgeSizeWidth, -edgeSizeHeight, -edgeSizeDepth);//-x, -y, -z
        glTexCoord2f(1.0f, 0.0f); glVertex3f(edgeSizeWidth,  -edgeSizeHeight, -edgeSizeDepth);//x, -y, -z
        glTexCoord2f(1.0f, 1.0f); glVertex3f(edgeSizeWidth,  -edgeSizeHeight,  edgeSizeDepth);//x, -y, z
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-edgeSizeWidth, -edgeSizeHeight,  edgeSizeDepth);//-x, -y, z

    glEnd();

	
	glBindTexture(GL_TEXTURE_2D, rightTex);
	glBegin(GL_QUADS);
        // Right face
		//glColor4f(0.4f, 0.1f, 0.6f, 0.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(edgeSizeWidth,  edgeSizeHeight,  edgeSizeDepth);//x, y, z
		glTexCoord2f(1.0f, 1.0f); glVertex3f(edgeSizeWidth,  edgeSizeHeight, -edgeSizeDepth);//x, y, -z
        glTexCoord2f(1.0f, 0.0f); glVertex3f(edgeSizeWidth, -edgeSizeHeight, -edgeSizeDepth);//x, -y, -z
        glTexCoord2f(0.0f, 0.0f); glVertex3f(edgeSizeWidth, -edgeSizeHeight,  edgeSizeDepth);//x, -y, z

	glEnd();

	
	glBindTexture(GL_TEXTURE_2D, leftTex);
	glBegin(GL_QUADS);
        // Left face
		//glColor4f(0.1f, 0.3f, 0.5f, 0.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-edgeSizeWidth,  edgeSizeHeight, -edgeSizeDepth);//-x, y, -z
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-edgeSizeWidth,  edgeSizeHeight,  edgeSizeDepth);//-x, y, z
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-edgeSizeWidth, -edgeSizeHeight,  edgeSizeDepth);//-x, -y, z
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-edgeSizeWidth, -edgeSizeHeight, -edgeSizeDepth);//-x, -y, -z
        
        
        

    glEnd();

    glCullFace(GL_BACK);  // Switch back to culling back faces
	glPopMatrix();
}

//void Cube::drawTable(){
//	Glunit tableTex;
//}
//
//void Cube::drawGate(){
//	GLuint topOfGateTex, mainGateTex, transparentTex, leftColumnTex, rightColumnTex, sideOfTopOfGateTex, sideOfColumnTex, beigeTex;
//	topOfGateTex = loadGltexture("res/textures/topOfGate.png");
//        mainGateTex = loadGltexture("res/textures/mainGate.png");
//        transparentTex = loadGltexture("res/textures/transparent.png");
//        sideOfTopOfGateTex = loadGltexture("res/textures/sideTopOfGate.png");
//        leftColumnTex = loadGltexture("res/textures/leftColumn.png");
//        rightColumnTex = loadGltexture("res/textures/rightColumn.png");
//        sideOfColumnTex = loadGltexture("res/textures/sideOfColumn.png");
//        beigeTex = loadGltexture("res/textures/beige.png");
//
//		Cube topOfThreeGate(2.0f, 1.0f, 0.5f, topOfGateTex, topOfGateTex, beigeTex, transparentTex, sideOfTopOfGateTex, sideOfTopOfGateTex, false);
//        topOfThreeGate.draw();
//
//        glPushMatrix();
//        glTranslatef(0.9f, -1.5f, 0.0f);
//        Cube rightColumnOfThreeGate(0.5f, 1.5f, 0.5f, rightColumnTex, sideOfColumnTex, beigeTex, beigeTex, sideOfColumnTex, sideOfColumnTex, false);
//        rightColumnOfThreeGate.draw();
//        glPopMatrix();
//
//        glPushMatrix();
//        glTranslatef(-0.9f, -2.0f, 0.0f);
//        Cube leftColumnOfThreeGate(0.5f, 1.5f, 0.5f, leftColumnTex, sideOfColumnTex, beigeTex, beigeTex, sideOfColumnTex, sideOfColumnTex, false);
//        leftColumnOfThreeGate.draw();
//        glPopMatrix();
//
//}
