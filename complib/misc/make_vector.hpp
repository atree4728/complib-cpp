#pragma once

#include <vector>

#include "alias.hpp"

namespace a2ry {

template<class T, usize N, usize I = 0> auto make_vector(usize (&&sizes)[N], T&& x = T{}) {
    if constexpr (I == N) {
        return std::forward<T>(x);
    } else {
        return std::vector(sizes[I], make_vector<T, N, I + 1>(std::forward<usize[N]>(sizes), std::forward<T>(x)));
    }
}

}  // namespace a2ry
