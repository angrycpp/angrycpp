#pragma once

#include "../windows/window.hpp"
#include "../helpers/c-api-resource.hpp"

#include <utility>
#include <functional>

#include "SDL.h"

namespace angrycpp {

namespace graphics {

struct renderer {
    using handle_t = c_api_resource<SDL_Renderer>;
    handle_t handle = { nullptr, std::bind(SDL_DestroyRenderer, std::placeholders::_1) };

    renderer(angrycpp::window &window);

    void begin(SDL_Color background_color);
    void end();

    void draw(SDL_Texture *texture, int x, int y);
    void draw(SDL_Rect rectangle, SDL_Color color);
};

}

}