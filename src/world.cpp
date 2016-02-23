#include <iostream>

#include "world.hpp"

Tileset2::Tileset2( int x, int y )
{
    // build a Tileset given the parameters
    this->set = new Tile*[x];
    for ( int i = 0; i < x; i++ ) {
        this->set[i] = new Tile[y];
    }

    // add dimensional contexts to the class
    this->dime.width    = x;
    this->dime.height   = y;

    // fill in all Tiles of the set with blanks
    for ( int iy = 0; iy < this->dime.height; iy++ ) {
        for ( int ix = 0; ix < this->dime.width; ix++ ) {
            this->set[ix][iy].type          = TILE_DIRT;
            this->set[ix][iy].location.x    = ix;
            this->set[ix][iy].location.y    = iy;
        }
    }
}

Tileset2::~Tileset2( void )
{
    // destructor of tset2
    for ( int i = 0; i < this->dime.height; i++ ) {
        delete[] this->set[i];
    }

    delete[] this->set;
}

void Tileset2::setTileType( int x, int y, TileType newType )
{
    if ( x > -1 && x < dime.width && y > -1 && y < dime.height ) {
        set[x][y].type = newType;
    }
}

TileType Tileset2::getTileType( int x, int y )
{
    if ( x > -1 && x < dime.width && y > -1 && y < dime.height ) {
        return set[x][y].type;
    }
    else {
        return TILE_BLANK;
    }
}

World::World( int world_x, int world_y )
{
    // world(): build the world
    this->set = new Tileset2 ( world_x, world_y );
}

World::~World( void )
{
    // world destructor
    delete this->set;
}

void World::setActor( Actor *actor )
{
    actor->getPosition( &curActorX, &curActorY );

    if ( curActorX < 0 || curActorX >= set->getWidth() ||
         curActorY < 0 || curActorY >= set->getHeight() )
    {
        actor->setPosition( lasActorX, lasActorY );
        actor->getPosition( &curActorX, &curActorY );
    }

    set->setTileType( lasActorX, lasActorY, TILE_DIRT );
    set->setTileType( curActorX, curActorY, TILE_ACTOR );

    lasActorX = curActorX;
    lasActorY = curActorY;
}

void World::fixClip( int *clipX, int *clipY, int width, int height )
{
    if ( *clipX < -2 ) {
        *clipX = -3;
    }
    else if ( *clipX+width > set->getWidth()+2 ) {
        *clipX = set->getWidth()-width+3;
    }

    if ( *clipY < -2 ) {
        *clipY = -3;
    }
    else if ( *clipY+height > set->getHeight()+2 ) {
        *clipY = set->getHeight()-height+3;
    }
}

TileType World::getTileType( int x, int y )
{
    return set->getTileType( x, y );
}

int Tileset2::getWidth()
{
    return dime.width;
}

int Tileset2::getHeight()
{
    return dime.height;
}
