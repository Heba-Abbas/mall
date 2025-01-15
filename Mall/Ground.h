#ifndef GROUND_H   //AHMAD AL HATI
#define GROUND_H

#include <glut.h>

class Ground
{
public:
	Ground(int x ,int y, int z , int image , int image1,int image2,int image3,int image4,int image5);
	~Ground(void);
	void draw();
private:
	int x ;
	int y ;
	int z;
	int image;
	int image1;
	int image2;
	int image3;
	int image4;
	int image5;
};
#endif