//
// Created by AlexanderSYN on 14.05.2026.
//

#include "../../header/json/JSON.h"

void JSON::save_command(std::string command, std::string action) {
    std::string path = "../commands/commands.json";
    json root_node;

    std::ifstream input_file(path);
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
    new_command["name"] = command;
    new_command["action"] = action;

    root_node.push_back(new_command);

    std::ofstream output_file(path);
    if (output_file.is_open()) {
        output_file << root_node.dump(4);
        output_file.close();
        std::println("[SYSTEM] Command: {} successfully saved!", command);
    }
    else {
        std::println(std::cerr, "[ERROR] Failed to saved command in commands.json");
    }
}
