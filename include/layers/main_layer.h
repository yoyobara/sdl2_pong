#pragma once

#include "layer.h"

struct Color
{
  Uint8 r;
  Uint8 g;
  Uint8 b;
};

class MainLayer : public Layer
{
private:
  Color c;
  bool show_modal;

public:
  MainLayer();
  void handle_event(SDL_Event *e);
  void draw(SDL_Renderer *renderer);
  LayerAction getAction();
};