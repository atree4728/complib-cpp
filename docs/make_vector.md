---
title: 多次元 vector の宣言
documentation_of: //complib/misc/make_vector.hpp
---

$N$ 次元 `vector` を簡便に宣言する。

## Usage

```c++
auto a = make_vector<int>({1, 2, 3});
// auto a = std::vector(1, std::vector(2, std::vector(3, int{})));
auto b = make_vector<int>({4, 5}, 42);
// auto b = std::vector(4, std::vector(5, 42));
```
