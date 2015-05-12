#include <iostream>

#include "world.hpp"

tset2::tset2 ( int x, int y )
{
	/* build a tileset given the parameters */
	this->set	= new tile*[y];
	for ( int i = 0; i < y; i++ ) {
		this->set[i]	= new tile[x];
	}

	/* add dimensional contexts to the class */
	this->dime.width	= x;
	this->dime.height	= y;

	/* fill in all tiles of the set with blanks */
	for ( int iy = 0; iy < this->dime.height; iy++ ) {
		for ( int ix = 0; ix < this->dime.width; ix++ ) {
			this->set[ix][iy].type
				= TILE_BLANK;
			this->set[ix][iy].location.x
				= ix;
			this->set[ix][iy].location.y
				= iy;
		}
	}
}

tset2::~tset2 ( void )
{
	/* destructor of tset2 */
	for ( int i = 0; i < this->dime.height; i++ ) {
		delete[]	this->set[i];
	}

	delete[]	this->set;
}

world::world ( int world_x, int world_y )
{
	/* world(): build the world */
	this->set	= new tset2 ( world_x, world_y );
}

world::~world ( void )
{
	/* world destructor */
	delete	this->set;
}
