#pragma once

#include <memory>
#include <stack>
#include <variant>

#include "layer.h"

class LayerManager {
public:
  void handle_event(SDL_Event *e);
  void update(double dt);
  void draw(SDL_Renderer *renderer);

private:
  std::stack<std::unique_ptr<Layer>> layers_stack;
};
