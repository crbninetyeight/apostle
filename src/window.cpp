//#include <iostream>
#include "window.hpp"
#include "noise.hpp"
#include <stdlib.h>

#define WHITE 0xFFFFFFFF
#define RED   0xFFFF0000
#define GRN   0xFF00FF00
#define BLU   0xFF0000FF

#define TILE_SIZE 32

#define undefined SDL_WINDOWPOS_UNDEFINED

ApoWindow::ApoWindow( const char* title, int width, int height )
{
    isServingEvents = true;

    window = SDL_CreateWindow(
        title,
        undefined, undefined,
        width, height,
        0
    );

    if ( window == NULL ) {
        //std::cerr << "There was an error while creating the window.\n"
            //<< SDL_GetError();
    }

    SDL_GetWindowSize( window, &width, &height );
    front = SDL_GetWindowSurface( window );

    viewport = new Viewport( 11, 11, 32 );

    if ( front == NULL ) {
        //std::cerr << "CreateRGBSurface failed:\n" << SDL_GetError();
    }
}

ApoWindow::~ApoWindow()
{
    SDL_DestroyWindow( window );
    SDL_Quit();
}

void ApoWindow::clearWindow()
{
    SDL_FillRect( front, NULL, 0x00000000 );
}

void ApoWindow::drawSurface()
{

}

int ApoWindow::drawSurface( SDL_Surface *surface )
{
    SDL_BlitSurface( surface, NULL, front, NULL );
    return 0;
}

void ApoWindow::drawViewport( Actor *actor, World *world )
{
    if ( drawSurface(viewport->drawSurface(actor, world)) == VIEW_CHANGED )
        isServingEvents = false;
}

void ApoWindow::updateWindow()
{
    SDL_UpdateWindowSurface( window );
}

bool ApoWindow::isEvent()
{
    return (SDL_PollEvent( NULL ) == 1);
}

SDL_Event ApoWindow::getEvent()
{
    SDL_PollEvent( &event );

    if ( isServingEvents ) {
        return event;
    } else {
        SDL_Event dummy;
        dummy.type = SDL_USEREVENT;
        return dummy;
    }
}
