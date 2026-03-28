//
// Created by AlexanderSYN on 28.03.2026.
//
#include "../../header/console/cmd.h"

void cmd::run(const std::string& command) {
    try {
        system(command.c_str());
    } catch (const std::exception& e) {
        std::cerr << "[CRITICAL_ERROR_CMD_COMMAND] " << e.what() << std::endl;
    }
}
