#include "gate.h"  //AHMAD AL HATI
#include <glut.h>
#include "texture.h"

gate::gate(float x,float y , float z,int txt,float i,float j,float k,int o,int l):x(x),y(y),z(z),txt(txt),i(i),j(j),k(k),o(o),l(l)
{
}


gate::~gate(void)
{
}

void gate::draw()
{
	glPushMatrix();
	glTranslated(i,j,k);
	glRotated(o,0,1,0);
	glScaled(1,0.1,0.1);
	glBindTexture(GL_TEXTURE_2D , txt);
	for (int i = 0; i < l; i++)
	{
glBegin(GL_POLYGON);
	glTexCoord2d(0,0);glVertex3d( x, y , z);
	glTexCoord2d(1,0);glVertex3d( 0, y , z);
	glTexCoord2d(0.5,1);glVertex3d( 0, y/3 , z);
	glTexCoord2d(1,0.5);glVertex3d( 3*x/4, -y , z);
	glTexCoord2d(0,1);glVertex3d( x, -y , z);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2d(0,0);glVertex3d( 0, y , z);
	glTexCoord2d(1,0);glVertex3d( -x, y , z);
	glTexCoord2d(0.5,1);glVertex3d( -x, -y , z);
	glTexCoord2d(1,0.5);glVertex3d( 3*-x/4, -y , z);
	glTexCoord2d(0,1);glVertex3d( 0, y/3 , z);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2d(0,0);glVertex3d( x, y , -z);
	glTexCoord2d(1,0);glVertex3d( 0, y , -z);
	glTexCoord2d(0.5,1);glVertex3d( 0, y/3 , -z);
	glTexCoord2d(1,0.5);glVertex3d( 3*x/4, -y , -z);
	glTexCoord2d(0,1);glVertex3d( x, -y , -z);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2d(0,0);glVertex3d( 0, y , -z);
	glTexCoord2d(1,0);glVertex3d( -x, y , -z);
	glTexCoord2d(0.5,1);glVertex3d( -x, -y , -z);
	glTexCoord2d(1,0.5);glVertex3d( 3*-x/4, -y , -z);
	glTexCoord2d(0,1);glVertex3d( 0, y/3 , -z);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2d(0,0);glVertex3d( x, y , z);
	glTexCoord2d(1,0);glVertex3d( x, y , -z);
	glTexCoord2d(1,1);glVertex3d( -x, y , -z);
	glTexCoord2d(0,1);glVertex3d( -x, y , z);

	
	glTexCoord2d(0,0);glVertex3d( -x, y , z);
	glTexCoord2d(1,0);glVertex3d( -x, -y-20 , z);
	glTexCoord2d(1,1);glVertex3d( -x, -y-20 , -z);
	glTexCoord2d(0,1);glVertex3d( -x, y , -z);

	
	glTexCoord2d(0,0);glVertex3d( x, y , z);
	glTexCoord2d(1,0);glVertex3d( x, -y-20 , z);
	glTexCoord2d(1,1);glVertex3d( x, -y-20 , -z);
	glTexCoord2d(0,1);glVertex3d( x, y , -z);

	
	glTexCoord2d(0,0);glVertex3d( -x, -y , z);
	glTexCoord2d(1,0);glVertex3d( 3*-x/4, -y , z);
	glTexCoord2d(1,1);glVertex3d( 3*-x/4, -y-20 , z);
	glTexCoord2d(0,1);glVertex3d( -x, -y-20 , z);

	
	glTexCoord2d(0,0);glVertex3d( x, -y , z);
	glTexCoord2d(1,0);glVertex3d( 3*x/4, -y , z);
	glTexCoord2d(1,1);glVertex3d( 3*x/4, -y-20 , z);
	glTexCoord2d(0,1);glVertex3d( x, -y-20 , z);
	
	
	glTexCoord2d(0,0);glVertex3d( -x, -y , -z);
	glTexCoord2d(1,0);glVertex3d( 3*-x/4, -y , -z);
	glTexCoord2d(1,1);glVertex3d( 3*-x/4, -y-20 , -z);
	glTexCoord2d(0,1);glVertex3d( -x, -y-20 , -z);

	
	glTexCoord2d(0,0);glVertex3d( x, -y , -z);
	glTexCoord2d(1,0);glVertex3d( 3*x/4, -y , -z);
	glTexCoord2d(1,1);glVertex3d( 3*x/4, -y-20 , -z);
	glTexCoord2d(0,1);glVertex3d( x, -y-20 , -z);

	
	glTexCoord2d(0,0);glVertex3d( 3*x/4, -y , -z);
	glTexCoord2d(1,0);glVertex3d( 3*x/4, -y , z);
	glTexCoord2d(1,1);glVertex3d( 3*x/4, -y-20 , z);
	glTexCoord2d(0,1);glVertex3d( 3*x/4, -y-20 , -z);

	
	glTexCoord2d(0,0);glVertex3d( 3*-x/4, -y , -z);
	glTexCoord2d(1,0);glVertex3d( 3*-x/4, -y , z);
	glTexCoord2d(1,1);glVertex3d( 3*-x/4, -y-20 , z);
	glTexCoord2d(0,1);glVertex3d( 3*-x/4, -y-20 , -z);

	
	glTexCoord2d(0,0);glVertex3d( 3*-x/4, -y , -z);
	glTexCoord2d(1,0);glVertex3d( 3*-x/4, -y , z);
	glTexCoord2d(1,1);glVertex3d( 0, y/3 , z);
	glTexCoord2d(0,1);glVertex3d( 0, y/3 , -z);

	
	glTexCoord2d(0,0);glVertex3d( 3*x/4, -y , -z);
	glTexCoord2d(1,0);glVertex3d( 3*x/4, -y , z);
	glTexCoord2d(1,1);glVertex3d( 0, y/3 , z);
	glTexCoord2d(0,1);glVertex3d( 0, y/3 , -z);

	glEnd();
	glTranslated(1,0,0);
	}
	
	
	glPopMatrix();
}