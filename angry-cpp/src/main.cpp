#include "SDL.h"
#undef main

#include "../dep/catch/run-tests.hpp"

int main(int argc, const char* argv[]) {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Quit();

    return run_tests(argc, argv);
}