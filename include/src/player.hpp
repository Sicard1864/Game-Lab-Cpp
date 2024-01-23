// -- HEADER ------------------------------------------------------------------------------------ //

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SDL2/SDL.h>
#include "input.hpp"


struct Coordinate {
    double x;
    double y;
};


// -- Class ------------------------------------------------------------------------------------- //

class Player
{
    public:
    // constructors
        Player();
        Player(double _x, double _y, int _w, int _h, double _speedMax, double _accelMax);

    // methods
        void handleInput(const Input&);
        void move();
        void displayOn(SDL_Renderer*);

    private:
    // attributes
        int w;
        int h;
        Coordinate pos; 
        Coordinate speed;
        Coordinate accel;
        Direction direction; 
        
        double speedMax;
        double accelMax;
};

#endif
