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

/* class that contains tilesets */
class	tset2 {
	private:
	tile**	set;	/* the set */
	dime2	dime;	/* the dimensions of the set */
	public:
	tset2 ( int x, int y ) {
		/* build a tileset array given the parameters */
		this->set	= new tile*[y];
		for ( int count = 0; count < y; i++ ) {
			this->set[count] = new tile[x];
		}
	}
};

/* class that contains tilesets and other world information */
class	world {
	private:
		tset2	set;	/* the set of tiles needed for world manipulation */
	public:
		world ( int world_x, int world_y );			/* world initializer */
};

#endif	/* APO_WORLD_HPP__ */
