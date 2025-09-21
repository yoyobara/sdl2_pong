#pragma once

#include "layer.h"

class SubLayer : public Layer {
private:
  bool finish = false;

public:
  void handle_event(SDL_Event *e) {
    if (e->type == SDL_KEYUP) {
      finish = true;
    }
  }

  void draw(SDL_Renderer *renderer) {
    SDL_Rect rect = {400, 400, 200, 200};
    SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);

    SDL_RenderFillRect(renderer, &rect);
  }

  LayerAction getAction() {
    if (finish) {
      return Pop{};
    }

    return None{};
  }
};