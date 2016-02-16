#ifndef APO_WINDOW_HPP__
#define APO_WINDOW_HPP__

#include <SDL2/SDL.h>

/**
 * Window class:
 *   renders graphics and handles input.
 */
class ApoWindow
{
private:
    SDL_Window      *window;

    SDL_Surface *front;
    SDL_Event event;

    int width;
    int height;

public:
    /* constructor and destructor */
     ApoWindow( const char* title, int width, int height );
    ~ApoWindow();

    void clearWindow();
    void updateWindow();

    /* event checking and polling */

    // returns true if there is an event in queue;
    // returns false if otherwise.
    bool        isEvent();

    // returns the SDL_Event, given that there is
    // one in the queue (in which NULL is returned).
    SDL_Event   getEvent();
};

#endif // APO_WINDOW_HPP__
