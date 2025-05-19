// Copyright 2025 Kirill Diduk (kirill.diduk@gmail.com)
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include "game.hxx"
#include "main_scene.hxx"
#include "texture.hxx"

#include <SDL3/SDL.h>
#include <string>

namespace main_scene
{
    static const std::string game_title = "Battleships";
    static constexpr auto text_scale = 4.0f;
    
    struct main_scene_data {
        std::shared_ptr<battleships::texture> texture;
    };


    void on_init(std::shared_ptr<main_scene_data> data)
    {
        SDL_Log("Initializing main scene");
        
        SDL_Renderer* renderer = battleships::game::instance()->get_renderer();
        data->texture = battleships::texture::load("assets/ship.png", renderer);
        if (!data->texture)
        {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to load texture");
        }
    }


    void on_render(std::shared_ptr<main_scene_data> data)    
    {
        SDL_Renderer* renderer = battleships::game::instance()->get_renderer();
        int w = 0, h = 0;
        SDL_GetRenderOutputSize(renderer, &w, &h);
        SDL_SetRenderScale(renderer, text_scale, text_scale);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        const auto x = ((w / text_scale) - SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE * game_title.length()) / 2;
        const auto y = ((h / text_scale) - SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE) / 2;
        SDL_RenderDebugText(renderer, x, y, game_title.c_str());
        
        // SDL_SetRenderScale(renderer, 1.0f, 1.0f);
        SDL_FRect rect = { 0.0f, 0.0f, 16.0f, 16.0f};

        SDL_RenderTexture(renderer, data->texture->get_texture(), nullptr, &rect);
        
        SDL_RenderPresent(renderer);
    }


    std::shared_ptr<scenes::scene> create_main_scene()
    {
        auto scene_data = std::make_shared<main_scene_data>();

        scenes::scene::builder builder;
        
        builder.set_on_init_callback(
            [scene_data]() {
                on_init(scene_data);
            }
        );
        builder.set_on_render_callback(
            [scene_data]() {
                on_render(scene_data);
            }
        );
        
        return builder.build();
    }

} // namespace main_scene

// EOF
