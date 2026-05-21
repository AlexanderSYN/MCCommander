//
// Created by AlexanderSYN on 15.05.2026.
//

#ifndef SIMPLEMINICOMMANDER_JSON_H
#define SIMPLEMINICOMMANDER_JSON_H

#include "json.hpp"
#include <iostream>
#include <print>
#include <fstream>

using json = nlohmann::json;

namespace fs = std::filesystem;

namespace JSON {
    const fs::path FILE_PATH = "../commands/commands.json";
    bool check_exists_json();

    void save_command(const std::string& cmd, const std::vector<std::string> act);
    std::string get_action(const std::string& command);
    bool change_command(const std::string& command);
    bool delete_command(const std::string& command);
    void print_all_commands();
}

#endif //SIMPLEMINICOMMANDER_JSON_H
