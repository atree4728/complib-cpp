---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"complib/misc/fix.hpp\"\n\n#include <functional>\n\nnamespace\
    \ a2ry {\n\ntemplate<class F> struct fix {\n    F f;\n    template<class... Args>\
    \ decltype(auto) operator()(Args&&... args) const& {\n        return f(std::ref(*this),\
    \ std::forward<Args>(args)...);\n    }\n};\n\n}  // namespace a2ry\n"
  code: "#pragma once\n\n#include <functional>\n\nnamespace a2ry {\n\ntemplate<class\
    \ F> struct fix {\n    F f;\n    template<class... Args> decltype(auto) operator()(Args&&...\
    \ args) const& {\n        return f(std::ref(*this), std::forward<Args>(args)...);\n\
    \    }\n};\n\n}  // namespace a2ry\n"
  dependsOn: []
  isVerificationFile: false
  path: complib/misc/fix.hpp
  requiredBy: []
  timestamp: '2023-01-19 14:01:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: complib/misc/fix.hpp
layout: document
title: Y combinator
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
