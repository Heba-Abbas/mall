#include <glut.h>  
#include "Stair.h"
#include "Texture.h"
#include "Stair.h"



Stair::Stair(int x , int y ,int z ,int a , int b ,int c, int texture,float i ,float j,float k ,float o,float s,float q,float l)
	:x(x),y(y),z(z),texture1(texture),i(i),j(j),k(k),o(o),a(a),b(b),c(c),s(s),q(q),l(l)
{
}


Stair::~Stair(void)
{
}

void Stair::draw()
{
	glPushMatrix();	
	glTranslated(i,j,k);
	glScaled(s,q,l);
	glRotated(o , 0 , 1 , 0);
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D , texture1);
	for (float n = 0; n < 15; n+=1) {	
	glBegin(GL_QUADS);
		
		glTexCoord2d(0,0);glVertex3d( -x*10 , -y , z);	
		glTexCoord2d(1,0);glVertex3d( x*10 , -y , z);
		glTexCoord2d(1,1);glVertex3d( x*10 , y , z);
		glTexCoord2d(0,1);glVertex3d( -x*10 , y , z);
		
		glTexCoord2d(0,0);glVertex3d( -x*10 , y , -z);	
		glTexCoord2d(1,0);glVertex3d( x*10 , y , -z);
		glTexCoord2d(1,1);glVertex3d( x*10 , y , z);
		glTexCoord2d(0,1);glVertex3d( -x*10 , y ,z);
	glEnd();
	glTranslated(0,2,-2);
	}	
	glPopMatrix();


	glColor3f(1,1,1);
	glBegin(GL_POLYGON);
		glVertex3d( a+9 , b+30 , c-24);
		glVertex3d( a+9 , b+5 , c);
		glVertex3d( a+9 , -b , c);
		glVertex3d( a+9 , -b , -c-28);
		glVertex3d( a+9 , b+30 , -c-28);
	
		glVertex3d( a+12 , b+30 , c-24);
		glVertex3d( a+12 , b+5 , c);
		glVertex3d( a+12 , -b , c);
		glVertex3d( a+12 , -b , -c-28);
		glVertex3d( a+12 , b+30 , -c-28);
	glEnd();
	
	glBegin(GL_QUADS);
	glVertex3d( a+9 , b+5 , c);
	glVertex3d( a+9 , -b , c);
	glVertex3d( a+12 , -b , c);
	glVertex3d( a+12 , b+5 , c);

	glVertex3d( a+9 , b+5 , c);
	glVertex3d( a+12 , b+5 , c);
	glVertex3d( a+12 , b+30 , c-24);
	glVertex3d( a+9 , b+30 , c-24);

	glVertex3d( a+9 , b+30 , c-24);
	glVertex3d( a+12 , b+30 , c-24);
	glVertex3d( a+12 , b+30 , -c-28);
	glVertex3d( a+9 , b+30 , -c-28);
	glEnd();

	
	glBegin(GL_POLYGON);
		glVertex3d( a-10 , b+30 , c-24);
		glVertex3d( a-10 , b+5 , c);
		glVertex3d( a-10 , -b , c);
		glVertex3d( a-10 , -b , -c-28);
		glVertex3d( a-10 , b+30 , -c-28);
	
		glVertex3d( a-13 , b+30 , c-24);
		glVertex3d( a-13 , b+5 , c);
		glVertex3d( a-13 , -b , c);
		glVertex3d( a-13 , -b , -c-28);
		glVertex3d( a-13 , b+30 , -c-28);
	glEnd();

	glBegin(GL_QUADS);
	
	glVertex3d( a-10 , b+5 , c);
	glVertex3d( a-10 , -b , c);
	glVertex3d( a-13 , -b , c);
	glVertex3d( a-13 , b+5 , c);

	
	glVertex3d( a-10 , b+5 , c);
	glVertex3d( a-13 , b+5 , c);
	glVertex3d( a-13 , b+30 , c-24);
	glVertex3d( a-10 , b+30 , c-24);


	glVertex3d( a-10 , b+30 , c-24);
	glVertex3d( a-13 , b+30 , c-24);
	glVertex3d( a-13 , b+30 , -c-28);
	glVertex3d( a-10 , b+30 , -c-28);
	glEnd();

	
	
	glPopMatrix();
	

}
