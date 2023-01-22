---
title: Cin Wrapper
documentation_of: //complib/misc/cin_wrapper.hpp
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
