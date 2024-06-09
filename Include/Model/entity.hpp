// -- HEADER ------------------------------------------------------------------------------------ //

#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SDL2/SDL.h>
#include "Controller/event_handler.hpp"



// -- Class ------------------------------------------------------------------------------------- //

class Entity
{
    public:
    // constructors
        Entity();
        Entity(double _x, double _y, int _w, int _h, double _speedMax, double _accelMax);

    // methods
        virtual bool isCollide(const Coordinate &co);
        virtual void handleInput(const EventHandler&);
        virtual void move();
        virtual void displayOn(SDL_Renderer*);

    protected:
    // attributes
        int w;
        int h;
        Coordinate pos_pi;
        Coordinate pos_i;
        Coordinate pos;
        Coordinate speed;
        Coordinate accel;
        Direction direction; 
        
        double speedMax;
        double accelMax;
};

#endif
