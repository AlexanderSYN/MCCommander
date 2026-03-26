//
// Created by AlexanderSYN on 26.03.2026.
//

// FILEO - File Open

#include "../../header/fs/FILEO.h"

void FILEO::read_txt(fs::path path_to_file_txt) {
    std::ifstream file(path_to_file_txt, std::ios::binary);
    if (!file) {
        std::cerr << "[ERROR_READ_TXT] File not found!\n";
        return;
    }

    char buffer[4096]; // reading for 4kb
    while (file.read(buffer, sizeof(buffer)) || file.gcount() > 0) {
        std::string_view view(buffer, file.gcount());
        std::cout << view;
    }
}
