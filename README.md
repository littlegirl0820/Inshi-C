# 大阪大学大学院情報科学研究科院試 Cのコード一覧
## 概要
情報科学研究科の院試で出題されたプログラミングの問題のコードをまとめたもの．
## 使い方
[build](/build/)以下の各ディレクトリにコンパイルファイルと入力ファイルをおいてあるのでそれを使うといいです．基本的に出題コードから変更を加えていない(フォーマッタの影響でやや違うけど)ので入力ファイルが相対参照です．なので例えば[R5のcode1.c](/R5/code1.c)を試したい場合は
```bash
# pwd : Inshi-C
cd build/R5
./code1
```
としてください．
```bash
# pwd : Inshi-C
cd build
./R5/code1
```
とかするとセグフォります．
で，`printf`とかしてない年は実行しても何も起こらないので`printf`を追加するなりなんなりしてください．

一応`CMakeLists.txt`もあるのですが，入力ファイルは作成されないので新たに`cmake`を実行した場合は各年のディレクトリに入力ファイルもあるのでコピーしてください．

新しい年度のものを増やしたい場合は他の年度のをコピーして書き換えて[Inshi-C直下のCMakeLists.txt](/CMakeLists.txt)に
```
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/<増やし年度のディレクトリ名>)
```
を加えてください．