#pragma once

#include <numeric>
#include <ranges>
#include <vector>

#include "../misc/alias.hpp"

namespace a2ry {

struct UnionFind {
    usize n;
    std::vector<usize> parent_or_size;
    explicit UnionFind(const usize n): n{ n }, parent_or_size(n, -1_uz) {}
    usize root(const usize u) {
        return parent_or_size[u] < n ? parent_or_size[u] = root(parent_or_size[u]) : u;
    }
    usize size(const usize u) {
        return -parent_or_size[root(u)];
    }
    bool same(const usize u, const usize v) {
        return root(u) == root(v);
    }
    bool unite(usize u, usize v) {
        u = root(u);
        v = root(v);
        if (u == v) return false;
        if (size(u) < size(v)) std::swap(u, v);
        parent_or_size[u] += parent_or_size[v];
        parent_or_size[v] = u;
        return true;
    }
    std::vector<std::vector<usize>> group() {
        std::vector g(n, std::vector<usize>{});
        for (const usize u: std::views::iota(0_uz, n)) {
            g[root(u)].emplace_back(u);
        }
        std::erase_if(g, [](auto &&i) { return empty(i); });
        return g;
    }
};

}  // namespace a2ry
