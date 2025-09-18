#include "layers_manager.h"
#include "utils/variant_overloaded.h"

void LayerManager::handle_event(SDL_Event *e) {
  layers_stack.top()->handle_event(e);
}

void LayerManager::update(double dt) {
  layers_stack.top()->update(dt);

  std::visit(
      overloaded{[this](Push p) { layers_stack.push(std::move(p.layer)); },
                 [this](Replace rp) {
                   layers_stack.pop();
                   layers_stack.push(std::move(rp.layer));
                 },
                 [this](Pop) { layers_stack.pop(); }, [this](None) {}},
      layers_stack.top()->getAction());
}

void LayerManager::draw(SDL_Renderer *renderer) {
  layers_stack.top()->draw(renderer);
}

void LayerManager::push(std::unique_ptr<Layer> l) {
  layers_stack.push(std::move(l));
}