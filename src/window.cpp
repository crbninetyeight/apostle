#include <iostream>
#include "window.hpp"
#include "noise.hpp"
#include <stdlib.h>

#define RED 0xFFFF0000
#define GRN 0xFF00FF00
#define BLU 0xFF0000FF

#define undefined SDL_WINDOWPOS_UNDEFINED

ApoWindow::ApoWindow( const char* title )
{
    stupid = 0;
    SDL_Init( SDL_INIT_VIDEO );

    red.r = 255;
    red.g = 0;
    red.b = 0;
    red.a = 255;

    green.r = 0;
    green.g = 255;
    green.b = 0;
    green.a = 255;

    blue.r = 0;
    blue.g = 0;
    blue.b = 255;
    blue.a = 255;

    window = SDL_CreateWindow(
        title,
        undefined, undefined,
        640, 480,
        0
    );

    if( window == NULL ) {
        std::cerr << "There was an error while creating the window.\n"
            << SDL_GetError();
    }

    SDL_GetWindowSize( window, &win_width, &win_height );

    front = SDL_GetWindowSurface( window );

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
    SDL_Rect rect;
    rect.w = 16;
    rect.h = 16;

    WhiteNoise *wn = new WhiteNoise( 40, 30 );

    srand( stupid );
    SDL_FillRect( front, NULL, 0x00000000 );
    for( int j = 0; j < 40; j++ ) {
        for( int i = 0; i < 30; i++ ) {
            blockColor[j][i] = 255;
            for( int shift = 0; shift <= 3; shift++ ) {
                blockColor[j][i] = blockColor[j][i] << 8;
                blockColor[j][i] = static_cast <int> (wn->getValue(j, i)*255);
            }

            rect.x = j*16;
            rect.y = i*16;
            SDL_FillRect( front, &rect, blockColor[j][i]);
        }
    }

    stupid++;
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
