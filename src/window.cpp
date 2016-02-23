#include <iostream>
#include "window.hpp"
#include "noise.hpp"
#include <stdlib.h>

#define RED 0xFFFF0000
#define GRN 0xFF00FF00
#define BLU 0xFF0000FF

#define TILE_SIZE 32

#define undefined SDL_WINDOWPOS_UNDEFINED

ApoWindow::ApoWindow( const char* title, int width, int height )
{
    window = SDL_CreateWindow(
        title,
        undefined, undefined,
        width, height,
        0
    );

    if( window == NULL ) {
        std::cerr << "There was an error while creating the window.\n"
            << SDL_GetError();
    }

    SDL_GetWindowSize( window, &width, &height );
    front = SDL_GetWindowSurface( window );

    viewport = new Viewport( 11, 11, 32 );

    if( front == NULL ) {
        std::cerr << "CreateRGBSurface failed:\n" << SDL_GetError();
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

void ApoWindow::drawSurface( SDL_Surface *surface )
{
    SDL_BlitSurface( surface, NULL, front, NULL );
}

void ApoWindow::drawViewport( Actor *actor, World *world )
{
    drawSurface( viewport->drawSurface(actor, world) );
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
    if( SDL_PollEvent(&event) != 1 ) {
        return event;
    } else {
        return event;
    }
}
