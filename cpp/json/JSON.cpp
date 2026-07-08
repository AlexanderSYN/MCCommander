//
// Created by AlexanderSYN on 14.05.2026.
//

#include "../../header/json/JSON.h"
#include "../../header/helper/IO.hpp"
#include "../../header/fs/COPY.h"

bool write_in_json(const json& root_node);

std::string get_absolute_path_json() {
    wchar_t buffer[MAX_PATH];
    GetModuleFileNameW(NULL, buffer, MAX_PATH);

    fs::path exe_path(buffer);
    fs::path project_root = exe_path.parent_path();

    fs::path commands_dir = project_root / "commands";

    if (!fs::exists(commands_dir))
        fs::create_directory(commands_dir);

    return (commands_dir / "commands.json").string();
}

void JSON::save_command(const std::string& cmd, const std::vector<std::string> act) {
    json root_node;

    std::string action = "";

    for (std::string tmp : act | std::views::drop(2)) {
        action += tmp += " ";
    }

    get_all_command(root_node);

    if (!root_node.is_array())
        root_node = json::array();

    json new_command;
    new_command["command"] = cmd;
    new_command["action"] = action;

    root_node.push_back(new_command);

    if (write_in_json(root_node))
        std::println("[SYSTEM] Command: {} successfully saved!", cmd);
    else
        IO::perror("Failed to saved command in commands.json");

}

bool JSON::delete_command(const std::string &command) {
    if (!check_exists_json()) return false;

    json root_node;
    get_all_command(root_node);

    if (!root_node.is_array()) return false;

    for (auto it = root_node.begin(); it != root_node.end(); ++it) {
        if (it->value("command", "none") == command) {
            root_node.erase(it);
            if (write_in_json(root_node)) return true;
        }
    }

    return false;
}

bool JSON::change_command(const std::string &old_command, const std::string& new_command) {
    if (!check_exists_json()) return false;

    json root_node;
    get_all_command(root_node);

    if (!root_node.is_array()) return false;

    bool was_changed = false;

    for (auto& item : root_node) {
        if (item.is_object() && item.contains("command")
            && item["command"] == old_command) {
            item["command"] = new_command;
            was_changed = true;
        }
    }
    if (was_changed) {
        write_in_json(root_node);
        return true;
    }
    return false;
}

bool JSON::change_action(const std::string &command, const std::vector<std::string>& new_action) {
    if (!check_exists_json()) return false;

    json root_node;
    get_all_command(root_node);

    std::string action = "";

    for (std::string tmp : new_action | std::views::drop(2)) {
        action += tmp += " ";
    }

    if (!root_node.is_array()) return false;

    bool was_change = false;

    for (auto& item : root_node) {
        if (item.is_object() && item.contains("command")
            && item.contains("action") && item["command"] == command) {
            item["action"] = action;
            was_change = true;
        }
    }

    if (was_change) {
        write_in_json(root_node);
        return true;
    }

    return false;
}

bool JSON::write_in_json(const json& root_node) {
    std::ofstream out_file(get_absolute_path_json());

    if (out_file.is_open()) {
        out_file << root_node.dump(4);
        return true;
    }

    return false;
}

void JSON::get_all_command(json& root_node) {
    std::ifstream file(get_absolute_path_json());

    if (!file.is_open()) {
        IO::pwarning("json file not found, trying created json");
        try {
            root_node = nlohmann::json::object();
            IO::psuccess("success");
        } catch (const std::exception& e) {
            IO::perror("[ERROR]: {}", e.what());
        }
        return;
    }

    if (file.peek() == std::ifstream::traits_type::eof()) {
        IO::perror("json file is empty");
        root_node = nlohmann::json::object();
        return;
    }

    try {
        file >> root_node;
    } catch (const nlohmann::json::parse_error& perr) {
        IO::perror("json parse error: checking file format!");
        root_node = nlohmann::json::object();
    }

    file.close();

}



std::string JSON::get_action(const std::string &command) {
    if (!check_exists_json()) return "";

    std::ifstream file(get_absolute_path_json());
    json root_node;
    file >> root_node;

    if (root_node.is_array())
        for (const auto& item : root_node) {
            std::string cmd = item.value("command", "unknown");
            std::string act = item.value("action", "unknown");

            if (cmd == command)
                return act;
        }

    return "None";
}

void JSON::print_all_commands() {
    if (!check_exists_json()) return;

    std::ifstream file(get_absolute_path_json());
    json root_node;
    file >> root_node;

    if (root_node.is_array()) {
        for (const auto& item : root_node) {
                std::string cmd = item.value("command", "uknown");
                std::string act = item.value("action", "none");

                std::println("{} :  {}", cmd, act);
        }
    }
    else {
        IO::perror("Cannot reading json with commands");
    }
}

bool JSON::check_exists_json() {
    if (!fs::exists(get_absolute_path_json())) {
        IO::perror("File is not exists!");
        return false;
    }
    return true;
}