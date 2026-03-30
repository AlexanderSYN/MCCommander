//
// Created by AlexanderSYN on 30.03.2026.
//

#ifndef HFILEO_H
#define HFILEO_H

#include "../include_helper.h"

//
// HFILEO -> Helper for FILEO
//

namespace HFILEO {
    std::string type(const fs::path& path_f);
    std::string is_hidden(const fs::path& path_f);
}

#endif //HFILEO_H
