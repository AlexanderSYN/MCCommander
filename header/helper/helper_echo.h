//
// Created by AlexanderSYN on 08.05.2026.
//

#ifndef SIMPLEMINICOMMANDER_HELPER_ECHO_H
#define SIMPLEMINICOMMANDER_HELPER_ECHO_H
#include <vector>

#include "include_helper.h"

class helper_echo {
private:
    static fs::path path_for_echo;

public:
    static bool contains_redirection(const std::vector<std::string>& args);
    static fs::path get_path_redirection();
};

#endif //SIMPLEMINICOMMANDER_HELPER_ECHO_H
