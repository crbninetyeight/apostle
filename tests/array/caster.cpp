#include <iostream>

struct	world_ptr {
	int**	ayy;
	int	width, height;
};

struct	world_25 {
	int	ayy[25][25];
};

int	main ( void )
{
	world_ptr	*p;

	p	= new world_25;

	return	0;
}
