---
title: Cout Wrapper
documentation_of: //complib/misc/cout_wrapper.hpp
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
