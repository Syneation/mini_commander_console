#include <iostream>

#ifdef  _WIN32
	#include <Windows.h>
#else // if MacOS / Linux
	#include <stdlib.h>
#endif

void clear_console()
{
	#ifdef _WIN32
		system("cls");	
	#else // if MacOS / Linux
		system("clear");
	#endif
}