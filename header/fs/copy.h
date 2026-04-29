//
// Created by AlexanderSYN on 29.04.2026.
//

#ifndef COPY_H
#define COPY_H

#include "include_fs.h"

namespace copy {
    void files(fs::path from, fs::path to, fs::path path_ff, std::string parameter);
    void folders(fs::path from, fs::path to, fs::path path_ff, std::string parameter);
}

#endif //COPY_H
