#include <SDL_image.h>
#include <SDL_mixer.h>
#include <filesystem>

#include "resource_manager.h"

ResourceManager::ResourceManager(SDL_Renderer *renderer, fs::path resources_directory, bool preload) : base_path(std::move(resources_directory)), renderer(renderer)
{
}

SDL_Texture *ResourceManager::load_texture(const fs::path &texture_path)
{
    const fs::path normalized_path = texture_path.lexically_normal();

    if (this->textures.count(normalized_path))
    {
        return this->textures.at(normalized_path).get();
    }

    SDL_Texture *texture = IMG_LoadTexture(renderer, (base_path / texture_path).c_str());
    this->textures.emplace(normalized_path, texture_ptr(texture, SDL_DestroyTexture));

    return texture;
}

Mix_Chunk *ResourceManager::load_sound(const fs::path &sound_path)
{
    const fs::path normalized_path = sound_path.lexically_normal();

    if (this->sounds.count(normalized_path))
    {
        return this->sounds.at(normalized_path).get();
    }

    Mix_Chunk *sound = Mix_LoadWAV((base_path / sound_path).c_str());
    this->sounds.emplace(normalized_path, sound_ptr(sound, Mix_FreeChunk));

    return sound;
}
