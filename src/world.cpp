#include <iostream>

#include "world.hpp"
/*
tset2*	world::build_tileset ( const int x, const int y )
{
*/
	/* build_tileset: build a tileset and return its pointer 
	 *
	 * return value:
	 * 	if there was an error, -1, else the pointer of tset2
	 * 	is returned.						*/
/*
	tile		retile[x][y];
	static tset2	retset;

	for ( int ycount = 0; ycount < y; ycount++ ) {
		for ( int xcount = 0; xcount < x; xcount++ ) {
			retile[xcount][ycount]	= TILE_BLANK;
		}
	}

	retset.set	= (tile **)retile;
	retset.dime.x	= x;
	retset.dime.y	= y;

	return	&retset;
}
*/

tset2::tset2 ( int x, int y )
{
	/* build a tileset given the parameters */
	this->set	= new tile*[y];
	for ( int count = 0; count < y; count++ ) {
		this->set[count]	= new tile[x];
	}

	/* add dimensional contexts to the class */
	this->dime.width	= x;
	this->dime.height	= y;

	/* fill in all tiles in the set with blanks */
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
	for ( int count = 0; count < this->dime.height; count++ ) {
		delete[]	this->set[count];
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
