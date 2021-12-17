#include <fstream>
#include <sstream>

#include <scp/utils/file-utils.hpp>

namespace file_utils = scp::utils::file_utils;

std::string file_utils::loadAsString(std::string_view path)
{
    std::ifstream file(path.data());
    std::stringstream fileContent;
    
    if (!file.is_open())
    {
        std::cerr << "[ERROR]: Failed to find or locate file " << path << std::endl;
        return "";
    }
    else
    {
        while (file)
        {
            char character = ' ';
            file >> character;
            fileContent << character;
        }
    }
    
    return fileContent.str();
}