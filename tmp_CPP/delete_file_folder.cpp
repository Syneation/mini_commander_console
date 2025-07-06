#include "helper_for_work_with_files.h"

void delete_file_or_folder(std::string user_input, std::string* path_f)
{
	char choice;

	//
	// check for option 1 - delete (path) or 2 - delete
	//
	if (user_input.substr(0, 7) == "delete ") // delete ...
	{
		std::string path = user_input.substr(7);
		if (!FILEH::path_exists(path))
		{
			std::cout << "File is not found!" << std::endl;
			return;
		}

		std::cout << "are you sure? (Y/N) >> ";
		std::cin >> choice;

		if (toupper(choice) == 'N')
			return;

		try
		{
			if (FILEH::is_file(path))
			{

				if (std::remove(path.c_str()) == 0)
				{
					std::cout << "File deleted successfully!" << std::endl;

					if (*path_f == path)
						*path_f = "\\";
				}
				else
				{
					std::cerr << "Error: failed to delete file (" << errno << ") - "
						<< path << std::endl;
					perror("Reason");
				}
			}
			else if (FILEH::is_directory(path))
			{
				try
				{
					if (fs::remove(path))
					{
						std::cout << "Empty folder deleted successfully!" << std::endl;
						if (*path_f == path)
							*path_f = "\\";
					}
				} 
				catch (const std::filesystem::filesystem_error& fs_err)
				{
					if (fs_err.code() != std::errc::directory_not_empty)
						throw;
				}

				if (*path_f != "\\")
				{
					uintmax_t uin_t = fs::remove_all(path);

					if (uin_t > 0)
					{
						std::cout << "Deleted " << uin_t << " items from folder succesffully!" << std::endl;

						if (*path_f == path)
							*path_f = "\\";
					}
					else
					{
						std::cerr << "Error: failed to delete folder - " << path << " !" << std::endl;
						return;
					}
				}
				
			}
		} 
		catch (const std::filesystem::filesystem_error& e)
		{
			std::cerr << "Filesystem error: " << e.what() << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << "[ERROR] " << e.what() << std::endl;
		}
	}
	//
	//delete
	//
	else // delete
	{
		if (!FILEH::path_exists(*path_f))
		{
			std::cout << "File is not found!" << std::endl;
			return;
		}

		std::cout << "are you sure? (Y/N) >> ";
		std::cin >> choice;

		if (toupper(choice) == 'N')
			return;

		try
		{
			std::string path = *path_f;

			if (FILEH::is_file(path))
			{

				if (std::remove(path.c_str()) == 0)
				{
					std::cout << "File deleted successfully!" << std::endl;
					path = "\\";
				}
				else
				{
					std::cerr << "Error: failed to delete file (" << errno << ") - "
						<< path << std::endl;
					perror("Reason");
				}
			}
			else if (FILEH::is_directory(path))
			{
				try
				{
					if (fs::remove(path))
					{
						std::cout << "Empty folder deleted successfully!" << std::endl;
						*path_f = "\\";
					}
				}
				catch (const std::filesystem::filesystem_error& fs_err)
				{
					if (fs_err.code() != std::errc::directory_not_empty)
						throw;
				}

				if (*path_f != "\\")
				{
					uintmax_t uin_t = fs::remove_all(path);

					if (uin_t > 0)
					{
						std::cout << "Deleted " << uin_t << " items from folder succesffully!" << std::endl;
						*path_f = "\\";
					}
					else
					{
						std::cerr << "Error: failed to delete folder - " << path << " !" << std::endl;
						return;
					}
				}

			}
		}
		catch (const std::filesystem::filesystem_error& e)
		{
			std::cerr << "Filesystem error: " << e.what() << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << "[ERROR] " << e.what() << std::endl;
		}
	}
}
