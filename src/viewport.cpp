#include "viewport.hpp"

Viewport::Viewport( int width, int height, int tileSize )
{
    isAnimating = false;

    this->width = width;
    this->height = height;

    isClipSet = false;

    curClipX = this->width;
    curClipY = this->height;

    lasClipX = curClipX;
    lasClipY = curClipY;

    this->tileSize = tileSize;

    viewSurf = SDL_CreateRGBSurface(
        0,
        (this->width+2)*tileSize, (this->height+2)*tileSize,
        24,
        // color mask //
        0x00FF0000, // R
        0x0000FF00, // G
        0x000000FF, // B
        0xFF000000  // A
    );
}

Viewport::~Viewport()
{
    SDL_FreeSurface( viewSurf );
}

SDL_Surface *Viewport::drawSurface( Actor *actor, World *world )
{
    entity_position x = 0;
    entity_position y = 0;

    actor->getPosition( &x, &y );

    // the exterior clip anchor.
    // where (0,0) is the top-left corner of the world space.
    curClipX = x-((width-1)/2);
    curClipY = y-((height-1)/2);

    world->fixClip( &curClipX, &curClipY, width, height );

    SDL_Rect rect;
    rect.w = tileSize;
    rect.h = tileSize;

    Uint32 color = 0xFF000000;

    int i = 0;
    int j = 0;

    do {
        rect.y = (j*rect.h);

        do {
            rect.x = (i*rect.w);

            switch( world->getTileType(curClipX+i, curClipY+j) ) {
                case TILE_ACTOR:
                color = 0xFFFFFFFF;
                break;

                case TILE_DIRT:
                color = 0xFF9E450F;
                break;

                case TILE_BLANK:
                color = 0xFF47372B;
                break;
            }

            SDL_FillRect( viewSurf, &rect, color );
            i++;
        } while ( i < width );

        i = 0;
        j++;
    } while ( j < height );

    return viewSurf;
}

void Viewport::clearSurface()
{
    SDL_FillRect( viewSurf, NULL, 0x00000000 );
}
