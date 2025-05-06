# ft_printf

C言語の `printf` を再実装して、文字列フォーマットと可変引数の処理を学ぶプロジェクトです。

## ✅ 構成

- 関数名：`ft_printf`
- プロトタイプ：`int ft_printf(const char *format, ...);`
- 対応フォーマット：`%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`
- 出力ライブラリ名：`libftprintf.a`

## 🔧 使用可能関数

- `write`
- `malloc`
- `free`
- `va_start`
- `va_arg`
- `va_copy`
- `va_end`

## 💎 ボーナス（任意）

- フラグ対応：`-`, `0`, `.`, 数値幅, `#`, `+`, スペース
- 精度やフィールド幅の処理を実装
