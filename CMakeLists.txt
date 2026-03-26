cmake_minimum_required(VERSION 3.31)
project(MCComand)

set(CMAKE_CXX_STANDARD 26)

add_executable(MCComand main.cpp
        header/fs/FILEO.h
        header/fs/include_fs.h
        cpp/fs/FILEO.cpp
        header/helper/check_command.hpp
        header/helper/include_helper.h)
target_link_libraries(MCComand PRIVATE stdc++exp)
