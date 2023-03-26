---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: complib/algebra/data_type.hpp
    title: complib/algebra/data_type.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://github.com/azaika/adsl/blob/master/include/adsl/algebra/type_util.hpp),
    - https://opensource.org/license/mit/).
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ complib/algebra/util.hpp: line 5: #pragma once found in a non-first line\n"
  code: "// Copyright (c) 2019 Azaika\n// This file is based on [azaika/adsl](https://github.com/azaika/adsl/blob/master/include/adsl/algebra/type_util.hpp),\n\
    // which is published on [MIT License](https://opensource.org/license/mit/).\n\
    \n#pragma once\n\n#include \"data_type.hpp\"\n#include <optional>\n\nnamespace\
    \ a2ry::algebra {\n\nnamespace impl {\n\ntemplate <class T, T identity, auto func,\
    \ bool is_commutative> struct make_monoid {\n    using value_type = T;\n\n   \
    \ static constexpr value_type unit() noexcept { return identity; }\n    static\
    \ constexpr value_type op(const value_type &x, const value_type &y) noexcept(noexcept(func(x,\
    \ y))) {\n        return func(x, y);\n    }\n};\n\ntemplate <class T, T identity,\
    \ auto func> struct make_monoid<T, identity, func, true> : commutative_tag {\n\
    \    using value_type = T;\n\n    static constexpr value_type unit() noexcept\
    \ { return identity; }\n    static constexpr value_type op(const value_type &x,\
    \ const value_type &y) noexcept(noexcept(func(x, y))) {\n        return func(x,\
    \ y);\n    }\n};\n\ntemplate <monoidally_additionable T, bool is_commutative>\
    \ struct default_monoid {\n    using value_type = T;\n\n    static constexpr value_type\
    \ unit() noexcept(noexcept(value_type{})) { return value_type{}; }\n    static\
    \ constexpr value_type op(const value_type &x, const value_type &y) noexcept(noexcept(x\
    \ + y)) { return x + y; }\n};\n\ntemplate <monoidally_additionable T> struct default_monoid<T,\
    \ true> : commutative_tag {\n    using value_type = T;\n\n    static constexpr\
    \ value_type unit() noexcept(noexcept(value_type{})) { return value_type{}; }\n\
    \    static constexpr value_type op(const value_type &x, const value_type &y)\
    \ noexcept(noexcept(x + y)) { return x + y; }\n};\n\ntemplate <class T, T identity,\
    \ auto func, auto inv_func, bool is_commutative> struct make_group {\n    using\
    \ value_type = T;\n\n    static constexpr value_type unit() noexcept { return\
    \ identity; }\n    static constexpr value_type op(const value_type &x, const value_type\
    \ &y) noexcept(noexcept(func(x, y))) {\n        return func(x, y);\n    }\n  \
    \  static constexpr value_type inv(const value_type &v) noexcept(noexcept(inv_func(v)))\
    \ { return inv_func(v); }\n};\n\ntemplate <class T, T identity, auto func, auto\
    \ inv_func>\nstruct make_group<T, identity, func, inv_func, true> : commutative_tag\
    \ {\n    using value_type = T;\n\n    static constexpr value_type unit() noexcept\
    \ { return identity; }\n    static constexpr value_type op(const value_type &x,\
    \ const value_type &y) noexcept(noexcept(func(x, y))) {\n        return func(x,\
    \ y);\n    }\n    static constexpr value_type inv(const value_type &v) noexcept(noexcept(inv_func(v)))\
    \ { return inv_func(v); }\n};\n\ntemplate <grouply_additionable T, bool is_commutative>\
    \ struct default_group {\n    using value_type = T;\n\n    static constexpr value_type\
    \ unit() noexcept(noexcept(value_type{})) { return value_type{}; }\n    static\
    \ constexpr value_type op(const value_type &x, const value_type &y) noexcept(noexcept(x\
    \ + y)) { return x + y; }\n    static constexpr value_type inv(const value_type\
    \ &v) noexcept(noexcept(-v)) { return -v; }\n};\n\ntemplate <grouply_additionable\
    \ T> struct default_group<T, true> : commutative_tag {\n    using value_type =\
    \ T;\n\n    static constexpr value_type unit() noexcept(noexcept(value_type{}))\
    \ { return value_type{}; }\n    static constexpr value_type op(const value_type\
    \ &x, const value_type &y) noexcept(noexcept(x + y)) { return x + y; }\n    static\
    \ constexpr value_type inv(const value_type &v) noexcept(noexcept(-v)) { return\
    \ -v; }\n};\n\n} // namespace impl\n\ntemplate <semigroup G> struct to_monoid\
    \ {\n    using value_type = std::optional<typename G::value_type>;\n\n    static\
    \ value_type unit() noexcept { return std::nullopt; }\n    static value_type op(const\
    \ value_type &x, const value_type &y) noexcept(noexcept(G::op(*x, *y))) {\n  \
    \      if (x == std::nullopt) return y;\n        if (y == std::nullopt) return\
    \ x;\n        return G::op(*x, *y);\n    }\n};\n\ntemplate <class T, T identity,\
    \ auto func, bool is_commutative = false>\nusing make_monoid = impl::make_monoid<T,\
    \ identity, func, is_commutative>;\n\ntemplate <monoidally_additionable T, bool\
    \ is_commutative = std::is_arithmetic_v<T>>\nusing default_monoid = impl::default_monoid<T,\
    \ is_commutative>;\n\ntemplate <class T, T identity, auto func, auto inv_func,\
    \ bool is_commutative = false>\nusing make_group = impl::make_group<T, identity,\
    \ func, inv_func, is_commutative>;\n\ntemplate <grouply_additionable T, bool is_commutative\
    \ = std::is_signed_v<T>>\nusing default_group = impl::default_group<T, is_commutative>;\n\
    \ntemplate <class D, class S, auto func>\n    requires requires {\n        {\n\
    \            func(std::declval<typename D::value_type>(), std::declval<typename\
    \ S::value_type>())\n        } -> std::convertible_to<typename S::value_type>;\n\
    \    }\n\nstruct make_action {\n    using domain = D;\n    using space = S;\n\n\
    \    static constexpr auto\n    act(const typename domain::value_type &v) noexcept(noexcept(func(v,\
    \ std::declval<typename space::value_type>()))) {\n        return [&v](const typename\
    \ space::value_type &s) noexcept(noexcept(func(v, s))) { return func(v, s); };\n\
    \    }\n};\n} // namespace a2ry::algebra\n"
  dependsOn:
  - complib/algebra/data_type.hpp
  isVerificationFile: false
  path: complib/algebra/util.hpp
  requiredBy: []
  timestamp: '2023-03-26 23:39:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: complib/algebra/util.hpp
layout: document
redirect_from:
- /library/complib/algebra/util.hpp
- /library/complib/algebra/util.hpp.html
title: complib/algebra/util.hpp
---
