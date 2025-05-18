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

#include "main_scene.hxx"

#include <string>

namespace main_scene
{
    static const std::string game_title = "Battleships";
    static constexpr auto text_scale = 4.0f;

    void on_render(SDL_Renderer* renderer)
    {
        int w = 0, h = 0;
        SDL_GetRenderOutputSize(renderer, &w, &h);
        SDL_SetRenderScale(renderer, text_scale, text_scale);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        const auto x = ((w / text_scale) - SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE * game_title.length()) / 2;
        const auto y = ((h / text_scale) - SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE) / 2;
        SDL_RenderDebugText(renderer, x, y, game_title.c_str());
        SDL_RenderPresent(renderer);
    }


    std::shared_ptr<scenes::scene> create_main_scene()
    {
        scenes::scene::builder builder;
        builder.set_on_render_callback(main_scene::on_render);
        return builder.build();
    }

} // namespace main_scene

// EOF
