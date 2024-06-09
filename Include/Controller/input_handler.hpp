// -- HEADER ------------------------------------------------------------------------------------ //

#ifndef INPUTHANDLER_HPP
#define INPUTHANDLER_HPP

#include <SDL2/SDL.h>
#include <iostream>
using namespace std;


enum class Direction {
    NONE,
    UP,
    UP_RIGHT,
    RIGHT,
    DOWN_RIGHT,
    DOWN,
    DOWN_LEFT,
    LEFT,
    UP_LEFT,
};

struct Coordinate {
    double x;
    double y;
};


// -- Class ------------------------------------------------------------------------------------- //

class InputHandler
{
    public:
    // constructors
        InputHandler();
        ~InputHandler();

    // accessors
        bool isKeyPressed(SDL_Scancode key) const;
        bool isKeyPressed(SDL_KeyCode key) const;
        bool isMouseButtonPressed(Uint8 button) const;
        int getMouseX() const;
        int getMouseY() const;
        int getMouseRelX() const;
        int getMouseRelY() const;
        int getMouseWheelX() const;
        int getMouseWheelY() const;
        Direction getDirection() const;

    // methodes
        void update();
        bool quitRequested() const;

    private:
    // attributs
        SDL_bool keyStates[SDL_NUM_SCANCODES];
        SDL_bool mouseStates[6];
        int mouseX, mouseY, mouseRelX, mouseRelY, mouseWheelX, mouseWheelY;
        bool quitFlag;

    // privates methodes
        void resetStates();
};

#endif
