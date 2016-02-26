#include "window.hpp"

namespace angrycpp {

window::window(size_t width, size_t height, const char *title) {
    handle.reset(
        SDL_CreateWindow(
            title,
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            static_cast<int>(width), static_cast<int>(height),
            SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL
        )
    );
}

}