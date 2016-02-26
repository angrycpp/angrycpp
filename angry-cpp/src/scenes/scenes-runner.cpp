#include "scenes-runner.hpp"
#include "SDL.h"

namespace angrycpp {

void scenes_runner::run(graphics::renderer &renderer) {
    SDL_Event e;
    auto &game = manager.scenes.back();

    game->init();
    //todo: scene lifetime
    while(true) {
        while(SDL_PollEvent(&e)) {
            switch(e.type) {
            case SDL_QUIT:
                break;
            case SDL_KEYUP:
            case SDL_KEYDOWN:
                //todo: keys handling
                break;
            }
        }

        game->update(/* todo: ticks*/);
        game->draw(renderer);
    }
    game->finish();
}

}