# 数据结构练习 · Data Structure Practice

C 语言数据结构练习代码，每个 `.c` 文件是一个**独立可运行**的小练习。

## 📂 目录结构

```
c-projects/
├── src/                 ← 所有练习代码都在这里
│   ├── seqlist.c        顺序表：结构定义与初始化
│   └── test1.c          环境测试
├── sample-input.txt    输入样例（供需要读入数据的练习使用）
├── Makefile
├── CMakeLists.txt
└── .github/workflows/  自动编译（三平台）
```

## 📑 练习索引

| 文件 | 内容 | 状态 |
|------|------|------|
| [src/seqlist.c](src/seqlist.c) | 顺序表：存储结构定义 + 初始化 | ✅ |
| [src/test1.c](src/test1.c) | 环境测试 | ✅ |

> 新增练习：在 `src/` 下新建 `xxx.c`（要有自己的 `main`），然后更新本表格。

## 🔨 编译与运行

### Make

```bash
make                    # 编译默认文件 src/seqlist.c
make SRC=src/test1.c    # 编译指定文件
make run                # 编译并运行
make clean              # 清理
```

### CMake（一次编译全部练习）

```bash
cmake -S . -B build
cmake --build build
```

每个 `src/*.c` 会生成一个同名可执行文件。

### 直接调用编译器

```bash
gcc -std=c17 -Wall -Wextra -O2 src/seqlist.c -o seqlist
./seqlist
```

## 📝 约定

- 源码统一 **UTF-8** 编码
- 每个练习文件**各自有 `main()`**，独立编译（一个程序只能有一个 `main`）
- 编译产物（`*.exe`、`build/`）和编辑器配置（`.vscode/`）不纳入版本控制
- Windows 中文控制台如遇乱码，本机可临时加 `-fexec-charset=GBK`；该参数不写进构建配置，以保证跨平台一致

## ✅ 自动构建

推送后 GitHub Actions 会在 **Ubuntu / Windows / macOS** 三个平台自动编译 `src/` 下全部文件。
