#include "layers/main_layer.h"
#include "layers/sub_layer.h"

const Color DEFAULT = {5, 2, 1};

MainLayer::MainLayer() : c(DEFAULT), show_modal(true) {}

void MainLayer::handle_event(SDL_Event *e) {
  if (e->type == SDL_KEYUP) {
    c.r = rand() % 256;
    c.g = rand() % 256;
    c.b = rand() % 256;
  }
}

void MainLayer::draw(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(renderer);
}

LayerAction MainLayer::getAction() {
  if (show_modal) {
    show_modal = false;
    return Push{std::make_unique<SubLayer>()};
  }

  return None{};
}
