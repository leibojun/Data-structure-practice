# 数据结构练习 —— 按文件编译
#
#   make                     编译默认文件（src/seqlist.c）
#   make SRC=src/test1.c     编译指定文件
#   make run                 编译并运行默认文件
#   make clean               清理所有产物

CC     = gcc
CFLAGS = -std=c17 -Wall -Wextra -O2

SRC ?= src/seqlist.c

ifeq ($(OS),Windows_NT)
    EXE := .exe
else
    EXE :=
endif

TARGET := $(SRC:.c=)$(EXE)

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

ifeq ($(OS),Windows_NT)
run: $(TARGET)
	cmd /c "$(subst /,\,$(TARGET))"

clean:
	-@del /f /q src\*.exe 2>nul
else
run: $(TARGET)
	./$(TARGET)

clean:
	-@rm -f src/*.exe src/seqlist src/test1
endif
