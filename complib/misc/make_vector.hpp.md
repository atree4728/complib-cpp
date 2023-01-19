---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: complib/misc/alias.hpp
    title: complib/misc/alias.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"complib/misc/make_vector.hpp\"\n\n#include <vector>\n\n\
    #line 2 \"complib/misc/alias.hpp\"\n\n#include <cstddef>\n#include <cstdint>\n\
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
    }\n\n}  // namespace a2ry\n#line 6 \"complib/misc/make_vector.hpp\"\n\nnamespace\
    \ a2ry {\n\ntemplate<class T, usize N, usize I = 0> auto make_vector(usize (&&sizes)[N],\
    \ T&& x = T{}) {\n    if constexpr (I == N) {\n        return std::forward<T>(x);\n\
    \    } else {\n        return std::vector(sizes[I], make_vector<T, N, I + 1>(std::forward<usize[N]>(sizes),\
    \ std::forward<T>(x)));\n    }\n}\n\n}  // namespace a2ry\n"
  code: "#pragma once\n\n#include <vector>\n\n#include \"alias.hpp\"\n\nnamespace\
    \ a2ry {\n\ntemplate<class T, usize N, usize I = 0> auto make_vector(usize (&&sizes)[N],\
    \ T&& x = T{}) {\n    if constexpr (I == N) {\n        return std::forward<T>(x);\n\
    \    } else {\n        return std::vector(sizes[I], make_vector<T, N, I + 1>(std::forward<usize[N]>(sizes),\
    \ std::forward<T>(x)));\n    }\n}\n\n}  // namespace a2ry\n"
  dependsOn:
  - complib/misc/alias.hpp
  isVerificationFile: false
  path: complib/misc/make_vector.hpp
  requiredBy: []
  timestamp: '2023-01-19 00:31:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: complib/misc/make_vector.hpp
layout: document
redirect_from:
- /library/complib/misc/make_vector.hpp
- /library/complib/misc/make_vector.hpp.html
title: complib/misc/make_vector.hpp
---
