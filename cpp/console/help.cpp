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
