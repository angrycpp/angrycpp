#pragma once

#include "../helpers/c-api-resource.hpp"

#include "SDL.h"

#include <utility>

namespace angrycpp {

struct window {
    using handle_t = c_api_resource<SDL_Window>;
    handle_t handle = {nullptr, std::bind(SDL_DestroyWindow, std::placeholders::_1) };

    window(size_t width, size_t height, const char *title);
};

}