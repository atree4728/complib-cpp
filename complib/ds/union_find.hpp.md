---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: complib/misc/alias.hpp
    title: Aliases
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_11_D.test.cpp
    title: test/aoj/ALDS1_11_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/unionfind.test.cpp
    title: test/library_checker/unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"complib/ds/union_find.hpp\"\n\n#include <numeric>\n#include\
    \ <ranges>\n#include <utility>\n#include <variant>\n#include <vector>\n\n#line\
    \ 2 \"complib/misc/alias.hpp\"\n\n#include <cstddef>\n#include <cstdint>\n\nnamespace\
    \ a2ry {\n\nusing i32 = std::int_fast32_t;\nusing i64 = std::int_fast64_t;\nusing\
    \ u32 = std::uint_fast32_t;\nusing u64 = std::uint_fast64_t;\nusing usize = std::size_t;\n\
    using isize = std::ptrdiff_t;\n\nconstexpr auto operator\"\"_i32(unsigned long\
    \ long n) noexcept {\n    return static_cast<i32>(n);\n}\nconstexpr auto operator\"\
    \"_i64(unsigned long long n) noexcept {\n    return static_cast<i64>(n);\n}\n\
    constexpr auto operator\"\"_u32(unsigned long long n) noexcept {\n    return static_cast<u32>(n);\n\
    }\nconstexpr auto operator\"\"_u64(unsigned long long n) noexcept {\n    return\
    \ static_cast<u64>(n);\n}\nconstexpr auto operator\"\"_uz(unsigned long long n)\
    \ noexcept {\n    return static_cast<usize>(n);\n}\nconstexpr auto operator\"\"\
    _iz(unsigned long long n) noexcept {\n    return static_cast<isize>(n);\n}\n\n\
    }  // namespace a2ry\n#line 10 \"complib/ds/union_find.hpp\"\n\nnamespace a2ry\
    \ {\n\nstruct UnionFind {\n    using node_t = std::variant<usize, usize>;\n  \
    \  const usize n;\n\n  private:\n    enum type : usize { vsize = 0, vparent =\
    \ 1 };\n    std::vector<node_t> node;\n\n  public:\n    explicit constexpr UnionFind(const\
    \ usize n): n{ n }, node(n, node_t{ std::in_place_index<vsize>, 1 }) {}\n    constexpr\
    \ auto root(usize u) & -> usize {\n        while (node[u].index() == vparent)\
    \ {\n            const auto p = get<vparent>(node[u]);\n            if (node[p].index()\
    \ == vparent) node[u].emplace<vparent>(get<vparent>(node[p]));\n            u\
    \ = p;\n        }\n        return u;\n    }\n    constexpr auto size(const usize\
    \ u) -> usize {\n        return get<vsize>(node[root(u)]);\n    }\n    constexpr\
    \ auto same(const usize u, const usize v) -> bool {\n        return root(u) ==\
    \ root(v);\n    }\n    constexpr auto unite(usize u, usize v) & -> std::optional<std::pair<usize,\
    \ usize>> {\n        u = root(u);\n        v = root(v);\n        if (u == v) return\
    \ std::nullopt;\n        if (size(u) < size(v)) std::ranges::swap(u, v);\n   \
    \     get<vsize>(node[u]) += get<vsize>(node[v]);\n        node[v].emplace<vparent>(u);\n\
    \        return std::pair{ u, v };\n    }\n    constexpr auto group() -> std::vector<std::vector<usize>>\
    \ {\n        std::vector g(n, std::vector<usize>{});\n        for (const usize\
    \ u: std::views::iota(0_uz, n)) {\n            g[root(u)].emplace_back(u);\n \
    \       }\n        std::erase_if(g, [](auto &&i) { return empty(i); });\n    \
    \    return g;\n    }\n};\n\n}  // namespace a2ry\n"
  code: "#pragma once\n\n#include <numeric>\n#include <ranges>\n#include <utility>\n\
    #include <variant>\n#include <vector>\n\n#include \"../misc/alias.hpp\"\n\nnamespace\
    \ a2ry {\n\nstruct UnionFind {\n    using node_t = std::variant<usize, usize>;\n\
    \    const usize n;\n\n  private:\n    enum type : usize { vsize = 0, vparent\
    \ = 1 };\n    std::vector<node_t> node;\n\n  public:\n    explicit constexpr UnionFind(const\
    \ usize n): n{ n }, node(n, node_t{ std::in_place_index<vsize>, 1 }) {}\n    constexpr\
    \ auto root(usize u) & -> usize {\n        while (node[u].index() == vparent)\
    \ {\n            const auto p = get<vparent>(node[u]);\n            if (node[p].index()\
    \ == vparent) node[u].emplace<vparent>(get<vparent>(node[p]));\n            u\
    \ = p;\n        }\n        return u;\n    }\n    constexpr auto size(const usize\
    \ u) -> usize {\n        return get<vsize>(node[root(u)]);\n    }\n    constexpr\
    \ auto same(const usize u, const usize v) -> bool {\n        return root(u) ==\
    \ root(v);\n    }\n    constexpr auto unite(usize u, usize v) & -> std::optional<std::pair<usize,\
    \ usize>> {\n        u = root(u);\n        v = root(v);\n        if (u == v) return\
    \ std::nullopt;\n        if (size(u) < size(v)) std::ranges::swap(u, v);\n   \
    \     get<vsize>(node[u]) += get<vsize>(node[v]);\n        node[v].emplace<vparent>(u);\n\
    \        return std::pair{ u, v };\n    }\n    constexpr auto group() -> std::vector<std::vector<usize>>\
    \ {\n        std::vector g(n, std::vector<usize>{});\n        for (const usize\
    \ u: std::views::iota(0_uz, n)) {\n            g[root(u)].emplace_back(u);\n \
    \       }\n        std::erase_if(g, [](auto &&i) { return empty(i); });\n    \
    \    return g;\n    }\n};\n\n}  // namespace a2ry\n"
  dependsOn:
  - complib/misc/alias.hpp
  isVerificationFile: false
  path: complib/ds/union_find.hpp
  requiredBy: []
  timestamp: '2023-01-20 11:12:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_11_D.test.cpp
  - test/library_checker/unionfind.test.cpp
documentation_of: complib/ds/union_find.hpp
layout: document
title: Union Find
---

UnionFind は、disjoint set union（素集合の併合）を管理するデータ構造である。
内部では集合を根付きの有向森として管理しており、以下の二つの工夫により高速化が実現されている。

- 併合時に木の「大きさ」を抑える。
  - union by rank: 「大きさ」を高さで評価する。
  - union by size: 「大きさ」を頂点数で評価する。
- 経路圧縮（木の高さを抑える）
  - path compression: 木の根を探索する際に、各頂点の親を直接根とするように再帰する。
  - path splitting: 「自分の親」を「自分の親の親」に上書きながら根まで登ると、深さの偶奇で分かれた二つの path が根に接続することになり、木の高さが半分になっている。
  - path halving: path splitting とほぼ同様だが、上書きをしてから頂点を更新することで根までの path 長を半分にしている。深さの偶奇が初期頂点と異なる祖先の親は更新しないため、根までの path が二分木に分解されるイメージ。

本実装では union by size + path havling を採用している。

## Usage
全ての関数は `constexpr` 修飾されている。
- `UnionFind(usize n) -> UnionFind` (constructor): 頂点数 $n$ で初期化する。
- `root(usize u) -> usize`: 頂点 $u$ の属する木の代表元を返す。
- `size(usize u) -> usize`: 頂点 $u$ の属する木の頂点数を返す。
- `same(usize u, usize v)  -> bool`: 頂点 $u, v$ の連結性を返す。
- `unite(usize u, usize v) -> std::optional<std::pair<usize, usize>>`: 頂点 $u, v$ を接続する。この際に、もともと $u, v$ が連結だったならば `std::nullopt`、そうでなかったのなら $u, v$ を接続する有向辺を `std::optional` で包んで返す。

## Complexity
二つの工夫のうち、どちらか片方のみを用いると $\mathcal{O}(\log n)$ 、両方用いれば $\mathcal{O}(\alpha (n))$ で全ての操作を達成する。ここで、$\alpha$ を Ackermann 関数の逆関数とした。

## Note
- 様々な亜種が存在するので一部は実装していきたい。
  - Potentialized
  - 可換 Monoid が乗るやつ
  - [関係式付き Union Find](https://qiita.com/Kiri8128/items/ae19133ee6921cb18dec)

## Reference
- [Wikipedia](https://en.wikipedia.org/wiki/Disjoint-set_data_structure)
- [UnionFindTree に関する知見の諸々](https://noshi91.hatenablog.com/entry/2018/05/30/191943)
