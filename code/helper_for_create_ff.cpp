#include "helper_for_work_with_files.h"

//
// helper for find anything in text on file create_ff
//

//
// find path (get) -> path <- file/folders name
//
std::string hFind::find_path_create(std::string text)
{
	std::string path;
	std::string tmp_find_path = text.substr(7);

	for (int i = 0; tmp_find_path[i] != ' '; i++)
	{
		path += tmp_find_path[i];
	}

	return path;
}

std::string hFind::find_path_cr(std::string text)
{
	std::string path;
	std::string tmp_find_path = text.substr(3);

	for (int i = 0; tmp_find_path[i] != ' '; i++)
	{
		path += tmp_find_path[i];
	}

	return path;
}
//
// End find path (get) -> path <- file/folders name
//

//
// find file or folder (create path  (get) -> (file / folder) <- name) 
//
std::string hFind::find_file_folder_create(std::string text)
{
	int tmp_index_path = 0;
	std::string tmp_path = text.substr(7);
	std::string tmp_folder_or_file; 

	for (int i = 0; tmp_path[i] != ' '; i++, tmp_index_path++); // here find a space after path

	for (int j = 1; tmp_path[tmp_index_path + j] != ' '; j++)
	{
		tmp_folder_or_file += tmp_path[tmp_index_path + j];
	}

	return tmp_folder_or_file;
}

std::string hFind::find_file_folder_cr(std::string text)
{
	int tmp_index_path = 0;
	std::string tmp_path = text.substr(3);
	std::string tmp_folder_or_file;

	for (int i = 0; tmp_path[i] != ' '; i++, tmp_index_path++); // here find a space after path

	for (int j = 1; tmp_path[tmp_index_path + j] != ' '; j++)
	{
		tmp_folder_or_file += tmp_path[tmp_index_path + j];
	}

	return tmp_folder_or_file;
}

//
// End find file or folder (create path  (get) -> (file / folder) <- name) 
//

//
// find name (create path  file / folder (get) -> name <- ) 
//
std::string hFind::name_file_folder_in_text_create(std::string text)
{
	int tmp_index_path = 0;
	std::string tmp_path = text.substr(7);
	std::string tmp_name_file;

	for (int i = 0; tmp_path[i] != ' '; i++, tmp_index_path++); // here find a space after path
	for (int j = 1; tmp_path[tmp_index_path + j] != ' '; j++, tmp_index_path++); // here find a space after file / folder

	tmp_index_path += 4;

	return tmp_path.substr(tmp_index_path);
}

std::string hFind::name_file_folder_in_text_cr(std::string text)
{
	int tmp_index_path = 0;
	std::string tmp_path = text.substr(3);
	std::string tmp_name_file;

	for (int i = 0; tmp_path[i] != ' '; i++, tmp_index_path++); // here find a space after path
	for (int j = 1; tmp_path[tmp_index_path + j] != ' '; j++, tmp_index_path++); // here find a space after file / folder

	tmp_index_path += 4;

	return tmp_path.substr(tmp_index_path);
}
//
// End find name (create path  file / folder (get) -> name <- ) 
//