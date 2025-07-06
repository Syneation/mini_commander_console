#include "main_func.h"

int main()
{
	
	setlocale(LC_ALL, "ru");

	bool isRun = true;
	std::string user_input, path = "";

	std::cout << "for help type help" << std::endl;

	while (isRun)
	{
		std::cout << "\\" << path << " >> ";
		std::getline(std::cin, user_input);
		

		if (user_input == "exit")
			isRun = false;
		//
		//open files/folders
		//
		else if (user_input.substr(0, 3) == "cd " || user_input.substr(0, 4) == "dir")
			open_file(user_input, &path);

		else if (user_input.substr(0, 5) == "open ") // for all OS
			open_file(user_input, &path);

		else if (user_input.substr(0, 6) == "openf ")
			open_file(user_input, &path);

		else if (user_input == "cls" || user_input == "clear")
			clear_console();

		//
		//End open files/folders
		//

		//
		//find file
		//
		else if (user_input.substr(0, 5) == "find ")
			find_file_or_folders(user_input, path);

		//
		//End find file
		//

		//
		//delete file / folders
		//
		else if (user_input.substr(0, 7) == "delete " || user_input == "delete")
			delete_file_or_folder(user_input, &path);
		//
		//End delete file / folders
		//

		else
		{
			std::cout << "unknown command!" << std::endl;
			std::cout << "for help type help" << std::endl;
		}
	}

}

