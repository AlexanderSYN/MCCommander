//
// Created by AlexandeSYN on 21.05.2026.
//

#ifndef SIMPLEMINICOMMANDER_OUTPUT_H
#define SIMPLEMINICOMMANDER_OUTPUT_H

#include "include_helper.h"


namespace IO {
    namespace detail {
        inline void log_base(std::ostream& stream, std::string_view prefix,
            std::string_view text) {

            std::println(stream, "[{}] {}", prefix, text);
        }

        template <typename ...Args>
        void log_templated(std::ostream& stream, std::string_view prefix,
            std::string_view text, Args&&... args) {

            std::print(stream, "[{}] ", prefix);

            if (text.find("{}") != std::string_view::npos) {
                std::vprint_nonunicode(stream, text, std::make_format_args(args...));
                std::print(stream, "\n");
            }
            else {
                std::print(stream, "{} ", text);
                ((std::print(stream, "{} ", std::forward<Args>(args))), ...);
                std::print(stream, "\n");
            }
        }
    }

    //====================
    // SUCCESS
    //====================
    inline void psuccess(std::string_view text) {
        detail::log_base(std::cout, "SUCCESS", text);
    }

    template <typename ...Args>
    void psuccess(std::string_view text, Args&&... args) {
        detail::log_templated(std::cout, "SUCCESS", text, std::forward<Args>(args)...);
    }

    //====================
    // ERROR
    //====================
    inline void perror(std::string_view text) {
        detail::log_base(std::cerr, "ERROR", text);
    }

    template <typename ...Args>
    void perror(std::string_view text, Args&&... args) {
        detail::log_templated(std::cerr, "ERROR", text, std::forward<Args>(args)...);
    }

    //====================
    // WARNING
    //====================
    inline void pwarning(std::string_view text) {
        detail::log_base(std::cout, "WARNING", text);
    }

    template <typename ...Args>
    void pwarning(std::string_view text, Args&&... args) {
        detail::log_templated(std::cout, "WARNING", text, std::forward<Args>(args)...);
    }

    //====================
    // HINT
    //====================
    inline void phint(std::string_view text) {
        detail::log_base(std::cout, "HINT", text);
    }

    template <typename ...Args>
    void phint(std::string_view text, Args&&... args) {
        detail::log_templated(std::cout, "HINT", text, std::forward<Args>(args)...);
    }

    //====================
    // SYSTEM
    //====================
    inline void psystem(std::string_view text) {
        detail::log_base(std::cout, "SYSTEM", text);
    }

    template <typename ...Args>
    void psystem(std::string_view text, Args&&... args) {
        detail::log_templated(std::cout, "SYSTEM", text, std::forward<Args>(args)...);
    }
}

#endif //SIMPLEMINICOMMANDER_OUTPUT_H
