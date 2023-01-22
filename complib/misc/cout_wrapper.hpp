#pragma once

#include "alias.hpp"
#include "type_traits.hpp"

namespace io_config {

inline auto sep = " ";
inline auto eoln = "\n";
inline auto yes = "Yes";
inline auto no = "No";

}  // namespace io_config

namespace a2ry {

template<class T> inline auto print(T&& x) -> void {
    if constexpr (stream_insertable<T>) {
        if constexpr (std::same_as<std::remove_cvref<T>, bool>) std::cout << (x ? io_config::yes : io_config::no);
        else std::cout << x;
    } else if constexpr (tuple_like<T>) {
        [&]<usize... I>(std::index_sequence<I...>)->void {
            (
                [&] {
                    print(std::forward<std::tuple_element_t<I, T>>(get<I>(x)));
                    if constexpr (I + 1 != std::tuple_size_v<T>) print(' ');
                }(),
                ...);
        }
        (std::make_index_sequence<std::tuple_size_v<T>>());
    } else if constexpr (std::ranges::forward_range<T>) {
        for (auto it = std::ranges::begin(x); it != std::ranges::end(x); ++it) {
            print(std::forward<decltype(*it)>(*it));
            if (std::ranges::next(it) != std::ranges::end(x)) print(io_config::sep);
        }
    } else {
        static_assert(
            requires(T) { requires(false); }, "print: got an unexpented type");
    }
}

template<class... Args> inline auto print(Args&&... args) -> void {
    print(std::tuple{ std::forward<Args>(args)... });
}

template<class... Args> inline auto println(Args&&... args) -> void {
    print(std::forward<Args>(args)...);
    print(io_config::eoln);
}

template<class... Args> [[noreturn]] inline auto drop(Args&&... args) -> void {
    println(std::forward<Args>(args)...);
    exit(0);
}

}  // namespace a2ry
