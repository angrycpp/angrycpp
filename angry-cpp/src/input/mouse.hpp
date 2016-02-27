#pragma once

#include <tuple>

namespace angrycpp {

namespace input {

namespace mouse {

struct data {
    int x, y;
    struct button_pressed_t {
        bool left, middle, right;
    } button_pressed;
};

data get();

}

}

}