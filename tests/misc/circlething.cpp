#include <iostream>
#include <cstdlib>
#include <math.h>

struct	point2 {
	int	x, y;
};

struct	circle {
	int	diameter;	/* half to get radius */
	point2	location;	/* location on 2D plane */
};

float	sqr ( float value )
{
	float	ret;

	/* really simple arithmetic, i know... */
	ret	= value * value;

	return	ret;
}

float	get_distance ( point2 a, point2 b )
{
	float	ret;		/* value to be returned */

	ret	= sqrt ( sqr((b.y-a.y)) + sqr((b.x-a.x)) );

	return	ret;
}

bool	circle_intersects ( circle base, circle test )
{
	bool	ret = false;
	float	distance,
		rad_a, rad_b;
	point2	loc_a, loc_b;

	/* locations for base circle */
	loc_a.x	= base.location.x;
	loc_a.y	= base.location.y;
	/* locations for test circle */
	loc_b.x	= test.location.x;
	loc_b.y	= test.location.y;

	/* radii for base circle */
	rad_a	= base.diameter / 2;
	/* radii for test circle */
	rad_b	= test.diameter / 2;

	distance	= get_distance ( loc_a, loc_b );

	distance	= distance - rad_a;
	distance	= distance - rad_b;

	if ( distance <= 0 ) {
		ret	= true;
	}

	return	ret;
}

int	main ( int argc, char** argv )
{
	circle	a, b;

	a.location.x	= atoi(argv[1]);
	a.location.y	= atoi(argv[2]);
	a.diameter	= atoi(argv[3]);

	b.location.x	= atoi(argv[4]);
	b.location.y	= atoi(argv[5]);
	b.diameter	= atoi(argv[6]);

	std::cout << circle_intersects ( a, b ) << '\n';

	return	0;
}
