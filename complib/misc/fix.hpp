#pragma once

#include <functional>

namespace a2ry {

template<class F> struct fix {
    F f;
    template<class... Args> decltype(auto) operator()(Args&&... args) const& {
        return f(std::ref(*this), std::forward<Args>(args)...);
    }
};

}  // namespace a2ry
