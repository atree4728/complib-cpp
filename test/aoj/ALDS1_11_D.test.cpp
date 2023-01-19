#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_11_D"

#include <iostream>

#include "complib/ds/union_find.hpp"

int main() {
    std::size_t n, m;
    std::cin >> n >> m;
    a2ry::UnionFind uf(n);
    while (m--) {
        std::size_t u, v;
        std::cin >> u >> v;
        uf.unite(u, v);
    }
    std::size_t q;
    std::cin >> q;
    while (q--) {
        std::size_t u, v;
        std::cin >> u >> v;
        std::cout << (uf.same(u, v) ? "yes" : "no") << "\n";
    }
}
