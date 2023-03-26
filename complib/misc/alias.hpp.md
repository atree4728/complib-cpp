---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: complib/ds/union_find.hpp
    title: Union Find
  - icon: ':heavy_check_mark:'
    path: complib/misc/cin_wrapper.hpp
    title: Cin Wrapper
  - icon: ':heavy_check_mark:'
    path: complib/misc/cout_wrapper.hpp
    title: Cout Wrapper
  - icon: ':warning:'
    path: complib/misc/make_vector.hpp
    title: "\u591A\u6B21\u5143 vector \u306E\u5BA3\u8A00"
  - icon: ':heavy_check_mark:'
    path: complib/misc/template.hpp
    title: Template
  - icon: ':heavy_check_mark:'
    path: complib/misc/type_traits.hpp
    title: Type Traits
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_11_D.test.cpp
    title: test/aoj/ALDS1_11_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/aplusb.test.cpp
    title: test/library_checker/aplusb.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/unionfind.test.cpp
    title: test/library_checker/unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"complib/misc/alias.hpp\"\n\n#include <cstddef>\n#include\
    \ <cstdint>\n#include <type_traits>\n\nnamespace a2ry {\n\nusing i32 = std::int_fast32_t;\n\
    using i64 = std::int_fast64_t;\nusing u32 = std::uint_fast32_t;\nusing u64 = std::uint_fast64_t;\n\
    using usize = std::size_t;\nusing isize = std::ptrdiff_t;\n\nconstexpr auto operator\"\
    \"_i32(unsigned long long n) noexcept {\n    return static_cast<i32>(n);\n}\n\
    constexpr auto operator\"\"_i64(unsigned long long n) noexcept {\n    return static_cast<i64>(n);\n\
    }\nconstexpr auto operator\"\"_u32(unsigned long long n) noexcept {\n    return\
    \ static_cast<u32>(n);\n}\nconstexpr auto operator\"\"_u64(unsigned long long\
    \ n) noexcept {\n    return static_cast<u64>(n);\n}\nconstexpr auto operator\"\
    \"_uz(unsigned long long n) noexcept {\n    return static_cast<usize>(n);\n}\n\
    constexpr auto operator\"\"_iz(unsigned long long n) noexcept {\n    return static_cast<isize>(n);\n\
    }\n\ntemplate<class T> struct is_1indexed: std::false_type {};\n#define INDEXED_IMPL(type)\
    \                    \\\n    struct type##_##1 { using base = type; }; \\\n  \
    \  template<> struct is_1indexed<type##_##1>: std::true_type {};\nINDEXED_IMPL(int)\n\
    INDEXED_IMPL(i32)\nINDEXED_IMPL(u32)\nINDEXED_IMPL(i64)\nINDEXED_IMPL(u64)\nINDEXED_IMPL(usize)\n\
    #undef INDEXED_IMPL\n\n}  // namespace a2ry\n"
  code: "#pragma once\n\n#include <cstddef>\n#include <cstdint>\n#include <type_traits>\n\
    \nnamespace a2ry {\n\nusing i32 = std::int_fast32_t;\nusing i64 = std::int_fast64_t;\n\
    using u32 = std::uint_fast32_t;\nusing u64 = std::uint_fast64_t;\nusing usize\
    \ = std::size_t;\nusing isize = std::ptrdiff_t;\n\nconstexpr auto operator\"\"\
    _i32(unsigned long long n) noexcept {\n    return static_cast<i32>(n);\n}\nconstexpr\
    \ auto operator\"\"_i64(unsigned long long n) noexcept {\n    return static_cast<i64>(n);\n\
    }\nconstexpr auto operator\"\"_u32(unsigned long long n) noexcept {\n    return\
    \ static_cast<u32>(n);\n}\nconstexpr auto operator\"\"_u64(unsigned long long\
    \ n) noexcept {\n    return static_cast<u64>(n);\n}\nconstexpr auto operator\"\
    \"_uz(unsigned long long n) noexcept {\n    return static_cast<usize>(n);\n}\n\
    constexpr auto operator\"\"_iz(unsigned long long n) noexcept {\n    return static_cast<isize>(n);\n\
    }\n\ntemplate<class T> struct is_1indexed: std::false_type {};\n#define INDEXED_IMPL(type)\
    \                    \\\n    struct type##_##1 { using base = type; }; \\\n  \
    \  template<> struct is_1indexed<type##_##1>: std::true_type {};\nINDEXED_IMPL(int)\n\
    INDEXED_IMPL(i32)\nINDEXED_IMPL(u32)\nINDEXED_IMPL(i64)\nINDEXED_IMPL(u64)\nINDEXED_IMPL(usize)\n\
    #undef INDEXED_IMPL\n\n}  // namespace a2ry\n"
  dependsOn: []
  isVerificationFile: false
  path: complib/misc/alias.hpp
  requiredBy:
  - complib/ds/union_find.hpp
  - complib/misc/template.hpp
  - complib/misc/type_traits.hpp
  - complib/misc/cin_wrapper.hpp
  - complib/misc/make_vector.hpp
  - complib/misc/cout_wrapper.hpp
  timestamp: '2023-01-22 16:59:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_11_D.test.cpp
  - test/library_checker/unionfind.test.cpp
  - test/library_checker/aplusb.test.cpp
documentation_of: complib/misc/alias.hpp
layout: document
title: Aliases
---

Rust 風の型 alias 集と、それらに対するユーザー定義リテラル。
