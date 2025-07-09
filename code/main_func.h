#pragma once
#include <iostream>
#include <string>

void toLowerCase(std::string& text);
void open_file(const std::string user_input, std::string* path_file);
void find_file_or_folders(std::string user_input, std::string path_f);
void delete_file_or_folder(std::string user_input, std::string* path_f);
void create_file_folder(std::string user_input, std::string path_f);
void change_font_in_console(std::string font);
void clear_console();

namespace ColCons
{
	void set_black_color_console();
	void set_red_color_console();
	void set_red_color_console();
	void set_green_color_console();
	void set_blue_color_console();
	void set_white_color_console();
}
