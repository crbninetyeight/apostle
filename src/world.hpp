#ifndef	APO_WORLD_HPP__
#define	APO_WORLD_HPP__

/* enumerator that describes tile types */
enum	tile {
	TILE_BLANK
};

/* structure that contains dimension information */
struct	dime2 {
	int	x, y;
};

/* structure that contains tilesets */
struct	tset2 {
	// tile**	set;	/* the set */
	dime2	dime;	/* the dimensions of the set */
};

/* class that contains tilesets and other world information */
class	world {
	private:
		tset2	set;	/* the set of tiles needed for world manipulation */
	public:
		world ( int world_x, int world_y );			/* world initializer */
};

#endif	/* APO_WORLD_HPP__ */
