#ifndef APO_VIEWPORT_HPP
#define APO_VIEWPORT_HPP

#include <SDL2/SDL.h>
#include "actor.hpp"
#include "world.hpp"

class Viewport
{
private:
    bool isAnimating;
    bool isClipSet;
    
    int width, height;
    int curClipX, curClipY;
    int lasClipX, lasClipY;
    int tileSize;

    SDL_Surface *viewSurf;
    Uint32 **tileColor;

public:
    // creates a new viewport.
    //  parameters:
    //      width, height: odd-valued dimensions of the viewport (in tiles).
    //      tileSize: squared size of the tiles being used.
    //
    //  it is required to use odd-parity values for both dimension
    //  parameters as the viewport will be centered.
     Viewport( int width, int height, int tileSize );
    ~Viewport();

    SDL_Surface *drawSurface( Actor *actor, World *world );
    void clearSurface();
};

#endif
