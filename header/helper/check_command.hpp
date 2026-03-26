//
// Created by AlexanderSYN on 26.03.2026.
//

#ifndef CHECK_COMMAND_H
#define CHECK_COMMAND_H
#include "include_helper.h"

namespace helper {
    ///
    /// Calls func if user_input matches command
    /// otherwise nothing
    ///
    /// @param user_input input by user
    /// @param command command which you need to check
    /// @param func function which you need run
    template <typename Func>
    void if_command(const std::string& user_input,
                    std::string command,
                    Func func) {

        if (user_input == command)
            func();

    }

    ///
    /// Calls func if user_input matches any of the provided commands
    /// otherwise nothing
    ///
    /// @param user_input input by user
    /// @param func function which you need run
    /// @param commands commands which you need to check
    template <typename Func, typename ...Commands>
    void if_commands(const std::string& user_input,
                    Func func,
                    Commands ...commands) {

        ((user_input == commands ? (func(), true) : false) || ...);

    }
}

#endif //CHECK_COMMAND_H
