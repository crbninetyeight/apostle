#ifndef APO_WINDOW_HPP__
#define APO_WINDOW_HPP__

#include <SDL2/SDL.h>
#include "viewport.hpp"

/**
 * Window class:
 *   renders graphics and handles input.
 */
class ApoWindow
{
private:
    SDL_Window *window;

    SDL_Surface *front;
    Viewport *viewport;
    SDL_Event event;

    // are we serving events?
    //  events could be silenced for a number of reasons,
    //  such as waiting for an animation to complete or
    //  a process to finish.
    bool isServingEvents;

    int width;
    int height;

public:
    /* constructor and destructor */
     ApoWindow( const char* title, int width, int height );
    ~ApoWindow();

    void clearWindow();

    void drawSurface();
    int  drawSurface( SDL_Surface *surface );
    void drawViewport( Actor *actor, World *world );

    void updateWindow();

    /* event checking and polling */

    // returns true if there is an event in queue;
    // returns false if otherwise.
    bool isEvent();

    // returns the SDL_Event, given that the window
    // is serving them (in which NULL is returned).
    //
    // the only exception to the serving rule is when
    // one of the events in the queue are either ones
    // pertaining to an escape or quit.
    SDL_Event getEvent();
};

#endif // APO_WINDOW_HPP__
