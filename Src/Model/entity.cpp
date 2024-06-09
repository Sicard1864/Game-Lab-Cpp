// -- IMPLEMENTATION ---------------------------------------------------------------------------- //

#include "Model/entity.hpp"
#include <algorithm> 


// -- Constructors ------------------------------------------------------------------------------ //

Entity::Entity() : 
    w(4), 
    h(4),
    pos_pi({10, 10}),
    pos_i({10, 10}),
    pos({10, 10}),
    speed({0, 0}), 
    accel({0, 0}),
    direction(Direction::RIGHT),
    speedMax(5),
    accelMax(2)
{}

Entity::Entity(double _x, double _y, int _w, int _h, double _speedMax, double _accelMax) : 
    w(_w), 
    h(_h),
    pos_pi({_x, _y}),
    pos_i({_x, _y}),
    pos({_x, _y}),
    speed({0, 0}), 
    accel({0, 0}),
    direction(Direction::RIGHT),
    speedMax(_speedMax),
    accelMax(_accelMax)
{}


// -- Methods ----------------------------------------------------------------------------------- //

bool Entity::isCollide(const Coordinate &co) {
    if ((pos.x-w < co.x && co.x < pos.x+w) && (pos.y-h < co.y && co.y < pos.y+h)) {
        return true;
    }
    return false;
}

/*
bool Entity::isCollision(const Rectangle& rect1, const Rectangle& rect2) {
    // Vérifie si l'un des rectangles est à gauche de l'autre
    if (rect1.x + rect1.width < rect2.x || rect2.x + rect2.width < rect1.x) {
        return false;
    }
    // Vérifie si l'un des rectangles est à droite de l'autre
    if (rect1.x > rect2.x + rect2.width || rect2.x > rect1.x + rect1.width) {
        return false;
    }
    // Vérifie si l'un des rectangles est au-dessus de l'autre
    if (rect1.y + rect1.height < rect2.y || rect2.y + rect2.height < rect1.y) {
        return false;
    }
    // Vérifie si l'un des rectangles est en dessous de l'autre
    if (rect1.y > rect2.y + rect2.height || rect2.y > rect1.y + rect1.height) {
        return false;
    }
    // Si aucune des conditions ci-dessus n'est vérifiée, il y a une collision
    return true;
}*/

void Entity::handleInput(const EventHandler& input) {
    Coordinate co = {(double)input.getMouseX(), (double)input.getMouseY()};
    if (input.isMouseButtonPressed(SDL_BUTTON_LEFT) && isCollide({ co.x, co.y })) {
        pos.x = co.x;
        pos.y = co.y;
    }
}


void Entity::move() {
    speed.x += accel.x;
    speed.y += accel.y;

    if (speed.x > speedMax) {
        speed.x = speedMax;
    }
    if (speed.y > speedMax) {
        speed.y = speedMax;
    }

    pos.x += speed.x;
    pos.y += speed.y;
}

void Entity::render(SDL_Renderer* renderer) {
    SDL_Rect rect = { (int)pos.x - w/2, (int)pos.y - h/2, w, h };

    // Display the square
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderDrawRect(renderer, &rect);
    SDL_RenderFillRect(renderer, &rect);
}

