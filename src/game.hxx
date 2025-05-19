#ifndef GAME_HXX
#define GAME_HXX

#include <memory>
#include <mutex>

#include <SDL3/SDL.h>


namespace battleships
{
    class game final
    {
    public:
        game(const game&) = delete;
        game& operator=(const game&) = delete;
        game(game&&) = delete;
        game& operator=(game&&) = delete;

        
        SDL_Window* get_window() const;
        SDL_Renderer* get_renderer() const;
        
        static game* instance();
        
        static void init(SDL_Window* window, SDL_Renderer* renderer);
    
    private:
        static std::unique_ptr<game> s_instance;
        static std::once_flag init_once_flag;

        explicit game(SDL_Window* window, SDL_Renderer* renderer);
        
        SDL_Window* window = nullptr;
        SDL_Renderer* renderer = nullptr;
    }; // class game

} // namespace battleships

#endif // GAME_HXX
