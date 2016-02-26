#include "game-core.hpp"

#include "SDL.h"

namespace angrycpp {

namespace game {

void core::init() {
    SDL_Init(SDL_INIT_EVERYTHING);
}

void core::finish() {
    SDL_Quit();
}

}

}