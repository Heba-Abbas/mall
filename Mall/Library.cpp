#include "Library.h"

// Constructor
Library::Library(GLuint libraryfloor, GLuint libraryroof, GLuint librarywalls, GLuint columnTexMake,GLuint columnTex, GLuint shelfTex, GLuint shelfTexMake,GLuint frontTextureL1,
        GLuint makeup1, GLuint makeup2, GLuint makeup3, GLuint frontTextureL2, GLuint frontTextureL3, GLuint frontTextureL4,
        GLuint backTexture, GLuint topTexture, GLuint bottomTexture, GLuint rightTexture, GLuint leftTexture,
		GLuint book1,GLuint book2,GLuint book3,GLuint book4,GLuint book5,GLuint book6,GLuint book7,GLuint book8,GLuint book9,GLuint book10,GLuint book11,GLuint book12,GLuint book13,GLuint book14,GLuint book15,GLuint book16,GLuint book17,GLuint book18,GLuint book19,GLuint book20,GLuint book21,GLuint book22
        ,GLuint picture1, GLuint darkWood, GLuint chairTex, GLuint frontTex, GLuint backTex, GLuint topTex, GLuint bottomTex, GLuint rightTex, GLuint leftTex
    ) {
    this->libraryfloor = libraryfloor;
    this->libraryroof = libraryroof;
    this->librarywalls = librarywalls;
    this->columnTexMake = columnTexMake;
    this->shelfTex = shelfTex;
    this->shelfTexMake = shelfTexMake;
	this ->columnTex =columnTex;
    this->book1 = book1;
    this->book2 = book2;
    this->book3 = book3;
	this->book4 = book4;
	this->book5 = book5;
	this->book6 = book6;
	this->book7 = book7;
	this->book8 = book8;
	this->book9 = book9;
	this->book10 = book10;
	this->book11 = book11;
	this->book12 = book12;
	this->book13 = book13;
	this->book14 = book14;
	this->book15 = book15;
	this->book16 = book16;
	this->book17 = book17;
	this->book18 = book18;
	this->book19 = book19;
	this->book20 = book20;
	this->book21 = book21;
	this->book22 = book22;
    this->frontTextureL2 = frontTextureL2;
    this->frontTextureL3 = frontTextureL3;
    this->frontTextureL4 = frontTextureL4;
    this->backTexture = backTexture;
    this->topTexture = topTexture;
    this->bottomTexture = bottomTexture;
    this->rightTexture = rightTexture;
    this->leftTexture = leftTexture;
    this->picture1 = picture1;
    this->darkWood = darkWood;
    this->chairTex = chairTex;
    this->frontTex = frontTex;
    this->backTex = backTex;
    this->topTex = topTex;
    this->bottomTex = bottomTex;
    this->rightTex = rightTex;
    this->leftTex = leftTex;
}

// Function to draw the lib
void Library::drawBookStore() {
    // Draw the floor
    glPushMatrix();
    glTranslatef(0.0, 50.0, 0);
    glBindTexture(GL_TEXTURE_2D, libraryfloor);
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
    glBindTexture(GL_TEXTURE_2D, libraryroof);
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
    glBindTexture(GL_TEXTURE_2D, librarywalls);
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
    glBindTexture(GL_TEXTURE_2D, librarywalls);
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
    glBindTexture(GL_TEXTURE_2D, librarywalls);
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
	 
	float cubeWidth = 50.0f;  
    float cubeHeight = 70.0f; 
    float cubeDepth = 10.0f;  

	
	//draw the shelves on the left wall
	for (int i = 0; i < 2; ++i) {
    float columnZ = 600.0f - i * columnSpacing;

    // columns
    glPushMatrix();
    glTranslatef(-800.0f + columnWidth / 2, columnHeight / 2 - 600.0f, columnZ - 700);
    glBindTexture(GL_TEXTURE_2D, columnTexMake);
    Cube column(columnWidth, columnHeight, columnDepth, columnTex, columnTex, columnTex, columnTex, columnTex, columnTex, false);
    column.draw();
    glPopMatrix();

    // shelves
    if (i < 1) {
        float startZ = columnZ - columnSpacing / 2 + columnDepth / 2;
        float endZ = startZ + columnSpacing - columnDepth;
        float shelfCenterZ = (startZ + endZ) / 2;

        for (int j = 0; j < numShelves; ++j) {
            float yOffset = j * (shelfHeight + spacing);

            
            glPushMatrix();
            glTranslatef(-800.0f + shelfDepth / 2, -400.0f + shelfHeight / 2 + yOffset - 300, shelfCenterZ - 950);
            glBindTexture(GL_TEXTURE_2D, shelfTex);
            Cube shelf(shelfDepth, shelfHeight, shelfWidth, shelfTexMake, shelfTexMake, shelfTexMake, shelfTexMake, shelfTexMake, shelfTexMake, false);
            shelf.draw();
            glPopMatrix();

           
            int numCubes = 3;
            int textureOffset = j * numCubes;
            unsigned int cubeTextures[] = {book1, book2, book3, book4, book5, book6, book7, book8, book9, book10, book11, book12, book13, book14, book15, book16, book17, book18, book19, book20, book21, book22};
            size_t numTextures = sizeof(cubeTextures) / sizeof(cubeTextures[0]);
            float cubeSpacing = 100.0f; 

            for (int k = 0; k < numCubes; ++k) {
                float cubeZ = shelfCenterZ - shelfWidth / 2 + k * (cubeDepth + cubeSpacing) ;

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


float width = 600.0f / 2.0f;  
float height = 700.0f / 2.0f; 
float depth = 110.0f / 2.0f;  


//placard1
Cube rectangle2(width, height, depth, frontTextureL1, backTexture, topTexture, bottomTexture, rightTexture, leftTexture, false);

glPushMatrix();
glTranslatef(-700.0f + columnWidth / 2, columnHeight / 2 - 600.0f, 300);
glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
rectangle2.draw();
glPopMatrix();

//placard2
Cube rectangle3(width, height, depth, frontTextureL2, backTexture, topTexture, bottomTexture, rightTexture, leftTexture, false);

glPushMatrix();
glTranslatef(500.0f + columnWidth / 2, columnHeight / 2 - 600.0f, -800);
rectangle3.draw();
glPopMatrix();

//placard3
Cube rectangle4(width, height, depth, frontTextureL3, backTexture, topTexture, bottomTexture, rightTexture, leftTexture, false);

glPushMatrix();
glTranslatef(-500.0f + columnWidth / 2, columnHeight / 2 - 600.0f, -800);
rectangle4.draw();
glPopMatrix();

//placard4
Cube rectangle5(width, height-150, depth, frontTextureL4, backTexture, topTexture, bottomTexture, rightTexture, leftTexture, false);

glPushMatrix();
glTranslatef(750.0f + columnWidth / 2, columnHeight / 2 - 750.0f, -300);
glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
rectangle5.draw();
glPopMatrix();

glPushMatrix();
	glTranslatef(-5.0, -180.0, -300);
	glScalef(1.0, 0.2, 0.5);
	glBindTexture(GL_TEXTURE_2D, picture1);
	glBegin(GL_QUADS);
        // Right wall art0
		//glColor4f(0.4f, 0.1f, 0.6f, 0.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(853,  450,  360);//x, y, z
		glTexCoord2f(1.0f, 1.0f); glVertex3f(853,  450, -360);//x, y, -z
        glTexCoord2f(1.0f, 0.0f); glVertex3f(853, -450, -360);//x, -y, -z
        glTexCoord2f(0.0f, 0.0f); glVertex3f(853, -450,  360);//x, -y, z
	glEnd();
	glPopMatrix();

	//2 tables and chairs
	// all the tables
	glPushMatrix();
	glTranslatef(0.0, -700.0, 0);


	//table1
	glPushMatrix();
	
	glTranslatef(-350.0f, 0.0f, -350.0f);

	glPushMatrix();
	glTranslatef(5.0f, 0.0f, 0.0f);
	Cachier table1(100, 100, 7.0, 10, 50, darkWood);
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



	//table and chair /cachier
	glPushMatrix();
	glTranslatef(450.0, -600.0, 700);
	glScaled(1,2,1.5);
	glRotated(-90,0,1,0);
	Cachier table4(100, 100, 7.0, 10, 50, darkWood);
	table4.draw();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(700.0f, -730.0f, 700.0f);
	glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
	Chair chair5(45.0f, 45.0f, 7.0f, 5.0f, 35.0f, 60.0f, 5.0f, chairTex, darkWood);
	glScaled(1.2,2,1.2);
	chair5.draw();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(450.0, -550.0, 700); 
	glScalef(0.7, 0.5, 0.7); 
	Cube cube(50.0f, 50.0f, 50.0f, frontTex, backTex, topTex, bottomTex, rightTex, leftTex, false);
	cube.draw();
	glPopMatrix();


}