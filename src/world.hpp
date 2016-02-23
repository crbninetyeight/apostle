#ifndef	APO_WORLD_HPP__
#define	APO_WORLD_HPP__

#include "actor.hpp"

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
    TILE_BLANK,
    TILE_DIRT,
    TILE_ACTOR
};

// structure that describes tiles
struct Tile {
    TileType    type;
    Position2   location;
};

// class that contains tilesets
class Tileset2
{
private:
    Tile        **set;  // the set
    Dimension2   dime;  // the dimensions of the set
public:
     Tileset2(int x, int y);  // build a tileset given the parameters
    ~Tileset2(void);

    int getWidth();
    int getHeight();

    void setTileType( int x, int y, TileType newType );
    TileType getTileType( int x, int y );
};

/* class that contains tilesets and other World information */
class World
{
private:
    bool actorSet;
    int actorX, actorY;

    Tileset2 *set;   // the set of tiles needed for World manipulation

public:
     World(int World_x, int World_y);   // World constructor
    ~World(void);                       // World  destructor

    void setActor( Actor *actor );
    void setActor( int x, int y );

    // constrains boundaries of clips given if they exceed the borders
    // of the world.
    void fixClip( int *clipX, int *clipY, int width, int height );

    TileType getTileType( int x, int y );
};

#endif	// APO_WORLD_HPP__
