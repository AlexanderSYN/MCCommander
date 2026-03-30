//
// Created by AlexanderSYN on 30.03.2026.
//

#include "../../../header/helper/Hfs/HFILEO.h"


///
/// return the file or folder type
/// [вернуть тип файла или папки]
///
/// example
/// t.txt -> [FILE]
///
/// @param path_f the path to check and find out which type
/// @return the file or folder type
std::string HFILEO::type(const fs::path& path_f) {
    if (fs::is_regular_file(path_f)) return "[FILE]";
    if (fs::is_directory(path_f)) return "[DIR]";
    if (fs::is_symlink(path_f)) return "[LINK]";
    if (fs::is_block_file(path_f)) return "[BLOCK]";
    if (fs::is_character_file(path_f)) return "[CHARACTER]";
    if (fs::is_fifo(path_f)) return "[PIPE (FIFO)]";
    if (fs::is_socket(path_f)) return "[SOCKET]";

    return "[UNKNOWN]";
}

///
/// Cross-platform verification of whether a file or folder is hidden
/// [Кроссплатформенная проверка того, скрыт ли файл или папка]
///
/// @param path_f the path to check and find out if it is hidden or not
/// @return [HIDDEN] or nothing
std::string HFILEO::is_hidden(const fs::path& path_f) {
    #ifdef _WIN32 // for windows
        DWORD attributes = GetFileAttributesA(path_f.string().c_str());

        if ((attributes & FILE_ATTRIBUTE_HIDDEN) != 0)
            return "[HIDDEN]";

    #else // for MACOS / Linux
        if (path_f.filename().string()[0] == '.')
            return "[HIDDEN]"

    #endif
}


