// -- IMPLEMENTATION ---------------------------------------------------------------------------- //

#include "player.hpp"


// -- Constructors ------------------------------------------------------------------------------ //

Player::Player() : 
    w(4), 
    h(4), 
    pos({10, 10}), 
    speed({0, 0}), 
    accel({0, 0}),
    direction(Direction::RIGHT),
    speedMax(5),
    accelMax(2)
{}

Player::Player(double _x, double _y, int _w, int _h, double _speedMax, double _accelMax) : 
    w(_w), 
    h(_h), 
    pos({_x, _y}), 
    speed({0, 0}), 
    accel({0, 0}),
    direction(Direction::RIGHT),
    speedMax(_speedMax),
    accelMax(_accelMax)
{}


// -- Methods ----------------------------------------------------------------------------------- //

void Player::handleInput(const Input& input) {
    if (input.getDirection() != Direction::NONE) {
        const double speedMaxDiago = speedMax / sqrt(2.0);
        direction = input.getDirection();
        switch (direction) {
            case Direction::UP:
                pos.y -= speedMax;
                break;
            case Direction::UP_RIGHT:
                pos.y -= speedMaxDiago;
                pos.x += speedMaxDiago;
                break;
            case Direction::RIGHT:
                pos.x += speedMax;
                break;
            case Direction::DOWN_RIGHT:
                pos.y += speedMaxDiago;
                pos.x += speedMaxDiago;
                break;
            case Direction::DOWN:
                pos.y += speedMax;
                break;
            case Direction::DOWN_LEFT:
                pos.y += speedMaxDiago;
                pos.x -= speedMaxDiago;
                break;
            case Direction::LEFT:
                pos.x -= speedMax;
                break;
            case Direction::UP_LEFT:
                pos.y -= speedMaxDiago;
                pos.x -= speedMaxDiago;
                break;
            default:
                // No movement if no valid direction
                break;
        }
    }
}


// vectorUpdate

void Player::move() {
    // Additional movement logic can be added here
}

void Player::displayOn(SDL_Renderer* renderer) {
    SDL_Rect rect = { (int)pos.x - w/2, (int)pos.y - h/2, w, h };

    // Display the square
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderDrawRect(renderer, &rect);
    SDL_RenderFillRect(renderer, &rect);

    // Calculate the position for the point based on the direction
    int pointDirecX = static_cast<int>(pos.x);
    int pointDirecY = static_cast<int>(pos.y);
    int const d = 10;
    int const diago_d = d / sqrt(2.0);
    switch (direction) {
        case Direction::UP:
            pointDirecY -= d;
            break;
        case Direction::UP_RIGHT:
            pointDirecX += diago_d;
            pointDirecY -= diago_d;
            break;
        case Direction::RIGHT:
            pointDirecX += d;
            break;
        case Direction::DOWN_RIGHT:
            pointDirecX += diago_d;
            pointDirecY += diago_d;
            break;
        case Direction::DOWN:
            pointDirecY += d;
            break;
        case Direction::DOWN_LEFT:
            pointDirecX -= diago_d;
            pointDirecY += diago_d;
            break;
        case Direction::LEFT:
            pointDirecX -= d;
            break;
        case Direction::UP_LEFT:
            pointDirecX -= diago_d;
            pointDirecY -= diago_d;
            break;
        default:
            // No point for an invalid direction
            break;
    }

    // Display the additional point
    SDL_SetRenderDrawColor(renderer, 100, 255, 100, 255);
    SDL_Rect littleRect = { pointDirecX - w/4, pointDirecY - h/4, w/2, h/2 };
    SDL_RenderDrawRect(renderer, &littleRect);
}

