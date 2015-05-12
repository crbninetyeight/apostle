#ifndef	APO_WORLD_HPP__
#define	APO_WORLD_HPP__

/* structure that contains dimension information */
struct	dime2 {
	int	width, height;
};

/* structure that contains position information */
struct	pos2 {
	int	x, y;
};

/* enumerator that describes tile types */
enum	tile_t {
	TILE_BLANK
};

/* structure that describes tiles */
struct	tile {
	tile_t	type;
	pos2	location;
};

/* class that contains tilesets */
class	tset2 {
	private:
	tile	**set;	/* the set */
	dime2	dime;	/* the dimensions of the set */
	public:
	tset2 ( int x, int y );	/* build a tileset given the parameters */
	~tset2 ( void );
};

/* class that contains tilesets and other world information */
class	world {
	private:
	tset2	*set;	/* the set of tiles needed for world manipulation */
	public:
	world ( int world_x, int world_y );	/* world constructor */
	~world ( void );			/* world  destructor */
};

#endif	/* APO_WORLD_HPP__ */
