---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: complib/algebra/util.hpp
    title: complib/algebra/util.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://github.com/azaika/adsl/blob/master/include/adsl/algebra/data_type.hpp),
    - https://opensource.org/license/mit/).
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ complib/algebra/data_type.hpp: line 5: #pragma once found in a non-first line\n"
  code: "// Copyright (c) 2019 Azaika\n// This file is based on [azaika/adsl](https://github.com/azaika/adsl/blob/master/include/adsl/algebra/data_type.hpp),\n\
    // which is published on [MIT License](https://opensource.org/license/mit/).\n\
    \n#pragma once\n\n#include <concepts>\n\nnamespace a2ry::algebra {\n\ntemplate\
    \ <class M>\nconcept magma = requires {\n    typename M::value_type;\n    {\n\
    \        M::op(std::declval<M::value_type>(), std::declval<M::value_type>())\n\
    \    } -> std::convertible_to<typename M::value_type>;\n};\n\ntemplate <class\
    \ M>\nconcept associative = true;\n\ntemplate <class M>\nconcept semigroup = magma<M>\
    \ and associative<M>;\n\ntemplate <class M>\nconcept monoid = semigroup<M> and\
    \ requires {\n    { M::unit() } -> std::convertible_to<typename M::value_type>;\n\
    };\n\ntemplate <class G>\nconcept group = monoid<G> and requires {\n    { G::inv(G::unit())\
    \ } -> std::convertible_to<typename G::value_type>;\n};\n\nclass commutative_tag\
    \ {};\n\ntemplate <class M>\nconcept commutative_monoid = monoid<M> and std::is_base_of_v<commutative_tag,\
    \ M>;\n\ntemplate <class G>\nconcept commutative_group = group<G> and std::is_base_of_v<commutative_tag,\
    \ G>;\n\ntemplate <class T>\nconcept monoidally_additionable = requires(T x, T\
    \ y) {\n    requires std::is_default_constructible_v<T>;\n    { x + y } -> std::convertible_to<T>;\n\
    };\n\ntemplate <class T>\nconcept grouply_additionable = monoidally_additionable<T>\
    \ and requires(T x) {\n    { -x } -> std::convertible_to<T>;\n};\n\ntemplate <class\
    \ A>\nconcept left_action = requires {\n    typename A::domain;\n    typename\
    \ A::space;\n    {\n        A::act(std::declval<A::domain::value_type>())(std::declval<A::space::value_type>())\n\
    \    } -> std::convertible_to<typename A::space::value_type>;\n};\n\ntemplate\
    \ <class A>\nconcept monoidal_action = left_action<A> and commutative_monoid<typename\
    \ A::domain>;\n\ntemplate <class F, class Domain, class Codomain>\nconcept monoidal_homomorphism\
    \ =\n    monoid<Domain> and monoid<Codomain> and\n    std::convertible_to<std::invoke_result_t<F,\
    \ typename Domain::value_type>, typename Codomain::value_type>;\n\ntemplate <class\
    \ F, class M>\nconcept monoidal_endomorphism = monoidal_homomorphism<F, M, M>;\n\
    \n} // namespace a2ry::algebra\n"
  dependsOn: []
  isVerificationFile: false
  path: complib/algebra/data_type.hpp
  requiredBy:
  - complib/algebra/util.hpp
  timestamp: '2023-03-26 23:39:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: complib/algebra/data_type.hpp
layout: document
redirect_from:
- /library/complib/algebra/data_type.hpp
- /library/complib/algebra/data_type.hpp.html
title: complib/algebra/data_type.hpp
---
