#include "viewport.hpp"

Viewport::Viewport( int width, int height, int tileSize )
{
    isAnimating = false;

    // two more rows and columns for pixels outside the drawing
    // surface.
    this->width = width+2;
    this->height = height+2;

    clipX = this->width;
    clipY = this->height;

    this->tileSize = tileSize;

    viewSurf = SDL_CreateRGBSurface(
        0,
        (this->width-2)*tileSize, (this->height-2)*tileSize,
        24,
        0x00FF0000,
        0x0000FF00,
        0x000000FF,
        0xFF000000
    );

    tileColor = new Uint32*[width];
    for ( int i = 0; i < this->width; i++ ) {
        tileColor[i] = new Uint32[this->height];
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

    // the exterior clip anchor.
    // where (0,0) is the top-left corner of the world space.
    clipX = x-((width-1)/2);
    clipY = y-((height-1)/2);

    world->fixClip( &clipX, &clipY, width, height );

    Uint32 color = 0xFF000000;
    for ( int i = 0; i < width; i++ ) {
        for ( int j = 0; j < height; j++ ) {
            switch( world->getTileType(clipX+i, clipY+j) ) {
                case TILE_ACTOR:
                color = 0xFFFFFFFF;
                break;

                case TILE_DIRT:
                color = 0xFFFF0000;
                break;

                case TILE_BLANK:
                color = 0xFF0000FF;
                break;
            }

            tileColor[i][j] = color;
        }
    }

    SDL_Rect rect;
    rect.w = tileSize;
    rect.h = tileSize;

    for ( int i = 0; i < width-1; i++ ) {
        for ( int j = 0; j < height-1; j++ ) {
            rect.x = (i*rect.w);
            rect.y = (j*rect.h);
            SDL_FillRect( viewSurf, &rect, tileColor[i+1][j+1] );
        }
    }

    return viewSurf;
}

void Viewport::clearSurface()
{
    for ( int i = 0; i < width; i++ ) {
        for ( int j = 0; j < height; j++ ) {
            tileColor[i][j] = 0xFF000000;
        }
    }
}
