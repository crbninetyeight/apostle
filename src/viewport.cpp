#include "viewport.hpp"

Viewport::Viewport( int width, int height, int tileSize )
{
    isAnimating = false;

    this->width = width;
    this->height = height;

    clipX = width;
    clipY = height;

    this->tileSize = tileSize;

    viewSurf = SDL_CreateRGBSurface(
        0,
        width, height,
        24,
        0x00FF0000,
        0x0000FF00,
        0x000000FF,
        0xFF000000
    );

    tileColor = new Uint32*[width];
    for( int i = 0; i < width; i++ ) {
        tileColor[i] = new Uint32[height];
    }
}

Viewport::~Viewport()
{
    SDL_FreeSurface( viewSurf );

    for ( int i = 0; i < width; i++ ) {
        delete[] tileColor[i];
    }   delete[] tileColor;
}

SDL_Surface *Viewport::drawSurface( Actor *actor, World *world )
{
    entity_position x = 0;
    entity_position y = 0;

    actor->getPosition( &x, &y );

    // where (0,0) is the top-left corner of the world space.
    clipX = x-((width-1)/2);
    clipY = y-((height-1)/2);

    world->fixClip( &clipX, &clipY, width, height );

    Uint32 color = 0xFF000000;
    for( int i = 0; i < width; i++ ) {
        for( int j = 0; j < height; j++ ) {
            switch( world->getTileType(clipX+i, clipY+j) ) {
                case TILE_ACTOR:
                color = 0xFFFFFFFF;
                break;

                case TILE_DIRT:
                color = 0xFFFFFF00;
                break;

                case TILE_BLANK:
                color = 0xFF000000;
                break;
            }

            tileColor[i][j] = color;
        }
    }

    SDL_Rect rect;
    rect.w = tileSize;
    rect.h = tileSize;

    for( int i = 0; i < width; i++ ) {
        for( int j = 0; j < height; j++ ) {
            rect.x = 0 + (i*rect.w);
            rect.y = 0 + (j*rect.h);
            SDL_FillRect( viewSurf, &rect, tileColor[i][j] );
        }
    }

    return viewSurf;
}

void Viewport::clearSurface()
{
    for( int i = 0; i < width; i++ ) {
        for( int j = 0; j < height; j++ ) {
            tileColor[i][j] = 0xFF000000;
        }
    }
}
