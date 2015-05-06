/*	array_cast.cpp: can arrays be casted to pointers?
 *
 *	given a structure that contains
 *		a. a pointer
 *		b. the given dimensions of the array
 *
 *	can an array be casted to it?				*/

#include <iostream>

struct	dime2 {
	int	width, height;
};

struct	shelf {
	int*	book;
	dime2	dimension;
};

int	main ( int argc, char** argv )
{
	dime2	dimension;

	dimension.width		= 25;
	dimension.height	= 25;	

	int	books[dimension.width][dimension.height];

	for ( int county = 0; county < dimension.height; county++ ) {
		for ( int countx = 0; countx < dimension.width; countx++ ) {
			books[countx][county]	= countx + county;
		}
	}

	shelf	bookshelf;

	bookshelf.dimension	= dimension;
	bookshelf.book		= (int *)books;

	/* now we extract the information from bookshelf */
	int (*c)[bookshelf.dimension.width][bookshelf.dimension.height]
		= (int(*)[bookshelf.dimension.width][bookshelf.dimension.height])bookshelf.book;

	std::cout << c[12][12] << '\n';

	return	0;
}
