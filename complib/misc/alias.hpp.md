---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: complib/misc/make_vector.hpp
    title: complib/misc/make_vector.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
  - complib/misc/make_vector.hpp
  timestamp: '2023-01-19 00:31:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: complib/misc/alias.hpp
layout: document
redirect_from:
- /library/complib/misc/alias.hpp
- /library/complib/misc/alias.hpp.html
title: complib/misc/alias.hpp
---
