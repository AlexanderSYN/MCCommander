//
// Created by AlexanderSYN on 04.04.2026.
//

#include "../../header/fs/FILEDEL.h"

#include "../../header/helper/helper.h"

void delete_folder(const fs::path &path);
void delete_file(const fs::path &path);

void FILEDEL::del(const fs::path &path) {
    try {
        char choice;

        std::print("[SYSTEM] Are you sure <y/n>? ");
        std::cin >> choice;

        if (std::tolower(choice) == 'y') {
            if (is_regular_file(path))
                delete_file(path);
            else
                delete_folder(path);

        } else {
            std::println("[SYSTEM] operation canceled!");
            helper::clear_input_buffer();
        }

    } catch (const std::exception &e) {
        std::println(std::cerr, "[CRITICAL_ERROR_DELETE] {}",
            e.what());
    }
}

///
/// better use it in func where need only delete without output
/// about operation, e.g. in func move
/// (critical_err outputing)
/// @param path path file or folder to delete
void FILEDEL::del_without_param_and_log(const fs::path& path) {
    try {
        if (is_regular_file(path))
            fs::remove(path);
        else
            fs::remove_all(path);
    } catch (const std::exception &e) {
        std::println(std::cerr, "[CRITICAL_ERROR] {}",
            e.what());
        helper::clear_input_buffer();
    }

}

void delete_file(const fs::path &path) {
    if (fs::remove(path)) {
        std::println("[SYSTEM] File [{}] "
                     "deleted successfully!",
                     path.filename().string());
        helper::clear_input_buffer();

    }
    else {
        std::println(std::cerr, "[ERR] deleting"
                                " file [{}]!",
                                path.filename().string());
        helper::clear_input_buffer();
    }
}

void delete_folder(const fs::path &path) {
    if (fs::remove_all(path)) {
        std::println("[SYSTEM] Folder [{}] deleted successfully!",
                     path.filename().string());
        helper::clear_input_buffer();
    }
    else {
        std::println(std::cerr, "[ERR] deleting "
                                "folder [{}]!",
                                path.filename().string());
        helper::clear_input_buffer();
    }
}
