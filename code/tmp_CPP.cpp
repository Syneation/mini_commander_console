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
		

		if (user_input == "exit" || user_input == "ex")
			isRun = false;

		//
		// help
		//
		else if (user_input == "help")
		{
			std::cout << "help - just help" << std::endl;
			std::cout << "clear / cls - clearing the console" << std::endl;
			std::cout << "clear / cls - clearing the console" << std::endl;
			std::cout << "info - information about this programm" << std::endl;
			std::cout << "cd - the command to change the working directory" << std::endl;
			std::cout << "dir - allows you to display a list of files and subdirectories for the specified directory" << std::endl;
			std::cout << "openf ... <- (path with file or just folder) - opening a file or folder through OS programs" << std::endl;
			std::cout << "open ... <- (path) - allows you to display a list of files and subdirectories for the specified directory" << std::endl;
			std::cout << "find ... <- (name file / folder) - first you need to specify the path via cd, then you can search for a file / folder." << std::endl;
			std::cout << "create / cr ... <- (path) ... <- (file or folder) ... <- (name file / folder) - the command to create a file or folder" << std::endl;
			std::cout << "delete ... <- (1 option: name file / folder or 2 option: first you need to specify the path via cd, then just write delete) - delete file / folder" << std::endl;
		}
		//
		// End help
		//

		//
		// info
		//
		else if (user_input == "info")
		{
			std::cout << "___MINI_COMMANDER_CONSOLE___" << std::endl;
			std::cout << "_________VERSION_1__________" << std::endl;
			std::cout << "______AUTHOR: ALEXANDER_____" << std::endl;
			std::cout << "_____GIT-HUB: SYNEATION_____" << std::endl;
			std::cout << "_________JUST FUN ;)________" << std::endl;
		}
		//
		// End info
		//

		//
		//open files/folders
		//
		else if (user_input.substr(0, 3) == "cd " || user_input.substr(0, 4) == "dir")
			open_file(user_input, &path);

		else if (user_input.substr(0, 5) == "open ") // for all OS
			open_file(user_input, &path);

		else if (user_input.substr(0, 6) == "openf ")
			open_file(user_input, &path);

		//
		//End open files/folders
		//

		//
		// clear / cls
		//
		else if (user_input == "cls" || user_input == "clear")
			clear_console();
		//
		// End clear / cls
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

		//
		//(cr / create) (path) (file / folder) name
		//
		else if (user_input.substr(0, 7) == "create " || user_input.substr(0, 3) == "cr ")
			create_file_folder(user_input, path);
		//
		// End (cr / create) (path) (file / folder) name
		//

		//
		// change a font size in console
		//
		else
		{
			ColCons::set_red_color_console();
			std::cout << "unknown command!" << std::endl;
			std::cout << "for help type help" << std::endl;
			ColCons::set_white_color_console();
		}
		//
		// End change a font size in console
		//
	}

}

