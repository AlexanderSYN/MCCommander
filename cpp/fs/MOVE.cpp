//
// Created by AlexanderSYN on 01.05.2026.
//
#include "../../header/fs/MOVE.h"
#include "../../header/fs/COPY.h"
#include "../../header/fs/FILEDEL.h"
#include "../../header/helper/Helperfs/HFILEF.h"

void move_file_or_folder(fs::path from, fs::path to, fs::path pathFF) {
    fs::path from_path = HFILEF::get_fetch_full_path(from, pathFF);
    fs::path to_path = HFILEF::get_fetch_full_path(to, pathFF);

    copy::copy_only_for_func_move(from, to, pathFF);

    if (exists(to_path) && exists(from_path)) {
        FILEDEL::del_without_param_and_log(from_path);
        std::println("[SYSTEM] FILE or FOLDER successfully moved to {}",to_path.string());
    }
    else
        std::println(std::cerr, "[ERROR] FILE or FOLDER is not moved to {}", to_path.string());
}

void MOVE::moveFF(fs::path from, fs::path to, fs::path path_ff) {
    try {
        move_file_or_folder(from, to, path_ff);
    } catch (const std::exception &e) {
        std::println(std::cerr, "[CRITICAL_ERROR_MOVE] {}", e.what());
    }
}

