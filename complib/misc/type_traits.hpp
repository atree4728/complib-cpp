#pragma once

#include <iostream>
#include <type_traits>
#include <utility>
#include <vector>

#include "alias.hpp"

namespace a2ry {

template<class T, std::size_t I>
concept has_tuple_element = requires(T t) {
                                typename std::tuple_element_t<I, std::remove_cvref_t<T>>;
                                { get<I>(t) } -> std::convertible_to<std::tuple_element_t<I, T>&>;
                            };

template<class T> concept tuple_like = not
std::is_reference_v<T>&& requires(T t) {
                             typename std::tuple_size<T>::type;
                             requires std::derived_from<std::tuple_size<T>,
                                                        std::integral_constant<std::size_t, std::tuple_size_v<T>>>;
                         }and[]<std::size_t... N>(std::index_sequence<N...>) {
    return (has_tuple_element<T, N> and ...);
}
(std::make_index_sequence<std::tuple_size_v<T>>());

template<class T, usize N> struct nth_vector {
    using type = std::vector<typename nth_vector<T, N - 1>::type>;
};
template<class T> struct nth_vector<T, 0> {
    using type = T;
};

template<class T, usize N> using nth_vector_t = nth_vector<T, N>::type;

template<class T> concept stream_extractable = requires(T& t) { std::cin >> t; } or is_1indexed<T>::value;
template<class T> concept stream_insertable = requires(T t) { std::cout << t; };

}  // namespace a2ry
