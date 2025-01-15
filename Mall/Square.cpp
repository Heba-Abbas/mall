#include "Square.h" //AHMAD AL HATI
#include "gate.h"
#include "Ground.h"
#include "Stair.h"

#include <glut.h>

Square::Square(int image,int image1):txt(image),txt1(image1)
{
}


Square::~Square(void)
{
}

void Square::draw()
{
	gate gate0 = gate(0.5,2,2,txt,0.75,3.2,9.8,0,4);
	gate0.draw();
	gate gate1 = gate(0.5,2,2,txt,-9.3,3.2,9.8,0,4);
	gate1.draw();
	gate gate2 = gate(0.5,2,2,txt,7.15,3.2,9.8,0,3);
	gate2.draw();
	gate gate3 = gate(0.5,2,2,txt,-0.1,3.2,-9.8,0,5);
	gate3.draw();
	gate gate4 = gate(0.5,2,2,txt,10,3.2,-4,90,3);
	gate4.draw();
	gate gate5 = gate(0.5,2,2,txt,10,3.2,4,90,3);
	gate5.draw();
	gate gate6 = gate(0.5,2,2,txt,-10,3.2,-4,-90,3);
	gate6.draw();
	gate gate7 = gate(0.5,2,2,txt,-10,3.2,4,-90,3);
	gate7.draw();
	
	Stair stair = Stair(1,1,1,1,1,1,txt,-8,-1,14.3,0,0.15,0.072,0.15);
	stair.draw();
	Stair stair1 = Stair(1,1,1,1,1,1,txt,8,-1,14.3 ,0,0.15,0.072,0.15);
	stair1.draw();
	Stair stair2 = Stair(1,1,1,1,1,1,txt,2,-1,14.3 ,0,0.15,0.072,0.15);
	stair2.draw();
	Stair stair3 = Stair(1,1,1,1,1,1,txt,2,-1,-14.3,-180,0.25,0.072,0.15);
	stair3.draw();
	Stair stair4 = Stair(1,1,1,1,1,1,txt,-12.9,-1,-3,-90,0.1,0.072,0.15);
	stair4.draw();
	Stair stair5 = Stair(1,1,1,1,1,1,txt,-12.9,-1,5,-90,0.1,0.072,0.15);
	stair5.draw();
	Stair stair6 = Stair(1,1,1,1,1,1,txt,12.9,-1,-5,90,0.1,0.072,0.15);
	stair6.draw();
	Stair stair7 = Stair(1,1,1,1,1,1,txt,12.9,-1,3,90,0.1,0.072,0.15);
	stair7.draw();
	Ground	myspace = Ground(10,1,10,txt1,txt1,txt1,txt1,txt1,txt1);
	myspace.draw();	
}
