#include "noise.hpp"
#include <stdlib.h>

WhiteNoise::WhiteNoise( int width, int height, int seed )
{
    this->noise = new float*[width];
    for( int i = 0; i < width; i++ ) {
        this->noise[i] = new float[height];
    }

    this->width     = width;
    this->height    = height;

    srand( seed );
    for( int j = 0; j < height; j++ ) {
        for( int i = 0; i < width; i++ ) {
            this->noise[i][j] = static_cast<float>(rand())/static_cast<float>(RAND_MAX);
        }
    }
}

WhiteNoise::~WhiteNoise()
{
    // destructor of tset2
    for ( int i = 0; i < this->width; i++ ) {
        delete[] this->noise[i];
    }

    delete[] this->noise;
}

float WhiteNoise::getValue( int x, int y )
{
    return (width <= x || height <= y) ? 1 : this->noise[x][y];
}

int WhiteNoise::getWidth()
{
    return this->width;
}

int WhiteNoise::getHeight()
{
    return this->height;
}
