---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: complib/misc/alias.hpp
    title: Aliases
  - icon: ':heavy_check_mark:'
    path: complib/misc/cin_wrapper.hpp
    title: Cin Wrapper
  - icon: ':heavy_check_mark:'
    path: complib/misc/cout_wrapper.hpp
    title: Cout Wrapper
  - icon: ':heavy_check_mark:'
    path: complib/misc/template.hpp
    title: Template
  - icon: ':heavy_check_mark:'
    path: complib/misc/type_traits.hpp
    title: complib/misc/type_traits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/library_checker/aplusb.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 2 \"complib/misc/template.hpp\"\
    \n\n#include <iomanip>\n#include <iostream>\n#include <memory>\n\n#line 2 \"complib/misc/alias.hpp\"\
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
    #undef INDEXED_IMPL\n\n}  // namespace a2ry\n#line 2 \"complib/misc/cin_wrapper.hpp\"\
    \n\n#include <algorithm>\n#include <concepts>\n#include <deque>\n#line 7 \"complib/misc/cin_wrapper.hpp\"\
    \n#include <ranges>\n#line 9 \"complib/misc/cin_wrapper.hpp\"\n#include <utility>\n\
    #include <vector>\n\n#line 2 \"complib/misc/type_traits.hpp\"\n\n#line 7 \"complib/misc/type_traits.hpp\"\
    \n\n#line 9 \"complib/misc/type_traits.hpp\"\n\nnamespace a2ry {\n\ntemplate<class\
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
    \ {\n    return in<nth_vector_t<T, N>>(sizes);\n}\n\n}  // namespace a2ry\n#line\
    \ 2 \"complib/misc/cout_wrapper.hpp\"\n\n#line 5 \"complib/misc/cout_wrapper.hpp\"\
    \n\nnamespace io_config {\n\ninline auto sep = \" \";\ninline auto eoln = \"\\\
    n\";\ninline auto yes = \"Yes\";\ninline auto no = \"No\";\n\n}  // namespace\
    \ io_config\n\nnamespace a2ry {\n\ntemplate<class T> inline auto print(T&& x)\
    \ -> void {\n    if constexpr (stream_insertable<T>) {\n        if constexpr (std::same_as<std::remove_cvref<T>,\
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
    \ a2ry\n#line 10 \"complib/misc/template.hpp\"\n\n__attribute__((constructor))\
    \ inline auto io_setup() noexcept {\n    std::ios::sync_with_stdio(false);\n \
    \   std::cin.tie(nullptr);\n    std::cout << std::fixed << std::setprecision(10);\n\
    \    std::cerr << std::fixed << std::setprecision(10);\n}\n#line 4 \"test/library_checker/aplusb.test.cpp\"\
    \n\nint main() {\n    a2ry::println(a2ry::in<int>() + a2ry::in<int>());\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    complib/misc/template.hpp\"\n\nint main() {\n    a2ry::println(a2ry::in<int>()\
    \ + a2ry::in<int>());\n}\n"
  dependsOn:
  - complib/misc/template.hpp
  - complib/misc/alias.hpp
  - complib/misc/cin_wrapper.hpp
  - complib/misc/type_traits.hpp
  - complib/misc/cout_wrapper.hpp
  isVerificationFile: true
  path: test/library_checker/aplusb.test.cpp
  requiredBy: []
  timestamp: '2023-01-22 19:33:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/aplusb.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/aplusb.test.cpp
- /verify/test/library_checker/aplusb.test.cpp.html
title: test/library_checker/aplusb.test.cpp
---
