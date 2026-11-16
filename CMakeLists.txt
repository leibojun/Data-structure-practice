cmake_minimum_required(VERSION 3.16)
project(c-projects C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

# src/ 下每个 .c 各自编译成一个可执行文件（每个练习都有独立 main）
file(GLOB PRACTICE_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")

if(NOT PRACTICE_SOURCES)
    message(WARNING "src/ 下没有 .c 文件")
endif()

foreach(src ${PRACTICE_SOURCES})
    get_filename_component(name ${src} NAME_WE)
    add_executable(${name} ${src})
    if(MSVC)
        target_compile_options(${name} PRIVATE /W3)
    else()
        target_compile_options(${name} PRIVATE -Wall -Wextra)
    endif()
endforeach()
