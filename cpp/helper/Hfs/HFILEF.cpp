//
// Created by AlexanderSYN on 31.03.2026.
//

#include "../../../header/helper/Helperfs/HFILEF.h"

#include "../../../header/fs/space.h"

std::string HFILEF::type(const fs::path& path_f) {
    if (fs::is_regular_file(path_f)) return "[FILE]";
    if (fs::is_directory(path_f)) return "[DIR]";
    if (fs::is_symlink(path_f)) return "[LINK]";
    if (fs::is_block_file(path_f)) return "[BLOCK]";
    if (fs::is_character_file(path_f)) return "[CHARACTER]";
    if (fs::is_fifo(path_f)) return "[PIPE (FIFO)]";
    if (fs::is_socket(path_f)) return "[SOCKET]";

    return "[UNKNOWN]";
}


std::string HFILEF::is_hidden(const fs::path& path_f) {
#ifdef _WIN32 // for windows
    DWORD attributes = GetFileAttributesA(path_f.string().c_str());

    if ((attributes & FILE_ATTRIBUTE_HIDDEN) != 0)
        return "[HIDDEN]";

    return "";

#else // for MACOS / Linux
    if (path_f.filename().string()[0] == '.')
        return "[HIDDEN]"

#endif
}


bool HFILEF::is_system(const fs::path &path) {
    try {
        std::string path_str = path.string();
        std::string filename = path.filename().string();

        // Skip hidden files/folders (starting with a dot in Linux/Mac)
        if (filename[0] == '.') {
            return true;
        }

        // Skip the system directories
        for (const auto &sys_dir: SYSTEM_DIRECTORIES) {
            if (path_str.find(sys_dir) != std::string::npos) {
                return true;
            }
        }

        // Skipping files with system extensions
        if (path.has_extension()) {
            std::string ext = path.extension().string();
            std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);

            for (const auto &sys_ext: SYSTEM_EXTENSIONS) {
                if (ext == sys_ext) {
                    return true;
                }
            }
        }

        // Skipping temporary files
        if (filename.find("~") != std::string::npos ||
            filename.find(".tmp") != std::string::npos ||
            filename.find("temp") != std::string::npos) {
            return true;
            }

        return false;
    } catch (const std::exception& e) {
        std::println(std::cerr, "[CRITICAL_ERROR_CHECK_SYSTEM_FILE] {}",
            e.what());
        return false;
    }
}

std::string HFILEF::get_size_file(const fs::path &path) {
    try {
        uintmax_t size_in_bytes = fs::file_size(path);

        return space::format_bytes(size_in_bytes);

    } catch (const std::exception& e) {
        return "ERR";
    }
}



///
/// @param path default path
/// @param path_ff the file specified in the path_ff file
/// @return if path is not exists then path_ff + path
fs::path HFILEF::get_fetch_full_path(const fs::path& path,
                                    const fs::path& path_ff) {
    return fs::exists(path) ? path : path_ff / path;
}


