#include <iostream>
#include <cstdlib>

#include "../../src/world.hpp"

int	main ( int argc, char** argv )
{
	world	*w;
	tset2	*t;

	int	wi, he;

	std::cout << "tileset implementation test\n";

	/* take first two arguments as the world dimensions */
	wi	= atoi ( argv[1] );
	he	= atoi ( argv[2] );
	w	= new world ( wi, he );
	t	= w->get_tileset();

	return	0;
}
