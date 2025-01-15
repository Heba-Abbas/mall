#ifndef SPHERE_H
#define SPHERE_H

class Sphere {
public:
    Sphere(float radius, int sectors, bool isSemiSphere, int tex);
    void draw();
private:
    float m_radius;
    int m_sectors;
    bool m_isSemiSphere;
	int texture;
};

#endif // SPHERE_H
