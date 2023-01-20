---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: complib/ds/union_find.hpp
    title: Union Find
  - icon: ':warning:'
    path: complib/misc/make_vector.hpp
    title: "\u591A\u6B21\u5143 vector \u306E\u5BA3\u8A00"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/ALDS1_11_D.test.cpp
    title: test/aoj/ALDS1_11_D.test.cpp
  - icon: ':x:'
    path: test/library_checker/unionfind.test.cpp
    title: test/library_checker/unionfind.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"complib/misc/alias.hpp\"\n\n#include <cstddef>\n#include\
    \ <cstdint>\n\nnamespace a2ry {\n\nusing i32 = std::int_fast32_t;\nusing i64 =\
    \ std::int_fast64_t;\nusing u32 = std::uint_fast32_t;\nusing u64 = std::uint_fast64_t;\n\
    using usize = std::size_t;\nusing isize = std::ptrdiff_t;\n\nconstexpr auto operator\"\
    \"_i32(unsigned long long n) noexcept {\n    return static_cast<i32>(n);\n}\n\
    constexpr auto operator\"\"_i64(unsigned long long n) noexcept {\n    return static_cast<i64>(n);\n\
    }\nconstexpr auto operator\"\"_u32(unsigned long long n) noexcept {\n    return\
    \ static_cast<u32>(n);\n}\nconstexpr auto operator\"\"_u64(unsigned long long\
    \ n) noexcept {\n    return static_cast<u64>(n);\n}\nconstexpr auto operator\"\
    \"_uz(unsigned long long n) noexcept {\n    return static_cast<usize>(n);\n}\n\
    constexpr auto operator\"\"_iz(unsigned long long n) noexcept {\n    return static_cast<isize>(n);\n\
    }\n\n}  // namespace a2ry\n"
  code: "#pragma once\n\n#include <cstddef>\n#include <cstdint>\n\nnamespace a2ry\
    \ {\n\nusing i32 = std::int_fast32_t;\nusing i64 = std::int_fast64_t;\nusing u32\
    \ = std::uint_fast32_t;\nusing u64 = std::uint_fast64_t;\nusing usize = std::size_t;\n\
    using isize = std::ptrdiff_t;\n\nconstexpr auto operator\"\"_i32(unsigned long\
    \ long n) noexcept {\n    return static_cast<i32>(n);\n}\nconstexpr auto operator\"\
    \"_i64(unsigned long long n) noexcept {\n    return static_cast<i64>(n);\n}\n\
    constexpr auto operator\"\"_u32(unsigned long long n) noexcept {\n    return static_cast<u32>(n);\n\
    }\nconstexpr auto operator\"\"_u64(unsigned long long n) noexcept {\n    return\
    \ static_cast<u64>(n);\n}\nconstexpr auto operator\"\"_uz(unsigned long long n)\
    \ noexcept {\n    return static_cast<usize>(n);\n}\nconstexpr auto operator\"\"\
    _iz(unsigned long long n) noexcept {\n    return static_cast<isize>(n);\n}\n\n\
    }  // namespace a2ry\n"
  dependsOn: []
  isVerificationFile: false
  path: complib/misc/alias.hpp
  requiredBy:
  - complib/ds/union_find.hpp
  - complib/misc/make_vector.hpp
  timestamp: '2023-01-19 00:31:39+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/ALDS1_11_D.test.cpp
  - test/library_checker/unionfind.test.cpp
documentation_of: complib/misc/alias.hpp
layout: document
title: Aliases
---

Rust 風の型 alias 集と、それらに対するユーザー定義リテラル。
