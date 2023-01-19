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
redirect_from:
- /library/complib/misc/fix.hpp
- /library/complib/misc/fix.hpp.html
title: complib/misc/fix.hpp
---
