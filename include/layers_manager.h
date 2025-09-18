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

  void push(std::unique_ptr<Layer> l);

private:
  std::stack<std::unique_ptr<Layer>> layers_stack;
};
