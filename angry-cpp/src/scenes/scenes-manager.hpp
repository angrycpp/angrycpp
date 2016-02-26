#pragma once

#include "scene.hpp"

#include <list>
#include <memory>

namespace angrycpp {

struct scenes_manager {
    using scence_ptr_t = std::unique_ptr<scene>;
    using scenes_t = std::list<scence_ptr_t>;

    scenes_t scenes;
};

}