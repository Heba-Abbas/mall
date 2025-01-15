#ifndef GATE_H  //AHMAD AL HATI
#define GATE_H


#include <glut.h>

class gate
{
public:
	gate(float x,float y,float z,int txt,float i,float j,float k,int o,int l);
	~gate(void);
	void draw();
private:
	float x;
	float y;
	float z;
	float i;
	float j;
	float k;
	int o;
	int l;
	int txt;

};
#endif
