# c-projects

C 语言练习工程 —— 栈排列合法性校验。

## 题目

给定栈容量 `m`、入栈序列长度 `n`、待检查序列数 `k`：元素按 `1..n` 顺序入栈，
判断每个长度为 `n` 的序列是否是合法的出栈序列。

输入格式：

```
m n k
<k 行，每行 n 个整数>
```

输出：每行一个 `YES` 或 `NO`。

## 环境要求

- C17 编译器：GCC / Clang / MSVC 任一
- 可选：CMake ≥ 3.16，或 GNU Make

## 编译与运行

### 方式一：Make

```bash
make          # 生成 main（Windows 下为 main.exe）
make run      # 用 sample-input.txt 跑一遍
make clean    # 清理
```

### 方式二：CMake

```bash
cmake -S . -B build
cmake --build build
```

### 方式三：直接调编译器

```bash
gcc -std=c17 -Wall -Wextra -O2 main.c -o main
./main < sample-input.txt
```

## 示例

```bash
./main < sample-input.txt
```

```
YES
NO
YES
```

## 说明

- 源码使用 **UTF-8** 编码。
- Windows 中文控制台如需避免乱码，可在本地临时加 `-fexec-charset=GBK`；
  该参数**没有写进** Makefile / CMake，以保证跨平台构建一致。
