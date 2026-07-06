//
// Created by AlexanderSYN on 02.06.2026.
//
#include "../../header/console/help.h"
#include "../../header/console/color_console.h"

void help::output_help_color() {
    std::println("_____available colors that you can use_____");

    ColCons::set_red_color_console();
    std::println("this text is dark red in color -> dark_red");
    ColCons::set_LightRed_color_console();
    std::println("this text is red in color -> red");

    ColCons::set_green_color_console();
    std::println( "this text is dark green in color -> dark_green");
    ColCons::set_LightGreen_color_console();
    std::println( "this text is green in color -> green");

    ColCons::set_blue_color_console();
    std::println( "this text is dark blue in color -> dark_blue");
    ColCons::set_LightBlue_color_console();
    std::println( "this text is blue in color -> blue");

    ColCons::set_cyan_color_console();
    std::println( "this text is dark cyan in color -> dark_cyan");
    ColCons::set_LightCyan_color_console();
    std::println( "this text is cyan in color -> cyan");

    ColCons::set_Brown_color_console();
    std::println( "this text is brown in color -> brown");

    ColCons::set_DarkGray_console();
    std::println( "this text is dark gray in color -> dark_gray");
    ColCons::set_LightGray_color_console();
    std::println( "this text is gray in color -> gray");

    ColCons::set_magenta_color_console();
    std::println( "this text is magenta in color -> magenta");

    ColCons::set_yellow_color_console();
    std::println( "this text is yellow in color -> yellow");

    ColCons::set_white_color_console();
    std::println( "this text is white in color -> white / default / def");
}

void help::output_help_date() {
    std::println("[--------HELP DATE--------]");
    std::println("date -> output current date");
    std::println("time -> output current time");
}

void help::output_help_all() {
    std::println("[---------HELP ALL---------]");
    std::println("cmd:");
    std::println("cmd - run cmd your os");
    std::println();
    std::println("path:");
    std::println("cd [dir] - change directory");
    std::println("cd !$ - last listed path");
    std::println("cd -p [number]");
    std::println("pwd - output current path");
    std::println("path [param] - show or hide path");
    std::println("^[param] - --show | -s | --hide | -h^");
    std::println();
    std::println("history:");
    std::println("history - show your history");
    std::println("history [param] | -h-s || --history_search - show a history search");
    std::println("^[param] - --search | -s^");
    std::println("history [param] - save your history in txt file");
    std::println("^[param] --save | -sv^");
    std::println();
    std::println("clear:");
    std::println("clear | cls - clear console");
    std::println();
    std::println("mkcommand:");
    std::println("mkcommand | mkcmd [name] [action] - make your command");
    std::println("to change:");
    std::println("change-command | chcmd [old command] [new command] - change old command");
    std::println("change-action | chact [command] [new-action] - change action");
    std::println("delete command:");
    std::println("del-command | delcmd [command] - delete command");
    std::println("to run:");
    std::println("run-command | rnc | rc | rn [your command] - run your command");
    std::println();
    std::println("open:");
    std::println("explorer | explr | exp | openf - show current path in explorer");
    std::println("explorer | explr | exp | openf [path] - open a path in explorer");
    std::println("D:\\t.txt>> | run [path to file] - run any file via console");
    std::println();
    std::println("File | Folder:");
    std::println("touch (name file).(extension) ... - create file in current path");
    std::println("mkdir name_dir ... - create folder in current path");
    std::println("del | delete | remove | rmv name ... - delete files or directories");
    std::println("copy | cp [source] [target] - copy from source path to target path");
    std::println("or just: D:\\test>>cp [target] - source path use from current path");
    std::println("move [source] [target] - move from source to target");
    std::println();
    std::println("Text File or any other:");
    std::println("read | cat | read/cat [path to any files which can to read] - read file");
    std::println("echo [param] [text] - write text in current path");
    std::println("[param] -> -w | --write | -rw | --rewrite");
    std::println("echoln | echoln [path] - write text with many lines");
    std::println("echoln-rw | echoln-rw [path] - rewrite text with many lines");
    std::println();
    std::println("ls:");
    std::println("ls - list files and folders with count");
    std::println("[HINT] you can too use number when you want change directory:");
    std::println("cd -p [number]");
    std::println("open - output all files and folders on all OS");
    std::println("dir - output all files and folders on Windows");
    std::println();
    std::println("Find:");
    std::println("find [param] [file or folder] - find file or folder");
    std::println("param -> -g | -gf | -gd | -l | -lf | -ld");
    std::println("param -> --global | --global-file | --global-directory | --local | --local-file | --local-directory");
    std::println("--global | -g -> search for files and folders by name throughout the system");
    std::println("--global-file | -gf -> search only files by name throughout the system");
    std::println("--global-directory | -gd -> search only directory by name throughout the system");
    std::println("--local | -l - search for files and folders by name in a local folder");
    std::println("--local-file | -lf - search only files by name in a local folder");
    std::println("--local-directory | -ld - search only folders by name in a local folder");
    std::println();
    std::println("disk:");
    std::println("free | free [path] - get free space in disk");
    std::println("du | size | size [path dir] | du [path dir] - size folder");
    std::println();
    std::println("exit:");
    std::println("ex | exit - to exit from console");
}