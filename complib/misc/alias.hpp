#pragma once

#include <cstddef>
#include <cstdint>
#include <type_traits>

namespace a2ry {

using i32 = std::int_fast32_t;
using i64 = std::int_fast64_t;
using u32 = std::uint_fast32_t;
using u64 = std::uint_fast64_t;
using usize = std::size_t;
using isize = std::ptrdiff_t;

constexpr auto operator""_i32(unsigned long long n) noexcept {
    return static_cast<i32>(n);
}
constexpr auto operator""_i64(unsigned long long n) noexcept {
    return static_cast<i64>(n);
}
constexpr auto operator""_u32(unsigned long long n) noexcept {
    return static_cast<u32>(n);
}
constexpr auto operator""_u64(unsigned long long n) noexcept {
    return static_cast<u64>(n);
}
constexpr auto operator""_uz(unsigned long long n) noexcept {
    return static_cast<usize>(n);
}
constexpr auto operator""_iz(unsigned long long n) noexcept {
    return static_cast<isize>(n);
}

template<class T> struct is_1indexed: std::false_type {};
#define INDEXED_IMPL(type)                    \
    struct type##_##1 { using base = type; }; \
    template<> struct is_1indexed<type##_##1>: std::true_type {};
INDEXED_IMPL(int)
INDEXED_IMPL(i32)
INDEXED_IMPL(u32)
INDEXED_IMPL(i64)
INDEXED_IMPL(u64)
INDEXED_IMPL(usize)
#undef INDEXED_IMPL

}  // namespace a2ry
