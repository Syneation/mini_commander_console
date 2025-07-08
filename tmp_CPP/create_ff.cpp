#include "helper_for_work_with_files.h"

//
//(cr / create) (path) (file / folder) name
//
void create_file_folder(std::string user_input, std::string path_f)
{
	std::string path;
    std::string full_path_with_file;
	std::string choice_file_or_folder;
	std::string name_ff; // ff - file / folder

	//
	// create path (file / folder) name
	//
	if (user_input.substr(0, 7) == "create ")
	{
		path = hFind::find_path_create(user_input) += "\\";
		choice_file_or_folder = hFind::find_file_folder_create(user_input);
		name_ff = hFind::name_file_folder_in_text_create(user_input);
		

		if (!FILEH::path_exists(path))
		{
			ColCons::set_red_color_console();
			std::cout << "File / Folder is not found!" << std::endl;
			ColCons::set_white_color_console();
			return;
		}

        if (choice_file_or_folder == "file")
        {
            // Checking for file extension
            if (name_ff.find(".") == std::string::npos)
            {
                ColCons::set_red_color_console();
                std::cout << "Error: This is not a valid file name. Please add a file extension!" << std::endl;
                ColCons::set_white_color_console();
                return;
            }

            // Checking for the validity of the file name
            if (name_ff.empty() || name_ff.find_first_of("\\/:*?\"<>|") != std::string::npos)
            {
                ColCons::set_red_color_console();
                std::cout << "Error: Invalid file name characters detected!" << std::endl;
                ColCons::set_white_color_console();
                return;
            }

            try {
                full_path_with_file += path += name_ff;
                //
                // check file in folder, if has then just do nothing
                //
                if (FILEH::is_file(full_path_with_file))
                {
                    ColCons::set_red_color_console();
                    std::cout << "Error: the file already exists!" << std::endl;
                    ColCons::set_white_color_console();
                    return;
                }

                // create file
                std::ofstream file(full_path_with_file);

                // checking file creation
                if (!FILEH::is_file(full_path_with_file))
                {
                    ColCons::set_red_color_console();
                    std::cerr << "Error: Failed to create file!" << std::endl;
                    ColCons::set_white_color_console();
                    return;
                }
 
                file.close();

                ColCons::set_green_color_console();
                std::cout << "File '" << name_ff << "' created successfully." << std::endl;
                std::cout << "in path '" << path << "'!" << std::endl;
                ColCons::set_white_color_console();

            }
            catch (const std::exception& e) {
                ColCons::set_red_color_console();
                std::cout << "Error creating file: " << e.what() << std::endl;
                ColCons::set_white_color_console();
            }
        }
		
	}
    //
    // cr path (file / folder) name
    //
	else if (user_input.substr(0, 3) == "cr ")
	{
        path = hFind::find_path_cr(user_input) += "\\";
        choice_file_or_folder = hFind::find_file_folder_cr(user_input);
        name_ff = hFind::name_file_folder_in_text_cr(user_input);


        if (!FILEH::path_exists(path))
        {
            ColCons::set_red_color_console();
            std::cout << "File / Folder is not found!" << std::endl;
            ColCons::set_white_color_console();
            return;
        }

        if (choice_file_or_folder == "file")
        {
            // Checking for file extension
            if (name_ff.find(".") == std::string::npos)
            {
                ColCons::set_red_color_console();
                std::cout << "Error: This is not a valid file name. Please add a file extension!" << std::endl;
                ColCons::set_white_color_console();
                return;
            }

            // Checking for the validity of the file name
            if (name_ff.empty() || name_ff.find_first_of("\\/:*?\"<>|") != std::string::npos)
            {
                ColCons::set_red_color_console();
                std::cout << "Error: Invalid file name characters detected!" << std::endl;
                ColCons::set_white_color_console();
                return;
            }

            try {
                full_path_with_file += path += name_ff;
                //
                // check file in folder, if has then just do nothing
                //
                if (FILEH::is_file(full_path_with_file))
                {
                    ColCons::set_red_color_console();
                    std::cout << "Error: the file already exists!" << std::endl;
                    ColCons::set_white_color_console();
                    return;
                }

                // create file
                std::ofstream file(full_path_with_file);

                // checking file creation
                if (!FILEH::is_file(full_path_with_file))
                {
                    ColCons::set_red_color_console();
                    std::cerr << "Error: Failed to create file!" << std::endl;
                    ColCons::set_white_color_console();
                    return;
                }

                file.close();

                ColCons::set_green_color_console();
                std::cout << "File '" << name_ff << "' created successfully." << std::endl;
                std::cout << "in path '" << path << "'!" << std::endl;
                ColCons::set_white_color_console();

            }
            catch (const std::exception& e) {
                ColCons::set_red_color_console();
                std::cout << "Error creating file: " << e.what() << std::endl;
                ColCons::set_white_color_console();
            }
        }
	}
}