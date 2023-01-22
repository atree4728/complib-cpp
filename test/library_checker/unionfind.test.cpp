#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include <cassert>
#include <iomanip>
#include <iostream>

#include "complib/ds/union_find.hpp"
#include "complib/misc/template.hpp"

int main() {
    using namespace a2ry;
    io_config::yes = "1";
    io_config::no = "0";
    auto [n, q] = in<usize, usize>();
    UnionFind uf(n);
    while (q--) {
        const auto [t, u, v] = in<usize, usize, usize>();
        if (t == 0) {
            uf.unite(u, v);
        } else if (t == 1) {
            println(uf.same(u, v));
        } else {
            assert(false);
        }
    }
}
