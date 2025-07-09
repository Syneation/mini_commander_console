#include "main_func.h"

#include <Windows.h>

int main()
{
	//
	// change font console 
	//
	HWND hwnd = GetConsoleWindow(); // Получаем дескриптор окна консоли
	if (hwnd == NULL) {
		std::cerr << "Не удалось получить дескриптор окна консоли." << std::endl;
		return 1;
	}

	// Пример изменения шрифта на Courier New, размер 16
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	if (!GetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi)) {
		std::cerr << "Не удалось получить информацию о шрифте." << std::endl;
		return 1;
	}

	wcscpy_s(cfi.FaceName, L"Courier New");
	cfi.dwFontSize.X = 16;
	cfi.dwFontSize.Y = 16;

	if (!SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi)) {
		std::cerr << "Не удалось установить шрифт." << std::endl;
		return 1;
	}
	//
	// End change font console 
	//

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
			std::cout << "cd - the command to change the working directory" << std::endl;
			std::cout << "dir - allows you to display a list of files and subdirectories for the specified directory" << std::endl;
			std::cout << "open ... <- (path) - allows you to display a list of files and subdirectories for the specified directory" << std::endl;
			std::cout << "openf ... <- (path with file or just folder) - opening a file or folder through OS programs" << std::endl;
			std::cout << "clear / cls - clearing the console" << std::endl;
			std::cout << "find ... <- (name file / folder) - first you need to specify the path via cd, then you can search for a file / folder." << std::endl;
			std::cout << "clear / cls - clearing the console" << std::endl;
			std::cout << "delete ... <- (name file / folder or first you need to specify the path via cd, then just write delete) - delete file / folder" << std::endl;
			std::cout << "create / cr ... <- (path) ... <- (file or folder) ... <- (name file / folder) - the command to create a file or folder" << std::endl;
		}
		//
		// End help
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

