//
// Created by AlexanderSYN on 13.04.2026.
//

#ifndef SPACE_H
#define SPACE_H

#include "include_fs.h"

namespace space {
    inline constexpr uint64_t KiB = 1024ULL;
    inline constexpr uint64_t MiB = 1024ULL * 1024ULL;
    inline constexpr uint64_t GiB = 1024ULL * 1024ULL * 1024ULL;
    inline constexpr uint64_t TiB = 1024ULL * 1024ULL * 1024ULL * 1024ULL;

    inline constexpr uint64_t PiB = 1024ULL * 1024ULL * 1024ULL * 1024ULL * 1024ULL;
    inline constexpr uint64_t EiB = 1024ULL * 1024ULL * 1024ULL * 1024ULL * 1024ULL * 1024ULL;

    std::string free_disk(const fs::path& path);
    std::string available_in_disk(const fs::path& path);
    std::string occupied_dir(const fs::path& path);
    std::string total_capacity(const fs::path& path);
    std::string format_bytes(uint64_t size);
}

#endif //SPACE_H
