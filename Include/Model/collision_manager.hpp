#ifndef COLLISIONMANAGER_HPP
#define COLLISIONMANAGER_HPP

#include <SDL2/SDL.h>
#include "Model/entity.hpp"

class CollisionManager {
public:
    static bool checkCollision(const SDL_Rect& a, const SDL_Rect& b);
};

#endif
