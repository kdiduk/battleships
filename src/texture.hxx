#ifndef TEXTURE_HXX
#define TEXTURE_HXX

#include <memory>
#include <string>

#include <SDL3/SDL_render.h>


namespace battleships
{
    class texture final
    {
        explicit texture(SDL_Texture* sdl_texture);
        
        texture(const texture&) = delete;
        texture& operator=(const texture&) = delete;
        texture(texture&&) = delete;
        texture& operator=(texture&&) = delete;
    
    public:
        static std::shared_ptr<texture> load(const std::string& path, SDL_Renderer* renderer);
        ~texture();

        SDL_Texture* get_texture() const;

    private:
        SDL_Texture* sdl_texture = nullptr;
        float pos_x = 0.0;
        float pos_y = 0.0;
        float scale_x = 1.0f;
        float scale_y = 1.0f;
    }; // class texture

} // namespace battleships

#endif // TEXTURE_HXX
