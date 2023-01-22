#pragma once

#include <algorithm>
#include <concepts>
#include <deque>
#include <iostream>
#include <ranges>
#include <type_traits>
#include <utility>
#include <vector>

#include "alias.hpp"
#include "type_traits.hpp"

namespace a2ry {

template<class T>
    requires stream_extractable<T>
inline auto in() {
    if constexpr (is_1indexed<T>::value) {
        typename T::base x{};
        std::cin >> x;
        --x;
        return x;
    } else {
        T x{};
        std::cin >> x;
        return x;
    }
}

template<class T>
    requires tuple_like<T>
inline auto in() -> T {
    return []<usize... I>(std::index_sequence<I...>) {
        return T{ in<std::remove_cvref_t<std::tuple_element_t<I, T>>>()... };
    }
    (std::make_index_sequence<std::tuple_size_v<T>>());
}

template<class... Args>
    requires(sizeof...(Args) > 1)
inline auto in() -> std::tuple<Args...> {
    return in<std::tuple<Args...>>();
}

template<class C, usize N, usize I = 0>
    requires(N > 0)
inline auto in(const usize (&sizes)[N]) -> C {
    auto cv = std::views::iota(0_uz, sizes[I]) | std::views::transform([&](auto&&) {
                  if constexpr (I + 1 == N) {
                      return in<typename C::value_type>();
                  } else {
                      return in<typename C::value_type, N, I + 1>(sizes);
                  }
              })
            | std::views::common;
    if constexpr (std::constructible_from<C, decltype(std::ranges::begin(cv)), decltype(std::ranges::end(cv))>) {
        return C(std::ranges::begin(cv), std::ranges::end(cv));
    } else if constexpr (std::constructible_from<C, std::deque<typename C::value_type>>) {
        // std::queue and std::stack (until C++23...)
        return C(std::deque(std::ranges::begin(cv), std::ranges::end(cv)));
    } else {
        static_assert(
            requires(C) { requires(false); }, "in: the container is unconstructible from range");
    }
}

template<class T, usize N> inline auto in_vec(const usize (&sizes)[N]) {
    return in<nth_vector_t<T, N>>(sizes);
}

}  // namespace a2ry
