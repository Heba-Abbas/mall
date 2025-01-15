#ifndef TREE_H  //AHMAD AL HATI
#define TREE_H

#include "Cylinder.h"
#include "Cube.h"
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library

class tree{

public:
	GLuint treeLeaves, treeTrunk;

	tree(int treeLeaves, int treeTrunk){
		this->treeLeaves = treeLeaves;
		this->treeTrunk = treeTrunk;
	}

	void tree::drawTree1(){

		glPushMatrix();

		Cylinder trunk(0.2f, 4.5f, 15, treeTrunk, treeTrunk, treeTrunk);
		trunk.drawWithCone();

		glTranslatef(0.0f, 7.0f, 0.0f);
		
		Cube leaves1(0.0f, 7.0f, 6.0f, treeLeaves, treeLeaves, treeLeaves, treeLeaves, treeLeaves, treeLeaves, false);
		leaves1.draw();

		glRotatef(20, 0.0f, 1.0f, 0.0f);
		leaves1.draw();

		glRotatef(20, 0.0f, 1.0f, 0.0f);
		leaves1.draw();

		glRotatef(20, 0.0f, 1.0f, 0.0f);
		leaves1.draw();

		glRotatef(20, 0.0f, 1.0f, 0.0f);
		leaves1.draw();

		glRotatef(20, 0.0f, 1.0f, 0.0f);
		leaves1.draw();
		
		glRotatef(20, 0.0f, 1.0f, 0.0f);
		leaves1.draw();
		
		glRotatef(20, 0.0f, 1.0f, 0.0f);
		leaves1.draw();
		
		glRotatef(20, 0.0f, 1.0f, 0.0f);
		leaves1.draw();

		glPopMatrix();

	}

	void tree::drawTree2(){

		glPushMatrix();

		Cylinder trunk(0.2f, 4.5f, 15, treeTrunk, treeTrunk, treeTrunk);
		trunk.drawWithCone();

		glTranslatef(0.0f, 7.0f, 0.0f);
		
		Cube leaves2(0.0f, 7.0f, 9.0f, treeLeaves, treeLeaves, treeLeaves, treeLeaves, treeLeaves, treeLeaves, false);
		leaves2.draw();

		glRotatef(20, 0.0f, 1.0f, 0.0f);
		leaves2.draw();

		glRotatef(20, 0.0f, 1.0f, 0.0f);
		leaves2.draw();

		glRotatef(20, 0.0f, 1.0f, 0.0f);
		leaves2.draw();

		glRotatef(20, 0.0f, 1.0f, 0.0f);
		leaves2.draw();

		glRotatef(20, 0.0f, 1.0f, 0.0f);
		leaves2.draw();
		
		glRotatef(20, 0.0f, 1.0f, 0.0f);
		leaves2.draw();
		
		glRotatef(20, 0.0f, 1.0f, 0.0f);
		leaves2.draw();
		
		glRotatef(20, 0.0f, 1.0f, 0.0f);
		leaves2.draw();
		
		glPopMatrix();

	}

	void tree::drawTree3(){
		
		glPushMatrix();

		Cylinder trunk(0.3f, 6.5f, 15, treeTrunk, treeTrunk, treeTrunk);
		trunk.drawWithCone();

		glTranslatef(0.0f, 8.0f, 0.0f);
		
		Cube leaves3(0.0f, 9.0f, 11.0f, treeLeaves, treeLeaves, treeLeaves, treeLeaves, treeLeaves, treeLeaves, false);
		leaves3.draw();

		glRotatef(20, 0.0f, 1.0f, 0.0f);
		leaves3.draw();

		glRotatef(20, 0.0f, 1.0f, 0.0f);
		leaves3.draw();

		glRotatef(20, 0.0f, 1.0f, 0.0f);
		leaves3.draw();

		glRotatef(20, 0.0f, 1.0f, 0.0f);
		leaves3.draw();

		glRotatef(20, 0.0f, 1.0f, 0.0f);
		leaves3.draw();
		
		glRotatef(20, 0.0f, 1.0f, 0.0f);
		leaves3.draw();
		
		glRotatef(20, 0.0f, 1.0f, 0.0f);
		leaves3.draw();
		
		glRotatef(20, 0.0f, 1.0f, 0.0f);
		leaves3.draw();
		
		glPopMatrix();

	}

	void tree::drawTree4(){
		
		glPushMatrix();

		Cylinder trunk(0.5f, 3.5f, 15, treeTrunk, treeTrunk, treeTrunk);
		trunk.drawWithCone();

		glTranslatef(0.0f, 10.5f, 0.0f);
		
		Cube leaves4(0.0f, 10.0f, 4.0f, treeLeaves, treeLeaves, treeLeaves, treeLeaves, treeLeaves, treeLeaves, false);
		leaves4.draw();

		glRotatef(20, 0.0f, 1.0f, 0.0f);
		leaves4.draw();

		glRotatef(20, 0.0f, 1.0f, 0.0f);
		leaves4.draw();

		glRotatef(20, 0.0f, 1.0f, 0.0f);
		leaves4.draw();

		glRotatef(20, 0.0f, 1.0f, 0.0f);
		leaves4.draw();

		glRotatef(20, 0.0f, 1.0f, 0.0f);
		leaves4.draw();
		
		glRotatef(20, 0.0f, 1.0f, 0.0f);
		leaves4.draw();
		
		glRotatef(20, 0.0f, 1.0f, 0.0f);
		leaves4.draw();
		
		glRotatef(20, 0.0f, 1.0f, 0.0f);
		leaves4.draw();
		
		glPopMatrix();

	}
}

#endif TREE_H