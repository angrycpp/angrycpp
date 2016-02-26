#pragma once

#include "../graphics/renderer.hpp"

namespace angrycpp {

struct scene {
    virtual void init() = 0;
    virtual void update() = 0;
    virtual void draw(graphics::renderer &) = 0;
    virtual void finish() = 0;

    virtual ~scene() = default;
};

}