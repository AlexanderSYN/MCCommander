#include <print>
#include <filesystem>
#include <string>

#include "header/fs/FILEO.h"

namespace fs = std::filesystem;

#include "header/helper/check_command.hpp"

//
// MCCommander - Mini Console Commander
//

int main() {
    fs::path path_f; // path file or folder
    std::string OPath = "\\"; // OPath - Output path
    std::string user_input;

    bool isRun = true;

    while (isRun) {
        std::getline(std::cin, user_input);

        //helper::if_command(user_input, "read", FILEO::read_txt(path_f));
        helper::if_command(user_input, "help", [&] { std::print("help"); });
        helper::if_commands(user_input, [&] {isRun = false;}, "ex", "exit");
    }

}


