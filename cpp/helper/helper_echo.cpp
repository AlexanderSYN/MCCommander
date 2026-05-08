//
// Created by AlexanderSYN on 08.05.2026.
//

#include "../../header/helper/helper_echo.h"

fs::path helper_echo::path_for_echo = "";

bool helper_echo::contains_redirection(const std::vector<std::string>& args) {
    for (int i = 0; args.size() > i; i++) {
        if (args[i] == ">>")
            if (exists(fs::path(args[i++]))) {
                path_for_echo = fs::path(args[i++]);
                return true;
            }
    }
    path_for_echo = "none";
    return false;
}

fs::path helper_echo::get_path_redirection() {
    return fs::exists(path_for_echo) ?
            path_for_echo : "none";
}
