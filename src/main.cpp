#include <iostream>
#include <SDL.h>

#include "game.h"

int main(int argc, char* argv[]) {
    Game g;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    g.mainloop();

    SDL_Quit();
    return 0;
}

