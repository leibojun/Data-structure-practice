# 最小可移植 Makefile —— Linux / macOS / Windows(MinGW) 通用
#
#   make        编译
#   make run    编译并运行（读取 sample-input.txt）
#   make clean  清理产物

# 用 = 而不是 ?=：make 内置了 CC=cc，?= 不会覆盖它。
# 命令行仍可覆盖：make CC=clang
CC     = gcc
CFLAGS = -std=c17 -Wall -Wextra -O2
SRC    = main.c

ifeq ($(OS),Windows_NT)
    TARGET := main.exe
else
    TARGET := main
endif

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

ifeq ($(OS),Windows_NT)
run: $(TARGET)
	cmd /c ".\$(TARGET) < sample-input.txt"

clean:
	-@del /f /q $(TARGET) *.o 2>nul
else
run: $(TARGET)
	./$(TARGET) < sample-input.txt

clean:
	-@rm -f $(TARGET) main main.exe *.o
endif
