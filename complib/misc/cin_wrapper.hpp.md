---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: complib/misc/alias.hpp
    title: Aliases
  - icon: ':heavy_check_mark:'
    path: complib/misc/type_traits.hpp
    title: complib/misc/type_traits.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: complib/misc/template.hpp
    title: Template
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_11_D.test.cpp
    title: test/aoj/ALDS1_11_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/aplusb.test.cpp
    title: test/library_checker/aplusb.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/unionfind.test.cpp
    title: test/library_checker/unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"complib/misc/cin_wrapper.hpp\"\n\n#include <algorithm>\n\
    #include <concepts>\n#include <deque>\n#include <iostream>\n#include <ranges>\n\
    #include <type_traits>\n#include <utility>\n#include <vector>\n\n#line 2 \"complib/misc/alias.hpp\"\
    \n\n#include <cstddef>\n#include <cstdint>\n#line 6 \"complib/misc/alias.hpp\"\
    \n\nnamespace a2ry {\n\nusing i32 = std::int_fast32_t;\nusing i64 = std::int_fast64_t;\n\
    using u32 = std::uint_fast32_t;\nusing u64 = std::uint_fast64_t;\nusing usize\
    \ = std::size_t;\nusing isize = std::ptrdiff_t;\n\nconstexpr auto operator\"\"\
    _i32(unsigned long long n) noexcept {\n    return static_cast<i32>(n);\n}\nconstexpr\
    \ auto operator\"\"_i64(unsigned long long n) noexcept {\n    return static_cast<i64>(n);\n\
    }\nconstexpr auto operator\"\"_u32(unsigned long long n) noexcept {\n    return\
    \ static_cast<u32>(n);\n}\nconstexpr auto operator\"\"_u64(unsigned long long\
    \ n) noexcept {\n    return static_cast<u64>(n);\n}\nconstexpr auto operator\"\
    \"_uz(unsigned long long n) noexcept {\n    return static_cast<usize>(n);\n}\n\
    constexpr auto operator\"\"_iz(unsigned long long n) noexcept {\n    return static_cast<isize>(n);\n\
    }\n\ntemplate<class T> struct is_1indexed: std::false_type {};\n#define INDEXED_IMPL(type)\
    \                    \\\n    struct type##_##1 { using base = type; }; \\\n  \
    \  template<> struct is_1indexed<type##_##1>: std::true_type {};\nINDEXED_IMPL(int)\n\
    INDEXED_IMPL(i32)\nINDEXED_IMPL(u32)\nINDEXED_IMPL(i64)\nINDEXED_IMPL(u64)\nINDEXED_IMPL(usize)\n\
    #undef INDEXED_IMPL\n\n}  // namespace a2ry\n#line 2 \"complib/misc/type_traits.hpp\"\
    \n\n#line 7 \"complib/misc/type_traits.hpp\"\n\n#line 9 \"complib/misc/type_traits.hpp\"\
    \n\nnamespace a2ry {\n\ntemplate<class T, std::size_t I>\nconcept has_tuple_element\
    \ = requires(T t) {\n                                typename std::tuple_element_t<I,\
    \ std::remove_cvref_t<T>>;\n                                { get<I>(t) } -> std::convertible_to<std::tuple_element_t<I,\
    \ T>&>;\n                            };\n\ntemplate<class T> concept tuple_like\
    \ = not\nstd::is_reference_v<T>&& requires(T t) {\n                          \
    \   typename std::tuple_size<T>::type;\n                             requires\
    \ std::derived_from<std::tuple_size<T>,\n                                    \
    \                    std::integral_constant<std::size_t, std::tuple_size_v<T>>>;\n\
    \                         }and[]<std::size_t... N>(std::index_sequence<N...>)\
    \ {\n    return (has_tuple_element<T, N> and ...);\n}\n(std::make_index_sequence<std::tuple_size_v<T>>());\n\
    \ntemplate<class T, usize N> struct nth_vector {\n    using type = std::vector<typename\
    \ nth_vector<T, N - 1>::type>;\n};\ntemplate<class T> struct nth_vector<T, 0>\
    \ {\n    using type = T;\n};\n\ntemplate<class T, usize N> using nth_vector_t\
    \ = nth_vector<T, N>::type;\n\ntemplate<class T> concept stream_extractable =\
    \ requires(T& t) { std::cin >> t; } or is_1indexed<T>::value;\ntemplate<class\
    \ T> concept stream_insertable = requires(T t) { std::cout << t; };\n\n}  // namespace\
    \ a2ry\n#line 14 \"complib/misc/cin_wrapper.hpp\"\n\nnamespace a2ry {\n\ntemplate<class\
    \ T>\n    requires stream_extractable<T>\ninline auto in() {\n    if constexpr\
    \ (is_1indexed<T>::value) {\n        typename T::base x{};\n        std::cin >>\
    \ x;\n        --x;\n        return x;\n    } else {\n        T x{};\n        std::cin\
    \ >> x;\n        return x;\n    }\n}\n\ntemplate<class T>\n    requires tuple_like<T>\n\
    inline auto in() -> T {\n    return []<usize... I>(std::index_sequence<I...>)\
    \ {\n        return T{ in<std::remove_cvref_t<std::tuple_element_t<I, T>>>()...\
    \ };\n    }\n    (std::make_index_sequence<std::tuple_size_v<T>>());\n}\n\ntemplate<class...\
    \ Args>\n    requires(sizeof...(Args) > 1)\ninline auto in() -> std::tuple<Args...>\
    \ {\n    return in<std::tuple<Args...>>();\n}\n\ntemplate<class C, usize N, usize\
    \ I = 0>\n    requires(N > 0)\ninline auto in(const usize (&sizes)[N]) -> C {\n\
    \    auto cv = std::views::iota(0_uz, sizes[I]) | std::views::transform([&](auto&&)\
    \ {\n                  if constexpr (I + 1 == N) {\n                      return\
    \ in<typename C::value_type>();\n                  } else {\n                \
    \      return in<typename C::value_type, N, I + 1>(sizes);\n                 \
    \ }\n              })\n            | std::views::common;\n    if constexpr (std::constructible_from<C,\
    \ decltype(std::ranges::begin(cv)), decltype(std::ranges::end(cv))>) {\n     \
    \   return C(std::ranges::begin(cv), std::ranges::end(cv));\n    } else if constexpr\
    \ (std::constructible_from<C, std::deque<typename C::value_type>>) {\n       \
    \ // std::queue and std::stack (until C++23...)\n        return C(std::deque(std::ranges::begin(cv),\
    \ std::ranges::end(cv)));\n    } else {\n        static_assert(\n            requires(C)\
    \ { requires(false); }, \"in: the container is unconstructible from range\");\n\
    \    }\n}\n\ntemplate<class T, usize N> inline auto in_vec(const usize (&sizes)[N])\
    \ {\n    return in<nth_vector_t<T, N>>(sizes);\n}\n\n}  // namespace a2ry\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <concepts>\n#include <deque>\n\
    #include <iostream>\n#include <ranges>\n#include <type_traits>\n#include <utility>\n\
    #include <vector>\n\n#include \"alias.hpp\"\n#include \"type_traits.hpp\"\n\n\
    namespace a2ry {\n\ntemplate<class T>\n    requires stream_extractable<T>\ninline\
    \ auto in() {\n    if constexpr (is_1indexed<T>::value) {\n        typename T::base\
    \ x{};\n        std::cin >> x;\n        --x;\n        return x;\n    } else {\n\
    \        T x{};\n        std::cin >> x;\n        return x;\n    }\n}\n\ntemplate<class\
    \ T>\n    requires tuple_like<T>\ninline auto in() -> T {\n    return []<usize...\
    \ I>(std::index_sequence<I...>) {\n        return T{ in<std::remove_cvref_t<std::tuple_element_t<I,\
    \ T>>>()... };\n    }\n    (std::make_index_sequence<std::tuple_size_v<T>>());\n\
    }\n\ntemplate<class... Args>\n    requires(sizeof...(Args) > 1)\ninline auto in()\
    \ -> std::tuple<Args...> {\n    return in<std::tuple<Args...>>();\n}\n\ntemplate<class\
    \ C, usize N, usize I = 0>\n    requires(N > 0)\ninline auto in(const usize (&sizes)[N])\
    \ -> C {\n    auto cv = std::views::iota(0_uz, sizes[I]) | std::views::transform([&](auto&&)\
    \ {\n                  if constexpr (I + 1 == N) {\n                      return\
    \ in<typename C::value_type>();\n                  } else {\n                \
    \      return in<typename C::value_type, N, I + 1>(sizes);\n                 \
    \ }\n              })\n            | std::views::common;\n    if constexpr (std::constructible_from<C,\
    \ decltype(std::ranges::begin(cv)), decltype(std::ranges::end(cv))>) {\n     \
    \   return C(std::ranges::begin(cv), std::ranges::end(cv));\n    } else if constexpr\
    \ (std::constructible_from<C, std::deque<typename C::value_type>>) {\n       \
    \ // std::queue and std::stack (until C++23...)\n        return C(std::deque(std::ranges::begin(cv),\
    \ std::ranges::end(cv)));\n    } else {\n        static_assert(\n            requires(C)\
    \ { requires(false); }, \"in: the container is unconstructible from range\");\n\
    \    }\n}\n\ntemplate<class T, usize N> inline auto in_vec(const usize (&sizes)[N])\
    \ {\n    return in<nth_vector_t<T, N>>(sizes);\n}\n\n}  // namespace a2ry\n"
  dependsOn:
  - complib/misc/alias.hpp
  - complib/misc/type_traits.hpp
  isVerificationFile: false
  path: complib/misc/cin_wrapper.hpp
  requiredBy:
  - complib/misc/template.hpp
  timestamp: '2023-01-22 19:33:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_11_D.test.cpp
  - test/library_checker/unionfind.test.cpp
  - test/library_checker/aplusb.test.cpp
documentation_of: complib/misc/cin_wrapper.hpp
layout: document
title: Cin Wrapper
---

`std::cin` の wrapper。

## Requirements
- `T` を型として、`T` が `requires (T& t) { std::cin >> t; }` を満たすとき、`T` を *extractable* と呼ぶことにする。
- `T` をクラステンプレートまたは型として、`T::value_type` が存在するとき、`T` を *container-like* と呼ぶことにする。
- `in` の型引数として妥当である型の集合を *inputable* とするとき、*inputable* は次の BNF で与えられる。
```
inputable ::=
    | extactable
    | tuple-like<inputable, inputable, ..., inputable>
    | container-like<inputable>
```
ただし、`container-like<inputable>` には `std::map<K, V>` みたいなのもお気持ちで含めています。
（`std::map<K, V>::value_type` は `std::pair<const K, V>` で、`std::pair<K, V>` が *extractable* なら OK）

## Usage
- `in<T>() -> T`
  - `T` は *extractable*
  - `T` の suffix が `_1` であれば 1-index を 0-indexed に変換する。
- `in<tuple-like<T1, T2, ..., TN>>() -> tuple-like<T1, T2, ..., TN>`
  - `tuple-like` は [*tuple-like*](https://cpprefjp.github.io/reference/tuple/make_from_tuple.html) な型とする。
  - `T1`, `T2`, ..., `TN` の順に入力される。
- `in<T1, T2, ..., TN> -> std::tuple<T1, T2, ..., TN>`
  - 構造化束縛を見越して `std::tuple` に wrap して返す。
  - `const auto [t1, t2, ..., tn] = in<T1, T2, ..., TN>()`
- `in<C>(const& usize[] extent) -> C`
  - $N$ を `extent` の長さとして、`C::value_type::...::value_type`（$N$ 回）が *extractable* であることを要請する。
  - `C(extent[0], C::value_type(extent[1], C::value_type::value_type(extent[2], ...)))` みたいなインスタンスを返す（）
- `in_vec<T>(extent)`
  - $N$ を `extent` の長さとして、`C` を `std::vector<std::vector<...<T>>>`（$n$ 重）として `in<C>(extent)` を返す。

```c++
// 42
in<int>() // -> 42
// 1 2.0 three
in<int, double, std::string>() // -> std::tuple<int, double, std::string>{ 1, 2.0, "three" }
// atree 4728
in<std::pair<std::string, uint>> // -> std::pair<std::string, uint>{ "atree", 4728 }
// 1 2 3 4 5
in<std::vector<int>>({5}) // -> std::vector<int>{ 1, 2, 3, 4, 5 }
// 1 1 2 3 5
in<std::set<int>>({5}) // -> std::set<int>{ 1, 2, 3, 5 }
// 1 2 3
// 4 5 6
in<std::deque<std::stack<int>>>({2, 3}) // -> std::deque<std::stack<int>>{ std::stack<int>{ 1, 2, 3 }, std::stack<int>{4, 5, 6}}
// abc
// def
in_vec<char>({2, 3}) // std::vector<std::vector<char>>{ {'a', 'b', 'c' }, {'d', 'e', 'f' } }
// 1
in<usize_1>() // -> 0 (1-indexed to 0-indexed)
```

## Note
- source を `std::cin` に限定したくない。
  - 例えば、`auto in = istream_wrapper(std::cin)` みたいな使い方ができると理想的。
  - source として `std::istringstream` とかを指定できると便利そう。
  - `istream_wrapper` には `std::basic_istream` を継承した型を渡されるべきだが、これどうやって保持すべきかわからない（型はなに？）
  - 適当な namespace に包んでも良いが、外部リンゲージを持たせにくい。
  - `istream_wrapper` が関数オブジェクトを返せばよいが、型引数を明示する必要のある `operator()` のオーバーロードは見栄えが悪い。
    - `in.template operator()<T>()` みたいな感じ（template 限定子）
    - `in<T>()` の `T` はクラステンプレート `in` の型引数と解釈されてしまう。
  - lambda をオーバーロードしようとも思ったが、オーバーロード同士が循環参照するのでダメ
- 無駄なコピーがどこかにありそう。

## Reference
- [ラムダ式のオーバーロード](https://yohhoy.hatenadiary.jp/entry/20200715/p1)
