#pragma once

#include "scenes-manager.hpp"

namespace angrycpp {

struct scenes_runner {
    scenes_manager &manager;

    void run(graphics::renderer &renderer);
};

}