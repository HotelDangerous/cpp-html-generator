cmake_minimum_required(VERSION 3.16)

project(cpp_html_generator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(cpp-html-generator
    src/main.cpp
    src/cpp_html_generator/Document.cpp
)

target_include_directories(cpp-html-generator
    PRIVATE
        include
)

target_compile_options(cpp-html-generator
    PRIVATE
        -Wall
        -Wextra
        -pedantic
)
