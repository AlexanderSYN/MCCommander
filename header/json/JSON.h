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
    bool check_exists_json();

    void save_command(const std::string& cmd, const std::vector<std::string> act);
    std::string get_action(const std::string& command);
    bool change_command(const std::string& old_command,const std::string& new_command);
    bool change_action(const std::string& command, const std::vector<std::string>& new_action);
    bool delete_command(const std::string& command);
    void print_all_commands();

    void get_all_command(json& root_node);
    bool write_in_json(const json& root_node);
}

#endif //SIMPLEMINICOMMANDER_JSON_H
