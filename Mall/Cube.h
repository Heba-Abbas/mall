#ifndef CUBE_H 
#define CUBE_H

class Cube {
public:
	Cube(float edgeSizeWidth, float edgeSizeHeight, float edgeSizeDepth, int front, int back, int top, int bottom, int right, int left, bool hasRoof);
	~Cube();

    void draw();
	void drawSkyBox();
	void drawGate();

private:
    float edgeSizeWidth;
	float edgeSizeHeight;
	float edgeSizeDepth;
	int frontTex;
	int backTex;
	int topTex;
	int bottomTex;
	int rightTex;
	int leftTex;
	bool hasRoof;
};

#endif
