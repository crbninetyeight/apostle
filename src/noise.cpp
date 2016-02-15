#include "noise.hpp"
#include <stdlib.h>

WhiteNoise::WhiteNoise( int width, int height )
{
    this->noise = new float*[width];
    for( int i = 0; i < width; i++ ) {
        this->noise[i] = new float[height];
    }

    this->width     = width;
    this->height    = height;

    for( int j = 0; j < height; j++ ) {
        for( int i = 0; i < width; i++ ) {
            srand( 0 );
            this->noise[i][j] = static_cast<float>(i+1)/static_cast<float>(j+1);
        }
    }
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
