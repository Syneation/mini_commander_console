#include "helper_for_work_with_files.h"

void find_file_or_folders(std::string user_input, std::string path_f)
{
	char choice;

	if (user_input.substr(0, 5) != "find ")
		return;

	if (path_f.empty() || path_f == "\\")
	{
		ColCons::set_red_color_console();
		std::cout << "Enter a valid path" << std::endl;
		ColCons::set_white_color_console();
		return;
	}

	std::string target = user_input.substr(5);
	std::string path = path_f + (path_f.back() == '\\' ? "" : "\\") + target;

	if (!FILEH::path_exists(path))
	{
		ColCons::set_red_color_console();
		std::cout << "path is not found: " << path << std::endl;
		ColCons::set_white_color_console();
		return;
	}

	std::cout << (FILEH::is_directory(path) ? "[FOLDER]" : "[FILE]");
	ColCons::set_green_color_console();
	std::cout << " found: " << path << std::endl;

	std::cout << "open in explorer? (Y/N) >> ";
	ColCons::set_white_color_console();
	std::cin >> choice;

	if (toupper(choice) == 'Y')
	{
		std::cout << "[OPENING IN FILE MANAGER]" << std::endl;
		FILEH::open_in_explorer(path);
	}
}

