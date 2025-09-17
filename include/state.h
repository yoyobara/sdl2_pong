
#include <SDL_events.h>

class State {
    public:
        virtual void handle_event(SDL_Event* e);
        virtual void update(double dt);
        virtual void draw();
};
