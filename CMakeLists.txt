cmake_minimum_required(VERSION 3.31)
project(MCComand)

set(CMAKE_CXX_STANDARD 26)

add_executable(MCComand main.cpp
        header/fs/FILEO.h
        header/fs/FILEC.hpp

        header/helper/check_command.hpp
        header/helper/include_helper.h
        header/helper/path_ff.h

        cpp/fs/FILEO.cpp
        cpp/fs/FILEC.cpp

        cpp/helper/path_ff.cpp
        header/console/cmd.h
        cpp/console/cmd.cpp
        header/helper/helper.h
        cpp/helper/helper.cpp
        header/console/color_console.h
        cpp/console/color_console.cpp
        header/fs/DIRMAKE.h
        cpp/fs/DIRMAKE.cpp
        header/helper/Helperfs/HFILEF.h
        cpp/helper/Hfs/HFILEF.cpp
        header/fs/FILEDel.h
        cpp/fs/FILEDEL.cpp
        header/date/date.h
        header/date/include_date.h
        cpp/date/date.cpp
        header/fs/FILEFF.h
        cpp/fs/FILEFF.cpp
        header/fs/explorer.h
        cpp/fs/explorer.cpp
        header/text/io_text.h
        cpp/text/io_text.cpp
        header/fs/disk.h
        cpp/fs/disk.cpp
        cpp/fs/space.cpp
        header/fs/space.h
        header/fs/copy.h
        cpp/fs/copy.cpp
        header/fs/MOVE.h
        cpp/fs/MOVE.cpp
)
target_link_libraries(MCComand PRIVATE stdc++exp)
