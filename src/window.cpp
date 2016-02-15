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
    int tile_width  = win_width/rect.w;
    int tile_height = win_height/rect.h;

    WhiteNoise *red = new WhiteNoise( tile_width, tile_height, stupid+0 );
    WhiteNoise *grn = new WhiteNoise( tile_width, tile_height, stupid+1 );
    WhiteNoise *blu = new WhiteNoise( tile_width, tile_height, stupid+2 );

    srand( stupid );
    SDL_FillRect( front, NULL, 0x00000000 );
    for( int j = 0; j < tile_width; j++ ) {
        for( int i = 0; i < tile_height; i++ ) {
            blockColor[j][i] = 255 << 24;
            blockColor[j][i] |= static_cast<int>(blu->getValue(j, i)*255) << 0;
            blockColor[j][i] |= static_cast<int>(grn->getValue(j, i)*255) << 8;
            blockColor[j][i] |= static_cast<int>(red->getValue(j, i)*255) << 16;

            rect.x = j*rect.w;
            rect.y = i*rect.h;
            SDL_FillRect( front, &rect, blockColor[j][i]);
        }
    }

    delete red;
    delete grn;
    delete blu;
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
