//
//helper_work_with_color
//

#include "helper_for_work_with_files.h"

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void ColCons::set_black_color_console()
{
	SetConsoleTextAttribute(hConsole, Black);
}

void ColCons::set_red_color_console()
{
	SetConsoleTextAttribute(hConsole, Red);
}

void ColCons::set_green_color_console()
{
	SetConsoleTextAttribute(hConsole, Green);
}

void ColCons::set_blue_color_console()
{
	SetConsoleTextAttribute(hConsole, Blue);
}

void ColCons::set_white_color_console()
{
	SetConsoleTextAttribute(hConsole, White);
}