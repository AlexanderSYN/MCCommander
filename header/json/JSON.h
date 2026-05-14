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
    void save_command(std::string command, std::string action);
}

#endif //SIMPLEMINICOMMANDER_JSON_H
