#ifndef	APO_WORLD_HPP__
#define	APO_WORLD_HPP__

// structure that contains dimension information
struct Dimension2 {
    int width;
    int height;
};

// structure that contains position information
struct Position2 {
    int	x;
    int y;
};

// enumerator that describes tile types
enum TileType {
    TILE_BLANK
};

// structure that describes tiles
struct Tile {
    TileType    type;
    Position2   location;
};

// class that contains tilesets
class TileSet2
{
private:
    Tile        **set;  // the set
    Dimension2   dime;  // the dimensions of the set
public:
     TileSet2(int x, int y);  // build a tileset given the parameters
    ~TileSet2(void);
};

/* class that contains tilesets and other World information */
class World
{
private:
    TileSet2 *set;   // the set of tiles needed for World manipulation

public:
     World(int World_x, int World_y);   // World constructor
    ~World(void);                       // World  destructor
};

#endif	// APO_WORLD_HPP__
