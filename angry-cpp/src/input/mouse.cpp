#include "mouse.hpp"

#include "SDL.h"

namespace angrycpp {

input::mouse::data input::mouse::get() {
    int x, y;
    Uint32 state = SDL_GetMouseState(&x, &y);
    return data{
        x, y, {
            (state & SDL_BUTTON(1)) != 0,
            (state & SDL_BUTTON(2)) != 0,
            (state & SDL_BUTTON(3)) != 0
        }
    };
}

}