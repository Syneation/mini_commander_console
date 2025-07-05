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

		else if (user_input.substr(0, 11) == "open whide ") // open with hidden file/folders
			open_file(user_input, &path);

		else if (user_input.substr(0, 6) == "openf ")
			open_file(user_input, &path);

		else if (user_input == "cls" || user_input == "clear")
			clear_console();

		//
		//End open files/folders
		//

		else
		{
			std::cout << "unknown command!" << std::endl;
			std::cout << "for help type help" << std::endl;
		}
	}

}

