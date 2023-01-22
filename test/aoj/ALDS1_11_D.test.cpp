#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_11_D"

#include "complib/ds/union_find.hpp"
#include "complib/misc/template.hpp"

int main() {
    using namespace a2ry;
    auto [n, m] = in<usize, usize>();
    UnionFind uf(n);
    while (m--) {
        uf.unite(in<usize>(), in<usize>());
    }
    auto q = in<usize>();
    while (q--) {
        println(uf.same(in<usize>(), in<usize>()) ? "yes" : "no");
    }
}
