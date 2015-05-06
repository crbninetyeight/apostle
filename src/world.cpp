#include <iostream>

#include "world.hpp"

tset2*	world::build_tileset ( const int x, const int y )
{
	/* build_tileset: build a tileset and return its pointer 
	 *
	 * return value:
	 * 	if there was an error, -1, else the pointer of tset2
	 * 	is returned.						*/
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

world::world ( int world_x, int world_y )
{
	/* world(): build the world
	 *
	 * todo:
	 * 	! make world_x and world_y be anything at the
	 *	expense of user resources, instead of using a
	 *	finite limit.					*/
}
