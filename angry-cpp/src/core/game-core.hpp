#pragma once

#include <utility>

namespace angrycpp {
namespace game{

namespace core{
    void init();
    void finish();

    //todo: scope sensitive singleton
    struct guard {
        template<typename... Args>
        guard(Args&&... args) {
            game::core::init(std::forward<Args>(args)...);
        }

        ~guard() {
            game::core::finish();
        }
    };
}

}

}