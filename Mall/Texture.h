#ifndef TEXTURE_H
#define TEXTURE_H
#include <glut.h>
/**********************************************************
 *
 * VARIABLES DECLARATION
 *
 *********************************************************/

 // Counter to keep track of the last loaded texture
extern int num_texture;


/**********************************************************
 *
 * FUNCTION LoadBitmap(char *)
 *
 * This function loads a bitmap file and return the OpenGL reference ID to use that texture
 *
 *********************************************************/

extern GLuint loadGltexture(char* filename);
extern void bindAlpha(GLuint textureID);
extern void unbind();
void cleanupTex(GLuint textureID);

//
//#include <GL/glew.h>
//#include <string>
//#include "stb_image.h"
//
//class Texture {
//public:
//    Texture(const std::string& filename, bool hasAlpha = false);
//    ~Texture();
//    void bind(GLenum textureUnit);
//
//private:
//    GLuint textureID;
//};
//
#endif // TEXTURE_H
