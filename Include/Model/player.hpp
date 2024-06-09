// -- HEADER ------------------------------------------------------------------------------------ //

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SDL2/SDL.h>
#include "Controller/event_handler.hpp"
#include "Model/entity.hpp"


// -- Class ------------------------------------------------------------------------------------- //

class Player : public Entity
{
    public:
    // constructors
        Player();
        Player(double _x, double _y, int _w, int _h, double _speedMax, double _accelMax);     
        // f = freq (speed of reponse f->+ sp->+)
        // z = amplitude of vibration (z=1 not stabilize, z<1 vibrate, z=1 crit, z>1 not vibra)
        // r = systeme reponse (r>1 overshot, r=1 imidiate, 0<r<1 take time, r<0 anticipate)
        Player(double _x, double _y, int _w, int _h, double _speedMax, double _accelMax, double f, 
                double z, double r);

    // methods
        void handleInput(const EventHandler&) override;
        tuple<Coordinate, Coordinate> coordinateUpdate();
        void move(const EventHandler& input);
        void render(SDL_Renderer*) override;

    private:
    // attributes
        double k1;
        double k2;
        double k3;
};

#endif
