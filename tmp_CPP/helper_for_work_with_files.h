#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <system_error>

#include <conio.h>
#include <Windows.h>

#include <stdio.h>

namespace fs = std::filesystem;

#ifndef HELPER_FOR_WORK_WITH_FILES_H
#define HELPER_FOR_WORK_WITH_FILES_H

extern HANDLE hConsole;

namespace timeff
{
    std::time_t to_time_t(const fs::file_time_type& ftime);
    std::string format_time(const fs::file_time_type& ftime);
}

namespace FILEH
{
    bool path_exists(const std::string& path);
    bool is_directory(const std::string& path);
    bool is_file(const std::string& path);
    void open_in_explorer(const std::string& path);
}

//
// helper for find anything in text on file create_ff
//
namespace hFind
{
    std::string find_path_create(std::string text);
    std::string find_path_cr(std::string text);
    std::string find_file_folder_create(std::string text);
    std::string find_file_folder_cr(std::string text);
    std::string name_file_folder_in_text_create(std::string text);
    std::string name_file_folder_in_text_cr(std::string text);
}

enum color_console
{
    Black        = 0,
    Blue         = 1,
    Green        = 2,
    Cyan         = 3,
    Red          = 4,
    Magenta      = 5,
    Brown        = 6,
    LightGray    = 7,
    DarkGray     = 8,
    LightBlue    = 9,
    LightGreen   = 10,
    LightCyan    = 11,
    LightRed     = 12,
    LightMagenta = 13,
    Yellow       = 14,
    White        = 15
};
namespace ColCons
{
	void set_black_color_console();
	void set_red_color_console();
	void set_red_color_console();
	void set_green_color_console();
    void set_blue_color_console();
	void set_white_color_console();
}

#endif // HELPER_FOR_WORK_WITH_FILES_H
