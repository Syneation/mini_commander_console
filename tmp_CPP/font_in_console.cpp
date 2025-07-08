#include "helper_for_work_with_files.h"

//
//Win Api
//
void change_font_in_console(std::string font)
{
	//
	// if you don't choice a font
	//
	if (font == " ")
	{
		HWND hwnd = GetConsoleWindow(); // Getting the handle of the console window
		if (hwnd == NULL)
		{
			ColCons::set_red_color_console();
			std::cerr << "Couldn't get a handle to the console window!" << std::endl;
			ColCons::set_white_color_console();
			return;
		}

		CONSOLE_FONT_INFOEX cons_font_inf;
		cons_font_inf.cbSize = sizeof(cons_font_inf);
		if (!GetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cons_font_inf))
		{
			ColCons::set_red_color_console();
			std::cerr << "Couldn't get information about the font!" << std::endl;
			ColCons::set_white_color_console();
			return;
		}

		wcscpy_s(cons_font_inf.FaceName, L"Courier New");
		cons_font_inf.dwFontSize.X = 16;
		cons_font_inf.dwFontSize.Y = 16;

		if (!SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cons_font_inf))
		{
			ColCons::set_red_color_console();
			std::cerr << "Couldn't install the font!" << std::endl;
			ColCons::set_white_color_console();
			return;
		}
	}
	//
	// if you choice a font
	//
	else if (font != " ")
	{
		std::string font = font

		HWND hwnd = GetConsoleWindow(); // Getting the handle of the console window
		if (hwnd == NULL)
		{
			ColCons::set_red_color_console();
			std::cerr << "Couldn't get a handle to the console window!" << std::endl;
			ColCons::set_white_color_console();
			return;
		}

		CONSOLE_FONT_INFOEX cons_font_inf;
		cons_font_inf.cbSize = sizeof(cons_font_inf);
		if (!GetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cons_font_inf))
		{
			ColCons::set_red_color_console();
			std::cerr << "Couldn't get information about the font!" << std::endl;
			ColCons::set_white_color_console();
			return;
		}

		wcscpy_s(cons_font_inf.FaceName, L"Courier New");
		cons_font_inf.dwFontSize.X = 16;
		cons_font_inf.dwFontSize.Y = 16;

		if (!SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cons_font_inf))
		{
			ColCons::set_red_color_console();
			std::cerr << "Couldn't install the font!" << std::endl;
			ColCons::set_white_color_console();
			return;
		}
	}
	
}