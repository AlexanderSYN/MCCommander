//
// Created by AlexanderSYN on 28.03.2026.
//

#include "../../header/helper/helper.h"

///
/// @param text the text that needs to be changed
/// @param old_chars The value to be replaced.
/// @param new_chars The replacement value.
void helper::replace_chars(std::string &text,
                           const std::string &old_chars,
                           const std::string &new_chars) {

    size_t pos = 0;
    while ((pos = text.find(old_chars, pos)) != std::string::npos)
        text.replace(pos, 2, new_chars);
}

