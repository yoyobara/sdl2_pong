#pragma once

#include <SDL_events.h>
#include <SDL_render.h>

class Layer;

struct Push {
  std::unique_ptr<Layer> layer;
};
struct Replace {
  std::unique_ptr<Layer> layer;
};
struct Pop {};
struct None {};

using LayerAction = std::variant<None, Pop, Push, Replace>;

class Layer {
public:
  virtual void handle_event(SDL_Event *e) {};
  virtual void update(double dt) {};
  virtual void draw(SDL_Renderer *renderer) {};
  virtual LayerAction getAction() { return None{}; };
};
