#include "helper_for_work_with_files.h"

void find_file_or_folders(std::string user_input, std::string path_f)
{

	char choice;

	if (user_input.substr(0, 5) != "find ")
		return;

	if (path_f.empty() || path_f == "\\")
	{
		std::cout << "Enter a valid path" << std::endl;
		return;
	}

	std::string target = user_input.substr(5);
	std::string path = path_f + (path_f.back() == '\\' ? "" : "\\") + target;

	if (!FILEH::path_exists(path))
	{
		std::cout << "path is not found: " << path << std::endl;
		return;
	}

	std::cout << (FILEH::is_directory(path) ? "[FOLDER]" : "[FILE]");
	std::cout << " found: " << path << std::endl;

	std::cout << "open in explorer? (Y/N) >> ";
	std::cin >> choice;

	if (toupper(choice) == 'Y')
	{
		std::cout << "[OPENING IN FILE MANAGER]" << std::endl;
		FILEH::open_in_explorer(path);
	}
}

