#include "main_func.h"
#include "helper_for_work_with_files.h"

//
//function for convert from file_time_type to time_t
//
std::time_t timeff::to_time_t(const fs::file_time_type& ftime)
{
	auto sctp = std::chrono::time_point_cast<std::chrono::system_clock::duration>(
		ftime - fs::file_time_type::clock::now() + std::chrono::system_clock::now()
	);

	return std::chrono::system_clock::to_time_t(sctp);
}

//
//function for formatter to output date and time
//
std::string timeff::format_time(const fs::file_time_type& ftime)
{
	std::time_t cftime = to_time_t(ftime);
	char buffer[80];

#ifdef  _WIN32
	struct tm timeinfo;
	localtime_s(&timeinfo, &cftime);
	std::strftime(buffer, sizeof(buffer), "%d.%m.%Y %H:%M:%S", &timeinfo);
#else // if MacOS / Linux
	std::strftime(buffer, sizeof(buffer), "%d.%m.%Y %H:%M:%S", std::localtime(&cftime));
#endif

	return buffer;
}

void toLowerCase(std::string& text)
{
	// ASCII
	for (char& c : text)
		if (c >= 'A' && c <= 'Z')
			c += 32;
}

//
//FILE helper
//
//
// Checking the existence of a file or folder
//
bool FILEH::path_exists(const std::string& path)
{
	struct stat sb;
	return (stat(path.c_str(), &sb) == 0);
}

//
// Checking if the path is a folder
//
bool FILEH::is_directory(const std::string& path)
{
	struct stat sb;

	if (stat(path.c_str(), &sb) == 0)
		return (sb.st_mode & S_IFDIR) != 0;

	return false;
}

//
// Checking if the path is a file
//
bool FILEH::is_file(const std::string& path)
{
	struct stat sb;

	if (stat(path.c_str(), &sb) == 0)
		return (sb.st_mode & S_IFREG) != 0;

	return false;
}

//
//open file or folder in explorer
//
void FILEH::open_in_explorer(const std::string& path)
{
#if defined(_WIN32)
	std::string  command = FILEH::is_directory(path)
		? "explorer \"" + path + "\""
		: "explorer /select,\"" + path + "\"";

#elif defined(__APPLE__)
	std::string command = "open \"" + path + "\"";

#elif defined(__linux__)
	std::string command = "xdg-open \"" + path + "\"";

#else 
	std::cerr << "Unsupported OS!" << std::endl;
	return;
#endif

	int result = system(command.c_str());
	if (result == 0) {
		std::cerr << "Failed to open file manager" << std::endl;
	}
}