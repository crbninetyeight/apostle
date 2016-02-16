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
    stupid = 0;
    SDL_Init( SDL_INIT_VIDEO );

    this->blockColor = new Uint32*[width/TILE_SIZE];
    for( int i = 0; i < width/TILE_SIZE; i++ ) {
        this->blockColor[i] = new Uint32[height/TILE_SIZE];
    }

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

    SDL_GetWindowSize( window, &win_width, &win_height );
    front   = SDL_GetWindowSurface( window );

    map = SDL_CreateRGBSurface(
        0,
        width-(TILE_SIZE*6),
        height-(TILE_SIZE),
        24,
        0x00FF0000,
        0x0000FF00,
        0x000000FF,
        0xFF000000
    );

    if( front == NULL ) {
        std::cerr << "CreateRGBSurface failed:\n" << SDL_GetError();
    }
}

ApoWindow::~ApoWindow()
{
    for( int i = 0; i < this->win_width/TILE_SIZE; i++ ) {
        delete[] this->blockColor[i];
    }

    delete[] this->blockColor;

    SDL_DestroyWindow( window );
    SDL_Quit();
}

void ApoWindow::clearWindow()
{
    SDL_FillRect( front, NULL, 0x00000000 );
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
