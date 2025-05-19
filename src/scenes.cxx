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

#include "scenes.hxx"

namespace scenes
{
    static std::shared_ptr<scene> current_scene = nullptr;

    void scene::on_init()
    {
        if (on_init_callback)
            on_init_callback();
    }


    void scene::on_render()
    {
        if (on_render_callback)
            on_render_callback();
    }


    void scene::on_event(SDL_Event* event)
    {
        if (on_event_callback)
            on_event_callback(event);
    }


    void scene::builder::set_on_init_callback(std::function<void()> callback)
    {
        on_init_callback = callback;
    }

    
    void scene::builder::set_on_render_callback(std::function<void()> callback)
    {
        on_render_callback = callback;
    }

    
    void scene::builder::set_on_event_callback(std::function<void(SDL_Event*)> callback)
    {
        on_event_callback = callback;
    }


    std::shared_ptr<scene> scene::builder::build()
    {
        auto new_scene = std::make_shared<scene>();
        
        new_scene->on_init_callback = on_init_callback;
        new_scene->on_render_callback = on_render_callback;
        new_scene->on_event_callback = on_event_callback;
        
        return new_scene;
    }

    
    void set_current_scene(std::shared_ptr<scene> scene)
    {
        current_scene = scene;
        if (scene)
            scene->on_init();
    }

    
    std::shared_ptr<scene> get_current_scene()
    {
        return current_scene;
    }

} // namespace scenes