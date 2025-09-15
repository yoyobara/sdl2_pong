#pragma once

#include <SDL_render.h>
#include <SDL_video.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;

class Game {
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;

        bool running;

    public:
        Game();
        ~Game();

        void mainloop();
};
