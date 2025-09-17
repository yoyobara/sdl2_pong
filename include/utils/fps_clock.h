#pragma once

#include <SDL2/SDL.h>

class FPSClock {
public:
    explicit FPSClock(float targetFps);

    void tick();
    float get_delta_time() const;

private:
    float targetFps;
    Uint32 frameDelay;
    Uint32 lastTick;
};

