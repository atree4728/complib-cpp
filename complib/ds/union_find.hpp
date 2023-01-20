#pragma once

#include <numeric>
#include <ranges>
#include <utility>
#include <variant>
#include <vector>

#include "../misc/alias.hpp"

namespace a2ry {

struct UnionFind {
    using node_t = std::variant<usize, usize>;
    const usize n;

  private:
    enum type : usize { vsize = 0, vparent = 1 };
    std::vector<node_t> node;

  public:
    explicit constexpr UnionFind(const usize n): n{ n }, node(n, node_t{ std::in_place_index<vsize>, 1 }) {}
    constexpr auto root(usize u) & -> usize {
        while (node[u].index() == vparent) {
            const auto p = get<vparent>(node[u]);
            if (node[p].index() == vparent) node[u].emplace<vparent>(get<vparent>(node[p]));
            u = p;
        }
        return u;
    }
    constexpr auto size(const usize u) -> usize {
        return get<vsize>(node[root(u)]);
    }
    constexpr auto same(const usize u, const usize v) -> bool {
        return root(u) == root(v);
    }
    constexpr auto unite(usize u, usize v) & -> std::optional<std::pair<usize, usize>> {
        u = root(u);
        v = root(v);
        if (u == v) return std::nullopt;
        if (size(u) < size(v)) std::ranges::swap(u, v);
        get<vsize>(node[u]) += get<vsize>(node[v]);
        node[v].emplace<vparent>(u);
        return std::pair{ u, v };
    }
    constexpr auto group() -> std::vector<std::vector<usize>> {
        std::vector g(n, std::vector<usize>{});
        for (const usize u: std::views::iota(0_uz, n)) {
            g[root(u)].emplace_back(u);
        }
        std::erase_if(g, [](auto &&i) { return empty(i); });
        return g;
    }
};

}  // namespace a2ry
