//
// Created by AlexanderSYN on 14.05.2026.
//

#include "../../header/json/JSON.h"
#include "../../header/helper/Output.hpp"
#include "../../header/fs/COPY.h"

void JSON::save_command(const std::string& cmd, const std::vector<std::string> act) {
    json root_node;

    std::string action = "";

    for (std::string tmp : act | std::views::drop(2)) {
        action += tmp += " ";
    }

    std::ifstream input_file(FILE_PATH);
    if (input_file.is_open()) {
        try {
            input_file >> root_node;
        }
        catch (const json::parse_error& err_parse) {
            // if the file is empty or corrupted, created empty array
            root_node = json::array();
        }
    }
    else {
        // If there is no file, initialize it as an empty array
        root_node = json::array();
    }

    if (!root_node.is_array())
        root_node = json::array();

    json new_command;
    new_command["command"] = cmd;
    new_command["action"] = action;

    root_node.push_back(new_command);

    std::ofstream output_file(FILE_PATH);
    if (output_file.is_open()) {
        output_file << root_node.dump(4);
        output_file.close();
        std::println("[SYSTEM] Command: {} successfully saved!", cmd);
    }
    else {
        O::perror("Failed to saved command in commands.json");
    }
}

std::string JSON::get_action(const std::string &command) {
    if (!check_exists_json()) return "";

    std::ifstream file(FILE_PATH);
    json root_node;
    file >> root_node;

    if (root_node.is_array())
        for (const auto& item : root_node) {
            std::string cmd = item.value("command", "unknown");
            std::string act = item.value("action", "unknown");

            if (cmd == command)
                return act;
        }

    return "None";
}

void JSON::print_all_commands() {
    if (!check_exists_json()) return;

    std::ifstream file(FILE_PATH);
    json root_node;
    file >> root_node;

    if (root_node.is_array()) {
        for (const auto& item : root_node) {
                std::string cmd = item.value("command", "uknown");
                std::string act = item.value("action", "none");

                std::println("{} :  {}", cmd, act);
        }
    }
    else {
        O::perror("Cannot reading json with commands");
    }
}

bool JSON::check_exists_json() {
    if (!fs::exists(FILE_PATH)) {
        O::perror("File is not exists!");
        return false;
    }
    return true;
}