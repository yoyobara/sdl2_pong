#include <stdexcept>

#include <SDL.h>
#include <SDL_events.h>
#include <SDL_stdinc.h>
#include <SDL_timer.h>
#include <SDL_render.h>
#include <SDL_video.h>

#include "game.h"
#include "utils/fps_clock.h"
#include "constants.h"


Game::Game(): running(false) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        throw std::runtime_error("could not initialize sdl2");
    }

    if (SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer) != 0) {
        throw std::runtime_error("could not initialize sdl2 window and renderer");
    };
}

Game::~Game() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
}

void Game::mainloop() {
    SDL_Event e;

    FPSClock clock(FPS);
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

        clock.tick();
    }
}
