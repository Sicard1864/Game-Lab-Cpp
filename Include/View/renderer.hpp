#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SDL2/SDL.h>
#include "Model/entity.hpp"

class Renderer {
public:
    Renderer(SDL_Window* window);
    ~Renderer();

    void clear();
    void present();
    void draw(Entity& entity);
    void setDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

private:
    SDL_Renderer* renderer;
};

#endif
