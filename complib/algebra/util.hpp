// Copyright (c) 2019 Azaika
// This file is based on [azaika/adsl](https://github.com/azaika/adsl/blob/master/include/adsl/algebra/type_util.hpp),
// which is published on [MIT License](https://opensource.org/license/mit/).

#pragma once

#include "data_type.hpp"
#include <optional>

namespace a2ry::algebra {

namespace impl {

template <class T, T identity, auto func, bool is_commutative> struct make_monoid {
    using value_type = T;

    static constexpr value_type unit() noexcept { return identity; }
    static constexpr value_type op(const value_type &x, const value_type &y) noexcept(noexcept(func(x, y))) {
        return func(x, y);
    }
};

template <class T, T identity, auto func> struct make_monoid<T, identity, func, true> : commutative_tag {
    using value_type = T;

    static constexpr value_type unit() noexcept { return identity; }
    static constexpr value_type op(const value_type &x, const value_type &y) noexcept(noexcept(func(x, y))) {
        return func(x, y);
    }
};

template <monoidally_additionable T, bool is_commutative> struct default_monoid {
    using value_type = T;

    static constexpr value_type unit() noexcept(noexcept(value_type{})) { return value_type{}; }
    static constexpr value_type op(const value_type &x, const value_type &y) noexcept(noexcept(x + y)) { return x + y; }
};

template <monoidally_additionable T> struct default_monoid<T, true> : commutative_tag {
    using value_type = T;

    static constexpr value_type unit() noexcept(noexcept(value_type{})) { return value_type{}; }
    static constexpr value_type op(const value_type &x, const value_type &y) noexcept(noexcept(x + y)) { return x + y; }
};

template <class T, T identity, auto func, auto inv_func, bool is_commutative> struct make_group {
    using value_type = T;

    static constexpr value_type unit() noexcept { return identity; }
    static constexpr value_type op(const value_type &x, const value_type &y) noexcept(noexcept(func(x, y))) {
        return func(x, y);
    }
    static constexpr value_type inv(const value_type &v) noexcept(noexcept(inv_func(v))) { return inv_func(v); }
};

template <class T, T identity, auto func, auto inv_func>
struct make_group<T, identity, func, inv_func, true> : commutative_tag {
    using value_type = T;

    static constexpr value_type unit() noexcept { return identity; }
    static constexpr value_type op(const value_type &x, const value_type &y) noexcept(noexcept(func(x, y))) {
        return func(x, y);
    }
    static constexpr value_type inv(const value_type &v) noexcept(noexcept(inv_func(v))) { return inv_func(v); }
};

template <grouply_additionable T, bool is_commutative> struct default_group {
    using value_type = T;

    static constexpr value_type unit() noexcept(noexcept(value_type{})) { return value_type{}; }
    static constexpr value_type op(const value_type &x, const value_type &y) noexcept(noexcept(x + y)) { return x + y; }
    static constexpr value_type inv(const value_type &v) noexcept(noexcept(-v)) { return -v; }
};

template <grouply_additionable T> struct default_group<T, true> : commutative_tag {
    using value_type = T;

    static constexpr value_type unit() noexcept(noexcept(value_type{})) { return value_type{}; }
    static constexpr value_type op(const value_type &x, const value_type &y) noexcept(noexcept(x + y)) { return x + y; }
    static constexpr value_type inv(const value_type &v) noexcept(noexcept(-v)) { return -v; }
};

} // namespace impl

template <semigroup G> struct to_monoid {
    using value_type = std::optional<typename G::value_type>;

    static value_type unit() noexcept { return std::nullopt; }
    static value_type op(const value_type &x, const value_type &y) noexcept(noexcept(G::op(*x, *y))) {
        if (x == std::nullopt) return y;
        if (y == std::nullopt) return x;
        return G::op(*x, *y);
    }
};

template <class T, T identity, auto func, bool is_commutative = false>
using make_monoid = impl::make_monoid<T, identity, func, is_commutative>;

template <monoidally_additionable T, bool is_commutative = std::is_arithmetic_v<T>>
using default_monoid = impl::default_monoid<T, is_commutative>;

template <class T, T identity, auto func, auto inv_func, bool is_commutative = false>
using make_group = impl::make_group<T, identity, func, inv_func, is_commutative>;

template <grouply_additionable T, bool is_commutative = std::is_signed_v<T>>
using default_group = impl::default_group<T, is_commutative>;

template <class D, class S, auto func>
    requires requires {
        {
            func(std::declval<typename D::value_type>(), std::declval<typename S::value_type>())
        } -> std::convertible_to<typename S::value_type>;
    }

struct make_action {
    using domain = D;
    using space = S;

    static constexpr auto
    act(const typename domain::value_type &v) noexcept(noexcept(func(v, std::declval<typename space::value_type>()))) {
        return [&v](const typename space::value_type &s) noexcept(noexcept(func(v, s))) { return func(v, s); };
    }
};
} // namespace a2ry::algebra
