// ---------------------------------------------------------------------------------------------- //
//  Arthur Sicard
//
//      g++ -std=c++17
//
//  
// ---------------------------------------------------------------------------------------------- //

#include <SDL2/SDL.h>
#include <iostream>

#include "Model/game_state.hpp"
#include "View/renderer.hpp"
#include "Controller/event_handler.hpp"

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 600;
const int FPS_LIMIT = 33;


// -- Main -------------------------------------------------------------------------------------- //

int main() 
{
    cout << endl << "lanch prog";

    SDL_Window *window = nullptr;

    if (SDL_Init(SDL_INIT_VIDEO != 0)) {
        cerr << endl << "Erreur SDL_Init : " << SDL_GetError();
        return EXIT_FAILURE;
    }

    window = SDL_CreateWindow("Le Lab", 
                            SDL_WINDOWPOS_UNDEFINED, // à changer
                            SDL_WINDOWPOS_UNDEFINED, // à changer
                            SCREEN_WIDTH, 
                            SCREEN_HEIGHT, 
                            SDL_WINDOW_SHOWN);
    // if (window == nullptr) {
    if (!window) {
        cerr << endl << "Erreur SDL_CreateWindow : " << SDL_GetError();
        SDL_Quit();
        return EXIT_FAILURE;
    }

    Renderer renderer(window);
    GameState gameState;

    Player player(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 10, 10, 5, 10, 7, 0.95, -0.5); 
    Entity entity(20, 20, 200, 50, 5, 10); 
    EventHandler event;
    unsigned int frame_limit = 0;

    bool isRunning = true;
    while (isRunning) {
        isRunning = !event.quitRequested();
        event.update(); 
        gameState.update(event);

        // Clear and update the screen
        renderer.setDrawColor(0, 0, 0, 255);
        renderer.clear();
        gameState.render(renderer);
        renderer.present();

        // à refaire
        frame_limit = SDL_GetTicks() + FPS_LIMIT;
        SDL_Delay(frame_limit - SDL_GetTicks());
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    std::cout << std::endl << "Fin du programme" << std::endl;
    return EXIT_SUCCESS;
}