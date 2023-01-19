---
title: Union Find
documentation_of: //complib/ds/union_find.hpp
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

本実装については、最も一般的な union by size + path compression を採用しているが、Wikipedia によれば path {halving, splitting} は more efficient in practice とのことなので変更の余地あり。

## Usage
- `UnionFind(usize n) -> UnionFind`(constructor): 頂点数 $n$ で初期化する。
- `root(usize u) -> usize`: 頂点 $u$ の属する木の代表元を返す。
- `size(usize u) -> usize`: 頂点 $u$ の属する木の頂点数を返す。
- `same(usize u, usize v)`: 頂点 $u, v$ の連結性を返す。
- `unite(usize u, usize v) -> bool`: 頂点 $u, v$ を接続する。この際に、もともと $u, v$ が連結でなかったかを返す。

## Complexity
二つの工夫のうち、どちらか片方のみを用いると $\mathcal{O}(\log n)$ 、両方用いれば $\mathcal{O}(\alpha (n))$ で全ての操作を達成する。ここで、$\alpha$ を Ackermann 関数の逆関数とした。

## Note
- 内部実装では頂点の index の正負で親か頂点数かを区別しているので `std::variant` を使うと気持ち良くなれそうだが、`std::variant` はカテゴリを型でしか区別できないので、うん…
- 様々な亜種が存在するので一部は実装していきたい。
  - Potentialized
  - 可換 Monoid が乗るやつ
  - [関係式付き Union Find](https://qiita.com/Kiri8128/items/ae19133ee6921cb18dec)

## Reference
- [Wikipedia](https://en.wikipedia.org/wiki/Disjoint-set_data_structure)
- [UnionFindTree に関する知見の諸々](https://noshi91.hatenablog.com/entry/2018/05/30/191943)
