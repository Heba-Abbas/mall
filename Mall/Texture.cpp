#ifdef __cplusplus
#include <cstdlib>
#else
#include <stdlib.h>
#endif
#include "Texture.h"
#include "SOIL.h"
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <gl/gl.h>			// Header File For The OpenGL32 Library
#include <gl/glu.h>			// Header File For The GLu32 Library
#include <glut.h>		// Header File For The Glaux Library

#define _CRT_SECURE_NO_DEPRECATE


GLuint loadGltexture(char* filename){
	GLuint textureID = SOIL_load_OGL_texture(
		filename,
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
		);

	if(textureID == 0){
		printf("texture loading failed: '%s'\n", SOIL_last_result);
	}
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // If the u,v coordinates overflow the range 0,1 the image is repeated
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	bindAlpha(textureID);

	return textureID;
}

void bindAlpha(GLuint textureID){
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBindTexture(GL_TEXTURE_2D, textureID);
}

void unbind(){

	glDisable(GL_BLEND);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void cleanupTex(GLuint textureID[10]) {
	for(int i = 0; i < 10 ; i++)
	glDeleteTextures(1, &textureID[i]);
}
//#include "Texture.h"
//#include <GL/glew.h>
//#include <iostream>
//#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image.h"
//
//
//Texture::Texture(const std::string& filename, bool hasAlpha) {
//    int width, height, channels;
//    stbi_set_flip_vertically_on_load(true);
//    unsigned char* image = stbi_load(filename.c_str(), &width, &height, &channels, 0);
//    if (!image) {
//        std::cerr << "Failed to load texture: " << filename << std::endl;
//        return;
//    }
//
//    glGenTextures(1, &textureID);
//    glActiveTexture(GL_TEXTURE0);
//    glBindTexture(GL_TEXTURE_2D, textureID);
//    
//    if (hasAlpha) {
//        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
//    } else {
//        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
//    }
//
//    __glewGenerateMipmap(GL_TEXTURE_2D);
//    stbi_image_free(image);
//}
//
//Texture::~Texture() {
//    glDeleteTextures(1, &textureID);
//}
//
//void Texture::bind(GLenum textureUnit) {
//    __glewActiveTexture(textureUnit);
//    glBindTexture(GL_TEXTURE_2D, textureID);
//}
