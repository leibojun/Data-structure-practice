cmake_minimum_required(VERSION 3.16)
project(c-projects C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(main main.c)

# 严格警告：GCC / Clang / MSVC 都生效
if(MSVC)
    target_compile_options(main PRIVATE /W3)
else()
    target_compile_options(main PRIVATE -Wall -Wextra)
endif()
