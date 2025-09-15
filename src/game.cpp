#include "game.h"

#include <SDL_events.h>
#include <stdexcept>

#include <SDL_render.h>
#include <SDL_video.h>

Game::Game(): running(false) {
    if (SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer) < 0) {
        throw std::runtime_error("could not initialize sdl2 window and renderer");
    };
}

Game::~Game() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void Game::mainloop() {
    SDL_Event e;

    running = true;

    while (running) {

        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                running = false;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 128, 255, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }
}
