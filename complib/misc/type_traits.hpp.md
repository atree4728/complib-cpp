---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: complib/misc/alias.hpp
    title: Aliases
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: complib/misc/cin_wrapper.hpp
    title: Cin Wrapper
  - icon: ':heavy_check_mark:'
    path: complib/misc/cout_wrapper.hpp
    title: Cout Wrapper
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
  bundledCode: "#line 2 \"complib/misc/type_traits.hpp\"\n\n#include <iostream>\n\
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
    #undef INDEXED_IMPL\n\n}  // namespace a2ry\n#line 9 \"complib/misc/type_traits.hpp\"\
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
    \ a2ry\n"
  code: "#pragma once\n\n#include <iostream>\n#include <type_traits>\n#include <utility>\n\
    #include <vector>\n\n#include \"alias.hpp\"\n\nnamespace a2ry {\n\ntemplate<class\
    \ T, std::size_t I>\nconcept has_tuple_element = requires(T t) {\n           \
    \                     typename std::tuple_element_t<I, std::remove_cvref_t<T>>;\n\
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
    \ a2ry\n"
  dependsOn:
  - complib/misc/alias.hpp
  isVerificationFile: false
  path: complib/misc/type_traits.hpp
  requiredBy:
  - complib/misc/cout_wrapper.hpp
  - complib/misc/template.hpp
  - complib/misc/cin_wrapper.hpp
  timestamp: '2023-01-22 19:33:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_11_D.test.cpp
  - test/library_checker/unionfind.test.cpp
  - test/library_checker/aplusb.test.cpp
documentation_of: complib/misc/type_traits.hpp
layout: document
title: Type Traits
---
