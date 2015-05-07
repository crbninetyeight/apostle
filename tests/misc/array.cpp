#include <iostream>

struct	dime2 {
	int	width, height;
};

struct	shelf {
	int	*book;
	dime2	dimension;
};

int	main ( int argc, char** argv )
{
	dime2	dimension;
	shelf	bookshelf;

	bookshelf.book		= new int [25*25];
	bookshelf.dimension	= dimension;

	/* now we extract the information from bookshelf */

	return	0;
}
