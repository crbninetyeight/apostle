#include <iostream>

#include "world.hpp"

TileSet2::TileSet2( int x, int y )
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
            this->set[ix][iy].type          = TILE_BLANK;
            this->set[ix][iy].location.x    = ix;
            this->set[ix][iy].location.y    = iy;
        }
    }
}

TileSet2::~TileSet2( void )
{
    // destructor of tset2
    for ( int i = 0; i < this->dime.height; i++ ) {
        delete[] this->set[i];
    }

    delete[] this->set;
}

World::World( int world_x, int world_y )
{
    // world(): build the world
    this->set = new TileSet2 ( world_x, world_y );
}

World::~World( void )
{
    // world destructor
    delete this->set;
}
