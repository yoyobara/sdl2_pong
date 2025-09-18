#include "utils/fps_clock.h"

FPSClock::FPSClock(float targetFps)
    : targetFps(targetFps),
      frameDelay(static_cast<Uint32>(1000.0f / targetFps)),
      lastTick(SDL_GetTicks()) {}

void FPSClock::tick() {
  Uint32 now = SDL_GetTicks();
  Uint32 elapsed = now - lastTick;

  if (elapsed < frameDelay) {
    SDL_Delay(frameDelay - elapsed);
  }

  lastTick = SDL_GetTicks();
}

float FPSClock::get_delta_time() const {
  return static_cast<float>(frameDelay) / 1000.0f;
}
