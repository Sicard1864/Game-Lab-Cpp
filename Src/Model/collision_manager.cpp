#include "Model/collision_manager.hpp"

bool CollisionManager::checkCollision(const SDL_Rect& a, const SDL_Rect& b) {
    // Check if two rectangles (a and b) overlap
    if (a.x + a.w <= b.x) return false;
    if (a.x >= b.x + b.w) return false;
    if (a.y + a.h <= b.y) return false;
    if (a.y >= b.y + b.h) return false;
    return true;
}
