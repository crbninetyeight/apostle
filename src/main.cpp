/*	APOSTLE: a post-apocalyptic roguelike for Linux
 *	developed by Christian Byrne <christianbyrne2012@gmail.com>
 *
 *	apostle is in early stages of development. Bugs are guaranteed
 *	to ensue.
 *
 *	Development of apostle is carried out publicly on my GitHub repo:
 *	    https://github.com/jenerick/apostle
 *	Feel free to make a pull request or something.			*/

// STANDARD libraries
//#include <iostream>
#include <cstring>

// APOSTLE libraries
#include "world.hpp"
#include "window.hpp"
#include "tools.hpp"

using namespace Tools::Location;

int main(int argc, char** argv)
{
    ApoWindow *window;
    SDL_Event event;

    Actor *actor;
    World *world;

/*
    std::string input;  // input string.
    bool interactive = false;

    std::cout << '\n';  // beginning newline to seperate apostle's output.
    print_init_msg();
    std::cout << '\n';
    handle_arguments(argc, argv, &interactive);
    if (interactive) doinput(&input);
*/

    SDL_Init( SDL_INIT_VIDEO );

    window = new ApoWindow( "apostleSDL", 17*32, 12*32 );
    world = new World( 51, 51 );
    actor = new Actor();
    actor->setPosition( 0, 0 );

    world->setActor( actor );

    int actorX, actorY;
    actor->getPosition( &actorX, &actorY );

    while ( window != NULL ) {
        while ( window->isEvent() ) {
            event = window->getEvent();
            switch ( event.type ) {
                case SDL_QUIT:
                delete window;
                window = NULL;
                break;

                case SDL_KEYDOWN:
                switch ( event.key.keysym.sym ) {
                    case SDLK_ESCAPE:
                    delete window;
                    window = NULL;
                    break;

                    case SDLK_KP_8:
                    case SDLK_UP:
                    actor->setPosition( actorX, actorY-1 );
                    break;

                    case SDLK_KP_2:
                    case SDLK_DOWN:
                    actor->setPosition( actorX, actorY+1 );
                    break;

                    case SDLK_KP_4:
                    case SDLK_LEFT:
                    actor->setPosition( actorX-1, actorY );
                    break;

                    case SDLK_KP_6:
                    case SDLK_RIGHT:
                    actor->setPosition( actorX+1, actorY );
                    break;

                    case SDLK_KP_7:
                    actor->setPosition( actorX-1, actorY-1 );
                    break;

                    case SDLK_KP_9:
                    actor->setPosition( actorX+1, actorY-1 );
                    break;

                    case SDLK_KP_3:
                    actor->setPosition( actorX+1, actorY+1 );
                    break;

                    case SDLK_KP_1:
                    actor->setPosition( actorX-1, actorY+1 );
                    break;
                }
            }
        }

        world->setActor( actor );

        window->clearWindow();
        window->drawViewport( actor, world );
        window->updateWindow();

        actor->getPosition( &actorX, &actorY );
        SDL_Delay( 50 );
    }

    delete world;

    return 0;
}
