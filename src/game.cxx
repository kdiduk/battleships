#include "game.hxx"

namespace battleships
{
    std::unique_ptr<game> game::s_instance = nullptr;
    std::once_flag game::init_once_flag;
    
    game::game(SDL_Window* window, SDL_Renderer* renderer)
        : window(window), renderer(renderer)
    {
    }
    

    game* game::instance()
    {
        if (!s_instance)
        {
            return nullptr;
        }

        return s_instance.get();
    }
    
    
    void game::init(SDL_Window* window, SDL_Renderer* renderer)
    {
        std::call_once(init_once_flag, [window, renderer]() {
            s_instance.reset(new game(window, renderer));
        });
    }

    SDL_Window* game::get_window() const
    {
        return window;
    }

    SDL_Renderer* game::get_renderer() const
    {
        return renderer;
    }
}

// EOF