#ifndef CYLINDER_H   //SALMA AL FAWAL
#define CYLINDER_H

class Cylinder {

public:
    Cylinder(float cylRadius,float cylHeight, int numSectors, int side, int top, int bottom);
	~Cylinder();

    void draw();
	void drawWithCone();

private:
    float radius;
	float height;
    int sectors;
	int sideTex;
	int topTex;
	int bottomTex;

};

#endif // CYLINDER_H
