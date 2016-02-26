#include "renderer.hpp"

namespace angrycpp {

namespace graphics {

renderer::renderer(angrycpp::window &window) {
    auto ptr = SDL_CreateRenderer(window.handle.get(), -1, SDL_RENDERER_ACCELERATED);
    handle.reset(ptr);
}

void renderer::begin(SDL_Color background_color) {
    auto renderer_ptr = handle.get();
    SDL_SetRenderDrawColor(
        renderer_ptr,
        background_color.r,
        background_color.g,
        background_color.b,
        background_color.a
        );
    SDL_RenderClear(renderer_ptr);
}

void renderer::end() {
    SDL_RenderPresent(handle.get());
}

void renderer::draw(SDL_Texture *texture, int x, int y) {
    int w, h;
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    SDL_Rect dest = { x, y, w, h };
    if(SDL_RenderCopy(handle.get(), texture, NULL, &dest)) {
        //todo: wrap in proper exception
        throw SDL_GetError();
    }
}

void renderer::draw(SDL_Rect rectangle, SDL_Color c) {
    auto renderer_ptr = handle.get();
    SDL_SetRenderDrawColor(renderer_ptr, c.r, c.g, c.b, c.a);
    SDL_RenderDrawRect(renderer_ptr, &rectangle);
}

}

}