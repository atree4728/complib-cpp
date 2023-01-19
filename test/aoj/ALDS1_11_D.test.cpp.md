---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: complib/ds/union_find.hpp
    title: Union Find
  - icon: ':heavy_check_mark:'
    path: complib/misc/alias.hpp
    title: Aliases
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_11_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_11_D
  bundledCode: "#line 1 \"test/aoj/ALDS1_11_D.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_11_D\"\
    \n\n#include <iostream>\n\n#line 2 \"complib/ds/union_find.hpp\"\n\n#include <numeric>\n\
    #include <ranges>\n#include <vector>\n\n#line 2 \"complib/misc/alias.hpp\"\n\n\
    #include <cstddef>\n#include <cstdint>\n\nnamespace a2ry {\n\nusing i32 = std::int_fast32_t;\n\
    using i64 = std::int_fast64_t;\nusing u32 = std::uint_fast32_t;\nusing u64 = std::uint_fast64_t;\n\
    using usize = std::size_t;\nusing isize = std::ptrdiff_t;\n\nconstexpr auto operator\"\
    \"_i32(unsigned long long n) noexcept {\n    return static_cast<i32>(n);\n}\n\
    constexpr auto operator\"\"_i64(unsigned long long n) noexcept {\n    return static_cast<i64>(n);\n\
    }\nconstexpr auto operator\"\"_u32(unsigned long long n) noexcept {\n    return\
    \ static_cast<u32>(n);\n}\nconstexpr auto operator\"\"_u64(unsigned long long\
    \ n) noexcept {\n    return static_cast<u64>(n);\n}\nconstexpr auto operator\"\
    \"_uz(unsigned long long n) noexcept {\n    return static_cast<usize>(n);\n}\n\
    constexpr auto operator\"\"_iz(unsigned long long n) noexcept {\n    return static_cast<isize>(n);\n\
    }\n\n}  // namespace a2ry\n#line 8 \"complib/ds/union_find.hpp\"\n\nnamespace\
    \ a2ry {\n\nstruct UnionFind {\n    usize n;\n    std::vector<usize> parent_or_size;\n\
    \    explicit UnionFind(const usize n): n{ n }, parent_or_size(n, -1_uz) {}\n\
    \    usize root(const usize u) {\n        return parent_or_size[u] < n ? parent_or_size[u]\
    \ = root(parent_or_size[u]) : u;\n    }\n    usize size(const usize u) {\n   \
    \     return -parent_or_size[root(u)];\n    }\n    bool same(const usize u, const\
    \ usize v) {\n        return root(u) == root(v);\n    }\n    bool unite(usize\
    \ u, usize v) {\n        u = root(u);\n        v = root(v);\n        if (u ==\
    \ v) return false;\n        if (size(u) < size(v)) std::swap(u, v);\n        parent_or_size[u]\
    \ += parent_or_size[v];\n        parent_or_size[v] = u;\n        return true;\n\
    \    }\n    std::vector<std::vector<usize>> group() {\n        std::vector g(n,\
    \ std::vector<usize>{});\n        for (const usize u: std::views::iota(0_uz, n))\
    \ {\n            g[root(u)].emplace_back(u);\n        }\n        std::erase_if(g,\
    \ [](auto &&i) { return empty(i); });\n        return g;\n    }\n};\n\n}  // namespace\
    \ a2ry\n#line 6 \"test/aoj/ALDS1_11_D.test.cpp\"\n\nint main() {\n    std::size_t\
    \ n, m;\n    std::cin >> n >> m;\n    a2ry::UnionFind uf(n);\n    while (m--)\
    \ {\n        std::size_t u, v;\n        std::cin >> u >> v;\n        uf.unite(u,\
    \ v);\n    }\n    std::size_t q;\n    std::cin >> q;\n    while (q--) {\n    \
    \    std::size_t u, v;\n        std::cin >> u >> v;\n        std::cout << (uf.same(u,\
    \ v) ? \"yes\" : \"no\") << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_11_D\"\n\
    \n#include <iostream>\n\n#include \"complib/ds/union_find.hpp\"\n\nint main()\
    \ {\n    std::size_t n, m;\n    std::cin >> n >> m;\n    a2ry::UnionFind uf(n);\n\
    \    while (m--) {\n        std::size_t u, v;\n        std::cin >> u >> v;\n \
    \       uf.unite(u, v);\n    }\n    std::size_t q;\n    std::cin >> q;\n    while\
    \ (q--) {\n        std::size_t u, v;\n        std::cin >> u >> v;\n        std::cout\
    \ << (uf.same(u, v) ? \"yes\" : \"no\") << \"\\n\";\n    }\n}\n"
  dependsOn:
  - complib/ds/union_find.hpp
  - complib/misc/alias.hpp
  isVerificationFile: true
  path: test/aoj/ALDS1_11_D.test.cpp
  requiredBy: []
  timestamp: '2023-01-19 17:28:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1_11_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_11_D.test.cpp
- /verify/test/aoj/ALDS1_11_D.test.cpp.html
title: test/aoj/ALDS1_11_D.test.cpp
---
