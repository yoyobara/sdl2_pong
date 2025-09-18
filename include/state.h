#pragma once

#include <SDL_events.h>
#include <SDL_render.h>

class State {
    public:
        virtual void handle_event(SDL_Event* e){};
        virtual void update(double dt){};
        virtual void draw(SDL_Renderer* renderer){};
};
