cmake_minimum_required(VERSION 3.31)
project(MCComand)

set(CMAKE_CXX_STANDARD 26)

add_executable(MCComand main.cpp
        header/fs/FILEO.h
        header/fs/include_fs.h

        header/helper/check_command.hpp
        header/helper/include_helper.h
        header/helper/path_ff.h

        cpp/fs/FILEO.cpp

        cpp/helper/path_ff.cpp
        header/console/cmd.h
        cpp/console/cmd.cpp
        header/helper/helper.h
        cpp/helper/helper.cpp
)
target_link_libraries(MCComand PRIVATE stdc++exp)
