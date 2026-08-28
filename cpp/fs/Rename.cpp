//
// Created by AlexanderSYN on 28.08.2026.
//

#include "../../header/fs/Rename.h"
#include "../../header/fs/FILEFIND.h"
#include "../../header/helper/path_ff.h"

void Rename::ren(const std::string &old_name,
                 const std::string &new_name) {

    if (old_name.empty() || new_name.empty()) {
        std::println(std::cerr, "[ERROR] File or Folder name cannot be empty!");
        return;
    }

    fs::path base_dir = path_ff::get_path();

    fs::path old_path = fs::path(old_name).is_relative() ? (base_dir / old_name)
                                                         : fs::path(old_name);
    fs::path new_path = fs::path(new_name).is_relative() ? (base_dir / new_name)
                                                         : fs::path(new_name);
    old_path = old_path.lexically_normal();
    new_path = new_path.lexically_normal();

    if (!fs::exists(old_path)) {
        std::println(std::cerr, "[ERROR] Cannot rename!");
        std::println(std::cerr, "[REASON] Source File or Folder not found: {}", old_path.string());
        return;
    }

    // 3. Проверяем, не занято ли уже новое имя
    if (fs::exists(new_path)) {
        std::println(std::cerr, "[ERROR] Cannot rename!");
        std::println(std::cerr, "[REASON] Destination path already exists: {}", new_path.string());
        return;
    }

    bool is_dir = fs::is_directory(old_path);

    // 4. Выполняем переименование
    try {
        fs::rename(old_path, new_path);

        if (is_dir)
            std::println("[SYSTEM] Directory successfully renamed!");
        else
            std::println("[SYSTEM] File successfully renamed!");

    } catch (const fs::filesystem_error& fs_e) {
        std::println(std::cerr, "[ERROR] Cannot rename!");
        std::println(std::cerr, "[REASON] {}", fs_e.what());
    }
}
