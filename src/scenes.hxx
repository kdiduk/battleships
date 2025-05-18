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

#ifndef SCENES_HXX
#define SCENES_HXX

#include <functional>
#include <memory>

#include <SDL3/SDL_render.h>


namespace scenes
{

    class scene final
    {
    public:
        class builder;

        virtual ~scene() = default;

        void on_render(SDL_Renderer* renderer);

        void on_event(SDL_Event* event);

    private:
        std::function<void(SDL_Renderer*)> on_render_callback;
        std::function<void(SDL_Event*)> on_event_callback;
    }; // class scene


    class scene::builder final
    {
    public:

        void set_on_render_callback(std::function<void(SDL_Renderer*)> callback);

        void set_on_event_callback(std::function<void(SDL_Event*)> callback);

        std::shared_ptr<scene> build();

    private:
        std::function<void(SDL_Renderer*)> on_render_callback;
        std::function<void(SDL_Event*)> on_event_callback;
    }; // class scene_builder


    void set_current_scene(std::shared_ptr<scene> scene);


    std::shared_ptr<scene> get_current_scene();

} // namespace scenes

#endif // SCENES_HXX
