#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include <cassert>
#include <iomanip>
#include <iostream>

#include "complib/ds/union_find.hpp"

int main() {
    std::size_t n, q;
    std::cin >> n >> q;
    a2ry::UnionFind uf(n);
    while (q--) {
        std::size_t t, u, v;
        std::cin >> t >> u >> v;
        if (t == 0) {
            uf.unite(u, v);
        } else if (t == 1) {
            std::cout << uf.same(u, v) << std::endl;
        } else {
            assert(false);
        }
    }
}
