// ---------------------------------------------------------------------------------------------- //
//  Arthur Sicard
//
//      g++ -std=c++17
//
//  
// ---------------------------------------------------------------------------------------------- //

#include <SDL2/SDL.h>
#include <iostream>

#include "player.hpp"
#include "input.hpp"

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 600;
const int FPS_LIMIT = 33;


// -- Main -------------------------------------------------------------------------------------- //

int main() 
{
    cout << endl << "lanch prog";

    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    int statut = EXIT_FAILURE;

    if (SDL_Init(SDL_INIT_VIDEO != 0)) {
        cerr << endl << "Erreur SDL_Init : " << SDL_GetError();
        return EXIT_FAILURE;
    }

    window = SDL_CreateWindow("Simple Game", 
                            SDL_WINDOWPOS_UNDEFINED, // à changer
                            SDL_WINDOWPOS_UNDEFINED, // à changer
                            SCREEN_WIDTH, 
                            SCREEN_HEIGHT, 
                            SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        cerr << endl << "Erreur SDL_CreateWindow : " << SDL_GetError();
        SDL_Quit();
        return EXIT_FAILURE;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        cerr << endl << "Erreur SDL_CreateRenderer : " << SDL_GetError();
        SDL_DestroyWindow(window);
        SDL_Quit();
        return EXIT_FAILURE;
    }

        // f = freq (speed of reponse f->+ sp->+)
        // z = amplitude of vibration (z=1 not stabilize, z<1 vibrate, z=1 crit, z>1 not vibra)
        // r = systeme reponse (r>1 overshot, r=1 imidiate, 0<r<1 take time, r<0 anticipate)
    Player player(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 10, 10, 5, 10, 8, 0.95, -0.5); 
    // 4.5, 0.5, 0     late to stop
    // 4.5, 1, 0    imidiately
    // 6, 0.95, -0.5       perfect
    Input input;
    unsigned int frame_limit = 0;

    while (!input.quitRequested()) {
        input.update(); 

        // Clear the screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Move and draw the player
        player.handleInput(input);
        player.move();
        player.displayOn(renderer);

        // Update the screen
        SDL_RenderPresent(renderer);

        // à refaire
        frame_limit = SDL_GetTicks() + FPS_LIMIT;
        SDL_Delay(frame_limit - SDL_GetTicks());
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    std::cout << std::endl << "Fin du programme" << std::endl;
    return statut;
}