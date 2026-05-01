//
// Created by AlexanderSYN on 30.03.2026.
//

#ifndef FILEDIRMAKE_H
#define FILEDIRMAKE_H

#include "include_fs.h"

namespace DIRMAKE {
    void create_dir(fs::path path, std::string dir);
    void command_mkdir(const fs::path &path,
                        std::vector<std::string> args);
}

#endif //FILEDIRMAKE_H
