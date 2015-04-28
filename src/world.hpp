#ifndef	APO_WORLD_HPP__
#define	APO_WORLD_HPP__

enum	tile {
	TILE_BLANK
};

struct	dime2 {
	int	x, y;
};

struct	tset2 {
	tile**	set;
	dime2	dime;
};

class	world {
	private:
		tset2	tset;
	public:
		tset2*	build_tileset ( const int x, const int y );
};

#endif	/* APO_WORLD_HPP__ */
