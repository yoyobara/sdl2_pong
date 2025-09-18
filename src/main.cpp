#include <cstdlib>
#include <SDL.h>

#include "game.h"

int main(int argc, char *argv[])
{
    Game g;

    g.mainloop();

    return EXIT_SUCCESS;
}
