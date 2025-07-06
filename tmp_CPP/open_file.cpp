#include "helper_for_work_with_files.h"

bool check_folders(const std::string path_folder);
void out_files_from_folders_comm_open(const fs::path path_f); // for output fils/folds use command open ...
void out_files_from_folders(const std::string path_f); // for output fils/fold use commmand dir
void open_file(const std::string path_f); // open file

void open_file(const std::string user_input, std::string* path_f)
{
	//
	//path folders
	//
	if (user_input.substr(0, 3) == "cd ")
	{
		std::string path = user_input.substr(3);

		if (check_folders(path))
		{
			*path_f = path;
		}
		else
		{
			std::cout << "Error: folder is not found!" << std::endl;
		}
	}
	//
	//if you need out files from folders
	//
	else if (user_input.substr(0, 4) == "dir")
	{
		out_files_from_folders(*path_f);
	}
	//
	//if you need show folders/files on all OS
	//
	else if (user_input.substr(0, 5) == "open ")
	{
		std::string path_file = user_input.substr(5);
		out_files_from_folders_comm_open(path_file);
	}
	//
	//open file
	//
	else if (user_input.substr(0, 6) == "openf ")
		open_file(user_input);
}

bool check_folders(const std::string path_folder)
{
	std::error_code err_code;
	return fs::exists(path_folder, err_code) && fs::is_directory(path_folder, err_code);
}

//
//for output fils/folds use command open ...
//
void out_files_from_folders_comm_open(const fs::path path_f)
{
	try
	{
		if (!fs::exists(path_f) || !fs::is_directory(path_f))
		{
			std::cout << "Error: folder ( " << path_f << " ) is not found!" << std::endl;
			return;
		}

		std::cout << "Contents of " << path_f << ":" << std::endl;

		for (const auto& entry : fs::directory_iterator(path_f))
		{
			auto ftime = entry.last_write_time();
			std::string hidden_marker = "";

			#ifdef _WIN32
				DWORD attrs = GetFileAttributesA(entry.path().string().c_str());
				if (attrs != INVALID_FILE_ATTRIBUTES && (attrs & FILE_ATTRIBUTE_HIDDEN))
				{
					hidden_marker = " [HIDDEN]";
				}
			#else // for MacOS / Linux
				if (entry.path().filename().string()[0] == ".")
				{
					hidden_marker = " [HIDDEN]";
				}
			#endif		

			if (fs::is_directory(entry.status()))
			{
				std::cout << std::setw(20) << timeff::format_time(ftime)
					<< std::setw(8) << "[DIR]"
					<< std::setw(10) << hidden_marker
					<< entry.path().filename() << std::endl;
			}
			else
			{
				std::cout << std::setw(20) << timeff::format_time(ftime)
					<< std::setw(10) << std::to_string(entry.file_size()) << " bytes"
					<< std::setw(8) << "[FILE]"
					<< std::setw(10) << hidden_marker
					<< entry.path().filename() << std::endl;
			}
		}
	}
	catch (const fs::filesystem_error& fs_err)
	{
		std::cerr << "[ERROR] " << fs_err.what() << std::endl;
	}
}

//
//for output fils/fold use commmand dir
//
void out_files_from_folders(const std::string path_f)
{
	if (!check_folders(path_f))
	{
		std::cout << "Error: folder ( " << path_f << " ) is not found!" << std::endl;
		return;
	}

	try
	{
		std::string command = "dir /a \"" + path_f + "\"";

		system(command.c_str());
	}
	catch (const std::exception& e)
	{
		std::cout << "[ERROR] " << e.what() << std::endl;
	}
}

void open_file(const std::string path_f)
{
	try
	{
		std::string path_file = path_f.substr(6);

		#if defined(_WIN32) //Windows
			std::string command = "start \"\" \"" + path_file + "\"";
		#elif defined(__APPLE__) // MacOs
			std::string command = "open \"" + path_file + "\"";
		#elif defined(__linux__) //Linux
			std::string command = "xdg-open \"" + path_file + "\"";
		#else
			std::cerr << "Unsupported OS" << std::endl;
			return;
		#endif

		bool result = system(command.c_str());

		if (!result)
			std::cout << "[SUCCESS OPEN]" << std::endl;
		else
			std::cerr << "[ERROR OPEN]" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "[ERROR OPEN FILE] " << e.what() << std::endl;
		return;
	}
}
