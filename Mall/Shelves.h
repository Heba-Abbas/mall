#ifndef SHELVES_H
#define SHELVES_H

#include "Cube.h"  
#include <vector>  

class Shelves {
private:
    float shelfWidth;         
    float shelfHeight;        
    float shelfDepth;         
    float spacing;            
    int numberOfShelves;     
    float columnWidth;        
    float columnHeight;       
    unsigned int leftTex, rightTex, shelfTex; 
    std::vector<unsigned int> cubeTextures;  

public:
    Shelves(float width, float height, float depth, float spacing, int numShelves, 
            unsigned int leftTex, unsigned int rightTex, unsigned int shelfTex, 
            const std::vector<unsigned int>& cubeTextures = std::vector<unsigned int>()
);

    void draw();
};

#endif // SHELVES_H
