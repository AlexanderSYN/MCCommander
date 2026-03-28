//
// Created by AlexanderSYN on 26.03.2026.
//

// FILEO - File Open

#ifndef FILEO_H
#define FILEO_H

#include "include_fs.h"

namespace FILEO {
    void set_path_in_cd(std::string path_by_user,
        std::string OPath, fs::path path);
    void read_file(const fs::path& path_f);

}

#endif //FILEO_H
