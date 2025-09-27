#pragma once

#include <filesystem>
#include <memory>
#include <unordered_map>

#include <SDL_mixer.h>
#include <SDL_render.h>

namespace fs = std::filesystem;

using texture_ptr = std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)>;
using sound_ptr = std::unique_ptr<Mix_Chunk, decltype(&Mix_FreeChunk)>;

class ResourceManager
{
public:
  SDL_Renderer *renderer;
  fs::path base_path;

  std::unordered_map<fs::path, texture_ptr>
      textures;

  std::unordered_map<fs::path, sound_ptr>
      sounds;

public:
  ResourceManager(SDL_Renderer *renderer, fs::path resources_directory, bool preload);

  SDL_Texture *load_texture(const fs::path &texture_path);
  Mix_Chunk *load_sound(const fs::path &sound_path);
};
