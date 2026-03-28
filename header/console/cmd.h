//
// Created by AlexanderSYN on 28.03.2026.
//

#ifndef CMD_H
#define CMD_H

#ifdef _IOSTREAM_
    #define IOSTREAM_INCLUDED 1
#else
    #include <iostream>
    #define IOSTREAM_INCLUDED 0
#endif

#ifdef __STRINGIFY__
    #define STRING_INCLUDED 1
#else
    #include <string>
    #define STRING_INCLUDED 0
#endif

namespace cmd {
    void run(const std::string& command);
}

#endif //CMD_H
