#pragma once

#include <memory>
#include <functional>

namespace angrycpp {

template<typename T>
using c_api_resource = std::unique_ptr<T, std::function<void(T*)>>;

}