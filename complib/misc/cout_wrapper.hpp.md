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
  bundledCode: "#line 2 \"complib/misc/cout_wrapper.hpp\"\n\n#line 2 \"complib/misc/alias.hpp\"\
    \n\n#include <cstddef>\n#include <cstdint>\n#include <type_traits>\n\nnamespace\
    \ a2ry {\n\nusing i32 = std::int_fast32_t;\nusing i64 = std::int_fast64_t;\nusing\
    \ u32 = std::uint_fast32_t;\nusing u64 = std::uint_fast64_t;\nusing usize = std::size_t;\n\
    using isize = std::ptrdiff_t;\n\nconstexpr auto operator\"\"_i32(unsigned long\
    \ long n) noexcept {\n    return static_cast<i32>(n);\n}\nconstexpr auto operator\"\
    \"_i64(unsigned long long n) noexcept {\n    return static_cast<i64>(n);\n}\n\
    constexpr auto operator\"\"_u32(unsigned long long n) noexcept {\n    return static_cast<u32>(n);\n\
    }\nconstexpr auto operator\"\"_u64(unsigned long long n) noexcept {\n    return\
    \ static_cast<u64>(n);\n}\nconstexpr auto operator\"\"_uz(unsigned long long n)\
    \ noexcept {\n    return static_cast<usize>(n);\n}\nconstexpr auto operator\"\"\
    _iz(unsigned long long n) noexcept {\n    return static_cast<isize>(n);\n}\n\n\
    template<class T> struct is_1indexed: std::false_type {};\n#define INDEXED_IMPL(type)\
    \                    \\\n    struct type##_##1 { using base = type; }; \\\n  \
    \  template<> struct is_1indexed<type##_##1>: std::true_type {};\nINDEXED_IMPL(int)\n\
    INDEXED_IMPL(i32)\nINDEXED_IMPL(u32)\nINDEXED_IMPL(i64)\nINDEXED_IMPL(u64)\nINDEXED_IMPL(usize)\n\
    #undef INDEXED_IMPL\n\n}  // namespace a2ry\n#line 2 \"complib/misc/type_traits.hpp\"\
    \n\n#include <iostream>\n#line 5 \"complib/misc/type_traits.hpp\"\n#include <utility>\n\
    #include <vector>\n\n#line 9 \"complib/misc/type_traits.hpp\"\n\nnamespace a2ry\
    \ {\n\ntemplate<class T, std::size_t I>\nconcept has_tuple_element = requires(T\
    \ t) {\n                                typename std::tuple_element_t<I, std::remove_cvref_t<T>>;\n\
    \                                { get<I>(t) } -> std::convertible_to<std::tuple_element_t<I,\
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
    \ a2ry\n#line 5 \"complib/misc/cout_wrapper.hpp\"\n\nnamespace io_config {\n\n\
    inline auto sep = \" \";\ninline auto eoln = \"\\n\";\ninline auto yes = \"Yes\"\
    ;\ninline auto no = \"No\";\n\n}  // namespace io_config\n\nnamespace a2ry {\n\
    \ntemplate<class T> inline auto print(T&& x) -> void {\n    if constexpr (stream_insertable<T>)\
    \ {\n        if constexpr (std::same_as<std::remove_cvref<T>, bool>) std::cout\
    \ << (x ? io_config::yes : io_config::no);\n        else std::cout << x;\n   \
    \ } else if constexpr (tuple_like<T>) {\n        [&]<usize... I>(std::index_sequence<I...>)->void\
    \ {\n            (\n                [&] {\n                    print(std::forward<std::tuple_element_t<I,\
    \ T>>(get<I>(x)));\n                    if constexpr (I + 1 != std::tuple_size_v<T>)\
    \ print(' ');\n                }(),\n                ...);\n        }\n      \
    \  (std::make_index_sequence<std::tuple_size_v<T>>());\n    } else if constexpr\
    \ (std::ranges::forward_range<T>) {\n        for (auto it = std::ranges::begin(x);\
    \ it != std::ranges::end(x); ++it) {\n            print(std::forward<decltype(*it)>(*it));\n\
    \            if (std::ranges::next(it) != std::ranges::end(x)) print(io_config::sep);\n\
    \        }\n    } else {\n        static_assert(\n            requires(T) { requires(false);\
    \ }, \"print: got an unexpented type\");\n    }\n}\n\ntemplate<class... Args>\
    \ inline auto print(Args&&... args) -> void {\n    print(std::tuple{ std::forward<Args>(args)...\
    \ });\n}\n\ntemplate<class... Args> inline auto println(Args&&... args) -> void\
    \ {\n    print(std::forward<Args>(args)...);\n    print(io_config::eoln);\n}\n\
    \ntemplate<class... Args> [[noreturn]] inline auto drop(Args&&... args) -> void\
    \ {\n    println(std::forward<Args>(args)...);\n    exit(0);\n}\n\n}  // namespace\
    \ a2ry\n"
  code: "#pragma once\n\n#include \"alias.hpp\"\n#include \"type_traits.hpp\"\n\n\
    namespace io_config {\n\ninline auto sep = \" \";\ninline auto eoln = \"\\n\"\
    ;\ninline auto yes = \"Yes\";\ninline auto no = \"No\";\n\n}  // namespace io_config\n\
    \nnamespace a2ry {\n\ntemplate<class T> inline auto print(T&& x) -> void {\n \
    \   if constexpr (stream_insertable<T>) {\n        if constexpr (std::same_as<std::remove_cvref<T>,\
    \ bool>) std::cout << (x ? io_config::yes : io_config::no);\n        else std::cout\
    \ << x;\n    } else if constexpr (tuple_like<T>) {\n        [&]<usize... I>(std::index_sequence<I...>)->void\
    \ {\n            (\n                [&] {\n                    print(std::forward<std::tuple_element_t<I,\
    \ T>>(get<I>(x)));\n                    if constexpr (I + 1 != std::tuple_size_v<T>)\
    \ print(' ');\n                }(),\n                ...);\n        }\n      \
    \  (std::make_index_sequence<std::tuple_size_v<T>>());\n    } else if constexpr\
    \ (std::ranges::forward_range<T>) {\n        for (auto it = std::ranges::begin(x);\
    \ it != std::ranges::end(x); ++it) {\n            print(std::forward<decltype(*it)>(*it));\n\
    \            if (std::ranges::next(it) != std::ranges::end(x)) print(io_config::sep);\n\
    \        }\n    } else {\n        static_assert(\n            requires(T) { requires(false);\
    \ }, \"print: got an unexpented type\");\n    }\n}\n\ntemplate<class... Args>\
    \ inline auto print(Args&&... args) -> void {\n    print(std::tuple{ std::forward<Args>(args)...\
    \ });\n}\n\ntemplate<class... Args> inline auto println(Args&&... args) -> void\
    \ {\n    print(std::forward<Args>(args)...);\n    print(io_config::eoln);\n}\n\
    \ntemplate<class... Args> [[noreturn]] inline auto drop(Args&&... args) -> void\
    \ {\n    println(std::forward<Args>(args)...);\n    exit(0);\n}\n\n}  // namespace\
    \ a2ry\n"
  dependsOn:
  - complib/misc/alias.hpp
  - complib/misc/type_traits.hpp
  isVerificationFile: false
  path: complib/misc/cout_wrapper.hpp
  requiredBy:
  - complib/misc/template.hpp
  timestamp: '2023-01-22 19:33:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_11_D.test.cpp
  - test/library_checker/unionfind.test.cpp
  - test/library_checker/aplusb.test.cpp
documentation_of: complib/misc/cout_wrapper.hpp
layout: document
title: Cout Wrapper
---

## Requirements
- `T` を型として、`T` が `requires (T t) { std::cout << t; }` を満たすとき、`T` を *insertable* と呼ぶことにする。
- `T` をクラステンプレートまたは型として、`T::value_type` が存在するとき、`T` を *container-like* と呼ぶことにする。
- `print` の型引数として妥当である型の集合を *printable* とするとき、*printable* は次の BNF で与えられる。
```
printable ::=
    | printable
    | tuple-like<printable, printable, ..., printable>
    | container-like<printable>
```

## Usage
- `print`: 与えられた引数を順に空白区切りで出力する。
  - *tuple-like* は空白区切りで出力する。
  - *continer-like* は `io_config::sep` 区切りで出力する。
- `println`: `print` 後に改行（`io_config::eoln` を出力）する。
- `drop`: `println` 後にプログラムを強制終了（`std::exit(0)`）する。

## Note
- 無駄なコピーがどこかにありそう。
