#include <glut.h>  //AHMAD AL HATI
#include "texture.h"
#include "Ground.h"

#include <glut.h>

Ground::Ground(int x ,int y, int z ,int image,int image1,int image2,int image3,int image4,int image5):x(x),y(y),z(z),image(image),image1(image1),image2(image2),image3(image3),image4(image4),image5(image5)
{
}


Ground::~Ground(void)
{
}

void Ground::draw()
{
	
	glBindTexture(GL_TEXTURE_2D , image);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);glVertex3d( x , y , z);
	glTexCoord2d(5,0);glVertex3d( x , -y , z);
	glTexCoord2d(5,5);glVertex3d( -x , -y , z);
	glTexCoord2d(0,5);glVertex3d( -x , y , z);
	glEnd();
	
	glBindTexture(GL_TEXTURE_2D , image1);
    glBegin(GL_QUADS);
	glTexCoord2d(0,0);glVertex3d( x , y , -z);
	glTexCoord2d(5,0);glVertex3d( -x , y , -z);
	glTexCoord2d(5,5);glVertex3d( -x , -y , -z);
	glTexCoord2d(0,5);glVertex3d( x , -y , -z);
	glEnd();
	
	glBindTexture(GL_TEXTURE_2D , image2);
    glBegin(GL_QUADS);
	glTexCoord2d(0,0);glVertex3d( x , y , z);
	glTexCoord2d(5,0);glVertex3d( x ,	y , -z);
	glTexCoord2d(5,5);glVertex3d( -x , y , -z);
	glTexCoord2d(0,5);glVertex3d( -x , y , z);
	glEnd();

   glBindTexture(GL_TEXTURE_2D , image3);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);glVertex3d( -x , -y , z);
	glTexCoord2d(5,0);glVertex3d( -x , -y , -z);
	glTexCoord2d(5,5);glVertex3d( x , -y , -z);
	glTexCoord2d(0,5);glVertex3d( x , -y , z);
	glEnd();

    glBindTexture(GL_TEXTURE_2D , image4);
	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glTexCoord2d(0,0);glVertex3d( x	, y , z);
	glTexCoord2d(5,0);glVertex3d( x , -y , z);
	glTexCoord2d(5,5);glVertex3d( x , -y , -z);
	glTexCoord2d(0,5);glVertex3d( x , y , -z);
	glEnd();

    glBindTexture(GL_TEXTURE_2D , image5);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);glVertex3d( -x , y , -z);
	glTexCoord2d(5,0);glVertex3d( -x , -y , -z);
	glTexCoord2d(5,5);glVertex3d( -x , -y , z);
	glTexCoord2d(0,5);glVertex3d( -x , y , z);	
	glEnd();
	


}
