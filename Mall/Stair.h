#ifndef STAIR_H
#define STAIR_H
class Stair
{
public:
	Stair(int x , int y ,int z , int a , int b ,int c ,int texture,float i ,float j,float k ,float s,float q,float l ,float o );
	~Stair(void);
	void draw();
private:
	int x;
	int y;
	int z;
	int a;
	int b;
	int c;
	int texture1;	
	float i ;
	float j;
	float k;
	float s;
	float q;
	float l;
	float o;
};
#endif

