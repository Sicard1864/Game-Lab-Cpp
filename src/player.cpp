// -- IMPLEMENTATION ---------------------------------------------------------------------------- //

#include "player.hpp"
#include <algorithm> 

const double PI = 3.14;


// -- Constructors ------------------------------------------------------------------------------ //

Player::Player() : 
    Entity(),
    k1(1 / (PI * 4.5)),
    k2(1 / ((2 * PI * 4.5) * (2 * PI * 4.5))),
    k3(0 * 1 / (2 * PI * 4.5))
{}

Player::Player(double _x, double _y, int _w, int _h, double _speedMax, double _accelMax) : 
    Entity(_x, _y, _w, _h, _speedMax, _accelMax),
    k1(1 / (PI * 4.5)),
    k2(1 / ((2 * PI * 4.5) * (2 * PI * 4.5))),
    k3(0 * 1 / (2 * PI * 4.5))
{}

Player::Player(double _x, double _y, int _w, int _h, double _speedMax, double _accelMax, 
                double f, double z, double r) : 
    Entity(_x, _y, _w, _h, _speedMax, _accelMax),
    k1(z / (PI * f)),
    k2(1 / ((2 * PI * f) * (2 * PI * f))),
    k3(r * z / (2 * PI * f))
{}


// -- Methods ----------------------------------------------------------------------------------- //

void Player::handleInput(const Input& input) {
    if (input.isKeyPressed(SDL_SCANCODE_T)) {
        if (w < 100) {
            h *= 1.2;
            w *= 1.2;
        }
    }
    if (input.isKeyPressed(SDL_SCANCODE_Y)) {
        if (w > 5) {
            h /= 1.2;
            w /= 1.2;
        }
    }
    if (input.getDirection() != Direction::NONE) {
        const double speedMaxDiago = speedMax / sqrt(2.0);
        direction = input.getDirection();
        switch (direction) {
            case Direction::UP:
                pos_i.x += 0;
                pos_i.y -= speedMax;
                break;
            case Direction::UP_RIGHT:
                pos_i.x += speedMaxDiago;
                pos_i.y -= speedMaxDiago;
                break;
            case Direction::RIGHT:
                pos_i.x += speedMax;
                break;
            case Direction::DOWN_RIGHT:
                pos_i.x += speedMaxDiago;
                pos_i.y += speedMaxDiago;
                break;
            case Direction::DOWN:
                pos_i.y += speedMax;
                break;
            case Direction::DOWN_LEFT:
                pos_i.x -= speedMaxDiago;
                pos_i.y += speedMaxDiago;
                break;
            case Direction::LEFT:
                pos_i.x -= speedMax;
                break;
            case Direction::UP_LEFT:
                pos_i.x -= speedMaxDiago;
                pos_i.y -= speedMaxDiago;
                break;
            default:
                // No movement if no valid direction
                break;
        }
    }
}

void Player::coordinateUpdate() {
    double T = 0.01667;
    Coordinate speed_e = {(pos_i.x - pos_pi.x) / T, (pos_i.y - pos_pi.y) / T};
    pos_pi = {pos_i.x, pos_i.y};
    //double k2_stad = std::max({k2, T * T / 2 + T * k1 / 2, T * k1});
    Coordinate pos_u = {pos.x + T*speed.x, pos.y + T*speed.y};
    Coordinate speed_u = {speed.x + T*(pos_i.x + k3*speed_e.x - pos_u.x - k1*speed.x) / k2,
            speed.y + T*(pos_i.y + k3*speed_e.y - pos_u.y - k1*speed.y) / k2};
    return pos_u, speed_u;

    //cout << endl << pos.x << "\t" << (int)pos.x << "\t" << pos_i.x << "\t" << (int)pos_i.x;
    //cout << endl << speed.x << "\t" << speed_e.x;
    //cout << endl << "k1: " << k1 << "\t" << "k2: " << k2 << "\t" << "k3: " << k3;
}

void Player::move() {
    Coordinate pos_futur, speed_futur = coordinateUpdate();
    Coordinate co = {(double)input.getMouseX(), (double)input.getMouseY()};
    if (!isCollide({ co.x, co.y })) {
        pos = pos_futur;
        speed = speed_futur;
    }
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
    int const d = w + 2 + w/2;
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
            break;
    }

    SDL_SetRenderDrawColor(renderer, 100, 255, 100, 255);
    SDL_Rect littleRect = { pointDirecX - w/4, pointDirecY - h/4, w/2, h/2 };
    SDL_RenderDrawRect(renderer, &littleRect);
    
}

