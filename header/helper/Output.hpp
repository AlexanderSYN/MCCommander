//
// Created by AlexandeSYN on 21.05.2026.
//

#ifndef SIMPLEMINICOMMANDER_OUTPUT_H
#define SIMPLEMINICOMMANDER_OUTPUT_H

#include "include_helper.h"

//================
// O - Output
//================
namespace O {
    //====================
    // SUCCESS
    //====================
    template <typename T>
    void psuccess(const T& text) {
        std::println("[SUCCESS] {}", text);
    }

    template <typename T, typename ...Args>
    void psuccess(const T& text, Args... args) {
        std::print("[SUCCESS] {} ", text);
        psuccess(args...);
    }

    //====================
    // ERROR
    //====================
    template <typename T>
    void perror(const T& text) {
        std::println("[ERROR] {}", text);
    }

    template <typename T, typename ...Args>
    void perror(const T& text, Args... args) {
        std::print("[ERROR] {} ", text);
        psuccess(args...);
    }

    //====================
    // WARNING
    //====================
    template <typename T>
    void pwarning(const T& text) {
        std::println("[WARNING] {}", text);
    }

    template <typename T, typename ...Args>
    void pwarning(const T& text, Args... args) {
        std::print("[WARNING] {} ", text);
        psuccess(args...);
    }

    //====================
    // HINT
    //====================
    template <typename T>
    void phint(const T& text) {
        std::println("[HINT] {}", text);
    }

    template <typename T, typename ...Args>
    void phint(const T& text, Args... args) {
        std::print("[HINT] {} ", text);
        psuccess(args...);
    }

    //====================
    // SYSTEM
    //====================
    template <typename T>
    void psystem(const T& text) {
        std::println("[SYSTEM] {}", text);
    }

    template <typename T, typename ...Args>
    void psystem(const T& text, Args... args) {
        std::print("[SYSTEM] {} ", text);
        psuccess(args...);
    }
}

#endif //SIMPLEMINICOMMANDER_OUTPUT_H
