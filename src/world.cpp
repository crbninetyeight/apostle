#include <iostream>

#include "world.hpp"

tset2*	world::build_tileset ( const int x, const int y )
{
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
