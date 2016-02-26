#pragma once

#include <tuple>

namespace angrycpp {

namespace input {

namespace mouse {

using pos_t = std::tuple<int, int>;

pos_t pos();

int x();
int y();


}

}

}