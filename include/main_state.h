#pragma once

#include <SDL_events.h>
#include <SDL_keycode.h>
#include <SDL_pixels.h>

#include <SDL_render.h>
#include <array>
#include <cstdlib>
#include <iostream>

#include "state.h"

class MainState : State {
    private:
        std::array<uint8_t, 4> color;

    public:

        MainState(): color{0xff, 0xff, 0xff, 0xff} {
            std::cout << unsigned(color[0]) << " " << (unsigned)color[1] << " " << (unsigned)color[2] << " " << (unsigned)color[3] << std::endl;
        }

        void handle_event(SDL_Event *e) override {
            if (e->type == SDL_KEYUP && e->key.keysym.sym == SDLK_SPACE) {
                for (auto it = color.begin() ; it < color.end() - 1 ; it++) {
                    *it = std::rand() % 256;
                }
            }
        }

        void update(double dt) override {}

        void draw(SDL_Renderer* renderer) override {
            SDL_SetRenderDrawColor(renderer, color[0], color[1], color[2], color[3]);
            SDL_RenderClear(renderer);
        }
};
