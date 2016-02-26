#include "mouse.hpp"

#include "SDL.h"

namespace angrycpp {

input::mouse::pos_t input::mouse::pos() {
    int x, y;
    SDL_GetMouseState(&x, &y);
    return std::make_tuple(x, y);
}

int input::mouse::x() {
    return std::get<0>(pos());
}

int input::mouse::y() {
    return std::get<1>(pos());
}

}