//
// Created by AlexanderSYN on 02.06.2026.
//

#ifndef SIMPLEMINICOMMANDER_FOR_HELP_H
#define SIMPLEMINICOMMANDER_FOR_HELP_H

#include <iostream>
#include <print>
#include <vector>

namespace help {
    void check_help(const std::vector<std::string>& args);
    void cmd();
    void path();
    void date();
    void history();
    void clear();
    void color();
    void my_commands();
    void open();
    void fileDir();
    void text();
    void ls();
    void find();
    void disk();
    void exit();
    void all();
}

#endif //SIMPLEMINICOMMANDER_FOR_HELP_H
