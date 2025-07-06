#pragma once
#include <iostream>
#include <string>

void toLowerCase(std::string& text);
void open_file(const std::string user_input, std::string* path_file);
void find_file_or_folders(std::string user_input, std::string path_f);
void delete_file_or_folder(std::string user_input, std::string* path_f);
void clear_console();
