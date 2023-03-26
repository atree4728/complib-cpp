// Copyright (c) 2019 Azaika
// This file is based on [azaika/adsl](https://github.com/azaika/adsl/blob/master/include/adsl/algebra/data_type.hpp),
// which is published on [MIT License](https://opensource.org/license/mit/).

#pragma once

#include <concepts>

namespace a2ry::algebra {

template <class M>
concept magma = requires {
    typename M::value_type;
    {
        M::op(std::declval<M::value_type>(), std::declval<M::value_type>())
    } -> std::convertible_to<typename M::value_type>;
};

template <class M>
concept associative = true;

template <class M>
concept semigroup = magma<M> and associative<M>;

template <class M>
concept monoid = semigroup<M> and requires {
    { M::unit() } -> std::convertible_to<typename M::value_type>;
};

template <class G>
concept group = monoid<G> and requires {
    { G::inv(G::unit()) } -> std::convertible_to<typename G::value_type>;
};

class commutative_tag {};

template <class M>
concept commutative_monoid = monoid<M> and std::is_base_of_v<commutative_tag, M>;

template <class G>
concept commutative_group = group<G> and std::is_base_of_v<commutative_tag, G>;

template <class T>
concept monoidally_additionable = requires(T x, T y) {
    requires std::is_default_constructible_v<T>;
    { x + y } -> std::convertible_to<T>;
};

template <class T>
concept grouply_additionable = monoidally_additionable<T> and requires(T x) {
    { -x } -> std::convertible_to<T>;
};

template <class A>
concept left_action = requires {
    typename A::domain;
    typename A::space;
    {
        A::act(std::declval<A::domain::value_type>())(std::declval<A::space::value_type>())
    } -> std::convertible_to<typename A::space::value_type>;
};

template <class A>
concept monoidal_action = left_action<A> and commutative_monoid<typename A::domain>;

template <class F, class Domain, class Codomain>
concept monoidal_homomorphism =
    monoid<Domain> and monoid<Codomain> and
    std::convertible_to<std::invoke_result_t<F, typename Domain::value_type>, typename Codomain::value_type>;

template <class F, class M>
concept monoidal_endomorphism = monoidal_homomorphism<F, M, M>;

} // namespace a2ry::algebra
