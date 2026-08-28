//
// Created by AlexanderSYN on 26.03.2026.
//

// FILEO - File Open

#ifndef FILEO_H
#define FILEO_H

#include "include_fs.h"

//=====================
// FILEO - File Open
//=====================

namespace FILEO {
    void set_path_in_cd(const std::string& path_by_user);
    void choice_place_path_in_cd(int place);

    void command_dir_windows();

    void output_for_command_open(const fs::directory_entry& entry,
                                const std::chrono::system_clock::time_point& sctp,
                                bool isDirectory);
    void command_open();
    void command_open(const fs::path& path_ff);

    void command_list();
    void command_list(const fs::path& path_f);
    void command_list_with_parameter(std::string param);


}

#endif //FILEO_H
