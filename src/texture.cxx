#include "texture.hxx"

#include <SDL3_image/SDL_image.h>
#include <SDL3/SDL_log.h>

namespace battleships
{
    texture::texture(SDL_Texture* sdl_texture)
        : sdl_texture(sdl_texture)
    {
    }
    
    
    std::shared_ptr<texture> texture::load(const std::string& path, SDL_Renderer* renderer)
    {
        auto sdl_texture = IMG_LoadTexture(renderer, path.c_str());
        if (!sdl_texture) {
            SDL_Log("Couldn't load texture: %s", SDL_GetError());
            return nullptr;
        }
        
        return std::shared_ptr<texture>(new texture(sdl_texture));
    }
    

    texture::~texture()
    {
        if (sdl_texture)
        {
            SDL_DestroyTexture(sdl_texture);
            sdl_texture = nullptr;
        }
    }


    SDL_Texture* texture::get_texture() const
    {
        return sdl_texture;
    }

} // namespace battleships

// EOF