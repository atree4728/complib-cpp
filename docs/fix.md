---
title: Y combinator
documentation_of: //complib/misc/fix.hpp
---

Y コンビネータ。不動点コンビネータとも。
自己再帰する lambda 式を（特に、束縛せず直接呼び出す際に）記述するためのヘルパー。
第一引数にクロージャオブジェクト自身、以降で通常の引数をとる lambda 式を与えると、通常の引数のみで呼び出せるクロージャオブジェクトを返す。

## Usage

```c++
fix{[](auto self, int n) -> int {
    return (n <= 1) ? 1 : n * self(n - 1);
}}(10)
// 3628800
```

## Reference
- [自己再帰するラムダ式 @ C++23](https://yohhoy.hatenadiary.jp/entry/20211025/p1)
  - C++23 で採択される Deducing this を用いれば、`this auto` で自身のクロージャ型を推論することができ、自然に自己再帰する lambda 式を記述することが可能。
