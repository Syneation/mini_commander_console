#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <system_error>
#include <Windows.h>
#include <sys/stat.h>

namespace fs = std::filesystem;

#ifndef HELPER_FOR_WORK_WITH_FILES_H
#define HELPER_FOR_WORK_WITH_FILES_H

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

#endif // HELPER_FOR_WORK_WITH_FILES_H
